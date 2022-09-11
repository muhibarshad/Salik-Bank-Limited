#include <string>
#include <cmath>
#include<iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

using namespace std;

#define interestRate 1.5
#define minmumBalanceForInterest 200

// Supporting-Functions
void spaces1()
{
    for (int i = 0; i < 4; i++)
        cout << endl;
    cout << "\t\t\t\t\t SALIK BANK LIMITED (SBL) " << endl;
}
void spaces2()
{
    for (int i = 0; i < 2; i++)
        cout << endl;
}

/* ========================================================
**********************ACCOUNT_CLASS***********************
========================================================*/ 

class account
{
private:
    string name;
    string userName;
    int size;
    int pin;
    double *movements;
    double totalBalance;
    double income;
    double outcome;
    double interest;
    bool sort;
public:
    //CONSTRUCTORS
    account(string, string, int, int, double, double, double, double, bool, double *);
    account(const account &);

    //SETTERS
    void setName(string);
    void setUserName(string);
    void setPin(int);
    void setSize(int);
    void setTotalBalance(double);
    void setIncome(double);
    void setOutcome(double);
    void setInterest(double);
    void setSort(bool);
    void setMovementsAddress(double *);
    void setMovementsValue();
    void setData(string, string, int, int, double *, double, double, double, double, bool);

    //GETTERS
    string getName();
    string getUserName();
    int getPin();
    int getSize();
    double getTotalBalance();
    double getIncome();
    double getOutcome();
    double getInterest();
    bool getSort();
    double *getMovementsAddress();
    void getMovementsValue();
    void getData();

    //FUNCTIONALITY-FUNCTIONS
    void createAccount();
    void calculateUserName();
    double calculateTotalBalance();
    double calculateTotalIncome();
    double calculateTotalOutcome();
    double calculateTotalInterest();
    void sortMovements();

    //DESTRUCTOR
    ~account();
};

/* ==============================================================================================
*******************************CLASS_MEMBER_FUNCTIONS_BODY***************************************
================================================================================================*/

/* ========================================================
************************CONSTRUCTORS**********************
========================================================*/ 

// OVERLOADED_CONSTRUCTOR(sum of default and parameterized)
account::account(string name = "", string userName = "", int pin = 0, int size = 0, double totalBalance = 0.0, double income = 0.0, double outcome = 0.0, double interest = 0.0, bool sort = false, double *movements = nullptr)
{
    setName(name);
    setUserName(userName);
    setPin(pin);
    setSize(size);
    setTotalBalance(totalBalance);
    setIncome(income);
    setOutcome(outcome);
    setInterest(interest);
    setSort(sort);
    setMovementsAddress(movements);
    // cout << "OVERLOADED CONSTRUCTOR CALLED:" << endl;

}
// COPY_CONSTRUCTOR
account::account(const account &temp)
{
    name = temp.name;
    userName = temp.userName;
    pin = temp.pin;
    size = temp.size;
    totalBalance = temp.totalBalance;
    income = temp.income;
    outcome = temp.outcome;
    interest = temp.interest;
    sort = temp.sort;
    movements = temp.movements;
    // cout << "COPY_CONSTRUCTOR CALLED:" << endl;
}

/* ========================================================
************************SETTERS***************************
========================================================*/ 

void account ::setName(string name) { this->name = name; }
void account ::setUserName(string userName) { this->userName = userName; }
void account ::setPin(int pin) { this->pin = pin; }
void account ::setSize(int size) { this->size = size; }
void account ::setTotalBalance(double totalBalance) { this->totalBalance = totalBalance; }
void account ::setIncome(double income) { this->income = income; }
void account ::setOutcome(double outcome) { this->outcome = outcome; }
void account ::setInterest(double interest) { this->interest = interest; }
void account ::setSort(bool sort) { this->sort = sort; }
void account ::setMovementsAddress(double *movements) { this->movements = movements; }
void account ::setMovementsValue()
{
    movements = new double[size];
    for (int i = 0; i < size; i++)
    {
        cin >> *(movements + i);
    }
}
void account ::setData(string name, string userName, int pin, int size, double *movements, double totalBalance, double income, double outcome, double interest, bool sort)
{
    setName(name);
    setUserName(userName);
    setPin(pin);
    setSize(size);
    setTotalBalance(totalBalance);
    setIncome(income);
    setOutcome(outcome);
    setInterest(interest);
    setSort(sort);
    setMovementsAddress(movements);
}

