//
// Created by Tahaa on 01/08/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

// function to create a note
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
    scanf("%s", &data);

    fgets(data, DATA_SIZE, stdin);
    fputs(data, fPtr);
    fclose(fPtr);

    printf("File created and saved!");

    return 0;
}

// function to edit a note
int edit_note() {
    char data[DATA_SIZE];
    char filename[20];
    FILE *fPtr;

    printf("Enter File Name : ");
    scanf("%s", &filename);

    fPtr = fopen(filename, "w");

    if (fPtr == NULL) {
        printf("Something Went Wrong");
        exit(EXIT_FAILURE);
    }

    printf("Enter Data To Write : ");
    scanf("%s", &data);

    fgets(data, DATA_SIZE, stdin);
    fputs(data, fPtr);
    fclose(fPtr);

    printf("File Edited");

    return 0;
}

// function to delete note
int delete_note() {
    char filename[20];
    char command[] = "rm -rf ";

    printf("Enter File Name : ");
    scanf("%s", &filename);

    system(strcat(command, filename));

    return 0;
}

// function to spawn a shell
int shell() {
    char command[100];

    printf("[1] HELP\n[2] id\n[3] whoami\n[4] hostname\n[5] exit\n[$] ");
    scanf("%s", command);

    if (strcmp(command, "whoami") == 0) {
        system(command);
    } else if (strcmp(command, "id") == 0) {
        system(command);
    } else if (strcmp(command, "hostname") == 0) {
        system(command);
    } else if (strcmp(command, "exit") == 0) {
        exit(EXIT_SUCCESS);
    } else if (strcmp(command, "ls") == 0) {
        exit(EXIT_FAILURE);
    } else {
        if (strlen(command) > 10) {
            printf("This isn't a normal execution");
        } else {
            system(command);
        }
    }
}

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