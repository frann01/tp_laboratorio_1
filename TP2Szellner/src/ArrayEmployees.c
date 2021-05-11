/*
 * ArrayEmployees.c
 *
 *  Created on: 11 may. 2021
 *      Author: USUARIO
 */

#include "ArrayEmployees.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief muestra un sector en particular
 *
 * \param sector eSector  array de todos los sectores
 * \return void
 *
 */
void mostrarSector(eSector sector)
{
    printf("%d     %s\n", sector.id, sector.descripcion);
}
/** \brief Muestra todos los sectores encolumnados
 *
 * \param sectores[] eSector array de todos los sectores
 * \param tam int tamaño del array
 * \return void
 *
 */
void mostrarSectores(eSector sectores[],int tam)
{
    printf("ID     Sector\n");
    printf("---------------\n");
    for(int i=0; i<tam; i++)
    {
        mostrarSector(sectores[i]);
    }
}
/** \brief Inicializa todos los isEmpty de los empleados del array en O
 *
 * \param list[] eEmployee arrary de empleados
 * \param len int tamaño del array
 * \return int devuelce -1 si hubo un error y 0 si no
 *
 */
int initEmployees(eEmployee list[], int len)
{
    int todoOk=-1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 0;
            todoOk=0;
        }
    }
    return todoOk;
}

/** \brief Revisa un array y chequea si hay lugar libre
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \return int develve el indice del espacio libre o -1 si hay un error
 *
 */
int hayLugar(eEmployee lista[], int tam)
{
    int bandera=-1;
    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty==0)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}

/** \brief chequea que el array no este vacio
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \return int devuelve el indice o -1 si hay error
 *
 */
int listaVacia(eEmployee lista[], int tam)
{
    int bandera=-1;
    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty==1)
        {
            bandera=i;
            break;
        }
    }
    return bandera;
}


/** \brief Presenta el Menu
 *
 * \return int devuelve la opcion seleccionada
 *
 */
int menu()
{
    int respuesta;
    printf("***ABM Empleados*** \n\n");
    printf("1) Alta empleado\n");
    printf("2) Modificar empleado \n");
    printf("3) Baja empleado\n");
    printf("4) Informar\n");
    printf("5) Salir \n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}

/** \brief Pregunta por los datos y da de alta un nuevo empleado
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param pLegajo int* direccion del legajo para asignar
 * \param sectores[] eSector array de sectores
 * \param TamSec int tamaño del array de los sectores
 * \return int devuelve -1 si hay un error
 *
 */
int altaEmpleado(eEmployee lista[], int tam, int* pLegajo, eSector sectores[], int TamSec)
{
    int todoOk = 0;
    eEmployee aux;
    if(lista != NULL && tam > 0 && pLegajo !=NULL )
    {
        printf("***Alta empleado***\n");
        printf("Legajo: %d\n", *pLegajo);
        int indice = hayLugar(lista,tam);
        if(indice!=-1)
        {

            printf("Ingrese el nombre: \n");
            fflush(stdin);
            gets(aux.Name);

            printf("Ingrese el apellido: \n");
            fflush(stdin);
            gets(aux.lastName);

            printf("Ingrese el sueldo: \n");
            fflush(stdin);
            scanf("%f",&aux.salary);

            mostrarSectores(sectores, TamSec);
            printf("Ingrese el ID del sector: \n");
            fflush(stdin);
            scanf("%d",&aux.sectorId);
            while(aux.sectorId<500 || aux.sectorId>504)
            {
                printf("Error! Ingrese un sector correcto: \n");
                fflush(stdin);
                scanf("%d",&aux.sectorId);
            }

            aux.id = *pLegajo;
            (*pLegajo) +=1;
            addEmployees(lista, tam, aux.id, aux.Name,aux.lastName,aux.salary, aux.sectorId);

            todoOk=1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }
    return todoOk;
}
/** \brief Asignan los datos al espacio vacio en el array
 *
 * \param list[] eEmployee array de los empleados
 * \param len int tamaño del array
 * \param id int id a asignar
 * \param name[] char nombre a asignar
 * \param lastName[] char apellido a asignar
 * \param salary float salario a asignar
 * \param sector int sector a asignar
 * \return int devuelve -1 si hay un error
 *
 */
int addEmployees(eEmployee list[], int len, int id, char name[],char lastName[],float salary, int sector)
{
    int todoOk=-1;
    if(list!= NULL && len>0&& name!=NULL&&lastName!=NULL)
    {
        int indice = hayLugar(list,len);
        list[indice].id = id;
        strcpy(list[indice].Name, name);
        strcpy(list[indice].lastName, lastName);
        list[indice].salary = salary;
        list[indice].sectorId = sector;
        list[indice].isEmpty = 1;
        todoOk=0;
    }
    return todoOk;
}


/** \brief Carga el nombre de un sector en una variable
 *
 * \param id int id del sector buscado
 * \param sectores[] eSector array de sectores
 * \param tam int tamaño del array
 * \param desc[] char variable para asignar el nombre
 * \return int devuelve -1 si hay un error
 *
 */
int cargarDecripcionSector(int id, eSector sectores[],int tam, char desc[])
{
    int todoOk =1;

    if(id>=500 && id<=504 && sectores != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(sectores[i].id==id)
            {
                strcpy(desc, sectores[i].descripcion);
                todoOk=0;
                break;
            }
        }
    }
    return todoOk;
}

/** \brief muestra un empleado en particular
 *
 * \param chabon eEmployee empleado a mostrar
 * \param sectores[] eSector array de sectores
 * \param tamSec int tamaño del array
 * \return void
 *
 */
void mostraEmpleado(eEmployee chabon, eSector sectores[], int tamSec)
{
    char descripcion[20];
    if(cargarDecripcionSector(chabon.sectorId, sectores, tamSec, descripcion)==0)
    {
        printf(" %4d%10s %10s      %8.1f    %7s  \n"
               ,chabon.id
               ,chabon.Name
               ,chabon.lastName
               ,chabon.salary
               ,descripcion);
    }
    else
    {
        printf("Hubo un problema\n");
    }
}


/** \brief muestra los empleados encolumnados
 *
 * \param list[] eEmployee array de empleados
 * \param len int tamaño del array
 * \param sectores[] eSector array de sectores
 * \param tamSec int tamaño del array de sectores
 * \return int devuelve -1 si hay un error
 *
 */
int printEmployees(eEmployee list[], int len, eSector sectores[], int tamSec)
{
    int todoOk=-1;
    int banderaNinguno=0;
    if(list != NULL && len > 0)
    {
        printf("Legajo    Nombre    Apellido       Sueldo      Sector     \n");
        printf("---------------------------------------------------- \n");

        for(int i = 0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                mostraEmpleado(list[i], sectores, tamSec);
                todoOk=0;
                banderaNinguno=1;
            }
        }
        if(banderaNinguno==0)
        {
            printf("\n     No hay ningun empleado!\n");
            todoOk=0;
        }

        printf("\n");
    }
    return todoOk;
}

/** \brief Busca un empleado segun su ID
 *
 * \param list[] eEmployee array de empleados
 * \param len int tamaños del array
 * \param id int ID para buscar
 * \return int devuelve el indice donde esta el empleado
 *
 */
int findEmployeeByID(eEmployee list[], int len, int id)
{
    int bandera=-1;
    for(int i = 0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty==1)
        {
            bandera=i;
//            mostraEmpleado(lista[i], sectores, 5);
            break;
        }
    }
    return bandera;
}

