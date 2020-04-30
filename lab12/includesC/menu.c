#include "../includesH/menu.h"

void menu(carHead *head)
{
    carNode *node;
    short choice = 1 , id;
    while(choice != 0){
        puts("\nMake your choice():");
        puts("\n1 - Insert before\n2 - Insert after\n3 - Delete element\n4 - Push front\n5 - Push back \n6 - Initialise list \n0 - Exit");
        scanf("%hi" , &choice);
        if((choice >= 0) && (choice <= 5)){
            if(head->count > 0){
                if(choice == 1){
                    node = get_node();
                    puts("\nEnter the element`s id:");
                    scanf("%hi" , &id); 
                    if((id <= head->count - 1) && (id >= 0)){
                        insert_before(head , node , id);
                    } else {CLS; puts("There is no element with this id!"); print_list(head);}
                }
                else if(choice == 2){
                    node = get_node();
                    puts("\nEnter the element`s id:");
                    scanf("%hi" , &id); 
                    insert_after(head , node , id);
                } else if(choice == 3){
                    puts("\nEnter the element`s id:");
                    scanf("%hi" , &id); 
                    if((id <= head->count - 1) && (id >= 0)){
                        delete_elem(head,id);
                    } else {CLS; puts("There is no element with this id!"); print_list(head);}
                } else if(choice == 4){
                    node = get_node();
                    push_front(head, node);
                } else if(choice == 5) {
                    node = get_node();
                    push_back(head , node);
                }
            } else {CLS; puts("Fill the list first!");}
        } else if(choice == 6) {
            init_list(head);
        } else {
            CLS;
            print_list(head);
            puts("\n==============Error!==============\n");
        }
    }
}