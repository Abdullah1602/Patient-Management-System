#ifndef DELETEPATIENT_H
#define DELETEPATIENT_H
void delete_patient()
{
    system("cls");
    struct patient pt;
    int id,check_ID=0;
    FILE *fptr,*fptr2;
    printf("Enter the ID of the patient you want to delete: ");
    scanf("%d",&id);
    if(id<0)
    {
        printf("NOT A VALID ID");
        return;
    }
    check_ID=checkid(id);
    fptr=fopen("patient_record.txt","ab+");
    if(fptr==NULL)
    {
        printf("ERROR OCCURED");
    }
    else
    {
        if(check_ID==0)
    {
        printf("Patient does not exist");
        return;
    }
    fptr2=fopen("sample.txt","wb");
    if(fptr2==NULL)
    {
        printf("ERROR OCCURED");
    }
    else
    {
        while(fread(&pt,sizeof(struct patient),1,fptr))
    {
        if(pt.ID!=id)
        {
            fwrite(&pt,sizeof(struct patient),1,fptr2);
        }
    }
    fclose(fptr);
    fclose(fptr2);
    remove("patient_record.txt");
    rename("sample.txt","patient_record.txt");
    printf("RECORD HAS BEEN DELETED SUCCESSFULLY");

    }

}
}
#endif
