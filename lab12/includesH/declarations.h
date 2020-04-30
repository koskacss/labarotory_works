#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 512

#ifdef linux
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

typedef struct carlHead carHead;
typedef struct carlNode carNode;
typedef struct carStruct car;

struct carStruct // Описание структуры из лаб работы 9
{
    char *name;
    char *company;
    int year;
    int price;
    float weight;
    float mileage;
    int speed[1];
};

struct carlNode{ // Описание структуры элемента списка
    int id; // Id элемента
    car *data; // Данные элемента
    carNode *next; // Указатель на следующий элемент списка
    carNode *prev; // Указатель на предыдущий элемент списка
};

struct carlHead // Описание структуры головы списка
{
    int count; // Количество элементов в списке
    carNode *first; // Указатель на первый элемент в списке
    carNode *last; // Указатель на последний элемент в списке
};