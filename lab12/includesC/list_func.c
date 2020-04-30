#include "../includesH/list_func.h"

void inc_id(carHead *head , carNode *cur_node)
{
    int i;
    for(i = cur_node->id; i < head->count; i++){
        cur_node->id++;
        cur_node = cur_node->next;
    }
}

void dec_id(carHead *head , carNode *cur_node)
{   
    int i;
    for(i = cur_node->id; i < head->count; i++){
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
        new_node->prev = NULL;
    }
    return new_node;
}

void insert_after(carHead *head , carNode *node, int id)
{
    carNode *tmp;
    
    tmp = head->first;

    if(id >= head->count) { // Если такого элемента в кольце нет,то добавляем звено в конец
        node->next = head->first;
        node->id = head->count;
        node->prev = head->last;
        head->last->next = node;
        head->last = node;
        head->first->prev = node;
    } else {
        while(tmp != NULL){
            if(tmp->id == id){
                if(tmp->next == tmp){ // Если в кольце одно звено
                    node->next = tmp;
                    node->prev = tmp;
                    tmp->prev = node;
                    head->last = node;
                    tmp->next = node;
                } else { // Если несколько звеньев в кольце
                    if(tmp->next == head->first){ // Если элемент является последним
                        node->id = head->count;
                        node->next = head->first;
                        head->first->prev = node;
                        tmp->next = node;
                        node->prev = tmp;
                        head->last = node;
                    } else { // Если элемент не последний
                        node->next = tmp->next;
                        tmp->next->prev = node;
                        node->prev = tmp;
                        node->id = tmp->next->id;
                        tmp->next = node;
                        inc_id(head , node->next);
                    }
                }
                tmp = NULL;
            } else tmp = tmp->next;
        }
    }

    CLS;
    head->count++;
    print_list(head);
}

void insert_before(carHead *head , carNode *node , int id)
{
    carNode *tmp;

    tmp = head->first;

    while(tmp != NULL){
        if(tmp->id == id){
            if(tmp->next == tmp){ // Если в кольце один элемент
                node->next = tmp;
                node->id = 0;
                node->prev = tmp;
                tmp->next = node;
                tmp->prev = node;
                tmp->id = 1;
            } else {
                if(tmp == head->first){ // Если вставляем элемент перед первым
                    node->id = 0;
                    node->prev = head->last;
                    node->next = tmp;
                    tmp->prev = node;
                    head->last->next = node;
                    head->first = node;
                    inc_id(head,head->first->next);
                } else{ // Если вставка не перед последним
                    node->id = tmp->id;
                    node->next = tmp;
                    node->prev = tmp->prev;
                    tmp->prev->next = node;
                    tmp->prev = node;
                    inc_id(head, node->next);
                }
            }

            tmp = NULL;
        } else tmp = tmp->next;
    }

    CLS;
    head->count++;
    print_list(head);   
}

void delete_elem(carHead *head , int id)
{
    carNode *tmp;
    
    tmp = head->first;

    while(tmp != NULL){
        if(tmp->id == id){
            if(tmp->next == tmp){ // Если происходит удаление единственного элемента в кольце
                free_del(tmp);
                head->first = NULL;
                head->last = NULL;
            } else{
                if(head->first == tmp){ // Если удаляется первый элемент в кольце
                    head->last->next = tmp->next;
                    tmp->next->prev = head->last;
                    dec_id(head , head->first);
                    head->first = tmp->next;
                    free_del(tmp);
                } else if (head->last == tmp){ // Если удаляется последний элемент в кольце
                    head->first->prev = head->last->prev;
                    head->last->prev->next = head->last->next;
                    head->last = head->last->prev;
                    free_del(tmp);
                } else { // Если удаляется не последний и не первый элемент
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;
                    dec_id(head, tmp->next);
                    free_del(tmp);
                }
            }
            tmp = NULL;
        } else tmp = tmp->next;
    }

    CLS;
    head->count--;
    print_list(head);
}

void push_front(carHead *head, carNode *node)
{
    node->id = 0;
    node->next = head->first;
    node->prev = head->last;
    head->last->next = node;
    head->first->prev = node;
    head->first = node;
    inc_id(head , head->first->next);
    CLS;
    head->count++;
    print_list(head);
}

void push_back(carHead *head , carNode *node)
{
    node->id = head->count;
    node->next = head->first;
    node->prev = head->last;
    head->last->next = node;
    head->first->prev = node;
    head->last = node;
    CLS;
    head->count++;
    print_list(head);
}

void init_list(carHead *head)
{
    carNode *node;

    if(head->count == 0){
        puts("\nFill new struct:\n");
        node = get_node();
        head->first = node;
        head->last = node;
        node->next = node;
        node->prev = node;
        node->id = 0;
        head->count++;
    } else {CLS; puts("The list is already initialised!");}
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
        head->first->prev = head->first;
        head->first->next = head->first;
    }
}

void print_list(carHead *head)
{
    int i;
    carNode *p;
    if(head->count == 0){
        puts("======================The list is empty!======================");
    } else {
        if((p = head->first) != NULL){
            puts("\nCurrent list:");
            printf("\n|-----------------------------------------------------------------------------------------|\n");
            printf("|%3s |%12s |%11s |%5s |%5s |%11s |%8s |%9s |%9s|\n" ,"Id", "Name" , "Company" , "Year" , "Price" , "Weight" ,
                "Mileage" , "Min speed" , "Max speed");
            printf("|-----------------------------------------------------------------------------------------|\n");
            for(i = 0; i < head->count; i++){
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
        cur_node->next = node;
        node->prev = cur_node;
        head->last = node;
        head->last->next = head->first;
        head->count++;
    }
}

void free_list(carHead *head)
{
    carNode *tmp , *p;
    int i;
    if(head){
        p = head->first;
       for(i = 0; i < head->count; i++){
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
