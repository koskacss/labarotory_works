#pragma once

#include <stdio.h>
#include "declarations.h"
#include "list_func.h"

void read_file(FILE *fp, carHead *head); // Считывание и преобразование строк из файла в элементы списка
char **split(char **text , char *string , char *sep); // Разбиение строки на подстроки по разделителю
void clear_array(char **arr, int count); // Очистка памяти, выделенной под массив строк
carNode *arr_to_node(char **arr, int id); // Преобразование строки из в элемент списка