/** \brief Modifica los datos de un empleado
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param sectores[] eSector array de sectores
 * \param tamSec int tamaños del array
 * \return void
 *
 */
void modificarEmpleado(eEmployee lista[], int tam, eSector sectores[],int tamSec)
{
    int opcionLegajo; //legajo
    int empleadoAModificar; //posicion del empleado
    int datoAModificar;
    char salir='s';
    eEmployee aux;
    printf("Modificar empleado\n");
    printEmployees(lista, tam, sectores,tamSec);
    printf("Ingrese el legajo de usuario: \n");
    fflush(stdin);
    scanf("%d", &opcionLegajo);

    empleadoAModificar = findEmployeeByID(lista, tam, opcionLegajo);
    aux = lista[empleadoAModificar];
    system("cls");


    do
    {
        printf("Que dato desea modificar? \n");
        printf("1) Nombre \n");
        printf("2) Apellido\n");
        printf("3) Sueldo \n");
        printf("4) Sector \n");
        fflush(stdin);
        scanf("%d", &datoAModificar);
        system("cls");

        switch(datoAModificar)
        {
        case 1:
            printf("Cambiar Nombre \n");
            printf("Ingrese el nombre: \n");
            fflush(stdin);
            gets(aux.Name);
            break;

        case 2:
            printf("Cambiar Apellido \n");
            printf("Ingrese el apellido: \n");
            fflush(stdin);
            gets(aux.lastName);
            break;

        case 3:
            printf("Cambiar Sueldo \n");
            printf("Ingrese el sueldo: \n");
            fflush(stdin);
            scanf("%f",&aux.salary);
            break;

        case 4:
            printf("Cambiar Sector \n");
            mostrarSectores(sectores, tamSec);
            printf("Ingrese el ID del sector nuevo: \n");
            fflush(stdin);
            scanf("%d",&aux.sectorId);
            while(aux.sectorId<500 || aux.sectorId>504)
            {
                printf("Error! Ingrese un sector correcto: \n");
                fflush(stdin);
                scanf("%d",&aux.sectorId);
            }
            break;


        default:
            printf("Opcion incorrecta!\n");
        }

        printf("Quiere cambiar otro dato?s/n\n");
        fflush(stdin);
        salir = getchar();
        system("cls");
    }
    while(salir != 'n');
    printf("Desea guardar los datos?\n");
    fflush(stdin);
    scanf("%c", &salir);

    if(salir=='s')
    {
        lista[empleadoAModificar] = aux;
    }
    else
    {
        printf("Cambios eliminados\n");
    }

}
/** \brief Cambia el valos isEmpty de un empleado a verdadero
 *
 * \param list[] eEmployee array der empleados
 * \param len int tamaños del array
 * \param id int Id del empleado a borrar
 * \return int devuelve -1 si hubo un error
 *
 */
