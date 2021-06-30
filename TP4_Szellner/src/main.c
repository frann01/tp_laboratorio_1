/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

int compararEdad(void* valor1, void* valor2);
void mostraMascota(eMascota* mascota);
void mostrarMascotas(LinkedList* this);

int main(void)
{
    //	startTesting(1);  // ll_newLinkedList
    LinkedList* lista = ll_newLinkedList();
    if(lista==NULL)
    {
        exit(1);
    }
    eMascota m1 = {1234, "Juan", 'm', 15};
    eMascota m2 = {1235, "Pedro", 'm', 1};
    eMascota m3 = {1236, "Lola", 'f', 7};
    eMascota m4 = {1237, "Juana", 'f', 10};
    eMascota m5 = {1238, "Marco", 'm', 3};

//	startTesting(5);  // ll_add
    ll_add(lista, &m1);
    ll_add(lista, &m2);
    ll_add(lista, &m3);
    ll_add(lista, &m4);
    ll_add(lista, &m5);


//    startTesting(2);  // ll_len
//    printf("El tamaño de la lista es: %d\n\n", ll_len(lista));


//	startTesting(3);  // getNode - test_getNode


//	startTesting(4);  // addNode - test_addNode


//	startTesting(6);  // ll_get  Anda
//    eMascota* pPrueba=NULL;
//    pPrueba = (eMascota*) ll_get(lista,0);
//    mostraMascota(pPrueba);


//	startTesting(7);  // ll_set
//    eMascota m6 = {1239, "Luna", 'f', 7};
//    mostrarMascotas(lista);
//    ll_set(lista, 4, &m6);
//    mostrarMascotas(lista);



//	startTesting(8);  // ll_remove
//    mostrarMascotas(lista);
//    ll_remove(lista, 4);
//    mostrarMascotas(lista);


//	startTesting(9);  // ll_clear
//    mostrarMascotas(lista);
//    ll_clear(lista);
//    mostrarMascotas(lista);


//	startTesting(10); // ll_deleteLinkedList
//    if(ll_deleteLinkedList(lista)==0)
//    {
//        printf("La lista se borro correctamente\n");
//    }


//	startTesting(11); // ll_indexOf
//    int indexPrueba;
//    indexPrueba = ll_indexOf(lista, &m5);
//    printf("El index es: %d\n", indexPrueba);
//    mostrarMascotas(lista);


//	startTesting(12); // ll_isEmpty
//    if(ll_isEmpty(lista)==0)
//    {
//        printf("La lista no esta vacia\n");
//    }


//	startTesting(13); // ll_push Mete un nuevo elemento en la posicion indicada
//    eMascota m6 = {1239, "Luna", 'f', 7};
//    mostrarMascotas(lista);
//    ll_push(lista, 4, &m6);
//    mostrarMascotas(lista);


//	startTesting(14); // ll_pop
//    mostrarMascotas(lista);
//    ll_pop(lista, 4);
//    mostrarMascotas(lista);


//	startTesting(15); // ll_contains
//    if(ll_contains(lista, &m3)==0)
//    {
//        printf("Esta en la lista\n");
//    }


//	startTesting(16); // ll_containsAll
//   LinkedList* lista2 = ll_newLinkedList();
//    ll_add(lista2, &m1);
//    ll_add(lista2, &m2);
//    if(ll_containsAll(lista, lista2)==0)
//    {
//        printf("Estan todos en la lista\n");
//    }


//	startTesting(17); // ll_subList
//    LinkedList* lista3 = ll_subList(lista,1, 3);
//    mostrarMascotas(lista3);


//	startTesting(18); // ll_clone
//    LinkedList* lista4 = ll_clone(lista);
//    mostrarMascotas(lista4);

//	startTesting(19); // ll_sort
//    mostrarMascotas(lista);
//    ll_sort(lista, compararEdad, 0);
//    mostrarMascotas(lista);

    return 0;
}




void mostraMascota(eMascota* mascota)
{
    if(mascota!=NULL)
    {
        printf("%4d   %10s      %3d         %1c\n",
           mascota->id,
           mascota->nombre,
           mascota->edad,
           mascota->sexo);
    }
}

void mostrarMascotas(LinkedList* this)
{
    int tam = ll_len(this);
    eMascota* aux=NULL;

    printf("Id         Nombre      Edad      Sexo\n");
    printf("--------------------------------------\n");
    for(int i =0; i<tam; i++)
    {
        aux = (eMascota*) ll_get(this, i);
        mostraMascota(aux);
    }
    printf("--------------------------------------\n");
    printf("\n");
}


int compararEdad(void* valor1, void* valor2)
{
    int retorno;
    int resultado;
    eMascota* aux1 = (eMascota*)valor1;
    eMascota* aux2 = (eMascota*)valor2;

    if(aux1 != NULL && aux2 != NULL)
    {
        resultado = aux1->edad - aux2->edad;

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

























