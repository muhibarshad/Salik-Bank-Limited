#include"_SBL_Features.h"

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