int removeEmployee(eEmployee list[], int len, int id)
{
    int todoOk=-1;
    if(list!= NULL && len>0)
    {
        list[id].isEmpty=0;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Permite dar de baja a un empleado
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param sectores[] eSector array de sectores
 * \param tamSec int tamaños del array
 * \return int devuelve 1 si hubo un error
 *
 */
int bajaEmpleado(eEmployee lista[], int tam, eSector sectores[], int tamSec)
{
    int todoOk=1;
    int opcionLegajo;
    int empleadoABaja;
    char resBaja;
    printf("Baja empleado\n");
    printEmployees(lista, tam, sectores, tamSec);
    printf("Ingrese el legajo de usuario: \n");
    fflush(stdin);
    scanf("%d", &opcionLegajo);
    while(findEmployeeByID(lista, tam, opcionLegajo)==-1)
    {
        printf("No hay ningun empleado con este legajo %d \n", opcionLegajo);
        printf("Ingrese un legajo correcto\n");
        fflush(stdin);
        scanf("%d", &opcionLegajo);
    }
    empleadoABaja = findEmployeeByID(lista, tam, opcionLegajo);

    printf("Seguro desea dar de baja a este empleado? s/n \n");
    fflush(stdin);
    scanf("%c", &resBaja);

    if(resBaja=='s')
    {
        removeEmployee(lista, tam, empleadoABaja);
        printf("Baja exitosa\n");
    }
    else
    {
        printf("Baja cancelada\n");
    }
    return todoOk;
}

/** \brief Ordena mlos empleados por sector y por apellido
 *
 * \param list[] eEmployee array de empleados a ordenar
 * \param len int tamaños del array
 * \param order int Valor para saber si hay que ordenarlo de manera ascendiete o descendiente
 * \return int devuelve -1 si hay un error
 *
 */
int sortEmployees(eEmployee list[], int len, int order)
{
    eEmployee aux;
    int todoOk=-1;
    if(list != NULL && len>0 && (order==1 || order==0))
    {
        todoOk=0;
        if(order==0)
        {
            for(int i=0; i< len-1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(list[i].sectorId < list[j].sectorId || (list[i].sectorId == list[j].sectorId && strcmp(list[i].lastName, list[j].lastName)> 0))
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
        }
        else
        {
            for(int i=0; i< len-1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(list[i].sectorId < list[j].sectorId || (list[i].sectorId == list[j].sectorId && strcmp(list[i].lastName, list[j].lastName)< 0))
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
        }

    }
    return todoOk;
}


/** \brief Da un informe sobre el total y promedio de los sueldos
 *
 * \param list[] eEmployee array de empleados
 * \param len int tamaño del array
 * \return int devuelce -1 si hay un error
 *
 */
int informesSueldos(eEmployee list[], int len)
{
    float acumulador=0;
    int contadorEmpleados=0;
    float promedio;
    int sueldoMayorPromedio=0;
    int todoOk=-1;
    if(list != NULL && len>0)
    {
        todoOk=0;
        for(int i=0; i< len; i++)
        {
            if(list[i].isEmpty==1)
            {
                acumulador = list[i].salary+acumulador;
                contadorEmpleados++;
            }
        }

        promedio = acumulador/contadorEmpleados;

        for(int i=0; i< len; i++)
        {
            if(list[i].salary>= promedio)
            {
                sueldoMayorPromedio++;
            }
        }
        printf(" Total            Promedio       Empleados que superan el promedio de sueldo\n");
        printf("-------------------------------------------------------------------\n");
        printf("%8.2f           %8.2f                            %d\n", acumulador,promedio, sueldoMayorPromedio);


    }
    return todoOk;
}

/** \brief Harcodea empleados principalmente para testear
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaños del array
 * \param cant int cantidad de empleados a hardcodear
 * \param pLegajo int* direccion del legajo para asignarle a los empleados
 * \return int devuelver 0 si hubo un error
 *
 */
int harcodearEmpleados(eEmployee lista[], int tam, int cant,int* pLegajo)
{
    int todoOk=0;
    int cantidad=0;
    if(lista != NULL && tam > 0 && cant > 0 && pLegajo !=NULL )
    {
        for(int i = 0; i<cant; i++)
        {
            lista[i].id = *pLegajo;
            (*pLegajo)++;
            strcpy(lista[i].Name, nombres[i]);
            strcpy(lista[i].lastName, apellidos[i]);
            lista[i].salary = sueldos[i];
            lista[i].sectorId = sector[i];
            lista[i].isEmpty=1;
            cantidad++;
        }
    }
    else
    {
        todoOk=1;
    }
    return todoOk;
}