/* ========================================================
************************GETTERS***************************
========================================================*/ 

string account ::getName() { return name; }
string account ::getUserName() { return userName; }
int account ::getPin() { return pin; }
int account ::getSize() { return size; }
double account ::getTotalBalance() { return totalBalance; }
double account ::getIncome() { return income; }
double account ::getOutcome() { return outcome; }
double account ::getInterest() { return interest; }
bool account ::getSort() { return sort; }
double *account ::getMovementsAddress() { return movements; }
void account ::getMovementsValue()
{
    for (int i = 0; i < size; i++)
    {
        cout << *(movements + i) << endl;
    }
}
void account ::getData()
{
    cout << "\t\t Your name : " << name << endl;
    cout << "\t\t Your userName : " << userName << endl;
    cout << "\t\t Your pin code : " << pin << endl;
    cout << "\t\t Your total Balance : " << totalBalance << endl;
    cout << "\t\t Your total incomes : " << income << endl;
    cout << "\t\t Your total outcomes : " << outcome << endl;
    cout << "\t\t Your total interest amount : " << interest << endl;
    spaces2();
    cout << "\t\t\t *YOUR MOVEMENTS * " << endl;
    spaces2();
    for (int i = 0; i < size; i++)
    {
        if (*(movements + i) > 0)
            cout << "\t\tDeposited : " << *(movements + i) << endl;
        if (*(movements + i) < 0)
            cout << "\t\tWithdrawl : " << *(movements + i) << endl;
    }
    cout << endl;
}

/* ========================================================
************************DESTRUCTOR*************************
========================================================*/

account ::~account()
{
    // cout << "DESTRUCTOR CALLED:" << endl;
}

/* ========================================================
******************FUNCTIONALITY_FUNCTIONS******************
========================================================*/ 

//CREATING_ACCOUNT
void account ::createAccount()
{
    cout << "\t\tEnter your full name = ";
    getline(cin, name);
    cout << "\t\tSet your pin code = ";
    cin >> pin;
    cout << "\t\t Are you want to deposit some balance now (y/n) :";
}

//CALCULATING_USER_NAME
void account ::calculateUserName()
{

    userName = "";
    userName.push_back(tolower(name[0]));
    bool flag = false;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ')
        {
            flag = true;
        }
        if (name[i] != ' ' && flag == true)
        {
            userName.push_back(tolower(name[i]));
            flag = false;
        }
    }
}

//CALCULATING_TOTAL_BALANCE
double account ::calculateTotalBalance()
{
    double total = calculateTotalIncome() - calculateTotalOutcome();
    totalBalance = total;
    return total;
}

//CALCULATING_TOTAL_IN_COME_MOVEMENTS
double account ::calculateTotalIncome()
{
    double totalIncome = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (*(movements + i) >= 0)
            totalIncome += (*(movements + i));
    }
    income = totalIncome;
    return totalIncome;
}

//CALCULATING_TOTAL_OUT_COME_MOVEMENTS
double account ::calculateTotalOutcome()
{
    double totalOutcome = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (*(movements + i) < 0)
            totalOutcome += (abs(*(movements + i)));
    }
    outcome = totalOutcome;
    return totalOutcome;
}

//CALCULATING_TOTAL_INTEREST
double account ::calculateTotalInterest()
{
    double totalInterest = 0.0;
    for (int i = 0; i < size; i++)
    {
        double deposit = 0.0;
        if (*(movements + i) > 0)
        {
            deposit = *(movements + i) * (interestRate / 100);
            if (deposit >= 1)
            {
                totalInterest += deposit;
            }
        }
    }
    interest = totalInterest;
    return totalInterest;
}

