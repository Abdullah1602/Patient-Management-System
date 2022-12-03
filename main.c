#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "addpatient.h"
#include "deletepatient.h"
#include "checkid.h"
#include "updatepatient.h"
#include "searchpatient.h"
#include "displaypatient.h"
int introduction ();
void add_patient();
void delete_pateint();
void update_patient();
void search_patient();
void all_patients();
int checkid(int );
int main()
{
    int flag=1;
    do
    {
      int intro=introduction();
      switch (intro)
        {
        case 1:
            add_patient();
            sleep(3);
            system("cls");
            break;
        case 2:
            delete_patient();
            sleep(3);
            system("cls");
            break;
        case 3:
           update_patient();
           sleep(3);
            system("cls");
            break;
        case 4:
            search_patient();
            sleep(3);
            system("cls");
            break;
        case 5:
            all_patients();
            break;
        case 6:
            flag=0;
            break;
        default:
            printf("Enter choice again");
            sleep(2);
            system("cls");
        }
    } while (flag==1);
}
int introduction()
{
  int choice=0;
  printf("\n\n\n\n\n\n");
  printf("\t\t**************************************************************************\n");
  printf("\t\t*                   1-Add patient                                        *\n");
  printf("\t\t*                   2-Delete Patient                                     *\n");
  printf("\t\t*                   3-Update patient                                     *\n");
  printf("\t\t*                   4-Search Patient                                     *\n");
  printf("\t\t*                   5-Display all patient                                *\n");
  printf("\t\t*                   6-Close the program                                  *\n");
  printf("\t\t**************************************************************************\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);
  system("cls");
  return choice;
}
