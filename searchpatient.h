#ifndef SEARCHPATIENT_H
#define SEARCHPATIENT_H
#include "struct.h"
void search_patient()
{
    system("cls");
    struct patient pt;
    FILE *fptr;
    fptr=fopen("patient_record.txt","ab+");
    if(fptr==NULL)
    {
        printf("File does not exists");
        
    }
    else
    {
    int tempID,flag=0,check=0,index=0;
    printf("Enter the ID of the patient you want to search: ");
    scanf("%d",&tempID);
    if(tempID<0)
    {
        printf("NOT A VALID ID");
        return;
    }
    check=checkid(tempID);
    if(check==0)
    {
        printf("Patient does not exists");
        return;
    }
    while(fread(&pt,sizeof(struct patient),1,fptr)>0&&flag==0)
    {
        if(pt.ID==tempID)
        {
            flag=1;
            printf("\t\t\t\tPATIENT FOUND SUCCESSFULLY!!\n");
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
        }

    }
    if(flag==0)
    {
            printf("No record found!!");
    }    
    fclose(fptr);
}
}
#endif

