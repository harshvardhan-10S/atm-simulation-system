#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define MAX_USERS 5
#define ADMIN_PIN 9999

typedef struct {
    int acc_no;
    char name[50];
    int pin;
    float balance;
} User;

User users[MAX_USERS] = {
    {1002, "Harshvardhan Shinde", 2345, 3000.0},
    {1003, "Mrs. Kirti", 3456, 4500.0},
    {1004, "Mrs. Prajakta", 4567, 2000.0},
    
};

void beepSuccess() { Beep(800, 200); }
void beepError() { Beep(300, 400); }
void beepCardInserted() { Beep(600, 150); Sleep(100); Beep(650, 150); }
void setBlueBackground() { system("color 1F"); }
void delay(int seconds) { Sleep(seconds * 1000); }

void saveTransaction(int acc_no, const char *type, float amount);
void viewHistory(int acc_no);
void maskPIN(char* pinBuffer);

int verifyPIN(char* inputPIN) {
    int pinEntered = atoi(inputPIN);
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].pin == pinEntered) {
            beepSuccess();
            return i;
        }
    }
    beepError();
    return -1;
}

void maskPIN(char* pinBuffer) {
    char ch;
    int index = 0;
    while ((ch = _getch()) != 13 && index < 6) {
        if (ch >= '0' && ch <= '9') {
            pinBuffer[index++] = ch;
            printf("*");
        }
    }
    pinBuffer[index] = '\0';
    printf("\n");
}

void withdraw(User *user) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        printf("\nPlease collect your cash.\n");
        beepSuccess();
        saveTransaction(user->acc_no, "Withdraw", amount);
    } else {
        printf("\nInsufficient balance.\n");
        beepError();
    }
}

void deposit(User *user) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        user->balance += amount;
        printf("\nAmount deposited successfully.\n");
        beepSuccess();
        saveTransaction(user->acc_no, "Deposit", amount);
    } else {
        printf("\nInvalid amount.\n");
        beepError();
    }
}

void checkBalance(User *user) {
    printf("\nCurrent Balance: Rs. %.2f\n", user->balance);
}

void saveTransaction(int acc_no, const char *type, float amount) {
    FILE *fp;
    char filename[30];
    sprintf(filename, "history_%d.txt", acc_no);

    fp = fopen(filename, "a");
    if (fp == NULL) return;

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char date[30];
    strftime(date, 30, "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(fp, "%s - %s: Rs. %.2f\n", date, type, amount);
    fclose(fp);
}

void viewHistory(int acc_no) {
    FILE *fp;
    char filename[30];
    sprintf(filename, "history_%d.txt", acc_no);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nNo transaction history found.\n");
        return;
    }

    char line[100];
    printf("\nTransaction History:\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

void changePIN(User *user) {
    char oldPinBuffer[10], newPinBuffer[10];

    printf("Enter current PIN: ");
    maskPIN(oldPinBuffer);

    if (atoi(oldPinBuffer) == user->pin) {
        printf("Enter new 4-digit PIN: ");
        maskPIN(newPinBuffer);

        if (strlen(newPinBuffer) == 4) {
            user->pin = atoi(newPinBuffer);
            printf("PIN changed successfully.\n");
            beepSuccess();
        } else {
            printf("Invalid PIN format. Must be 4 digits.\n");
            beepError();
        }
    } else {
        printf("Incorrect current PIN.\n");
        beepError();
    }
}

void userMenu(int index) {
    int choice;
    do {
        printf("\n1. Withdraw\n2. Deposit\n3. Balance Enquiry\n4. Transaction History\n5. Change PIN\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: withdraw(&users[index]); break;
            case 2: deposit(&users[index]); break;
            case 3: checkBalance(&users[index]); break;
            case 4: viewHistory(users[index].acc_no); break;
            case 5: changePIN(&users[index]); break;
            case 6: printf("\nThank you for using ATM.\n"); break;
            default: printf("\nInvalid option.\n"); beepError(); break;
        }
    } while (choice != 6);
}

void adminMenu() {
    int choice;
    do {
        printf("\n--- Admin Panel ---\n");
        printf("1. View All Accounts\n2. Refill ATM Cash (Simulated)\n3. Exit Admin Panel\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (int i = 0; i < MAX_USERS; i++) {
                    printf("Acc No: %d | Name: %s | Balance: Rs. %.2f\n", users[i].acc_no, users[i].name, users[i].balance);
                }
                break;
            case 2:
                printf("\nATM cash refilled (simulated).\n");
                beepSuccess();
                break;
            case 3:
                printf("\nExiting Admin Panel.\n");
                break;
            default:
                printf("\nInvalid option.\n");
                beepError();
        }
    } while (choice != 3);
}

int main() {
    setBlueBackground();
    char pinBuffer[10];

    printf("\n=== Welcome to Smart ATM Simulator ===\n");
    beepCardInserted();
    printf("Insert Card... Done\n");

    printf("Enter 4-digit PIN: ");
    maskPIN(pinBuffer);

    int pin = atoi(pinBuffer);
    if (pin == ADMIN_PIN) {
        adminMenu();
    } else {
        int index = verifyPIN(pinBuffer);
        if (index != -1) {
            printf("\nWelcome, %s\n", users[index].name);
            userMenu(index);
        } else {
            printf("\nAccess Denied.\n");
        }
    }

    return 0;
}
