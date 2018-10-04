#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define CANT 4


int main()
{
    int opcion=0;

    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int contador=0;
    int order=0;


    Employee employee[CANT];
    initEmployees(employee,CANT);

    do
    {

        switch(menu())
        {
            case 1:
                if(addEmployee(employee,CANT,employee[CANT].id,name, lastName, salary, sector))
                {
                    contador++;
                }
                system("pause");
                break;
            case 2:
                if(contador==0)
                {
                    printf("There is no employee loaded in the system");
                }
                else
                {
                     modifyEmployee(employee,CANT,employee[CANT].id);
                }
                system("pause");
                break;
            case 3:
                if(contador==0)
                {
                    printf("There is no employee loaded in the system");
                }
                else
                {
                     removeEmployee(employee,CANT,employee[CANT].id);
                }
                system("pause");
                break;
            case 4:
                if(contador==0)
                {
                    printf("There is no employee loaded in the system");
                }
                else
                {
                    sortEmployees(employee,CANT,order);
                }
                system("pause");
                break;
            case 5:
                printf("Leaving the program\n\n");
                opcion=5;
                system("pause");
                break;
            default:
                printf("Wrong option");
                system("pause");
        }
    }while(opcion!=5);

    return 0;
}
