#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "stdbool.h"
#include "fun.h"
 Uint_16 top=0;
Uint_8 List[5];

bool SDB_AddEntry(Uint_8 ID,Uint_16 year_of_birth,Uint_8* C_id,Uint_8* C_grade)
{
    Uint_8 i,k;
    Uint_8 f=1;
    for(i=0;i<5;i++)
        {
            if(school[i].id==ID || top==5)
                {
                    f=0;
                    return false;
                }
        }
        if(f)
            {
                school[top].id=ID;
                school[top].year_of_birth=year_of_birth;
                for(k=0;k<3;k++)
                    {
                        school[top].course_id[k]=C_id[k];
                        school[top].course_grade[k]=C_grade[k];
                    }
                    List[top]=school[top].id;
                    top++;
                return true;
            }



}



bool SDB_ReadEntry(Uint_8 ID,Uint_16* Year_of_birth,Uint_8* C_id,Uint_8* C_grade)
{       Uint_8 i,k,found=0,h;
        for(i=0;i<=top;i++)
        {
            if(ID==school[i].id)
                {
                    found=1;
                    *Year_of_birth=school[i].year_of_birth;
                    for(k=0;k<3;k++)
                        {
                            C_id[k]=school[i].course_id[k];
                            C_grade[k]=school[i].course_grade[k];
                        }
                        printf("ID: %d\nDate Of Birth: %d\n",ID,*Year_of_birth);
                        for (h=0;h<3;h++)
                        {
                            printf("Course ID: %c\tGrade: %c\n",C_id[h],C_grade[h]);
                        }

                    return true;
                }

        }
        if(found==0)
            {
                return false;
            }

}




bool SDB_IsIdExist(Uint_8 ID)
{
    Uint_8 i,f=0;
    for(i=0;i<=top;i++)
        {
            if(ID==school[i].id)
                {
                    f=1;
                }
                if(f==1)
                {
                    break;
                }
        }
    if(f==1)
        {
            return true;
        }
        else
            {
                return false;
            }
}



void Get_ListID (Uint_8 *Count , Uint_8 *List)
{
     Count=top;
    printf("Number Of Students Are: %d\n",Count);
    Uint_16 c;
    printf("\t\t**IDs List**\n\n");
    for (c=0;c<=top;c++)
    {
        if (top==0)
        {
            printf("\t\t<<No Data Found!!>>\n");
            break;
        }
        if (c==top)
        {
            break;
        }
        List[top]=school[c].id;
        printf("%d- %d\n",c+1,List[c]);

    }
}



void SDB_DeleteEntry(Uint_8 id)
{   Uint_8 i,k,j=0;
    for(i=0;i<=5;i++)
        {
            if(id==school[i].id)
                {   j=1;
                    if(i==top)
                        {
                            top--;
                        }
                        else
                            {
                                for(k=i;k<=top;k++)
                                    {
                                        school[i].id = school[i+1].id;
                                        school[i].year_of_birth=school[i+1].year_of_birth;

                                        for(k=0;k<3;k++)
                                            {
                                                school[i].course_id[k]=school[i+1].course_id[k];
                                            }
                                    }

                                top--;
                            }
                 }
        }
        if(j==1)
        {
            printf("\n\t\t\t<<This ID Successfully Deleted>>\n\n");
        }

        if(j==0)
            {
                printf("ID Not Found!!\n\n");
            }

}

