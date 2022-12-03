#ifndef DISPLAYPATIENT_H
#define DISPLAYPATIENT_H
#include "struct.h"
void all_patients()
{
    system("cls");
	struct patient pt;
    FILE *fptr;
    int i=0,index=0;
    fptr=fopen("patient_record.txt","rb+");
    if(fptr==NULL)
    {
        printf("ERROR OCCURED");
    }
    else
    {
     while(fread(&pt,sizeof(struct patient),1,fptr))
    {
                    printf("\t\t\t\tDISPLAYING PATIENT NO %d DATA\n",i+1);
printf("=====================================================================================================================\n\n");
            printf("\t\t\t\tID OF THE PATIENT: %d\n",pt.ID);
            fflush(stdin);
            printf("\t\t\t\tNAME OF THE PATIENT:%s\n",pt.Name);
            fflush(stdin);
            printf("\t\t\t\tCNIC OF THE PATIENT:");
            for(index=0;index<13;index++)
            {
                printf("%c",pt.CNIC[index]);
            }
            index=0;
            printf("\n\t\t\t\tPHONE NUMBER OF THE PATIENT: ");
            for(index=0;index<11;index++)
            {
                printf("%c",pt.PHONE_NUMBER[index]);
            }
            fflush(stdin);
            printf("\n\t\t\t\tDISEASE OF THE PATIENT: %s\n\n\n",pt.disease);
            fflush(stdin);
printf("=====================================================================================================================\n");

        i++;
    }
    sleep(2);
    fclose(fptr);
    system("cls");
    system("cls");
    }
}
#endif
