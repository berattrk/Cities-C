#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void clearTerminal(){
    #ifndef _WIN32
        system("cls");
    #else   
        system("cls");
    #endif
}

typedef struct CitiesNode CitiesNode;
typedef struct CitiesList CitiesList;

struct CitiesNode
{
    char name[25];
    char region[25];
    int plate;
    CitiesNode* prev;
    CitiesNode* next;

};

struct CitiesList
{
    CitiesNode* head;
    CitiesNode* tail;
};

int addCity(CitiesList* citiesList, char* cityName, char* regionName, int plate)
{
    CitiesNode *temp = (CitiesNode *) malloc(sizeof(CitiesNode));
    CitiesNode *current = (CitiesNode *) malloc(sizeof(CitiesNode));
    int check = 0;

    if(citiesList->head == NULL){
        strcpy(current->name,cityName);
        strcpy(current->region,regionName);
        current->plate = plate;
        citiesList->head = current;
        citiesList->tail = current;
        current->prev = NULL;
        current->next = NULL;
        return check;
    }
    else{
        current = citiesList->head;
        while(current != NULL){
            if(current->plate == plate){
                printf("There is already a city with this plate. Please check your inputs.\n");
                check++;
                break;
            }
            current = current->next;
        }
        if(check == 0) {
            current = citiesList->head;

            strcpy(temp->name, cityName);
            strcpy(temp->region, regionName);
            temp->plate = plate;

            /*Adding First index*/
            if(temp->plate < current->plate){
                current->prev = temp;
                temp->next = current;
                temp->prev = NULL;
                citiesList->head = temp;
            }else {
                while (current != NULL && current->plate < temp->plate) {
                    current = current->next;
                }
                if(current == NULL){
                    citiesList->tail->next = temp;
                    temp->next = NULL;
                    temp->prev = citiesList->tail;
                    citiesList->tail = temp;
                }else{
                    current->prev->next = temp;
                    temp->prev = current->prev;
                    temp->next = current;
                    current->prev = temp;
                }
            }
        }
        return check;
    }
}

