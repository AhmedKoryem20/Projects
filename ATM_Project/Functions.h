#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
typedef struct
{
    char ID;
    int Password;
    int Balance;
}E1_Users;
void Login_To_System (void);
void Balance_Check (char ID,int n);
void Deposit_Money (char ID , int Cash_Amount,int n);
char Withdraw_Money (char ID , int Cash_Amount, int n);
void Transfer_Money (char ID , int n);
#endif // FUNCTIONS_H_INCLUDED
