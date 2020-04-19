#include "../includesH/list_func.h"

void inc_id(carHead *head , carNode *cur_node)
{
    while(cur_node != NULL){
        cur_node->id++;
        cur_node = cur_node->next;
    }
}

void dec_id(carHead *head , carNode *cur_node)
{   
    while(cur_node != NULL){
        cur_node->id--;
        cur_node = cur_node->next;
    }
}

void free_del(carNode *tmp)
{
    free(tmp->data->name);
    free(tmp->data->company);
    free(tmp->data);
    free(tmp);
}

carNode *get_node()
{
    carNode *new_node = NULL;
    if((new_node = (carNode*)malloc(sizeof(carNode))) != NULL){
        if((new_node->data = (car*)malloc(sizeof(car))) != NULL){
            new_node->data->company = (char*)malloc(MAXLENGTH*sizeof(char));
            new_node->data->name = (char*)malloc(MAXLENGTH*sizeof(char));
            if(new_node->data->company && new_node->data->name){
                getchar();
                puts("Enter the name(Max length is 512 chars!):");
                fgets(new_node->data->name , MAXLENGTH , stdin);
                new_node->data->name[strlen(new_node->data->name) - 1] = '\0';
                puts("Enter the company(Max length is 512 chars!):");
                fgets(new_node->data->company , MAXLENGTH , stdin);
                new_node->data->company[strlen(new_node->data->company) - 1] = '\0';
                puts("Enter the year of production:");
                scanf("%d" , &new_node->data->year);
                puts("Enter the price:");
                scanf("%d" , &new_node->data->price);
                puts("Enter the weight:");
                scanf("%f" , &new_node->data->weight);
                puts("Enter the mileage");
                scanf("%f" , &new_node->data->mileage);
                puts("Enter min and max speed");
                scanf("%d %d" , &new_node->data->speed[0] , &new_node->data->speed[1]);
                getchar();
            } else {
                new_node = NULL;
            }
        } else {
            new_node = NULL;
        }
        new_node->next = NULL;
    }
    return new_node;
}

void insert_after(carHead *head)
{
    int uid;
    carNode *node , *tmp;
    if(head){
        if(head->count != 0){
            puts("\nFill new struct\n");
            node = get_node();
            puts("\nEnter element`s id");
            scanf("%d" , &uid);
            if((uid > 0) && (uid <= head->count)){
                CLS;
                tmp = head->first;

                while(tmp->id != uid){
                    tmp = tmp->next;
                }
                if(tmp->next == NULL){
                    tmp->next = node;
                    head->last = node;
                    node->next = NULL;
                    node->id = head->count;
                } else {
                    node->next = tmp->next;
                    node->id = tmp->id;
                    tmp->next = node;
                }
                head->count++;
                inc_id(head , node);
            } else {CLS; puts("There is no this id in the list!"); }
        } else {CLS; puts("Fill the list first!"); }
    }
    print_list(head);
}

void insert_before(carHead *head) // finish
{
    int uid;
    carNode *node , *tmp , *tmp1;
    if(head){
        if(head->count != 0){
            puts("\nFill new struct\n");
            node = get_node();
            puts("\nEnter element`s id");
            scanf("%d" , &uid);
            if((uid > 0) && (uid <= head->count)){
                CLS;
                tmp = head->first;
                if(tmp->id == uid){
                    node->next = head->first;
                    head->first = node;
                    node->id = 1;
                } else {
                    while(tmp != NULL){
                        if(tmp->next->id == uid){
                            node->next = tmp->next;
                            node->id = tmp->next->id;
                            tmp->next = node;
                            tmp = NULL;
                        } else tmp = tmp->next;
                    }
                }
                inc_id(head,node->next);
                head->count++;
            } else {CLS; puts("There is no this id in the list! Or trying to add before the first element!");}
        } else {CLS; puts("Fill the list first!"); }
    }
    print_list(head);
}

