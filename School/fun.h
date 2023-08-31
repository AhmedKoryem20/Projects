#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
#include "STD_TYPES.h"
#include "stdbool.h"

typedef struct
{
    Uint_8 id;
    Uint_16 year_of_birth;
    Uint_8 course_id[3];
    Uint_8 course_grade[3];

}school_t;
school_t school[5];




bool SDB_AddEntry(Uint_8 ID,Uint_16 year_of_birth,Uint_8* C_id,Uint_8* C_grade);
bool SDB_ReadEntry(Uint_8 ID,Uint_16* year_of_birth,Uint_8* C_id,Uint_8* C_grade);
bool SDB_IsIdExist(Uint_8 id);
void Get_ListID (Uint_8 *Count , Uint_8 *List);
void SDB_DeleteEntry(Uint_8 id);
#endif // FUN_H_INCLUDED