CitiesNode* findCitybyPlate(CitiesList* citiesList, int plate)
{
    CitiesNode *current = citiesList->head;
    while(current != NULL){
        if(current->plate == plate){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

CitiesNode* findCitybyName(CitiesList* citiesList, char* cityName)
{
    CitiesNode *current = citiesList->head;
    while(current != NULL){
        if(strcmp(current->name, cityName) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void delCitybyPlate(CitiesList* citiesList, int plate)
{
    CitiesNode *current = findCitybyPlate(citiesList,plate);

    /*Deleting first element*/
    if(current == citiesList->head && current == citiesList->tail){
        citiesList->head = NULL;
        citiesList->tail = NULL;
        free(current);
    }
    else if(current == citiesList->head){
        citiesList->head = current->next;
        current->next->prev = NULL;
        free(current);
    }
    else if(current == citiesList->tail){
        citiesList->tail = current->prev;
        current->prev->next = NULL;
        free(current);
    }
    else if(current != NULL){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    else{
        printf("There isn't any city with this plate.");
        return;
    }
}

void delCitybyName(CitiesList* citiesList, char* cityName)
{
    CitiesNode *current = findCitybyName(citiesList,cityName);

    /*Deleting first element*/
    if(current == citiesList->head && current == citiesList->tail){
        citiesList->head = NULL;
        citiesList->tail = NULL;
        free(current);
    }
    else if(current == citiesList->head){
        citiesList->head = current->next;
        current->next->prev = NULL;
        free(current);
    }
    else if(current == citiesList->tail){
        citiesList->tail = current->prev;
        current->prev->next = NULL;
        free(current);
    }
    else if(current != NULL){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    else{
        printf("There isn't any city with this name.");
        return;
    }
}

void swap(CitiesNode* prev, CitiesNode* current){
    int tempPlate;
    char tempName[25];
    char tempRegion[25];

    tempPlate = prev->plate;
    strcpy(tempName, prev->name);
    strcpy(tempRegion, prev->region);

    prev->plate = current->plate;
    strcpy(prev->name,current->name);
    strcpy(prev->region, current->region);

    current->plate = tempPlate;
    strcpy(current->name,tempName);
    strcpy(current->region,tempRegion);
}

void sortbyPlate(CitiesList* citiesList){
    int swapped;
    CitiesNode *current;
    CitiesNode *head = citiesList->head;

    if(head == NULL){
        return;
    }
    do{
        swapped = 0;
        current = head;

        while(current->next != NULL){
            if(current->plate > current->next->plate){
                swap(current,current->next);
                swapped = 1;
            }
            current = current->next;
        }
    }while(swapped);
}

void sortbyName(CitiesList* citiesList){
    int swapped;
    CitiesNode *current;
    CitiesNode *head = citiesList->head;

    if(head == NULL){
        return;
    }
    do{
        swapped = 0;
        current = head;

        while(current->next != NULL){
            if(strcmp(current->next->name, current->name)<0){
                swap(current,current->next);
                swapped = 1;
            }
            current = current->next;
        }
    }while(swapped);
}

void sortbyRegion(CitiesList* citiesList){
    int swapped;
    CitiesNode *current;
    CitiesNode *head = citiesList->head;

    if(head == NULL){
        return;
    }
    do{
        swapped = 0;
        current = head;

        while(current->next != NULL){
            if(strcmp(current->next->region, current->region)<0){
                swap(current,current->next);
                swapped = 1;
            }
            current = current->next;
        }
    }while(swapped);
}

void updateCitybyPlate(CitiesList* citiesList, char* name, char* region, int plate){
    CitiesNode *current = findCitybyPlate(citiesList,plate);

    strcpy(current->name,name);
    strcpy(current->region,region);
}

void printingCities(CitiesList* citiesList){
    CitiesNode *current = citiesList->head;
    while(current != NULL){
        printf("City name: %-25s Region: %-25s Plate: %d\n",current->name,current->region,current->plate);
        current = current->next;
    }

}

void arrowHere(int realPos, int arrowPos){
    if(realPos == arrowPos){
        printf("\033[0;32m  ----->");
    }else{
        printf("\033[0;37m         ");
    }
}

int mainMenu(){
    clearTerminal();
    int pos = 1;
    int keyPressed = 0;

    #define MAINMAX 5
    #define MAINMIN 1

    while(keyPressed != 13) {
        clearTerminal();
        arrowHere(1, pos);  printf(" Add City \n");
        arrowHere(2, pos);  printf(" Find City by Name \n");
        arrowHere(3, pos);  printf(" Find City by Plate \n");
        arrowHere(4, pos);  printf(" List Cities \n");
        arrowHere(5, pos);  printf(" Exit \n");

        keyPressed = getch();

        if (keyPressed == 80 && pos != MAINMAX) {
            pos++;
        } else if (keyPressed == 72 && pos != MAINMIN) {
            pos--;
        } else {
            pos = pos;
        }
    }
    return pos;
}

int findMenubyName(char *name, char *region, int plate){
    clearTerminal();
    printf("----------------------\nCity Name: %s\nRegion: %s\nPlate:%d\n----------------------\n",name,region,plate);
    int pos = 1;
    int keyPressed = 0;

    #define FINDMAX 3
    #define FINDMIN 1

    while(keyPressed != 13) {
        clearTerminal();
        printf("----------------------\nCity Name: %s\nRegion: %s\nPlate:%d\n----------------------\n",name,region,plate);
        arrowHere(1, pos);  printf(" Update City \n");
        arrowHere(2, pos);  printf(" Delete City \n");
        arrowHere(3, pos);  printf(" Exit \n");

        keyPressed = getch();

        if (keyPressed == 80 && pos != FINDMAX) {
            pos++;
        } else if (keyPressed == 72 && pos != FINDMIN) {
            pos--;
        } else {
            pos = pos;
        }
    }
    return pos;
}

int findMenubyPlate(char *name, char *region, int plate){
    clearTerminal();
    printf("----------------------\nCity Name: %s\nRegion: %s\nPlate:%d\n----------------------\n",name,region,plate);
    int pos = 1;
    int keyPressed = 0;

    #define FINDMAX 3
    #define FINDMIN 1

    while(keyPressed != 13) {
        clearTerminal();
        printf("----------------------\nCity Name: %s\nRegion: %s\nPlate:%d\n----------------------\n",name,region,plate);
        arrowHere(1, pos);  printf(" Update City \n");
        arrowHere(2, pos);  printf(" Delete City \n");
        arrowHere(3, pos);  printf(" Exit \n");

        keyPressed = getch();

        if (keyPressed == 80 && pos != FINDMAX) {
            pos++;
        } else if (keyPressed == 72 && pos != FINDMIN) {
            pos--;
        } else {
            pos = pos;
        }
    }
    return pos;
}

int listMenu(CitiesList *citiesList){
    clearTerminal();
    printf("---------------------------------------------\n");
    printingCities(citiesList);
    printf("---------------------------------------------\n");
    int pos = 1;
    int keyPressed = 0;

    #define LISTMAX 4
    #define LISTMIN 1

    while(keyPressed != 13){
        clearTerminal();
        printf("---------------------------------------------\n");
        printingCities(citiesList);
        printf("---------------------------------------------\n");
        arrowHere(1, pos);  printf(" Sort by Name \n");
        arrowHere(2, pos);  printf(" Sort by Plate \n");
        arrowHere(3, pos);  printf(" Sort by Region \n");
        arrowHere(4, pos);  printf(" Exit \n");

        keyPressed = getch();

        if (keyPressed == 80 && pos != LISTMAX) {
            pos++;
        } else if (keyPressed == 72 && pos != LISTMIN) {
            pos--;
        } else {
            pos = pos;
        }
    }
    return pos;
}



int main()
{
    CitiesList *citiesList = (CitiesList *) malloc(sizeof(CitiesList));
    citiesList->head = NULL;
    citiesList->tail = NULL;
    CitiesNode *temp;
    char name[25];
    char region[25];
    char data[255], *token;
    int plate, check, tempPlate;
    FILE *fptr;
    fptr = fopen("cities.txt","a+");

    if(fptr != NULL){
        while (fgets(data,255,fptr)){
            token = strtok(data,",");
            strcpy(name,token);

            token = strtok(NULL,",");
            strcpy(region,token);

            token = strtok(NULL,",");
            tempPlate = atoi(token);
            plate = tempPlate;


            addCity(citiesList,name,region,plate);
        }
    }

    while(TRUE) {
        int selection = mainMenu();
        switch (selection) {
            case 1:
                printf("City Name: "); scanf("%24s",&name);
                printf("Region Name: "); scanf("%24s",&region);
                printf("Plate: "); scanf("%d",&plate);
                check = addCity(citiesList,name,region,plate);
                if(check == 0){
                    printf("City was added.\n");
                }
                printf("Press Enter to return main menu.");
                getch();
                break;
            case 2:
                printf("City Name: "); scanf("%24s",&name);
                temp = findCitybyName(citiesList,name);
                if(temp) {
                    int findSelectionbyName = findMenubyName(temp->name, temp->region, temp->plate);
                    switch (findSelectionbyName) {
                        case 1:
                            printf("City Name: ");   scanf("%24s", &name);
                            printf("Region Name: "); scanf("%24s", &region);
                            printf("Plate: ");       scanf("%d", &plate);
                            updateCitybyPlate(citiesList, name, region, plate);
                            clearTerminal();
                            printf("City was updated.\n");
                            printf("Press Enter to return main menu.");
                            getch();
                            break;
                        case 2:
                            delCitybyName(citiesList, name);
                            clearTerminal();
                            printf("City was deleted.\n");
                            printf("Press Enter to return main menu.");
                            getch();
                            break;
                        case 3:
                            printf("Returning to main menu...");
                            Sleep(1000);
                            break;
                    }
                }else{
                    printf("There isn't any city with this name.\n");
                    printf("Press Enter to return main menu.");
                    getch();
                }
                break;
            case 3:
                printf("Plate: "); scanf("%d",&plate);
                temp = findCitybyPlate(citiesList,plate);
                if(temp) {
                    int findSelectionbyPlate = findMenubyPlate(temp->name, temp->region, temp->plate);
                    switch (findSelectionbyPlate) {
                        case 1:
                            printf("City Name: ");   scanf("%24s", &name);
                            printf("Region Name: "); scanf("%24s", &region);
                            printf("Plate: ");       scanf("%d", &plate);
                            updateCitybyPlate(citiesList, name, region, plate);
                            clearTerminal();
                            printf("City was updated.\n");
                            printf("Press Enter to return main menu.");
                            getch();
                            break;
                        case 2:
                            delCitybyPlate(citiesList, plate);
                            printf("City was deleted.\n");
                            printf("Press Enter to return main menu.");
                            getch();
                            break;
                        case 3:
                            printf("Returning to main menu...");
                            Sleep(1000);
                            break;
                    }
                }else{
                    printf("There isn't any city with this plate.\n");
                    printf("Press Enter to return main menu.");
                    getch();
                }
                break;
            case 4:
                check = 1;
                while (check)
                {
                    int listSelection = listMenu(citiesList);
                    switch (listSelection)
                    {
                    case 1:
                        sortbyName(citiesList);
                        printf("Press Enter to update list.");
                        getch();
                        break;
                    case 2:
                        sortbyPlate(citiesList);
                        printf("Press Enter to update list.");
                        getch();
                        break;
                    case 3:
                        sortbyRegion(citiesList);
                        printf("Press Enter to update list.");
                        getch();
                        break;
                    case 4:
                        printf("Returning to main menu...");
                        Sleep(1000);
                        check = 0;
                        break;
                    }
                }
                sortbyPlate(citiesList);
                break;
            case 5:
                printf("Exiting from program...\n");
                printf("Cities are being saved...");
                fclose(fptr);
                fptr = fopen("cities.txt","w");
                temp = citiesList->head;
                while (temp != NULL)
                {
                    fprintf(fptr,"%s,%s,%d\n",temp->name,temp->region,temp->plate);
                    temp = temp->next;
                }           
                Sleep(1000);
                break;
        }
        if(selection == 5){
            break;
        }
    }
    fclose(fptr);
    return 0;
}

