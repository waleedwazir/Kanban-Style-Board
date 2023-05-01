#include "functions.h"
//This function prints the main menu
void menu(void){
    int col = 20;
    int row = 11;
    printf("\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(i == 1 && j == 8){
                printf("Menu");
                j += 2 - 1;
            }else if(i == 2 && j == 1) {
                printf("1. Display board");
                j += 8 - 1;
            }else if(i == 3 && j == 1){
                printf("2. Load board from a file ");
                j += 13 - 1;
            }else if(i == 4 && j == 1){
                printf("3. Edit list");
                j += 6 - 1;
            }else if(i == 5 && j == 1){
                printf("4. Edit board ");
                j += 7 - 1;
            }else if(i == 6 && j == 1){
                printf("5. Save board to a file ");
                j += 12 - 1;
            }else if(i == 7 && j == 1){
                printf("6. Quit ");
                j += 4 - 1;

            }else if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
                printf("* ");
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//This function prints an error message
void ERROR(void)
{
    printf("Please enter a valid number\n");
}

//This function prints the menu for Option 3
void MENU_OPTION3(void)
{
    int col = 20;
    int row = 9;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(i == 1 && j == 8){
                printf("Options:");
                j += 4 - 1;
            }else if(i == 2 && j == 1) {
                printf("1. Edit the name of an item ");
                j += 14 - 1;
            }else if(i == 3 && j == 1){
                printf("2. Add a new item ");
                j += 9 - 1;
            }else if(i == 4 && j == 1){
                printf("3. Delete an item ");
                j += 9 - 1;
            }else if(i == 5 && j == 1){
                printf("4. Return to main menu");
                j += 11 - 1;

            }else if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
                printf("* ");
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

//This function prints out the menu for Option 4
void MENU_OPTION4(void)
{
    int col = 20;
    int row = 9;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(i == 1 && j == 8){
                printf("Options:");
                j += 4 - 1;
            }else if(i == 2 && j == 1) {
                printf("1. Edit the name of a list");
                j += 13 - 1;
            }else if(i == 3 && j == 1){
                printf("2. Add a new list ");
                j += 9 - 1;
            }else if(i == 4 && j == 1){
                printf("3. Delete a list");
                j += 8 - 1;
            }else if(i == 5 && j == 1){
                printf("4. Return to main menu");
                j += 11 - 1;

            }else if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
                printf("* ");
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/*This function changes user input to a list name by adding a colon to the end. It takes in:
 * listName - the user inputted list name
 */
void LIST_NAME(char listName[MAX_STR_LEN])
{
    listName[strlen(listName) - 1] = ':';
}

/*This function ensures there are no repeated list or item names. It takes in:
 * head - the pointer to the start of the board
 * listName - the name of the list or the item
 * a - an integer that determines if the listName being checked is the name of a list(person) or item
 */
int UNIQUE_NAME(PersonPtr head, char listName[MAX_STR_LEN], int a)
{
    //no need to check if it is the first list created
    if(head == NULL)
    {

    }

    else{
        PersonPtr person = head;
        ItemPtr item = person -> firstItemPtr;

        //if the name is a list
        if(a == 1)
        {
            //looping through the board to check the user inputted name
            while ( person != NULL ) {
                if(strcmp(person -> name, listName) == 0)
                {
                    printf("This name has already been used\n");
                    return 1;
                }
                person = person -> personNextPtr;
            }
        }

            //if the name is an item
        else if(a == 2)
        {
            while ( item != NULL ) {
                if(strcmp(item -> name, listName) == 0)
                {
                    printf("This name has already been used\n");
                    return 1;
                }
                item = item -> itemNextPtr;
            }
        }
    }
}

/*
 * This function is equivalent to the main menu Option 4. It takes in:
 * The ptr to the start of the board
 */
void EDIT_BOARD(PersonPtr *head)
{
    MENU_OPTION4();

    int choice;
    printf("Enter your option:\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        //Cannot choose to edit list name if no lists
        if(*head == NULL)
        {
            printf("No lists yet\n");

        }

        else
        {
            char tempTaskName[MAX_STR_LEN];
            printf("Enter the name of the list to edit:\n");
            fflush(stdin);
            fgets(tempTaskName, MAX_STR_LEN, stdin);
            LIST_NAME(tempTaskName);

            PersonPtr newPtr = *head;

            //looping through board and comparing list names to user inputted list name
            while(newPtr != NULL)
            {
                if(strcmp(tempTaskName, newPtr -> name) == 0)
                {
                    printf("What would you like to rename the list to?\n");
                    fflush(stdin);
                    fgets(tempTaskName, MAX_STR_LEN, stdin);
                    //adding a colon to inputted name to turn it into a list name
                    LIST_NAME(tempTaskName);
                    //checking the name hasn't already been used
                    if(UNIQUE_NAME(*head, tempTaskName, 1) == 1)
                        break;

                    strcpy(newPtr -> name, tempTaskName);
                    break;
                }

                //error if user inputted non-existent list name
                if(newPtr -> personNextPtr == NULL && strcmp(tempTaskName, newPtr -> name) != 0)
                    printf("Name not found\n\n");

                //if the name inputted is not found in the current list ptr, the next ptr is checked
                newPtr = newPtr -> personNextPtr;

            }
        }
    }

    else if(choice == 2)
    {
        //new list
        char tempTaskName[MAX_STR_LEN];
        printf("Enter the name of the new list:\n");
        fflush(stdin);
        fgets(tempTaskName, MAX_STR_LEN, stdin);
        LIST_NAME(tempTaskName);

        if(UNIQUE_NAME(*head, tempTaskName, 1) == 1)
        {

        }

        else{

            //assigning memory for new list
            PersonPtr newPtr = malloc(sizeof(Person));

            //checking if there's enough memory available to create new list
            if(newPtr != NULL)
            {
                //inputting name into the list and initializing the first item to NULL
                strcpy(newPtr -> name, tempTaskName);
                newPtr -> firstItemPtr = NULL;

                //this new list will become the head of the list, so its next list is the old head
                newPtr -> personNextPtr = *head;
                newPtr -> personPrevPtr = NULL;

                if (*head != NULL)
                    (*head) -> personPrevPtr = newPtr; //old head points back to the new list

                *head = newPtr; //head points to the new list
            }

            else
                printf("No memory available\n");
        }
    }

    else if(choice == 3)
    {
        if(*head == NULL)
        {
            printf("No boards yet\n");
        }

        else
        {
            char tempTaskName[MAX_STR_LEN];
            printf("Enter the name of the list you want to delete:\n");
            fflush(stdin);
            fgets(tempTaskName, MAX_STR_LEN, stdin);
            LIST_NAME(tempTaskName);

            PersonPtr currentPtr = *head;

            //looping through board to find correct list
            while(currentPtr != NULL)
            {
                //new ptr created to make it easier to keep track of the list to be deleted
                PersonPtr newPtr = currentPtr;

                if(strcmp(tempTaskName, currentPtr -> name) == 0)
                {
                    //if the list to be deleted is in the middle of the board
                    if(currentPtr != *head && currentPtr -> personNextPtr != NULL)
                    {
                        //the next list ptr after the list to be deleted now has a prev ptr of the LTBD's prev ptr
                        currentPtr = newPtr -> personNextPtr;
                        currentPtr -> personPrevPtr = newPtr -> personPrevPtr;
                        //the list before the LTBD now has a next ptr of the list after the LTBD
                        currentPtr = newPtr -> personPrevPtr;
                        currentPtr -> personNextPtr = newPtr -> personNextPtr;
                    }

                        //if the list to be deleted is at the end of the list
                    else if(currentPtr != *head && (currentPtr -> personNextPtr == NULL))
                    {
                        currentPtr -> personPrevPtr -> personNextPtr = NULL;
                    }

                        //if there is only one list in the board
                    else
                        *head = NULL;

                    free(newPtr);
                    break;
                }

                if(currentPtr -> personNextPtr == NULL && strcmp(tempTaskName, currentPtr -> name) != 0)
                    printf("Name not found\n\n");

                currentPtr = currentPtr -> personNextPtr;
            }
        }
    }

    else if(choice == 4)
    {
        //return to main menu
    }

    else
        ERROR();
}



/*
* This function is used for option 2: Loading board from file
* It asks the user for input of file name and then opens it up and displays the data
*/
void load_board(){

    char filename[100]; //string to store filename
    char line[100]; // string used to store lines from the file

    //asking using for input
    printf("Enter filename: \n");
    //stores input to filename
    scanf("%s", &filename);

    // creating a file pointer and opening file using fopen function
    //using r mode so it will be read only
    FILE* file = fopen(filename, "r");

    //error checking if file doesnt exist it will throw error
    if(file == NULL){
        printf("Error: could not open file : %s", filename);
    }

    // read and print each line of the file
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
    }

    fclose(file); // close the file
}

/*
 * save_to_file function is used to save a board/data to a file of the users choice
 * it takes a parameter called PersonPtr head which is a pointer to start of the board
 */
void save_to_file(PersonPtr head)
{

    char filename[100]; //used to store

    //ask user to choose the name of the file to save the board to.
    //if the file does not exist it will create one
    printf("Enter a file name to create and save data to file: \n");
    scanf("%s", &filename); //saves input from user to filename

    //opens file/creates file of users choice
    /* we using the mode "w+" which allows us to write to the file.
     * W+ also wipes the file clean everytime we reopen it which allows us to overwrite the file
     * w+ also creates a file if it doesnt already exist
    */

    //creating a file pointer and opening the file using fopen function
    FILE* file = fopen(filename, "w+");

    //creating new pointer and setting head as its value which is another pointer
    PersonPtr personPtr = head;
    while (personPtr != NULL) {
        //keep looping and printing to file until next pointer is null
        fprintf(file,  "%s\n", personPtr->name);

        // Print out information for each item associated with the person
        ItemPtr itemPtr = personPtr->firstItemPtr;
        //keep looping and printing to file until next pointer is null
        while (itemPtr != NULL) {
            fprintf(file, "\t%s\n", itemPtr->name);
            itemPtr = itemPtr->itemNextPtr;
            itemPtr = itemPtr->itemNextPtr; //pointer to next pointer in itemPtr
        }

        //points to the next pointer inside the board
        personPtr = personPtr->personNextPtr;
    }

    //closes file
    fclose(file);

    printf("Board has been saved to a file called: %s\n", filename);
}

/*
 * print_board function displays the board on the system.
 * it takes in a parameter called PersonPtr head which is the pointer to the start of the board
 */
void print_board(PersonPtr head)
{
    //creating new pointer and setting the value to head which is another pointer
    PersonPtr personPtr = head;
    //keep looping and printing out each value in the board until next pointer is null
    while (personPtr != NULL) {
        printf("%s\n", personPtr->name);

        // Print out information for each item associated with the person
        ItemPtr itemPtr = personPtr->firstItemPtr;
        while (itemPtr != NULL) {
            printf("\t%s\n", itemPtr->name);
            itemPtr = itemPtr->itemNextPtr;
            itemPtr = itemPtr->itemNextPtr; //pointer to next pointer in itemPtr
        }

        personPtr = personPtr->personNextPtr;
        personPtr = personPtr->personNextPtr; //pointer to next pointer in personPtr
    }
}

/*
 * This function is equivalent to the main menu Option 3 to edit a list. It takes in:
 * head - the ptr to the start of the board
 */
void EDIT_LIST(PersonPtr *head)
{
    if(*head == NULL)
    {
        printf("No boards yet\n");

    }

    else
    {
        char tempTaskName[MAX_STR_LEN];
        printf("Enter the name of the list to edit:\n");
        fflush(stdin);
        fgets(tempTaskName, MAX_STR_LEN, stdin);
        LIST_NAME(tempTaskName);

        PersonPtr PnewPtr = *head;

        //looping through the board to find the list to edit
        while(PnewPtr != NULL)
        {
            if(strcmp(tempTaskName, PnewPtr -> name) == 0)
            {
                int choice;
                MENU_OPTION3();
                printf("Enter your option\n");
                fflush(stdin);
                scanf("%d", &choice);

                if (choice == 1)
                {
                    if(PnewPtr -> firstItemPtr == NULL)
                    {
                        printf("No items to edit\n");
                    }

                    else{
                        char tempTaskName[MAX_STR_LEN];
                        printf("Enter the name of the item to edit:\n");
                        fflush(stdin);
                        fgets(tempTaskName, MAX_STR_LEN, stdin);
                        tempTaskName[strlen(tempTaskName) - 1] = '\0';

                        ItemPtr newPtr = PnewPtr->firstItemPtr;

                        //looping through to find the item to edit
                        while(newPtr != NULL)
                        {
                            if(strcmp(tempTaskName, newPtr -> name) == 0)
                            {
                                printf("What would you like to rename the item to?\n");
                                fflush(stdin);
                                fgets(tempTaskName, MAX_STR_LEN, stdin);
                                tempTaskName[strlen(tempTaskName) - 1] = '\0';

                                if(UNIQUE_NAME(*head, tempTaskName, 2) == 1)
                                {
                                    break;
                                }

                                strcpy(newPtr -> name, tempTaskName);
                                break;
                            }

                            if(newPtr -> itemNextPtr == NULL && strcmp(tempTaskName, newPtr -> name) != 0)
                                printf("Name not found\n\n");

                            newPtr = newPtr -> itemNextPtr;

                        }
                    }
                }

                else if(choice == 2)
                {

                    char tempTaskName[MAX_STR_LEN];
                    printf("Enter the name of the new item:\n");
                    fflush(stdin);
                    fgets(tempTaskName, MAX_STR_LEN, stdin);
                    tempTaskName[strlen(tempTaskName) - 1] = '\0';

                    if(UNIQUE_NAME(*head, tempTaskName, 2) == 1)
                    {

                    }

                    else{

                        ItemPtr newItem = malloc(sizeof(Item));

                        if(newItem != NULL)
                        {
                            strcpy(newItem -> name, tempTaskName);
                            newItem -> itemNextPtr = NULL;
                            newItem -> itemPrevPtr = NULL;

                            if (PnewPtr->firstItemPtr != NULL)
                            {   //linking items
                                PnewPtr->firstItemPtr ->itemPrevPtr = newItem;
                                newItem -> itemNextPtr = PnewPtr -> firstItemPtr;

                            }

                            PnewPtr -> firstItemPtr = newItem;
                        }

                        else
                            printf("No memory available\n");

                    }

                }

                else if(choice == 3)
                {
                    if(PnewPtr -> firstItemPtr == NULL)
                    {
                        printf("No items to edit\n");
                    }

                    else{
                        char tempTaskName[MAX_STR_LEN];
                        printf("Enter the name of the item you want to delete:\n");
                        fflush(stdin);
                        fgets(tempTaskName, MAX_STR_LEN, stdin);
                        tempTaskName[strlen(tempTaskName) - 1] = '\0';

                        ItemPtr currentPtr = PnewPtr->firstItemPtr;

                        while(currentPtr != NULL)
                        {
                            ItemPtr newPtr = currentPtr;

                            if(strcmp( tempTaskName, currentPtr -> name) == 0)
                            {   //if item is in middle of list, link the items before and after the item to be deleted
                                if(currentPtr != PnewPtr ->firstItemPtr && currentPtr -> itemNextPtr != NULL)
                                {
                                    currentPtr = newPtr -> itemNextPtr;
                                    currentPtr -> itemPrevPtr = newPtr -> itemPrevPtr;
                                    currentPtr = newPtr -> itemPrevPtr;
                                    currentPtr -> itemNextPtr = newPtr -> itemNextPtr;
                                }
                                    //if the item is at the end of the list
                                else if(currentPtr != PnewPtr->firstItemPtr && (currentPtr -> itemNextPtr == NULL))
                                    currentPtr -> itemPrevPtr-> itemNextPtr = NULL;

                                else if(currentPtr == PnewPtr->firstItemPtr && (currentPtr -> itemNextPtr != NULL))
                                {   //if the item is the first with an item after it
                                    currentPtr = newPtr -> itemNextPtr;
                                    currentPtr -> itemPrevPtr = NULL;
                                    PnewPtr ->firstItemPtr = currentPtr;
                                }

                                else
                                    PnewPtr->firstItemPtr = NULL;

                                free(newPtr);
                                break;
                            }

                            if(currentPtr -> itemNextPtr == NULL && strcmp(tempTaskName, currentPtr -> name) != 0)
                                printf("Name not found\n\n");

                            currentPtr = currentPtr -> itemNextPtr;

                        }
                    }
                }

                else if(choice == 4)
                {

                }

                else
                    ERROR();

                break;
            }

            if(PnewPtr -> personNextPtr == NULL && strcmp(tempTaskName, PnewPtr -> name) != 0)
                printf("List not found\n\n");

            PnewPtr = PnewPtr -> personNextPtr;
        }
    }
}

void defaultBoard(PersonPtr *head){


    PersonPtr list1 = malloc(sizeof(Person));
    strcpy(list1->name, "Abey: ");
    list1->personNextPtr = NULL;

    ItemPtr item1_1 = malloc(sizeof(Item));
    strcpy(item1_1->name, "Oculus Pro");
    ItemPtr item1_2 = malloc(sizeof(Item));
    strcpy(item1_2->name, "Oculus Quest 1");

    item1_2->itemNextPtr = NULL;
    list1->firstItemPtr = item1_1;
    item1_1->itemNextPtr = item1_2;

    PersonPtr list2 = malloc(sizeof(Person));
    strcpy(list2->name, "Dante:");

    list2->personNextPtr = list1;
    ItemPtr item2_1 = malloc(sizeof(Item));
    strcpy(item2_1->name, "Oculus Quest 1");
    item2_1->itemNextPtr = NULL;

    ItemPtr item2_2 = malloc(sizeof(Item));
    strcpy(item2_2->name, "3070 RTX");

    item2_2->itemNextPtr = NULL;
    list2->firstItemPtr = item2_1;
    item2_1->itemNextPtr = item2_2;

    PersonPtr list3 = malloc(sizeof(Person));
    strcpy(list3->name, "Tim:");
    list3->personNextPtr = list2;
    ItemPtr item3_1 = malloc(sizeof(Item));
    strcpy(item3_1->name, "Oculus Quest 2");
    list3->firstItemPtr = item3_1;
    item3_1->itemNextPtr = NULL;
    PersonPtr list4 = malloc(sizeof(Person));
    strcpy(list4->name, "Nick:");
    ItemPtr item4_1 = malloc(sizeof(Item));
    strcpy(item4_1->name, "3070 RTX");

    item4_1->itemNextPtr = NULL;
    list4->firstItemPtr = item4_1;
    list4->personNextPtr = list3;
    list1->personPrevPtr = list2;
    list2->personPrevPtr = list3;
    list3->personPrevPtr = list4;
    list4->personPrevPtr = NULL;

    *head = list4;
}

void ASCII(void)
{
    printf("                   .     _,\n");
    printf("                   |`\\__/ /\n");
    printf("                   \\  . .(\n");
    printf("                    | __T|\n");
    printf("                   /   |\n");
    printf("      _.---=======`    |\n");
    printf("     //               {}\n");
    printf("    `|      ,   ,     {}\n");
    printf("     \\      /___;    ,'\n");
    printf("      ) ,-;`    `\\  //\n");
    printf("     | / (        ;||\n");
    printf("     ||`\\\\        |||\n");
    printf("     ||  \\\\       |||\n");
    printf("     )\\   )\\      )||\n");
    printf("     `\"   `\"      `\"\"\n");
}
