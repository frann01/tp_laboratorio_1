/*
 ============================================================================
 Name        : calculadoraSzellnerTp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "szellner.h"
#include <ctype.h>


int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
    float numero1=EOF;
    float numero2=EOF;
    char respuesta;
    int banderaNum1=0;
    int banderaNum2=0;
    int banderaResultados=0;
    float sumaRes;
    float restaRes;
    float divisionRes;
    float multiplicacionRes;
    float factorA;
    float factorB;

    do
    {
        respuesta=menu(numero1, numero2);
        validarChar(respuesta, &respuesta);
        switch(respuesta)
            {
            case '1':
            	validarNum(&numero1, "Ingrese el primer numero: \n", "Error! Ingrese un numero: \n");
            	banderaNum1=1;
            	break;

            case '2':
                if(banderaNum1==0)
            	  {
            	      printf("\nPrimero ingrese el primer operando\n\n");
            	  }
            	  else
            	   	   {
            	            validarNum(&numero2, "Ingrese el segundo numero: \n", "Error! Ingrese un numero: \n");
            	       }
            	banderaNum2=1;
                break;

            case '3':
                if(banderaNum1==0 || banderaNum2==0)
                    {
                        printf("\nPrimero ingrese todos los numeros\n\n");

                    }
                    else
                        {
                            printf("Se realizaron las operaciones\n\n");
                            sumaRes= sumar(numero1, numero2);
                            restaRes= restar(numero1, numero2);
                            divisionRes= dividir(numero1, numero2);
                            multiplicacionRes= multiplicar(numero1, numero2);
                            factorA= factorial(numero1);
                            factorB= factorial(numero2);
                            banderaResultados=1;
                        }
                break;

            case '4':
                if(banderaResultados==0)
                    {
                        printf("\nPrimero debe realizar las operaciones\n\n");
                    }
                    else
                        {
                            mostrarResultados(sumaRes, restaRes, divisionRes, multiplicacionRes, factorA, factorB, numero1, numero2);
                        }
                break;

            case '5':
                printf("\nEsta seguro que quiere salir?\n\n");
                fflush(stdin);
                respuesta = getchar();
                break;

            }

        	getchar();  // lo utilizo como un system("pause")
        	fflush(stdin);
            system("cls");

    }while(respuesta != 's');
    printf("***Gracias por usar la calculadora de Francisco Szellner***");
    return 0;
}



