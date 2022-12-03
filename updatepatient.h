#ifndef UPDATEPATIENT_H
#define UPDATEPATIENT_H
#include "struct.h"
void update_patient()
{
    system("cls");
    struct patient pt;
    int id,check,index=0;
    FILE *fptr;
    fptr=fopen("patient_record.txt","rb+");
    if(fptr==NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
    printf("Enter ID of the patient you want to update: ");
    scanf("%d",&id);
    if(id<0)
    {
        printf("NOT A VALID ID");
        return;
    }
    check=checkid(id);
    if(check==0)
    {
        printf("No such patient exists");
        return;
    }

    while(fread(&pt,sizeof(struct patient),1,fptr))
    {
        if(id==pt.ID)
        {
        printf("\t\t\t\ORIGINAL DATA\n");
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
            printf("NOW UPDATE THE DATA\n");
            printf("Enter ID of the patient: ");
            scanf("%d",&pt.ID);
            fflush(stdin);
            if(pt.ID<0)
            {
                printf("NOT A VALID ID");
                return;
            }
            printf("Enter name of the patient: ");
            gets(pt.Name);
            printf("Enter CNIC without Dash: ");
            gets(pt.CNIC);
            printf("Enter Phone number of the patient: ");
            gets(pt.PHONE_NUMBER);
            printf("Enter name of the disease: ");
            scanf("%s",&pt.disease);
            fseek(fptr,-(long)sizeof(struct patient),1);
            fwrite(&pt,sizeof(struct patient),1,fptr);
            printf("RECORD UPDATED SUCCESSFULLY");
            fflush(fptr);
        }
    }
   fclose(fptr);
}
}
#endif
