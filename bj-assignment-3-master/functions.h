//
// Created by Walee on 30/03/2023.
//
#define MAX_STR_LEN 80
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
    int ID;
    char name[MAX_STR_LEN];
    struct Person *personNextPtr;
    struct Person *personPrevPtr;
    struct Item *firstItemPtr;
} Person, *PersonPtr;

typedef struct Item{
    char name[MAX_STR_LEN];
    struct Item *itemNextPtr;
    struct Item *itemPrevPtr;
    int ID[2]; //ID[0] = list id, ID[1] = item id
} Item, *ItemPtr;

void EDIT_BOARD(PersonPtr *head);
void ERROR(void);
void MENU_OPTION4(void);
void LIST_NAME(char listName[MAX_STR_LEN]);
int UNIQUE_NAME(PersonPtr head, char currentPtr[MAX_STR_LEN], int a);
void MENU_OPTION3(void);
void EDIT_LIST(PersonPtr *head);
void ASCII(void);
void menu(void);
void save_to_file(PersonPtr head);
void print_board(PersonPtr head);
void defaultBoard(PersonPtr *head);
void load_board();