//SORTING_MOVEMENTS_________(ALGORITHUM::_SELECTION_SORT)
void account ::sortMovements()
{
    int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (*(movements + j) < *(movements + min_index))
            {
                min_index = j;
            }
        }
        int temp;
        temp = *(movements + i);
        *(movements + i) = *(movements + min_index);
        *(movements + min_index) = temp;
    }
}


/* ========================================================
**********************_FUNCTION_PROTOTYPES******************
========================================================*/

void SIGN_IN_OR_SIGN_UP(account *, int, account &);
void loginPage(char &);
account Login(string &, int &, account *, const int);
account createNewAccount(account *&, int &);
void successfullyCreatedAccount(account &);
void secondPage(account &, char &, account *, int &);
void loanRequest(account &);
void requestLoan(account *, int &, account &, char, bool);
void transictionProcess(account *, int &, account &, char, bool);
void deleteAccount(account *, int &, account &, char, bool, bool &);


int main()
{

/* ==============================================================================================
********************************************MAIN_FUNCTION***************************************
================================================================================================*/

    //_ALLOCATION
    int noOfAccounts = 3;
    int *defaultPins = new int[noOfAccounts]{111, 222, 333};
    double *movementsAcc0 = new double[5]{2000, 1000, -500, 20000, -6000};
    double *movementsAcc1 = new double[5]{5000, -2000, 10000, 5000, -8000};
    double *movementsAcc2 = new double[5]{8000, 10000, 4000, -12000, -1000};

    //RUNTIME_INFORMATION
    account *accounts = new account[noOfAccounts];
    account currentUser;

    //====================================================
    //____________________DEFAULT_ACCOUNTS________________
    //====================================================
    
    //Account-1
    accounts[0].setName("Muhib Arshad");
    accounts[0].calculateUserName();
    accounts[0].setPin(defaultPins[0]);
    accounts[0].setSize(5);
    accounts[0].setMovementsAddress(movementsAcc0);
    accounts[0].calculateTotalBalance();
    accounts[0].calculateTotalIncome();
    accounts[0].calculateTotalOutcome();
    accounts[0].calculateTotalInterest();

    //Account-2
    accounts[1].setName("Ali Abdullah");
    accounts[1].calculateUserName();
    accounts[1].setPin(defaultPins[1]);
    accounts[1].setSize(5);
    accounts[1].setMovementsAddress(movementsAcc1);
    accounts[1].calculateTotalBalance();
    accounts[1].calculateTotalIncome();
    accounts[1].calculateTotalOutcome();
    accounts[1].calculateTotalInterest();

    //Account-3
    accounts[2].setName("Bilal Sharafat");
    accounts[2].calculateUserName();
    accounts[2].setPin(defaultPins[2]);
    accounts[2].setSize(5);
    accounts[2].setMovementsAddress(movementsAcc2);
    accounts[2].calculateTotalBalance();
    accounts[2].calculateTotalIncome();
    accounts[2].calculateTotalOutcome();
    accounts[2].calculateTotalInterest();

    //BRAIN_AND_HEART_OF_SBL
    SIGN_IN_OR_SIGN_UP(accounts, noOfAccounts, currentUser);

    //_DEALLOCATION
    delete[] movementsAcc0;
    movementsAcc0 = nullptr;
    delete[] movementsAcc1;
    movementsAcc0 = nullptr;
    delete[] movementsAcc2;
    movementsAcc0 = nullptr;
    delete[] accounts;
    accounts = nullptr;

    return 0;
}

/* ==============================================================================================
***************************************_FUNCTIONS_BODY******************************************
================================================================================================*/

/* ========================================================
************************_LOGIN_PAGE_FUNCTION***************
========================================================*/

void loginPage(char &login)
{
    spaces1();
    spaces2();
    cout << "\t\t\t\t\t\t LOGIN " << endl;
    spaces2();

    cout << "\t\t -----------------------------------------------------------------------------" << endl;
    cout << "\t\t | *If you have already an account then press \'L\' for login your account :   |" << endl;
    cout << "\t\t | *If you don't have an account then press \'C\' for create your account :    |" << endl;
    cout << "\t\t -----------------------------------------------------------------------------" << endl;
    login = getch();
    login = tolower(login);

    //_INPUT_VALIDATION
    while (login != 'l' && login != 'c')
    {
        cout << "\t\tError->Invalid Input :" << endl;
        cout << "\t\tPlease enter the valid input as \'L\' or \'C\':" << endl;
        login = getch();
        login = tolower(login);
    }
}

