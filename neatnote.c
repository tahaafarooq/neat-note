//
// Created by Tahaa on 01/08/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

int create_note() {
    char data[DATA_SIZE];
    char filename[20];
    FILE *fPtr;

    printf("Enter File Name : ");
    scanf("%s", &filename);

    fPtr = fopen(filename, "w");

    if (fPtr == NULL) {
        printf("Unable to create file\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter Data To Write : \n");

    fgets(data, DATA_SIZE, stdin);
    fputs(data, fPtr);
    fclose(fPtr);

    printf("File created and saved!");

    return 0;
}

void edit_note();
void delete_note();
void shell();

int main() {
    char username[10];
    char password[10];
    int choice;

    printf("Enter Username : ");
    scanf("%s", &username); // takes username
    printf("Enter Password : ");
    scanf("%s", &password); // takes password

    int uname_verify = strcmp(username, "admin");
    int pword_verify = strcmp(password, "password");

    if (uname_verify == 0 && pword_verify == 0) {
        printf("Select Your Option\n[1] Create Note\n[2] Edit Note\n[3] Delete Note\n[4] NeatShell\n[5] Exit\n[>] ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_note();
                break;
            case 2:
                edit_note();
                break;
            case 3:
                delete_note();
                break;
            case 4:
                shell();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Option");
                break;
        }
    }

    return 0;
}