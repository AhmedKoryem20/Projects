#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "stdbool.h"
#include "fun.h"
extern Uint_16 top;
extern Uint_8 List[5];
        Uint_16 Selection;
        Uint_16 Counter=0;
        Uint_8 id , i  , Course_ID[3] , Course_Grades[3];
        Uint_16 Year;
        Uint_16 flag=0;
        Uint_16 year_of_birth=0;
        Uint_8 C_id[3];
        Uint_8 C_grade[3];
int main ()
{
        Loop:
    printf("\t\t*****Welcome To Predators International School*****\n\n");
    while(1)
    {
        printf("\t\t\t<<Select What Do You Need To Do>>\n\n");
        printf("1-To Add New Student\n2-To Search If ID Is Exist Or Not\n3-To Show ID's List\n4-To Delete Specific ID\n5-To Get Student's Information\n");
        printf("Your Selection: ");
        fflush(stdin);
        scanf("%d",&Selection);
        switch(Selection)
        {
        case 1:
                Counter++;
                    if (Counter==6)
                    {
                        printf("\t\t<<Stack Is Full!!>>\n\n");
                        goto Loop;
                    }
            ADD_LOOP:
                printf("Please Enter Student's ID: ");
                fflush(stdin);
                scanf("%d",&id);
                Uint_16 search = SDB_IsIdExist(id);

                if (search==0)
                {
                    printf("Enter Student's Year Of Birth: ");
                    fflush(stdin);
                    scanf("%d",&Year);
                    for (i=0;i<3;i++)
                    {
                        printf("Enter Course's %d ID ('ID From 0 to 9'): ",i+1);
                        fflush(stdin);
                        scanf("%c",&Course_ID[i]);
                        printf("Enter Course's %d Grade In Letters ('A,B,C,D,F'): ",i+1);
                        fflush(stdin);
                        scanf("%c",&Course_Grades[i]);
                    }
                    SDB_AddEntry(id,Year,&Course_ID,&Course_Grades);
                        printf("\n\n\n");
                        goto Loop;
                }
                else
                {
                    printf("This ID Is Already Saved For Another Student,Try Again With Different ID!!\n\n");
                    flag++;
                    if (flag<3)
                    {
                        goto ADD_LOOP ;
                    }
                    else
                    {
                        break;
                    }
                }
            break;
        case 2:
                printf("Enter Student's ID: ");
                Uint_16 Check;
                fflush(stdin);
                scanf("%d",&id);
                Check = SDB_IsIdExist(id);
                if (Check==1)
                {
                    printf("\nThis Student Is Already Registered In Our System>>\n");
                }
                else
                {
                    printf("\nStudent Is Not Registered In Our System,We Can't Find Him/Her!!\n");
                }
                printf("Check Is: %d\n\n",Check);
                goto Loop;
            break;
        case 3:
                printf("\n\t\t\t<<Our Students List>>\n\n");
                Get_ListID (&top,&List);
            break;
        case 4:
                printf("Enter ID You Need To Delete: ");
                fflush(stdin);
                scanf("%d",&id);
                SDB_DeleteEntry(id);
            break;
        case 5:
                printf("Enter ID You Need To Search: ");
                fflush(stdin);
                scanf("%d",&id);
                Uint_8 flash = SDB_ReadEntry(id,&year_of_birth,&C_id,&C_grade);
                if (flash==1)
                {
                    printf("\n\t\t***All Student's Informations We Got***\n\n");
                }
                else{printf("User Not Found!!\n\n");}
            break;
        default:
            printf("Operation Not Found!!\n");
        }
    }
    return 0;
}

