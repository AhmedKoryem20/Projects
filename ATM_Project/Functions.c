#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
E1_Users Arr_Users[]={{11,111,0},{22,222,0},{33,333,0}};
/*****************************************Login Function (Checks ID If Exist & Password If Accurate And Starts The Machine Operation)*********/
void Login_To_System (void)
{
int id,pass,i,w;
int Deposit_Cash=0 , Withdraw_Cash=0 , Tranfer_Cash=0;
int Operation;
int press;
for (w=0;w<3;w++)
{
    printf("Please Enter Your ID: ");
    scanf("%d",&id);
    int flag=3;
for (i=0;i<3;i++)
{
if(id==Arr_Users[i].ID)
{
    printf("\t\t\t******Welcome User %d******",Arr_Users[i].ID);
    while (flag)
    {
    printf("\nPlease Enter Your Password: ");
    scanf("%d",&pass);
    if (pass==Arr_Users[i].Password)
    {
    Loop:
        printf("\t\t****Please Select Your Operation****: ");
        printf("\n\nEnter Number '1' To Transfer Money\nEnter Number '2' To Deposit Money\nEnter Number '3' To Withdraw Money\nEnter Number '4' To Check Your Balance\n");
        printf("\nChoose Your Operation: \t");
        scanf("%d",&Operation);
        switch (Operation)
        {
        case 1:////////////////////////////////////////////////////////Transfer Money Case
            Transfer_Money (Arr_Users[i].ID , i);
            break;
        case 2:////////////////////////////////////////////////////////Deposit Case
            printf("Please Enter The Amount Of Cash:\t");
            scanf("%d",&Deposit_Cash);
            Deposit_Money (Arr_Users[i].ID,Deposit_Cash,i);
            break;
        case 3:///////////////////////////////////////////////////////Withdraw Case
            printf("Please Enter The Amount Of Cash:\t");
            scanf("%d",&Withdraw_Cash);
            char Case = Withdraw_Money (Arr_Users[i].ID ,Withdraw_Cash,i);
            break;
        case 4:///////////////////////////////////////////////////////Balance Check Case
            Balance_Check(Arr_Users[i].Balance,i);
            break;
        default:
            printf("\nNo Operation Found\n");
        }
        printf("If You Need To Continue Press Number'1',Otherwise Press'0'\n");
        scanf("%d",&press);
        if (press==1)
        {
            goto Loop;
        }
        else
        {
            printf("Thanks For Using Our Services, Hope To See You Again!\n\n\n");
            flag=0;
            i=0;
            w=3;
            break;
        }

    }
    else
    {
        printf("Wrong Password, Please Try Again");
        flag--;
    }
    if (flag==0)
    {
        printf("You Can Try Again After 10 Minutes");
        break;
    }
    }
}
}
if (w<3)
{
    printf("User Not Found,Please Try Again\n");
}
else{break;}
}
}
/***************************************************************************************************/

/**************************Balance Check Function**************************/
void Balance_Check (char ID, int n)
{
    printf("Your Current Balance Is: %d\n",Arr_Users[n].Balance);
}
/**************************Deposit Function*******************************/
void Deposit_Money (char ID , int Cash_Amount,int n)
{
Arr_Users[n].Balance=+ Cash_Amount;
}
/**************************Withdraw Function******************************/
char Withdraw_Money (char ID , int Cash_Amount, int n)
{
    if (Arr_Users[n].Balance>=Cash_Amount)
    {
        Arr_Users[n].Balance-= Cash_Amount;
        return "True";
    }
    else
    {
        printf ("The Amount You Need To Withdraw Is More Than Your Balance!\n");
    }
}
/*************************Transfer Function*******************************/
void Transfer_Money (char ID , int n)
{
    int id , money_transfer,j,h,counter=0;
    for (h=0;h<3;h++)
        {
        printf("Enter User's ID That Will Receive The Money\n");
        scanf("%d",&id);
        for (j=0;j<3;j++)
        {
            if (id==Arr_Users[j].ID)
            {
                printf("Enter The Amount Of Cash You Need To Transfer:\t");
                scanf("%d",&money_transfer);
                if (money_transfer<=Arr_Users[n].Balance)
            {
                Arr_Users[j].Balance=+ money_transfer;
                Arr_Users[n].Balance-= money_transfer;
                printf("Transaction Done~~\n");
                Balance_Check(ID,n);
                counter=1;
                break;
            }
            else
            {
                printf("The Amount You Need To Transfer Is More Than Your Balance!\n");
                h=3;
            }
            }
        }
        if (counter==1)
        {
            break;
        }
                if (h<3)
                {
                printf("ID Not Found Please Try Again\n");
                }
            if (h==2)
            {
                printf("Multiple Trials, Sorry, Try Again After While!!\n");
                break;
            }
        }
}
