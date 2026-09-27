#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define DATA_FILE "users.txt"

void registerUser();
void loginUser();
void viewUsers();

int main() {
    int choice;

    while (1) {
        printf("\n====== USER MANAGEMENT SYSTEM ======\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. View Users\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: viewUsers(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void registerUser() {
    char username[MAX_LEN], password[MAX_LEN];
    FILE *fp;

    printf("\n=== Register User ===\n");
    printf("Enter username: ");
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline

    printf("Enter password: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';

    fp = fopen(DATA_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf("User registered successfully!\n");
}

void loginUser() {
    char username[MAX_LEN], password[MAX_LEN];
    char fileUser[MAX_LEN], filePass[MAX_LEN];
    FILE *fp;
    int found = 0;

    printf("\n=== Login ===\n");
    printf("Enter username: ");
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';

    fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        printf("No users found. Please register first.\n");
        return;
    }

    while (fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found)
        printf("✅ Login successful! Welcome, %s\n", username);
    else
        printf("❌ Invalid username or password.\n");
}

void viewUsers() {
    char fileUser[MAX_LEN], filePass[MAX_LEN];
    FILE *fp = fopen(DATA_FILE, "r");

    printf("\n=== Registered Users ===\n");
    if (fp == NULL) {
        printf("No users registered yet.\n");
        return;
    }

    while (fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
        printf("User: %s | Password: %s\n", fileUser, filePass);
    }
    fclose(fp);
}