/* ========================================================
************************LOGIN_FUNCTION*********************
========================================================*/

account Login(string &username, int &pin, account *accs, const int noOfAccounts)
{
    bool flag = false;
    account temp;
    do
    {
        cout << endl;
        cout << "\t\t ----------------------------" << endl;
        cout << "\t\t Enter username:";
        getline(cin, username);
        cout << "\t\t Enter pin :";
        cin >> pin;
        cout << "\t\t ----------------------------" << endl;

        // CALCULATING_USERNAME
        for (int i = 0; i < noOfAccounts && flag == false; i++)
        {
            if ((accs + i)->getUserName() == username && (accs + i)->getPin() == pin)
            {
                flag = true;
                temp = *(accs + i);
            }
        }

        //_INPUT_VALIDATION
        if (flag == false)
        {
            cout << "\t >>Error: Such Account does'nt exist. Enter valid Information again :" << endl;
            cin.ignore();
        }
    } while (flag == false);

    if (flag == true)
    {
        return temp;
    }
}

/* ========================================================
*********************CALCULATIONS_FUNCTION*****************
========================================================*/

void successfullyCreatedAccount(account &newAccount)
{
    newAccount.calculateUserName();
    newAccount.calculateTotalBalance();
    newAccount.calculateTotalIncome();
    newAccount.calculateTotalOutcome();
    newAccount.calculateTotalInterest();
}

/* ========================================================
*****************_CREATE_NEW_ACCOUNT_FUNCTION**************
========================================================*/

account createNewAccount(account *&accs, int &noOfAccounts)
{
    system("cls");
    spaces1();
    spaces2();
    cout << "\t\t Create an account : " << endl;
    spaces2();

    account newAccount;
    char boolDeposit;
    newAccount.createAccount();
    boolDeposit = getch();
    boolDeposit = tolower(boolDeposit);

    switch (boolDeposit)
    {
    case 'y':
    {
        spaces2();
        cout << "\t\t Do your first movement by depositing at least $200:";
        newAccount.setSize(1);
        newAccount.setMovementsValue();

        //_INPUT_VALIDATION
        while (*(newAccount.getMovementsAddress() + 0) < 200)
        {
            cout << "\t\t Error : Low balance you must have deposit at leat $200 :";
            newAccount.setMovementsValue();
        }
        successfullyCreatedAccount(newAccount);

        break;
    }
    case 'n':
    {
        successfullyCreatedAccount(newAccount);
        break;
    }
    }

    //_ADDING_NEW_ACCOUNT_TO_THE_*ACCOUNTS*_ARRAY
    account *tempAccounts = new account[noOfAccounts + 1];
    for (int i = 0; i < noOfAccounts; i++)
    {
        *(tempAccounts + i) = *(accs + i);
    }
    delete[] accs;
    accs = tempAccounts;
    accs[noOfAccounts] = newAccount;
    noOfAccounts++;

    return newAccount;
}

/* ========================================================
************************_SECOND_PAGE_FUNCTION***************
========================================================*/

