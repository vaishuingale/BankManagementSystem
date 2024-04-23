#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for different account types
#define SAVINGS 1
#define CURRENT 2

// Define structures
typedef struct {
    int account_number;
    char holder_name[100];
    int account_type;
    float balance;
} Account;

// Function prototypes
void createAccount(Account accounts[], int *num_accounts);
void deposit(Account accounts[], int num_accounts);
void withdraw(Account accounts[], int num_accounts);
void checkBalance(Account accounts[], int num_accounts);
void calculateInterest(Account accounts[], int num_accounts);

int main() {
    Account accounts[100]; // Array to store accounts
    int num_accounts = 0;
    int choice;

    do {
        // Display menu
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                checkBalance(accounts, num_accounts);
                break;
            case 5:
                calculateInterest(accounts, num_accounts);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 6);

    return 0;
}

void createAccount(Account accounts[], int *num_accounts) {
    Account new_account;
    
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter account holder name: ");
    scanf(" %s", &new_account.holder_name);
    printf("Enter account type (1 for Savings, 2 for Current): ");
    scanf("%d", &new_account.account_type);
    new_account.balance = 100;

    accounts[*num_accounts] = new_account;
    (*num_accounts)++;

    printf("Account created successfully.\n");
}

void deposit(Account accounts[], int num_accounts) {
    int acc_num;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(Account accounts[], int num_accounts) {
    int acc_num;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. Current balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}

void checkBalance(Account accounts[], int num_accounts) {
    int acc_num;

    printf("Enter account number: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            printf("Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void calculateInterest(Account accounts[], int num_accounts) {
    int acc_num;
    float interest_rate;

    printf("Enter account number: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == acc_num) {
            if (accounts[i].account_type == SAVINGS) {
                interest_rate = 0.05; // Example interest rate for savings account (5%)
            } else if (accounts[i].account_type == CURRENT) {
                interest_rate = 0.02; // Example interest rate for current account (2%)
            } else {
                printf("Invalid account type.\n");
                return;
            }

            float interest = accounts[i].balance * interest_rate;
            printf("Interest calculated: %.2f\n", interest);
            return;
        }
    }

    printf("Account not found.\n");
}
