#ifndef CHECKID_H
#define CHECKID_H

#include "struct.h"
int checkid(int );
int checkid(int temp)
{

	struct patient pt;
    int flag=0;
    FILE *fptr;
    fptr=fopen("patient_record.txt","rb+");
    if(fptr==NULL)
    {
        printf("ERROR OCCURED");
    }
    else
{
    while(fread(&pt,sizeof(struct patient),1,fptr)&&flag==0)
    {
        if(pt.ID==temp)
        {
            flag=1;

        }
        else
        {
            flag=0;
        }
    }
    fclose(fptr);
    return flag;
}
}

#endif