void secondPage(account &currentUser, char &login, account *accounts, int &noOfAccounts, bool &flag)
{
    bool exit = false;
    do
    {
        if (flag == true)
        {
            system("cls");
            flag = false;
        }
        char options;

        spaces1();
        spaces2();
        cout << "\t\t\t\t\t WELCOME ! " << currentUser.getName() << endl;
        spaces2();
        cout << "Total Balance : " << currentUser.getTotalBalance() << endl;
        spaces2();

        cout << "\t\t\t\t *OPTIONS* " << endl;
        cout << "\t\t ------------------------------------------" << endl;
        cout << "\t\t|      Press \'R\' for request loan        |" << endl;
        cout << "\t\t|      Press \'T\' for transfer money      |" << endl;
        cout << "\t\t|      Press \'S\' for sort movements      |" << endl;
        cout << "\t\t|      Press \'D\' for delete account      |" << endl;
        cout << "\t\t|      Press \'E\' for log out             |" << endl;
        cout << "\t\t ------------------------------------------" << endl;
        spaces2();
        cout << "\t\t\t *YOUR ACCOUNT DETAILS* " << endl;
        spaces2();
        currentUser.getData();

        options = getch();
        options = tolower(options);

        //_INPUT_VALIDATION
        while (options != 'r' && options != 't' && options != 's' && options != 'd' && options != 'e')
        {
            cout << "\t\t Error : Invalid Input ! " << endl;
            cout << "\t\t Please enter the valid input :" << endl;
            options = getch();
            options = tolower(options);
        }

        switch (options)
        {
        case 'r':
        {
            requestLoan(accounts, noOfAccounts, currentUser, login, flag);
            break;
        }
        case 't':
        {
            transictionProcess(accounts, noOfAccounts, currentUser, login, flag);
            break;
        }
        case 'd':
        {
            deleteAccount(accounts, noOfAccounts, currentUser, login, flag, exit);
            break;
        }
        case 's':
        {
            currentUser.sortMovements();
            system("cls");
            secondPage(currentUser, login, accounts, noOfAccounts, flag);
            break;
        }
        case 'e':
        {
            spaces2();
            cout<<"\t\t\t Logging out..........."<<endl;
            Sleep(2*1000);
            system("cls");
            cin.ignore();
            exit = true;
            SIGN_IN_OR_SIGN_UP(accounts, noOfAccounts, currentUser);
            break;
        }
        }
    } while (exit == false);
}

/* ========================================================
****************_SIGN_IN_OR_SIGN_UP_FUNCTION****************
========================================================*/

void SIGN_IN_OR_SIGN_UP(account *accounts, int noOfAccounts, account &currentUser)
{
    string username;
    int pin;
    char login;
    bool flag = false;
    loginPage(login);
    switch (login)
    {
    case 'l':
    {
        currentUser = Login(username, pin, accounts, noOfAccounts);
        successfullyCreatedAccount(currentUser);
        flag = true;

        spaces2();
        cout << "\t\t\t Loading......" << endl;
        Sleep(2 * 1000);

        secondPage(currentUser, login, accounts, noOfAccounts, flag);

        break;
    }
    case 'c':
    {
        currentUser = createNewAccount(accounts, noOfAccounts);
        system("cls");
        cout << "\t\tCongratulations ! You have successfully created your first Account :" << endl;
        secondPage(currentUser, login, accounts, noOfAccounts, flag);
        break;
    }
    }
}

/* ========================================================
**********************_REQUEST_LOAN_FUNCTION***************
========================================================*/

void requestLoan(account *accounts, int &noOfAccounts, account &currentUser, char login, bool flag)
{

    // INPUT_VALIDATION
    if (currentUser.getTotalBalance() >= 500)
    {
        double amount = 0;
        spaces2();
        cout << "\t\t\t Enter the loan amount you want to request from bank : ";
        cin >> amount;

        // INPUT_VALIDATION
        while (amount < 0)
        {
            cout << "\t\t\t Invalid Input : Please Enter the valid input (amount should be a positive value ) :";
            cin >> amount;
        }

        //_SLEEP_FUNCTION
        spaces2();
        cout << "\t\t\t\t Your request is in progress........." << endl;
        Sleep(3 * 1000);
        system("cls");
        cout << "\t\t\t You request is approved ,You got $" << amount << " of loan from Salik Bank Limited (SBL) " << endl;

        // CALCULATE_CURRENT_USER_INDEX
        int currentIndex = 0;
        for (int i = 0; i < noOfAccounts; i++)
        {
            if ((accounts + i)->getUserName() == currentUser.getUserName())
            {
                currentIndex = i;
                break;
            }
        }

        // DEEPY_COPY_CHANGING_CURRENTUSER_MOVEMNETS
        account *tempAccounts = new account[noOfAccounts];
        for (int i = 0; i < noOfAccounts; i++)
        {
            *(tempAccounts + i) = *(accounts + i);
        }
        int tempSize = (tempAccounts + currentIndex)->getSize();

        double *tempMov = new double[tempSize + 1];
        for (int i = 0; i < tempSize; i++)
        {
            *(tempMov + i) = *((tempAccounts + currentIndex)->getMovementsAddress() + i);
        }
        *(tempMov + tempSize) = amount;
        delete[](tempAccounts + currentIndex)->getMovementsAddress();
        (tempAccounts + currentIndex)->setMovementsAddress(tempMov);
        (tempAccounts + currentIndex)->setSize((tempAccounts + currentIndex)->getSize() + 1);

        delete[] accounts;
        accounts = tempAccounts;
        currentUser = *(accounts + currentIndex);
        successfullyCreatedAccount(currentUser);
        secondPage(currentUser, login, accounts, noOfAccounts, flag);
    }
    else
    {
        system("cls");
        cout << "\t\t Low Balance ! For requesting Loan you must have at least $500 in your account. " << endl;
        secondPage(currentUser, login, accounts, noOfAccounts, flag);
    }
}

