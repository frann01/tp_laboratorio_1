#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
    int option = 0;
    char salir='n';
    int contador;
    int IDasignar=-1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No hay espacio en la memoria del sistema");
        system("pause");
        exit(1);
    }

    do
    {
        contador =ll_len(listaEmpleados);
        printf("***ABM Empleados*** \n");
        printf("Empleados cargados: %d\n\n",contador);
        IDasignar=idMasAlto(listaEmpleados)+1;
        option = menu();
        switch(option)
        {
        case 1:
            contador = controller_loadFromText("data.csv", listaEmpleados);
            if(contador > 0)
            {
                printf("Se cargaron %d Empleados desde el archivo de texto\n", contador);
            }
            else
            {
                printf("No se puede cargar Empleados \n");
            }

            break;
        case 2:
            contador = controller_loadFromBinary("datos.bin",listaEmpleados);
            if(contador > 0)
            {
                printf("Se cargaron %d Empleados desde el archivo binario\n", contador);
            }
            else
            {
                printf("No se puede cargar Empleados\n");
            }
            break;

        case 3:
            controller_addEmployee(listaEmpleados, &IDasignar);
            break;

        case 4:
            if(contador==0)
            {
                printf("No hay empleados cargados\n");
            }
            else
            {
                controller_editEmployee(listaEmpleados);
            }

            break;

        case 5:
            if(contador==0)
            {
                printf("No hay empleados cargados\n");
            }
            else
            {
                if(controller_removeEmployee(listaEmpleados)==1)
                {
                    printf("Se elimino el empleado\n");
                }
                else
                {
                    printf("No se elimino el empleado\n");
                }
            }
            break;

        case 6:
            if(contador==0)
            {
                printf("No hay empleados cargados\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }
            break;

        case 7:
            if(contador==0)
            {
                printf("No hay empleados cargados\n");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
            }
            break;

        case 8:
            if(!controller_saveAsText("data.csv", listaEmpleados))
            {
                printf("No se guardo el archivo\n");
            }
            else
            {
                printf("El archivo fue guardado correctamente\n");
            }
            break;

        case 9:
            if(!controller_saveAsBinary("datos.bin", listaEmpleados))
            {
                printf("No se guardo el archivo\n");
            }
            else
            {
                printf("El archivo fue guardado correctamente\n");
            }
            break;


        case 10:
            printf("Seguro desea salir?\n");
            fflush(stdin);
            salir = getchar();
            while(validarSN(salir)==-1)
            {
                printf("Por favor ingrese s/n\n");
                fflush(stdin);
                scanf("%c", &salir);
            }
            break;

        default:
            printf("Opcion incorrecta!\n");

        }
        system("pause");
        system("cls");
    }
    while(salir != 's');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

