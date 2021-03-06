#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int menu();
int mostrarEmpleado(Employee* e);
Employee* employee_nuevoParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldoStr);
int idMasAlto(LinkedList* pArrayListEmployee);

int validarString(char cadena[], int tam);
void validarNum(int* pResultado, char* mensaje, char* mensajeError);
int validarSN(char simbolo);

int employee_compararID(void* valor1, void* valor2);
int employee_compararNombre(void* valor1, void* valor2);
int employee_compararHorasTra(void* valor1, void* valor2);
int employee_compararSueldo(void* valor1, void* valor2);

#endif // employee_H_INCLUDED
