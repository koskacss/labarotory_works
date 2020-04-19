#pragma once

#include "declarations.h"

carNode *get_node(); // Считывание элемента списка с клавиатуры
carHead *init_head(); // Инициализация головы списка
void inc_id(carHead *head , carNode *cur_node); // Увеличение id элементов в списке на 1
void dec_id(carHead *head , carNode *cur_node); // Уменьшение id элементов в списке на 1
void add_first(carHead *head , carNode *node); // Добавление первого элемента в список
void insert_after(carHead *head); // Вставка элемента перед элементом с введенным id
void insert_before(carHead *head); // Вставка элемента после элемента с введенным id
void delete_elem(carHead *head); // Удаление элемента из списка
void free_del(carNode *tmp); // Вспомогательная функция для очитски памяти, использующаяся в функции delete_elem
void insert_before_last(carHead *head); // Добавление элемента перед последним или в начало, если список пустой
void init_list(carHead *head); // Функция для инициализации списка, когда считанный файл оказался пустым
void fill_from_file(carHead *head , carNode *cur_node , carNode *node); // Добавление элементов из файла в список
void print_list(carHead *ph); // Печать списка на экран
void free_list(carHead *head); // Освобождение памяти, выделенной под список