/* ========================================================
**********************_TRANSICTION_MONEY_FUNCTION***************
========================================================*/

void transictionProcess(account *accounts, int &noOfAccounts, account &currentUser, char login, bool flag)
{

    bool accountExist = false;
    int indexReciever = 0;
    int currentIndex = 0;
    double amountTransfer = 0;
    string usernameTransfer = "";
    spaces2();
    cout << "\t\t\t Enter the amount that you want to transfer :";
    cin >> amountTransfer;

    // INPUT_VALIDATION
    while (currentUser.getTotalBalance() - amountTransfer < 200)
    {
        cout << "Sorry Sir ! You cannot transfer more than $" << currentUser.getTotalBalance() - 200 << ", At least your bank account has $200 in it." << endl;
        cout << "\t\t\t Again enter the amount that you want to transfer :";
        cin >> amountTransfer;
    }
    do
    {
        bool selfTransfer = false;
        cout << "\t\t\t Enter the username of the account ,whom you want to transfer money:";
        cin >> usernameTransfer;

        // CALCULATING_CURRENT_USER_Index_AND_RECEIVER_INDEX
        if (usernameTransfer == currentUser.getUserName())
        {
            selfTransfer = true;
        }
        for (int i = 0; i < noOfAccounts; i++)
        {
            if ((accounts + i)->getUserName() == usernameTransfer && (accounts + i)->getUserName() != currentUser.getUserName())
            {
                accountExist = true;
                indexReciever = i;
                break;
            }
        }
        for (int i = 0; i < noOfAccounts; i++)
        {
            if ((accounts + i)->getUserName() == currentUser.getUserName())
            {
                currentIndex = i;
                break;
            }
        }

        // INPUT_VALIDATION
        if (accountExist == true && selfTransfer == false)
        {

            spaces2();
            cout << "\t\t\t Transiction is in process...." << endl;
            Sleep(3 * 1000);
            system("cls");
            cout << "\t\t\t SUCCESSFULLY TRANSFERED ,You transfered $" << amountTransfer << " to the account  " << usernameTransfer << endl;

            // DEEP_COPY::_ADDING_WITHRAWL_IN_THE_CURRENT_USER
            amountTransfer = amountTransfer * (-1);
            account *tempAccounts = new account[noOfAccounts];
            for (int i = 0; i < noOfAccounts; i++)
            {
                *(tempAccounts + i) = *(accounts + i);
            }
            int tempSize = (tempAccounts + currentIndex)->getSize();

            double *tempMov = new double[tempSize + 1];
            for (int i = 0; i < tempSize; i++)
            {
                *(tempMov + i) = *((tempAccounts + currentIndex)->getMovementsAddress() + i);
            }
            *(tempMov + tempSize) = amountTransfer;
            delete[](tempAccounts + currentIndex)->getMovementsAddress();
            (tempAccounts + currentIndex)->setMovementsAddress(tempMov);
            (tempAccounts + currentIndex)->setSize((tempAccounts + currentIndex)->getSize() + 1);

            delete[] accounts;
            accounts = tempAccounts;
            currentUser = *(accounts + currentIndex);
            successfullyCreatedAccount(currentUser);

            // DEEP_COPY::_ADDING_DEPOSITED_IN_THE_RECEIVER_ACCOUNT_MOVEMENTS
            amountTransfer = abs(amountTransfer);
            account *tempAccounts2 = new account[noOfAccounts];
            for (int i = 0; i < noOfAccounts; i++)
            {
                *(tempAccounts2 + i) = *(accounts + i);
            }
            int tempSize2 = (tempAccounts2 + indexReciever)->getSize();

            double *tempMov2 = new double[tempSize2 + 1];
            for (int i = 0; i < tempSize2; i++)
            {
                *(tempMov2 + i) = *((tempAccounts + indexReciever)->getMovementsAddress() + i);
            }
            *(tempMov2 + tempSize2) = amountTransfer;
            delete[](tempAccounts2 + indexReciever)->getMovementsAddress();
            (tempAccounts2 + indexReciever)->setMovementsAddress(tempMov2);
            (tempAccounts2 + indexReciever)->setSize((tempAccounts2 + indexReciever)->getSize() + 1);

            delete[] accounts;
            accounts = tempAccounts2;
            successfullyCreatedAccount(*(accounts + indexReciever));
            secondPage(currentUser, login, accounts, noOfAccounts, flag);
        }
        if (accountExist == false)
        {
            cout << "\t\t\t Error: Such Account does'nt exist : " << endl;
        }
        if (selfTransfer == true)
        {
            spaces2();
            cout << "\t\tError :You could not transfer money to yourself:" << endl;
            spaces2();
        }
    } while (accountExist == false);
}

