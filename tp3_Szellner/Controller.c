#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "controller.h"


int getIndexByID(LinkedList* pArrayListEmployee, int id);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int counter = 0;
    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "r");
        if(file != NULL)
        {
            counter = parser_EmployeeFromText(file, pArrayListEmployee);
        }
    }

    fclose(file);
    return counter;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int contador=0;

    FILE* f = NULL;

    if(pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");

        if(f != NULL)
        {
            contador = parser_EmployeeFromBinary(f, pArrayListEmployee);
        }
    }

    return contador;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int todoOk = 0;
    char nombre[128];
    int id=0;
    int sueldo =0;
    int horas=0;
    Employee* puntero;
    if(pArrayListEmployee != NULL)
    {
        printf("***Alta empleado***\n");

        id=*pId;

        printf("Ingrese el nombre: \n");
        fflush(stdin);
        gets(nombre);
        while(strlen(nombre)>128 || validarString(nombre, strlen(nombre))==-1)
        {
            printf("Error! Ingrese un nombre valido: \n");
            fflush(stdin);
            gets(nombre);
        }

        validarNum(&sueldo, "Ingrese el sueldo: \n", "Error! Ingrese un sueldo valido: \n");

        validarNum(&horas, "Ingrese las horas trabajdas: \n", "Error! Ingrese una cantidad valida: \n");


        puntero = employee_nuevoParametros(id, nombre, horas, sueldo);

        if(puntero!=NULL && ll_add(pArrayListEmployee, (Employee*)puntero)==0)
        {
            puntero = NULL;
            todoOk=1;
            printf("El empleado fue creado con exito \n");
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk =0;
    int opcionLegajo;
    int indice;
    Employee* empleadoAModificar;
    int datoAModificar;
    char salir='s';
    Employee* aux;
    if(pArrayListEmployee!=NULL)
    {
        todoOk = 1;
        printf("***Modificar empleado***\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese el ID del empleado: \n");
        fflush(stdin);
        scanf("%d", &opcionLegajo);
        indice = getIndexByID(pArrayListEmployee,opcionLegajo);
        while(indice ==-1)
        {
            printf("Ingrese un ID valido: \n");
            fflush(stdin);
            scanf("%d", &opcionLegajo);
            indice = getIndexByID(pArrayListEmployee,opcionLegajo);
        }


        empleadoAModificar = (Employee*) ll_get(pArrayListEmployee, indice);

        aux = employee_nuevoParametros(empleadoAModificar->id, empleadoAModificar->nombre, empleadoAModificar->horasTrabajadas, empleadoAModificar->sueldo);
        system("cls");

        do
        {
            printf(" Legajo       Nombre  Sueldo  Horas Trabajadas \n");
            printf("-----------------------------------------------\n");
            mostrarEmpleado(aux);
            printf("\nQue dato desea modificar? \n");
            printf("1) Nombre \n");
            printf("2) Sueldo \n");
            printf("3) Horas trabajadas \n");
            fflush(stdin);
            scanf("%d", &datoAModificar);
            system("cls");

            switch(datoAModificar)
            {
            case 1:
                printf("Cambiar Nombre \n");
                printf("Ingrese el nombre: \n");
                fflush(stdin);
                gets(aux->nombre);
                while(strlen(aux->nombre)>128 || validarString(aux->nombre, strlen(aux->nombre))==-1)
                {
                    printf("Error! Ingrese un nombre valido: \n");
                    fflush(stdin);
                    gets(aux->nombre);
                }
                break;


            case 2:
                printf("Cambiar Sueldo \n");
                validarNum(&(aux->sueldo), "Ingrese el sueldo: \n", "Error! Ingrese un sueldo valido: \n");
                break;

            case 3:
                printf("Cambiar Horas trabajadas \n");
                validarNum(&(aux->horasTrabajadas), "Ingrese la cantidad de horas: \n", "Error! Ingrese una cantidad valida: \n");
                break;


            default:
                printf("Opcion invalida!\n");
                break;
            }

            printf("Quiere cambiar otro dato?\n");
            fflush(stdin);
            salir = getchar();
            while(validarSN(salir)==-1)
            {
                printf("Por favor infrese s/n\n");
                fflush(stdin);
                scanf("%c", &salir);
            }
            system("cls");
        }
        while(salir != 'n');
        printf("Desea guardar los datos? s/n\n");
        fflush(stdin);
        scanf("%c", &salir);
        while(validarSN(salir)==-1)
        {
            printf("Por favor infrese s/n\n");
            fflush(stdin);
            scanf("%c", &salir);
        }

        if(salir=='s')
        {
            if(ll_set(pArrayListEmployee, indice, (Employee*)aux)==0)
            {
                printf("Cambios guardados\n");
            }
        }
        else
        {
            printf("Cambios eliminados\n");
        }
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk =0;
    int opcionLegajo;
    int indice;
    Employee* empleadoAEliminar;
    char salir='s';
    Employee* aux;
    if(pArrayListEmployee!=NULL)
    {
        printf("***Eliminar empleado***\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese el legajo del empleado: \n");
        fflush(stdin);
        scanf("%d", &opcionLegajo);
        indice = getIndexByID(pArrayListEmployee,opcionLegajo);
        while(indice ==-1)
        {
            printf("Ingrese un legajo valido: \n");
            fflush(stdin);
            scanf("%d", &opcionLegajo);
            indice = getIndexByID(pArrayListEmployee,opcionLegajo);
        }

        empleadoAEliminar = (Employee*) ll_get(pArrayListEmployee, indice);
        aux = employee_nuevoParametros(empleadoAEliminar->id, empleadoAEliminar->nombre, empleadoAEliminar->horasTrabajadas, empleadoAEliminar->sueldo);
        system("cls");

        printf("Seguro desea eliminar a este empleado?\n\n");
        printf(" Legajo       Nombre  Sueldo  Horas Trabajadas \n");
        printf("-----------------------------------------------\n");
        mostrarEmpleado(aux);
        fflush(stdin);
        scanf("%c", &salir);
        while(validarSN(salir)==-1)
        {
            printf("Por favor ingrese s/n\n");
            fflush(stdin);
            scanf("%c", &salir);
        }
        system("cls");
        if(salir=='s')
        {
            if(ll_remove(pArrayListEmployee, indice)==0)
            {
                employee_delete(aux);
                aux=NULL;
                todoOk=1;
            }
        }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=1;
    int tam=0;
    Node* puntero= NULL;
    if(pArrayListEmployee!=NULL)
    {
        tam = ll_len(pArrayListEmployee);
        puntero = pArrayListEmployee->pFirstNode;
        printf(" Legajo       Nombre      Sueldo  Horas Trabajadas \n");
        printf("---------------------------------------------------\n");
        if(puntero!=NULL)
        {
            mostrarEmpleado(puntero->pElement);
            for(int i =0; i<tam-1; i++)
            {
                puntero = puntero->pNextNode;
                mostrarEmpleado(puntero->pElement);
            }
            printf("\n\n");
        }
        todoOk=0;
    }
    if(tam<1)
    {
        printf("No hay empleados cargados! \n");
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int valorParaOrdenar;
    int opcionOrdenar;
    if(pArrayListEmployee!=NULL)
    {
        todoOk=1;
        printf("Por que dato quiere ordenar a los empleados? \n");
        printf("1) ID \n");
        printf("2) Nombre\n");
        printf("3) Horas trabajadas\n");
        printf("4) Sueldo \n");
        fflush(stdin);
        scanf("%d", &valorParaOrdenar);
        system("cls");

        printf("Como quiere ordenar los empleados? \n");
        printf("0) Descendente\n");
        printf("1) Ascendente\n");
        fflush(stdin);
        scanf("%d", &opcionOrdenar);
        system("cls");

        printf("Espere un segundo \n");
        switch(valorParaOrdenar)
        {
        case 1:
            if(ll_sort(pArrayListEmployee, employee_compararID, opcionOrdenar) == 0)
            {
                printf("Empledos ordenados por ID\n");
            }
            break;

        case 2:
            if(ll_sort(pArrayListEmployee, employee_compararNombre, opcionOrdenar) == 0)
            {
                printf("Empledos ordenados por nombre\n");
            }
            break;

        case 3:
            if(ll_sort(pArrayListEmployee, employee_compararHorasTra, opcionOrdenar) == 0)
            {
                printf("Empleados ordenados por Horas trabajadas\n");
            }
            break;

        case 4:
            if(ll_sort(pArrayListEmployee, employee_compararSueldo, opcionOrdenar) == 0)
            {
                printf("Empleados ordenados por sueldo\n");
            }
            break;

        default:
            printf("Opcion invalida!\n");
        }
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;
    int retorno = 0;
    int tam;
    int i;
    char guardar;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        printf("Desea guardar los datos? Puede que se sobreescriban los archivos s/n\n");
        fflush(stdin);
        scanf("%c", &guardar);
        while(validarSN(guardar)==-1)
        {
            printf("Por favor ingrese s/n\n");
            fflush(stdin);
            scanf("%c", &guardar);
        }
        if(guardar=='s')
        {
            tam = ll_len(pArrayListEmployee);

            file = fopen(path, "w");

            if(file != NULL && tam > 0 && fprintf(file, "id,nombre,horasTrabajadas,sueldo\n") != -1)
            {
                for(i = 0; i < tam; i++)
                {
                    aux = (Employee*)ll_get(pArrayListEmployee, i);

                    if(aux == NULL || fprintf(file, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo) == -1)
                    {
                        break;
                    }
                }
            }

            if(i > 0 && i == tam)
            {
                retorno = 1;
            }
        }
        fclose(file);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;
    int retorno=0;
    int tam;
    int i;
    char guardar;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        printf("Desea guardar los datos? Puede que se sobreescriban los archivos s/n\n");
        fflush(stdin);
        scanf("%c", &guardar);
        while(validarSN(guardar)==-1)
        {
            printf("Por favor ingrese s/n\n");
            fflush(stdin);
            scanf("%c", &guardar);
        }
        if(guardar=='s')
        {
            tam = ll_len(pArrayListEmployee);

            file = fopen(path, "wb");

            if(file != NULL && tam>0)
            {
                for(i = 0; i < tam; i++)
                {
                    aux = (Employee*) ll_get(pArrayListEmployee, i);

                    if(aux == NULL || fwrite((Employee*)aux, sizeof(Employee), 1, file) != 1)
                    {
                        break;
                    }
                }
            }

            if(i > 0 && i == tam)
            {
                retorno = 1;
            }
        }
        fclose(file);
    }
    return retorno;
}

/** \brief Busca la posicion de un empleado dentro del linkedList por su ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int Id a buscar
 * \return int direccion en caso de encontralo -1 en caso de que no
 *
 */
int getIndexByID(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    int tam;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        tam = ll_len(pArrayListEmployee);

        if(tam > 0)
        {
            for(int i = 0; i < tam; i++)
            {
                aux = ll_get(pArrayListEmployee, i);

                if(aux != NULL && aux->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }

    return indice;
}

