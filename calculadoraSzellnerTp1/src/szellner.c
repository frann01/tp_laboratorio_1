/*
 * szellner.c
 *
 *  Created on: 15 abr. 2021
 *      Author: USUARIO
 */


#include "szellner.h"
#include <stdio.h>
#include <stdlib.h>

/** \brief toma dos floats y los suma
 *
 * \param a float operando 1
 * \param b float operando 2
 * \return respuesta float devuelve el resultado de la suma
 *
 */
float sumar(float a,float b)
{
    float respuesta;
    respuesta= a+b;
    return respuesta;
}

/** \brief toma dos numeros y resta el segundo al primero
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return respuesta float resultado de la resta
 *
 */
float restar(float a, float b)
{
    float respuesta;
    respuesta= a-b;
    return respuesta;
}

/** \brief toma dos numeros y realiza una division
 *
 * \param a float dividendo
 * \param b float divisor
 * \return resultado float resultado de la division
 *
 */
float dividir(float a, float b)
{
    float respuesta;
    respuesta= a/b;
    return respuesta;
}

/** \brief tomo dos numeros y los multiplica entre si
 *
 * \param a float primer numero
 * \param b float segundo numero
 * \return resultado float devuelve el resultado de la multiplicacion
 *
 */
float multiplicar(float a, float b)
{
    float respuesta;
    respuesta= a*b;
    return respuesta;
}

/** \brief toma un numero y devuelve su factorial
 *
 * \param a float numero
 * \return resultado float devuelve el factorial
 *
 */
float factorial(float a)
{
    float Resultado = 1;
    while(a > 1)
    {
       Resultado *= a;
       a--;
    }
    return Resultado;
}




/** \brief presenta el menu al usuario, se actualiza a medida que se ingresan los numeros y le pide una respuesta
 *
 * \param a float primer numero a actualizar
 * \param b float segundo numero a actualizar
 * \return char devuelve la opcion que elige el usuario
 *
 */
char menu(float a, float b)
{
    char respuesta;
    printf("***Menu de opciones*** \n");
    if(a==EOF && b==EOF)
        {

            printf("1) Ingresar el primer operando (A = x)\n");
            printf("2) Ingresar el segundo operando (B = y)\n");
            printf("3) Realizar las operaciones \n");
            printf("  A + B \n");
            printf("  A - B \n");
            printf("  A / B \n");
            printf("  A * B \n");
            printf("  A! & B!\n");
        }
        else
            {
                if(b==EOF)
                    {
                        printf("1) Ingresar el primer operando (A = %.1f)\n", a);
                        printf("2) Ingresar el segundo operando (B = y)\n");
                        printf("3) Realizar las operaciones \n");
                        printf("  %.1f + B \n",a);
                        printf("  %.1f - B \n",a);
                        printf("  %.1f / B \n",a);
                        printf("  %.1f * B \n",a);
                        printf("  %.1f! & B!\n",a);
                    }
                    else
                        {
                            printf("1) Ingresar el primer operando (A = %.1f)\n", a);
                            printf("2) Ingresar el segundo operando (B = %.1f)\n",b);
                            printf("3) Realizar las operaciones \n");
                            printf("  %.1f + %.1f \n",a,b);
                            printf("  %.1f - %.1f \n",a,b);
                            printf("  %.1f / %.1f \n",a,b);
                            printf("  %.1f * %.1f \n",a,b);
                            printf("  %.1f! & %.1f!\n",a,b);
                        }
            }
    printf("4) Mostrar los resultados \n");
    printf("5) presione s si desea salir\n");
    fflush(stdin);
    respuesta = getchar();
    fflush(stdin);
    return respuesta;
}




/** \brief toma los resultados de todas las operaciones y los muestra
 *
 * \param suma float resultado suma
 * \param resta float resultado resta
 * \param division float resultado division
 * \param multiplicacion float resultado multiplicacion
 * \param factorA float resultado primer factorial
 * \param factorB float resultado segundo factorial
 * \param a float primer numero (solo para mostrar)
 * \param b float segundo numero (solo para mostrar)
 * \return void
 *
 */
void mostrarResultados(float suma, float resta, float division, float multiplicacion, float factorA, float factorB, float a, float b)
{
    printf("El resultado de %.1f + %.1f es: %.1f \n",a, b, suma);
    printf("El resultado de %.1f - %.1f es: %.1f \n",a, b, resta);
    if(b==0)
        {
            printf("Error! No se puede dividir por 0\n");
        }
        else
            {
                printf("El resultado de %.1f / %.1f es: %.1f \n", a, b, division);
            }

    printf("El resultado de %.1f * %.1f es: %.1f \n",a, b, multiplicacion);

    if(a > 34 || a < 0)
    {
    	printf("La operacion no se pudo completar\n");
    }
    else
    {
    	printf("El resultado de %.1f! es %.1f \n",a, factorA);
    }

    if(b > 34 || b < 0)
        {
        	printf("La operacion no se pudo completar\n\n");
        }
        else
        {
        	printf("El resultado de %.1f! es %.1f \n\n",b, factorB);
        }
}




/** \brief pide un numero, valida que sea un numero y lo escribe en una variable fuera de la funcion
 *
 * \param float* la direccion donde quiero escribir el numero ingresado
 * \param *char mensaje elmensaje para pedir el numero
 * \param *char mensajeError mensaje en caso de error
 * \return int
 *
 */

void validarNum(float* pResultado, char* mensaje, char* mensajeError)
{
	float num;
	printf(mensaje);
    fflush(stdin);
    while(scanf("%f", &num)!=1)
    	{
    		printf(mensajeError);
    		fflush(stdin);
    	}
	*pResultado = num;
}




/** \brief valida que la opcion ingresada sea correcta
 *
 * \param char respuesta es la opcion ingresada
 * \param *char direccion de la variable
 * \return int
 *
 */
void validarChar(char respuesta, char* direccion)
{
	fflush(stdin);
	while(respuesta != '1' && respuesta != '2' && respuesta != '3' && respuesta != '4' && respuesta != '5')
		{
		    fflush(stdin);
		    printf("Ingrese una opcion correcta por favor!");
		    respuesta = getchar();
		}
	*direccion = respuesta;
}










