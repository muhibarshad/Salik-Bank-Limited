<h1 align="center" style="font-size: 52px;" > Welcome to BANKIST APPLICATION  👋</h1>

![GitHub top language](https://img.shields.io/github/languages/top/muhib7353/Salik-Bank-Limited?logo=c%2B%2B&style=flat-square)
![GitHub repo size](https://img.shields.io/github/repo-size/muhib7353/Salik-Bank-Limited)
![GitHub](https://img.shields.io/github/license/muhib7353/Salik-Bank-Limited)
![GitHub followers](https://img.shields.io/github/followers/muhib7353?logo=Github&style=flat-square)
![GitHub User's stars](https://img.shields.io/github/stars/muhib7353?logo=Github&style=flat-square)
![GitHub commit activity](https://img.shields.io/github/commit-activity/y/muhib7353/Salik-Bank-Limited?logo=git)
![GitHub last commit](https://img.shields.io/github/last-commit/muhib7353/Salik-Bank-Limited?logo=git)
![GitHub language count](https://img.shields.io/github/languages/count/muhib7353/Salik-Bank-Limited?logo=c%2B%2B)

> Bankist application in `C++` by using `DYNAMIC MEMPRY ALLOCATION` and `OBJECT_ORIENTED_PROGRAMMING` concepts. Its main features are login system, user authentication ,create a new account , requesting loan , transfer money, sort your movements , currency converter , delete your account and log out system .

# ✨ Demo

`Bankist project` main feature is `abstraction` and `data-encapsulation`.Main contain only `default` accounts data, memory allocation and deallocation and one executed external function.

<p align="center">
  <img width="1000" src="Demo/demo.gif" alt="demo"/>
</p>

### Example of Abstraction and encapsulation see [main.cpp](/main.cpp):

```cpp
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

```
# Usage

### Default Accounts for login:

| username | password |
| -------- | -------- |
|    ma    |   111    |
|    aa    |   222    |
|    bs    |   333    |

# 🚀 Features:

- How to use the `Dynamic Memory Allocation` .
- Data hiding and Encapsultion of Classes .
- Real World Banking system .
- Login, create new account system.
- Requesting Loan ,Transfering loan system.
- Sort your movements and delete your account system.
- All input validations are done .
- No memory leakage in run-time all dynamic memory is deallocated.

# 🤝 Contributing

Feel Free to contribute.
If you want to add some features and resolve any issues then just fork the repository. To want to change the code only in the one [main.cpp]() file then create `pull-request` to the master branch. I will review it and then i merge it to the branch. And same for the main branch also.

# Author

### 👨‍💻 Muhib Arshad

   <div align="center">
<p align="center">Let's connect!</p>

<a href="https://www.linkedin.com/in/muhib-arshad-85439b242/" target="blank">
    <img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white" />
</a>

<a href="https://medium.com/@muhibarshad123" target="blank">
    <img src="https://img.shields.io/badge/Medium-12100E?style=for-the-badge&logo=medium&logoColor=white" />
</a>

<a href="https://stackoverflow.com/users/18215817/muhib-arshad?tab=profile" target="blank">
    <img src="https://img.shields.io/badge/Stack_Overflow-FE7A16?style=for-the-badge&logo=stack-overflow&logoColor=white" />
</a>

<a href = "https://twitter.com/muhib7353" target="blank">
    <img src="https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white" />
</a>

<a href="https://www.facebook.com/muhib7353/" target="blank">
    <img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white" />
</a>

<a href="https://www.instagram.com/muhib7353/" target="blank">
    <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" />
</a>

</div>



## Show your support

Please ⭐️ this repository if this project helped you!

You can also follow my GitHub Profile to stay updated:
<a href="https://github.com/muhib7353" target="blank">
@muhib7353
</a>


## 📝 License

Copyright © 2022 [Muhib Arshad](https://github.com/muhib7353). 


This project is [MIT](https://github.com/muhib7353/Salik-Bank-Limited/blob/main/LICENSE) licensed.