void delete_elem(carHead *head)
{
    int uid;
    carNode *tmp , *tmp1;

    if(head){
        if(head->count != 0){
            puts("Enter the element`s id");
            scanf("%d" , &uid);
            if((uid > 0) && (uid <= head->count)){
                CLS;
                tmp = head->first;
                if(tmp->id == uid){
                    if(tmp->next != NULL){
                        head->first->id = 1;
                        dec_id(head,head->first->next);
                    }
                    head->first = tmp->next;
                    free_del(tmp);
                } else {
                    while(tmp != NULL){
                        if(tmp->next->id == uid){
                            if(tmp->next->next != NULL){
                                tmp1 = tmp->next->next;
                                tmp->next->next->id = tmp->next->id;
                                free_del(tmp->next);
                                tmp->next = tmp1;
                                dec_id(head , tmp->next->next);
                            } else {
                                free_del(tmp->next);
                                tmp->next = NULL;
                            }
                            tmp = NULL;
                        } else tmp = tmp->next;
                    }
                }
                head->count--;
            } else {CLS; puts("There is no this id in the list!");}
        } else {CLS; puts("Fill the list first!"); }
    }
    print_list(head);
}

void insert_before_last(carHead *head)
{    
    carNode *node , *tmp;
    if(head){
        puts("\nFill new struct:\n");
        node = get_node();
        if(head->count == 0){
            head->first = node;
            node->id = 1;
        } else {
            tmp = head->first;
            if(head->count == 1){
                node->next = tmp;
                node->id = 1;
                head->first = node;
                inc_id(head,node->next);
            } else {
                while(tmp != NULL){
                    if(tmp->next->id == head->count){
                        node->id = head->count;
                        node->next = tmp->next;
                        tmp->next = node;
                        inc_id(head,node->next);
                        tmp = NULL;
                    } else tmp = tmp->next;
                }
            }
        }
        head->count++;
    }
    print_list(head);
}

void init_list(carHead *head)
{
    carNode *node;
    if(head){
        if(head->count == 0){
            puts("\nFill new struct:\n");
            node = get_node();
            head->first = node;
            head->last = node;
            node->id = 1;
            head->count++;
        } else {CLS; puts("The list is already initialised!");}
    }
    print_list(head);
}

carHead* init_head()
{
    carHead *head = NULL;
    if((head = malloc(sizeof(carHead))) != NULL){
        head->count = 0;
        head->first = NULL;
        head->last = NULL;
    }

    return head;
}

void add_first(carHead *head , carNode *node)
{
    if(head && node){
        head->count++;
        head->first = node;
        head->last = node;
    }
}

void print_list(carHead *head)
{
    carNode *p;
    if(head->count == 0){
        puts("======================The list is empty!======================");
    } else {
        if((p = head->first) != NULL){
            puts("\nReaded data from file");
            printf("\n|-----------------------------------------------------------------------------------------|\n");
            printf("|%3s |%12s |%11s |%5s |%5s |%11s |%8s |%9s |%9s|\n" ,"Id", "Name" , "Company" , "Year" , "Price" , "Weight" ,
                "Mileage" , "Min speed" , "Max speed");
            printf("|-----------------------------------------------------------------------------------------|\n");
            while(p != NULL){
                printf("|%3d |%12s |%11s |%5d |%5d |%11.3f |%8.3f |%9d |%9d|\n" , p->id ,p->data->name , p->data->company ,
                p->data->year, p->data->price , p->data->weight , 
                p->data->mileage, p->data->speed[0] , p->data->speed[1]);
                p = p->next;
            }
        }
    }
}

void fill_from_file(carHead *head , carNode *cur_node , carNode *node)
{
    if(head && cur_node && node){
        if(cur_node->next == NULL){
            cur_node->next = node;
            head->last = node;
        } else {
            node->next = cur_node->next;
            cur_node->next=node;
        }
        head->count++;
    }
}

void free_list(carHead *head)
{
    carNode *tmp , *p;
    
    if(head){
        p = head->first;
        while(p != NULL){
            tmp = p->next;
            free(p->data->name);
            free(p->data->company);
            free(p->data);
            free(p);
            p = tmp;
        }
        free(head);
        head = NULL;
    }
}
