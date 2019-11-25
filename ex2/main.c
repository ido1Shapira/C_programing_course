#include <stdio.h>
#include "myBank.h"


int main (){
  int quit=0;
  char input;
  do{
    printf("\nWelcome to the bank!\n");
    printf("Enter O for Opening Account.\nEnter B for Getting Balance.\nEnter D for Deposit.\nEnter W for Withrawal.\n");
    printf("Enter C for Closing Account.\nEnter I for Adding Interest.\nEnter P for Printing all open accounts.\nEnter E for Exit.\n");
    printf("\nTransaction‬‬ ‫‪type?:‬‬");
    scanf(" %c",&input);
    while(getchar()!='\n');//cleans buffer
    float amount = 0;
    int num_account = 0;
      switch (input) {
        case 'O':
          printf("‫‪Initial deposit‬‬?:‬‬");
          scanf("%f", &amount);
        while(getchar()!='\n');//cleans buffer
          num_account=openAccount(amount);
          if(num_account!=-1){
          printf("The new account's number is: %d\n",num_account);
          }
          break;
        case 'B':
          printf("Account number?:");
          scanf("%d", &num_account);
          while(getchar()!='\n');//cleans buffer
          if(getBalance(num_account)!=-1){
            printf("The balance of %d is: %.2f\n",num_account,getBalance(num_account));
          }
          break;
        case 'D':
          printf("Account number?:");
          scanf("%d", &num_account);
          while(getchar()!='\n');//cleans buffer
          printf("Amount?:");
          scanf("%f", &amount);
          while(getchar()!='\n');//cleans buffer
          if(deposit(num_account,amount)!=-1){
            printf("The new balance of %d is: %.2f\n",num_account,getBalance(num_account));
          }
          break;
        case 'W':
          printf("Account number?:");
          scanf("%d", &num_account);
          while(getchar()!='\n');//cleans buffer
          printf("Amount?:");
          scanf("%f", &amount);
          while(getchar()!='\n');//cleans buffer
          if(withrawal(num_account,amount)!=-1){
            printf("The new balance of %d is: %.2f\n",num_account,getBalance(num_account));
          }
          break;
        case 'C':
          printf("Account number?:");
          scanf("%d", &num_account);
          while(getchar()!='\n');//cleans buffer
          closeAccount(num_account);
          break;
        case 'I':
          printf("Interest rate?:");
          float interest_rate = 1;
          scanf("%f", &interest_rate);
          while(getchar()!='\n');//cleans buffer
          interest(interest_rate);
          break;
        case 'P':
          printAll();
          break;
        case 'E':
          exiting();
          quit=1;
          printf("Bye Bye...\n");
          break;
        default:
          printf("Invalid input\n");
      }
}
while(!quit);
return 0;
}
