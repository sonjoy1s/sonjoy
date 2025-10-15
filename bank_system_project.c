
#include <stdio.h>
#include <string.h>

// Structure for Account (Base class)
struct Account {
    char name[50];
    int account_no;
    double balance;
};

// Function prototypes
void createAccount(struct Account *acc, char *name, int account_no, double balance);
double getBalance(struct Account *acc);
void deposit(struct Account *acc, double money);
void withdraw(struct Account *acc, double amount);

// Derived Structure for Saving Account
struct SavingAccount {
    struct Account base;
    double interest_rate;
};

// Derived Structure for Current Account
struct CurrentAccount {
    struct Account base;
    double overlimit;
};

// ATM function (similar to abstract class implementation)
void transaction() {
    printf("ATM Transaction: Cash Withdraw or Balance Check\n");
}

// Account functions
void createAccount(struct Account *acc, char *name, int account_no, double balance) {
    strcpy(acc->name, name);
    acc->account_no = account_no;
    acc->balance = balance;
}

double getBalance(struct Account *acc) {
    return acc->balance;
}

void deposit(struct Account *acc, double money) {
    acc->balance += money;
    printf("%.2lf is added, New Balance: %.2lf\n", money, acc->balance);
}

void withdraw(struct Account *acc, double amount) {
    if (amount > acc->balance) {
        printf("Insufficient Balance!\n");
    } else {
        acc->balance -= amount;
        printf("%.2lf is withdrawn, New Balance: %.2lf\n", amount, acc->balance);
    }
}

// Saving Account interest calculation
void calculateInterest(struct SavingAccount *sAcc) {
    double interest = sAcc->base.balance * sAcc->interest_rate / 100.0;
    printf("Interest: %.2lf\n", interest);
}

// Withdraw for Current Account (override)
void currentWithdraw(struct CurrentAccount *cAcc, double amount) {
    if (amount > cAcc->base.balance + cAcc->overlimit) {
        printf("Insufficient Balance!\n");
    } else {
        double newBalance = cAcc->base.balance - amount;
        printf("%.2lf is withdrawn, New Balance: %.2lf\n", amount, newBalance);
    }
}

// Main Program
int main() {
    struct SavingAccount sAcc;
    createAccount(&sAcc.base, "Takib", 133, 100.0);
    sAcc.interest_rate = 2.0;

    printf("Saving Account Holder: %s\n", sAcc.base.name);
    printf("Balance: %.2lf\n", getBalance(&sAcc.base));
    calculateInterest(&sAcc);

    struct CurrentAccount cAcc;
    createAccount(&cAcc.base, "Rakib", 123, 1000.0);
    cAcc.overlimit = 5000.0;

    printf("\nCurrent Account Holder: %s\n", cAcc.base.name);
    printf("Balance: %.2lf\n", getBalance(&cAcc.base));
    currentWithdraw(&cAcc, 3000);

    printf("\n--- ATM Section ---\n");
    transaction();

    return 0;
}
