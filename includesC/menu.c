#include "../includesH/menu.h"

void menu(carHead *head)
{
    void(*actions[5]) (carHead *head) = {insert_before, insert_after , delete_elem, insert_before_last , init_list};
    short choice = 1;
    while(choice != 0){
        puts("\nMake your choice():");
        puts("\n1 - Insert before\n2 - Insert after\n3 - Delete element\n4 - Insert before the last\n5 - Initialise list\n0 - Exit");
        scanf("%hi" , &choice);
        if((choice >= 1) && (choice <= 5)){
            actions[choice - 1](head);
        } else {
            CLS;
            print_list(head);
            puts("\n==============Error!==============\n");
        }
    }
}