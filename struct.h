#ifndef STRUCT_H
#define STRUCT_H
struct patient
{
    int ID;
    char Name[30];
    char CNIC[13];
    char PHONE_NUMBER[11];
    char disease[30];
    int is_Admitted;
};
#endif
