/*
 * szellner.h
 *
 *  Created on: 15 abr. 2021
 *      Author: USUARIO
 */

#ifndef SZELLNER_H_
#define SZELLNER_H_



#endif /* SZELLNER_H_ */

float sumar(float a, float b);

float restar(float a, float b);

float dividir(float a, float b);

float multiplicar(float a, float b);

float factorial(float a);

int validarDato(const char* fm, void* var);

char menu(float a, float b);

void mostrarResultados(float suma, float resta, float division, float multiplicacion, float factorA, float factorB, float a, float b);

void validarNum(float* pResultado, char* mensaje, char* mensajeError);

void validarChar(char caracter, char* direccion);
