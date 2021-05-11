/*
 * ArrayEmployees.h
 *
 *  Created on: 11 may. 2021
 *      Author: USUARIO
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



#endif /* ARRAYEMPLOYEES_H_ */

typedef struct
{
    int id;
    char descripcion[20];
}eSector;

typedef struct
{
    int id;
    char Name[51];
    char lastName[51];
    float salary;
    int sectorId;
    int isEmpty;
} eEmployee;

int menu();

int listaVacia(eEmployee lista[], int tam);
int hayLugar(eEmployee lista[], int tam);
int initEmployees(eEmployee lista[], int tam);
int cargarDecripcionSector(int id, eSector sectores[],int tam, char desc[]);
void mostrarSector(eSector sector);
void mostrarSectores(eSector sectores[],int tam);

int printEmployees(eEmployee list[], int len, eSector sectores[], int tamSec);
int findEmployeeByID(eEmployee list[], int len, int id);
int addEmployees(eEmployee lista[], int tam, int id, char name[],char lastName[],float salary, int sector);
int removeEmployee(eEmployee list[], int len, int id);
int sortEmployees(eEmployee list[], int len, int order);

int altaEmpleado(eEmployee lista[], int tam, int* pLegajo, eSector sectores[], int TamSec);
int bajaEmpleado(eEmployee lista[], int tam, eSector sectores[], int tamSec);
void modificarEmpleado(eEmployee lista[], int tam, eSector sectores[],int tamSec);
int informesSueldos(eEmployee list[], int len);
int harcodearEmpleados(eEmployee lista[], int tam, int cant,int* pLegajo);