/* ========================================================
**********************_DELETE_ACCOUNT_FUNCTION***************
========================================================*/

void deleteAccount(account *accounts, int &noOfAccounts, account &currentUser, char login, bool flag, bool &exit)
{

    spaces2();
    string deleteUsername;
    int deleteUserPin;
    bool found = false;
    char confirm;

    do
    {
        cout << "\t\t To delete your account enter your username or pin code:" << endl;
        cout << "\t\t\t Enter your username:";
        cin >> deleteUsername;
        cout << "\t\t\t Enter your pincode: ";
        cin >> deleteUserPin;
        if (currentUser.getUserName() == deleteUsername && currentUser.getPin() == deleteUserPin)
        {
            found = true;
            cout << "\t\t\t Are you sure to delete your account (y/n): ";
            confirm = getch();
            confirm = tolower(confirm);

            // INPUT_VALIDATION
            while (confirm != 'y' && confirm != 'n')
            {
                cout << "\t\t\t Invalid input : Please enter the valid input as (y/n) :";
                confirm = getch();
                confirm = tolower(confirm);
            }

            switch (confirm)
            {
            case 'y':
            {
                // DEEP_DELETION_ACCOUNT_FROM_THE_ACCOUNTS_ARRAY
                int loc = 0;
                account *tempAccountsDelete = new account[noOfAccounts - 1];
                for (int i = 0; i < noOfAccounts; i++)
                {
                    if ((accounts + i)->getPin() != currentUser.getPin())
                    {
                        *(tempAccountsDelete + loc) = *(accounts + i);
                        loc++;
                    }
                }
                delete[] accounts;
                accounts = tempAccountsDelete;
                noOfAccounts--;

                // DELETING....
                spaces2();
                cout << "\t\t\t Deleting your account........" << endl;
                Sleep(3 * 1000);
                system("cls");
                cin.ignore();
                exit = true;
                cout << "\t\t\t\t YOUR ACCOUNT HAS BEEN DELETED SUCCESSFULLY " << endl;
                SIGN_IN_OR_SIGN_UP(accounts, noOfAccounts, currentUser);

                break;
            }
            case 'n':
            {
                system("cls");
                secondPage(currentUser, login, accounts, noOfAccounts, flag);
                break;
            }
            }
        }
        else
        {
            cout << "\t\t You enter the worng username or pincode : Try Again : " << endl;
        }
    } while (found == false);
}

