/*
 ============================================================================
 Name        : TP2Szellner.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 10
#define TAMSEC 5

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int respuesta;
	    int legajo=20000;
	    char salir;
	    eSector sectores[TAMSEC]= {{500, "Sistemas"},{501, "Legales"},{502, "RRHH"}, {503, "Contable"}, {504,"ventas"}};
	    eEmployee nomina[TAM];
	    initEmployees(nomina,TAM);
	    harcodearEmpleados(nomina, TAM, 10, &legajo);

	    do
	    {
	        respuesta=menu();
	        switch(respuesta)
	        {
	        case 1:
	            system("cls");
	            if(altaEmpleado(nomina, TAM, &legajo, sectores,TAMSEC))
	            {
	                printf("Alta exitosa\n");
	            }
	            else
	            {
	                printf("Hubo un problema\n");
	            }
	            break;

	        case 2:
	            if(listaVacia(nomina, TAM)==-1)
	            {
	                printf("No hay ningun empleado ingresado\n");
	                printf("Primero ingrese un empleado\n");
	            }
	            else
	            {
	                modificarEmpleado(nomina, TAM, sectores,TAMSEC);
	            }
	            break;

	        case 3:
	            if(listaVacia(nomina, TAM)==-1)
	            {
	                printf("No hay ningun empleado ingresado\n");
	                printf("Primero ingrese un empleado\n");
	            }
	            else
	            {
	                bajaEmpleado(nomina, TAM, sectores, TAMSEC);
	            }
	            break;

	        case 4:
	            system("cls");
	            char respuestaMenu='n';
	            do
	            {

	                int respuestaInformes;
	                printf("***Informes*** \n\n");
	                printf("1) Listar empleados \n");
	                printf("2) Total y promedios de salarios\n");
	                printf("3) Volver\n");
	                fflush(stdin);
	                scanf("%d", &respuestaInformes);
	                switch(respuestaInformes)
	                {
	                case 1:
	                    if(listaVacia(nomina, TAM)==-1)
	                    {
	                        printf("No hay ningun empleado ingresado\n");
	                        printf("Primero ingrese un empleado\n");
	                    }
	                    else
	                    {
	                        sortEmployees(nomina, TAM,1);
	                        printEmployees(nomina, TAM, sectores, TAMSEC);
	                    }
	                    break;

	                case 2:
	                    if(listaVacia(nomina, TAM)==-1)
	                    {
	                        printf("No hay ningun empleado ingresado\n");
	                        printf("Primero ingrese un empleado\n");
	                    }
	                    else
	                    {
	                        informesSueldos(nomina, TAM);
	                    }
	                    break;

	                case 3:
	                    printf("Seguro desea volver?\n");
	                    fflush(stdin);
	                    respuestaMenu = getchar();
	                    break;

	                default:
	                    printf("Opcion incorrecta!\n");
	                }
	                system("pause");
	                system("cls");
	            }
	            while(respuestaMenu=='n');
	            break;

	        case 5:
	            printf("Seguro desea salir?\n");
	            fflush(stdin);
	            salir = getchar();
	            break;

	        case 6:
	            printEmployees(nomina, TAM, sectores, TAMSEC);
	            break;


	        default:
	            printf("Opcion incorrecta!\n");
	        }
	        system("pause");
	        fflush(stdin);
	        system("cls");

	    }
	    while(salir != 's');
	    printf("Gracias por usar mi programa");
	return EXIT_SUCCESS;
}
