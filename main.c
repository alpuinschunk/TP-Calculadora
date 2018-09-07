#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
int main()
{
    float nro1, nro2, suma, resta, multiplicacion, division;
    int opcion, factorialNro1, factorialNro2, contNro1, contNro2, contCase3;
    contNro1=0;
    contNro2=0;
    contCase3=0;
    nro1=0;
    nro2=0;

    do
    {
        system("cls");
        printf("\tCALCULADORA\n\n");
        printf("Menu");
        printf("\n\n1. Ingresar 1er operando A= %.2f", nro1);
        printf("\n\n2. Ingresar 2do operando B= %.2f", nro2);

        printf("\n\n3. Calcular todas las operaciones");
        printf("\na) Suma (A+B)");
        printf("\nb) Resta (A-B)");
        printf("\nc) Division (A/B)");
        printf("\nd) Multiplicacion (A*B)");
        printf("\ne) Factorial (A!) y (B!)");

        printf("\n\n4. Informar resultados");
        printf("\n\n5. Salir");

        printf("\n\nSeleccione una opcion: ");
        scanf("%d",&opcion);


        switch(opcion)
        {

            case 1://ingresa 1er numero
                printf("\nIngresar primer operando ");
                scanf("%f",&nro1);
                contNro1++;
                break;


            case 2://ingresa 2do numero
                printf("\nIngresar segundo operando ");
                scanf("%f",&nro2);
                contNro2++;
                break;

            case 3://operaciones

                suma=sumar(nro1,nro2);
                resta=restar(nro1,nro2);
                division= dividir(nro1,nro2);
                multiplicacion=multiplicar(nro1,nro2);
                factorialNro1=factorearNro1(nro1);
                factorialNro2=factorearNro2(nro2);
                contCase3++;
                printf("\nRealizando operaciones...\n\n");
                break;

            case 4://respuestas
                if(contNro1==0||contNro2==0||contCase3==0)
                {
                    printf("\nNo se puede calcular\n");
                }
                else
                {
                    printf("\nEl resultado de la suma es: %.2f",suma);
                    printf("\nEl resultado de la resta es: %.2f",resta);
                    if(nro2==0)
                    {
                        printf("\nEl resultado de la resta es: No se puede dividir por 0");
                    }
                    else
                    {
                    printf("\nEl resultado de la division es: %.2f",division);
                    }
                    printf("\nEl resultado de la multiplicacion es: %.2f",multiplicacion);
                    if(nro1<0)
                    {
                        printf("\nEl factorial de A es: Un numero negativo no tiene factorial");
                    }
                    else
                    {
                        printf("\nEl factorial de A es: %d",factorialNro1);
                    }
                    if(nro2<0)
                    {
                        printf("\nEl factorial de B es: Un numero negativo no tiene factorial\n\n");
                    }
                    else
                    {
                        printf("El factorial de B es: %d\n\n",factorialNro2);
                    }
                }
                nro1=0;
                nro2=0;
                break;
            case 5://salir de la calculadora
                printf("\nGracias por usar la calculadora\n");
                break;
            default:
                printf("\nLa opcion elegida es incorrecta");

        }
        system("pause");
        system("cls");
    }while(opcion!=5);


    return 0;
}
