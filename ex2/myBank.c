#include <stdio.h>
#include "myBank.h"
#define numOfAccounts 50
#define range 901
static float accounts [2][numOfAccounts] ={0};
int isValid(int account_number){
  int index = account_number-range;
  if (index < 0 || index > numOfAccounts-1){
    printf("Invalid account number\n");
    return 0;
  }
  return 1;
}
int isOpen(int account_number) {
  if (accounts[1][account_number-range] == 0){
    printf("This account is close\n");
    return 0;
  }
  return 1;
}
int checkAmount(int amount){
  if(amount<=0){
    printf ("This amount is invalid\n");
    return 0;
  }
  return 1;
}
int openAccount(float amount){
  int i=0;
  while(i<numOfAccounts && accounts[1][i]==1){
    i++;
  }
  if(i>numOfAccounts){
    printf("The bank is full of accounts");
    return -1;
  }
  if(checkAmount(amount)){
    accounts[0][i]=decimalPoints(amount);
    accounts[1][i]=1;// open the account.
  }
  else {return -1;}
  return (i+range);// the range of the account's numbers is 901 to 950.
}
float decimalPoints (float num)// Rounding the number to 2 Decimal Places.
{
  num*=100;
  num=(int)num;
  num/=100.0;
  return num;
}

double getBalance(int account_number){
  if (isValid(account_number)&& isOpen(account_number)){
    return accounts[0][account_number-range];
  }
  return -1;
}

double deposit(int account_number, float amount){
  if (isValid(account_number) && isOpen(account_number)&& checkAmount(amount)){
    accounts[0][account_number-range] += decimalPoints(amount);
    return accounts[0][account_number-range];
  }
  return -1;
}

double withrawal(int account_number, float amount){
  if (isValid(account_number) && isOpen(account_number)&& checkAmount(amount)){
    if(getBalance(account_number)<amount){
      printf("There is no enough money in the account\n");
      return -1;
    }
    else
    accounts[0][account_number-range] -=decimalPoints(amount);
    return accounts[0][account_number-range];
  }
  return -1;
}
void closeAccount(int account_number){
    if (isValid(account_number) && isOpen(account_number)){
      accounts[1][account_number-range] = 0;
      accounts[0][account_number-range] = 0;
    }
}
void interest(float interest_rate){
  int i;
  interest_rate/=100;
  for (i = 0;i<numOfAccounts;i++){
    if (accounts[1][i]==1){
      accounts[0][i] = decimalPoints((1+interest_rate)*accounts[0][i]);
    }
  }
}
void printAll(){
  int i;
  int flag = 1;
  for (i = 0;i<numOfAccounts;i++){
    int account_number = i+range;
    if (accounts[1][i]==1){
      flag =0;
      printf("Account number: %d , balance = %.2f\n", account_number , getBalance(account_number));
    }
  }
  if(flag){
      printf("The bank is empty\n");
  }
}
void exiting(){
  int i;
  for (i = 0;i<numOfAccounts;i++){
    int account_number = i+range;
    if (accounts[1][i]==1){
      closeAccount(account_number);
    }
  }
}
