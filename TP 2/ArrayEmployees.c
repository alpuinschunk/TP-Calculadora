#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0


static int generarNextId()
{
    static int id=-1;
    id++;
    return id;
}

int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=0;

    if(list==NULL)
    {
       if(len<=0)
       {
           retorno = -1;
       }
    }
    for(i=0; i<len; i++)
    {
        list[i].isEmpty = TRUE;
    }

    return retorno;
}


int getFreeSpace(Employee list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    Employee employee;
    int retorno= -1;
    int found;




        found = getFreeSpace(list,len);
        if(found != -1)
        {

            printf("Enter name: ");
            fflush(stdin);
            gets(employee.name);

            printf("Enter lastname: ");
            fflush(stdin);
            gets(employee.lastName);

            printf("Enter salary: ");
            scanf("%f",&employee.salary);

            printf("Enter sector: ");
            scanf("%d",&employee.sector);

            employee.id=generarNextId();
            employee.isEmpty=FALSE;



            list[found]=employee;
        }
        else
        {
            printf("There is not enough space\n\n");
        }

    return retorno;
}

int printEmployees(Employee* list, int length)
{
     for(int i=0; i<length;i++)
    {
        if(!list[i].isEmpty)
        {
            printf("Id: %d Name: %s Lastname: %s Salary: %f Sector: %d\n\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}

int findEmployeeById(Employee* list, int len,int id)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            return i;
            break;
        }
    }
    return -1;
}

void printEmployee(Employee list)
{
    printf("Id: %d Name: %s Lastname: %s Salary: %.2f Sector: %d\n\n",list.id,list.name,list.lastName,list.salary,list.sector);
}

int menu()
{
    int opcion=0;
    system("cls");
    printf("--MENU--\n\n");
    printf("1- HIGH\n");
    printf("2- MODIFY\n");
    printf("3- LOW\n");
    printf("4- SORT\n");
    printf("5- EXIT\n\n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int removeEmployee(Employee* list, int len, int id)
{
    int found;
    char remove;

    printf("Enter the ID you want to delete\n");
    scanf("%d",&id);

        found=findEmployeeById(list,len,id);

        if(found <0)
        {
            printf("User not found\n");
        }
        else
        {
            printEmployee(list[found]);
            printf("Are you sure you want to delete this user? s/n\n");
            fflush(stdin);
            scanf("%c",&remove);

            if(remove=='s')
            {
                list[found].isEmpty=TRUE;
                printf("User delete\n\n");
            }
            else
            {
                printf("Cancelled\n\n");
            }
        }


    return -1;
}
int modifyEmployee(Employee* list, int len, int id)
{
    int found;
    char modify;

    printf("Enter the ID you want to modify\n");
    scanf("%d",&id);

    found=findEmployeeById(list,len,id);

    if(found == -1)
        {
            printf("User not found\n");
        }
        else
        {
            printEmployee(list[found]);

            printf("Do you want to modify this user? s/n\n");
            fflush(stdin);
            scanf("%c",&modify);

            if(modify=='s')
            {
                int opcion=0;
                printf("--MENU--\n\n");
                printf("1- Name\n");
                printf("2- Lastname\n");
                printf("3- Salary\n");
                printf("4- Sector\n");
                printf("5- Exit\n\n");
                fflush(stdin);
                scanf("%d",&opcion);

                switch(opcion)
                {
                    case 1:
                        printf("Enter new name: \n");
                        fflush(stdin);
                        gets(list[found].name);
                        break;
                    case 2:
                        printf("Enter new lastname: \n");
                        fflush(stdin);
                        gets(list[found].lastName);
                        break;
                    case 3:
                        printf("Enter new salary: \n");
                        scanf("%f",&list[found].salary);
                        break;
                    case 4:
                        printf("Enter new sector: \n");
                        scanf("%d",&list[found].sector);
                        break;
                    case 5:
                        opcion=5;
                        break;
                    default:
                        printf("Wrong option: \n");
                        system("pause");
                }

            }
            else
            {
                printf("Cancelled modification\n\n");
            }
        }
    return 0;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee employee;

    printf("\n\n 1. Ordenar de manera ascendente. \n\n 2. Ordenar de manera descendente.\n\n Seleccione una opcion: ");
    fflush(stdin);
    scanf("%d",&order);

    if(order==1)///ASCENDENTE
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)<0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[j].sector>list[i].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;

                }

            }
        }
    }

    else if(order==0)
    {
        for(int i=0; i<len-1; i++) ///DESCENDENTE
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[j].sector<list[i].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
    }
    printEmployees(list,len);
    averageSalary(list,len);


    return 0;

}

int averageSalary(Employee*list,int len)
{
    float average;
    int accountant=0;
    int accountantEmployees=0;
    int sum;


    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty=TRUE)
        {
            sum=sum+list[i].salary;
            accountant++;
            average=sum/accountant;
        }
    }

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            if(list[i].salary>accountant)
            {
                accountantEmployees++;
            }
        }
    }

    printf("Total and average salaries\n\n");
    printf("Total salary: %d\n",sum);
    printf("Average salary: %d\n",accountant);
    printf("Employees that exceed the average salary: %d\n",accountantEmployees);

    return 0;
}
