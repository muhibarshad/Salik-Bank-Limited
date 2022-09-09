
#include "reusedFunctions.h"
#include <string>
#include <cmath>

#define interestRate 1.5
#define minmumBalanceForInterest 200

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