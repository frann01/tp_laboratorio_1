#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int contador = 0;
    char buffer[4][128];
    Employee* aux;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4
               && atoi(buffer[0]) && buffer[1] != NULL
               && atoi(buffer[2])
               && atoi(buffer[3]))
            {
                aux = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(aux != NULL && ll_add(pArrayListEmployee, (Employee*)aux) == 0)
                {
                    contador++;
                }
            }
        }
    }

    return contador;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int contador = 0;
    Employee aux;
    Employee* puntero = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((Employee*)&aux, sizeof(Employee), 1, pFile) == 1)
            {
                puntero = employee_nuevoParametros(aux.id, aux.nombre, aux.horasTrabajadas, aux.sueldo);
                if(puntero != NULL && ll_add(pArrayListEmployee, puntero)== 0)
                {
                    contador++;
                }
            }
        }
    }
    return contador;
}
