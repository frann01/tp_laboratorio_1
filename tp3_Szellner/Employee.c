#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"


/** \brief Presenta el menu
 *
 * \return int
 *
 */
int menu()
{
    int respuesta;
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado \n");
    printf("4. Modificar datos de empleado \n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo datos.bin (modo binario)\n");
    printf("10. Salir\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}

/** \brief muestra un empleado individualmente
 *
 * \param e Employee*
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int mostrarEmpleado(Employee* e)
{
    int todoOk=1;
    int legajo;
    char nombre[20];
    int horasTrabajo;
    int sueldo;

    if(e!=NULL &&
            employee_getId(e, &legajo)==0 &&
            employee_getHorasTrabajadas(e, &horasTrabajo)==0 &&
            employee_getSueldo(e, &sueldo)==0 &&
            employee_getNombre(e, nombre)==0)
    {

        printf(" %d       %10s       %d          %d \n",
               legajo,
               nombre,
               sueldo,
               horasTrabajo);
        todoOk=0;
    }
    return todoOk;
}


/** \brief Busca el Id de un empleado y lo guarda en una variable
 *
 * \param this Employee*
 * \param id int*
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_getId(Employee* this,int* id)
{
    int todoOk=1;
    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Busca el nombre de un empleado y lo guarda en una variable
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=1;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk=0;
    }
    return todoOk;
}

/** \brief Busca el nombre de un empleado y lo guarda en una variable
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=1;
    if(this!=NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Busca la horas trabajadas de un empleado y las guarda en una variable
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=1;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Le asigna un id a un empleado
 *
 * \param this Employee*
 * \param id int
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_setId(Employee* this,int id)
{
    int todoOk=1;
    if(this!=NULL && id >0)
    {
        this->id=id;
        todoOk=0;
    }

    return todoOk;
}

/** \brief Le asigna un nombre a un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=1;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128 && strlen(nombre)>2)
    {
        strcpy(this->nombre, nombre);
        todoOk=0;
    }

    return todoOk;
}

/** \brief Le asigna las horas trabajadas a un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=0;
    }

    return todoOk;
}

/** \brief Le asigna aun empleado el sueldo
 *
 * \param this Employee*
 * \param sueldo int
 * \return int 1 en caso de error 0 en caso de todoOK
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        todoOk=0;
    }

    return todoOk;
}

/** \brief Crea un nuevo empleado con los datos ya cargados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* Direccion hacia ese empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* p = employee_new();
    if(p!= NULL)
    {
        if(!(employee_setId(p, atoi(idStr))==0 && employee_setHorasTrabajadas(p, atoi(horasTrabajadasStr))==0 && employee_setNombre(p, nombreStr)== 0&& employee_setSueldo(p, atoi(sueldoStr))==0))
        {
            p = NULL;
        }
    }
    return p;
}

/** \brief  Crea un nuevo empleado con los datos ya cargados
 *
 * \param idStr int
 * \param nombreStr char*
 * \param horasTrabajadasStr int
 * \param sueldoStr int
 * \return Employee* Direccion hacia ese empleado
 *
 */
Employee* employee_nuevoParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldoStr)
{
    Employee* p = employee_new();
    if(p!= NULL)
    {
        if(!(employee_setId(p, idStr)==0 && employee_setHorasTrabajadas(p, horasTrabajadasStr)==0 && employee_setNombre(p, nombreStr)== 0&& employee_setSueldo(p, sueldoStr)==0))
        {
            p = NULL;
        }
    }
    return p;
}

/** \brief Separa el espacio para un empleado en memoria y asigna sus datos a 0
 *
 * \return Employee* Direccion hacia ese empleado
 *
 */
Employee* employee_new()
{
    Employee* p =(Employee*) malloc(sizeof(Employee));
    if(p!= NULL)
    {
        p->id=0;
        p->horasTrabajadas=0;
        p->sueldo=0;
        strcpy(p->nombre, " ");
    }
    return p;
}

/** \brief toma una cadena de caracteres y valida que todos lo sean
 *
 * \param cadena[] char cadena a validar
 * \param tam int tamaño de la cadena
 * \return int devuelve -1 si hay un valor que no sea un caracter
 *
 */
int validarString(char cadena[], int tam)
{
    int todoOk=0;

    for(int i = 0; i<tam ; i++)
    {
        cadena[i]=tolower(cadena[i]);
        if(cadena[i]<97 || cadena[i]>122)
        {
            todoOk=-1;
        }
    }
    return todoOk;
}



/** \brief Libera un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);
}

/** \brief Compara dos Ids
 *
 * \param valor1 void*
 * \param valor2 void*
 * \return int SI el primer valor es mayor que el segundo devuelve 1, si el segundo es mayor -1 y si son iguales 0
 *
 */
int employee_compararID(void* valor1, void* valor2)
{
    int retorno;
    int resultado;
    Employee* aux1 = (Employee*)valor1;
    Employee* aux2 = (Employee*)valor2;

    if(aux1 != NULL && aux2 != NULL)
    {
        resultado = aux1->id - aux2->id;

        if(resultado > 0)
        {
            retorno = 1;
        }
        else
        {
            if(resultado < 0)
            {
                retorno = -1;
            }
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Compara dos nombres de empleados
 *
 * \param valor1 void*
 * \param valor2 void*
 * \return int
 *
 */
int employee_compararNombre(void* valor1, void* valor2)
{
    int retorno;
    Employee* aux1 = (Employee*)valor1;
    Employee* aux2 = (Employee*)valor2;

    if(aux1 != NULL && aux2 != NULL)
    {
        retorno = strcmp(aux1->nombre, aux2->nombre);
    }

    return retorno;
}

/** \brief Compara dos cantidades de horas trabajadas
 *
 * \param valor1 void*
 * \param valor2 void*
 * \return int SI el primer valor es mayor que el segundo devuelve 1, si el segundo es mayor -1 y si son iguales 0
 *
 */
int employee_compararHorasTra(void* valor1, void* valor2)
{
    int retorno;
    int resultado;
    Employee* aux1 = (Employee*)valor1;
    Employee* aux2 = (Employee*)valor2;

    if(aux1 != NULL && aux2 != NULL)
    {
        resultado = aux1->horasTrabajadas - aux2->horasTrabajadas;

        if(resultado > 0)
        {
            retorno = 1;
        }
        else
        {
            if(resultado < 0)
            {
                retorno = -1;
            }
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief  Compara dos sueldos
 *
 * \param valor1 void*
 * \param valor2 void*
 * \return int SI el primer valor es mayor que el segundo devuelve 1, si el segundo es mayor -1 y si son iguales 0
 *
 */
int employee_compararSueldo(void* valor1, void* valor2)
{
    int retorno;
    int resultado;
    Employee* aux1 = (Employee*)valor1;
    Employee* aux2 = (Employee*)valor2;

    if(aux1 != NULL && aux2 != NULL)
    {
        resultado = aux1->sueldo- aux2->sueldo;

        if(resultado > 0)
        {
            retorno = 1;
        }
        else
        {
            if(resultado < 0)
            {
                retorno = -1;
            }
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief valida que una valor dado sea un numero y lo guarda en una variable fuera de la funcion
 *
 * \param pResultado float* variable donde se guarda el numero
 * \param mensaje char* mensaje que pide el valor
 * \param mensajeError char* mensaje en caso de que el valor no sea un numero
 * \return void
 *
 */
void validarNum(int* pResultado, char* mensaje, char* mensajeError)
{
    int num;
    printf(mensaje);
    fflush(stdin);
    while(scanf("%d", &num)!=1)
    {
        printf(mensajeError);
        fflush(stdin);
    }
    *pResultado = num;
}

/** \brief valida que el valor ingresado sea s/n
 *
 * \param simbolo char caracter a validar
 * \return int devuelve -1 si no es correcto
 *
 */
int validarSN(char simbolo)
{
    int todoOk=-1;
    simbolo=tolower(simbolo);
    if(simbolo=='s' || simbolo == 'n')
    {
        todoOk=0;
    }
    return todoOk;
}

/** \brief Busca el id mas alto en un linkedList y lo devuelve
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Id mas alto
 *
 */
int idMasAlto(LinkedList* pArrayListEmployee)
{
    int idMax=1000;
    Employee* puntero;
    int tam;
    int flag=0;
    if(pArrayListEmployee!=NULL)
    {
        tam = ll_len(pArrayListEmployee);
        for(int i=0; i<tam; i++)
        {
            puntero = ll_get(pArrayListEmployee, i);
            if(puntero!=NULL)
            {
                if(flag==0 || puntero->id > idMax)
                {
                    idMax=puntero->id;
                    flag=1;
                }
            }
        }
    }
    return idMax;
}






