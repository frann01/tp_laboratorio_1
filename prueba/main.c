#include <stdio.h>
#include <stdlib.h>

int sumarv2(int a,int b);
int main()
{
    int num1;
    int num2;
    int respuesta;

    printf("Ingrese el primer numero: \n");
    fflush(stdin);
    scanf("%i", &num1);

    printf("Ingrese el segundo numero: \n");
    fflush(stdin);
    scanf("%i", &num2);

    respuesta = sumarv2(num1, num2);
    printf("%i", respuesta);
    return 0;
}

int sumarv2(int a,int b)
{
    int respuesta;
    respuesta= a+b;
    return respuesta;
}
