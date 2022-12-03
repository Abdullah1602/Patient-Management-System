#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include "struct.h"
void add_patient()
{
    system("cls");
	struct patient pt;
    int check_ID,temp_ID;
    FILE *fptr;
    fptr=fopen("patient_record.txt","ab+");
    if(fptr==NULL)
    {
        printf("ERROR OCCURED");
    }
    else
    {
        printf("Enter ID of the patient: ");
        scanf("%d",&pt.ID);
        if(pt.ID<0)
        {
            printf("NOT A VALID ID");
            return;
        }
        fflush(stdin);
        temp_ID=pt.ID;
        check_ID=checkid(temp_ID);
        if(check_ID==1)
        {
            printf("Patient is already admitted");
            return;
        }
        printf("Enter name of the patient: ");
        gets(pt.Name);
        printf("Enter CNIC without Dash: ");
        gets(pt.CNIC);
        fflush(stdin);
        printf("Enter Phone number of the patient: ");
        gets(pt.PHONE_NUMBER);
        fflush(stdin);
        printf("Enter name of the disease: ");
        scanf("%s",&pt.disease);
        fflush(stdin);
        fwrite(&pt,sizeof(struct patient),1,fptr);
        printf("RECORD ADDED SUCCESSFULLY");
        fclose(fptr);
    }

}
#endif // ADDPATIENT_H
