//
// Created by Walee on 30/03/2023.
//
#include "functions.h"

int main(){

    PersonPtr head = NULL;
    int choice;

    defaultBoard(&head);
    beginning:
    menu();
    printf("Enter your choice (1-6): \n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        //display board
        print_board(head);

    }

    else if(choice == 2)
    {
        //load board
        load_board();
    }

    else if(choice == 3)
    {
        //edit list
        EDIT_LIST(&head);
    }

    else if(choice == 4)
    {
        //edit board
        EDIT_BOARD(&head);

    }

    else if(choice == 5)
    {
        //save board
        save_to_file(head);
    }

    else if(choice == 6)
    {
        ASCII();
        printf("Thank you :)\n");
        return 0;
    }

    else
        ERROR();

    goto beginning;

}
