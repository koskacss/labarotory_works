#include "includesH/declarations.h"
#include "includesH/struct_func.h"
#include "includesH/list_func.h"
#include "includesH/menu.h"

int main()
{
    FILE *fp;
    carHead *ph;
    if((fp = fopen("data.csv", "r")) != NULL){
        ph = init_head();
        read_file(fp , ph);
        print_list(ph);
        menu(ph);
        free_list(ph);
        fclose(fp);
    } else {
        puts("There was an error while opening file!");
    }

    return 0;
}

