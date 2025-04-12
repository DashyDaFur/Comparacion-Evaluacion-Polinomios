#include "metodos.hpp"

double EvaluarPolinomioEstandar(double* a, int grado, double n)
{
    double suma = a[0];
    double potencia = 1;

    for (int i = 1; i <= grado; i++){
        potencia *= n;
        suma += a[i] * potencia;
    }

    return suma;
}

double EvaluarPolinomioHorner(double* a, int grado, double n)
{
    double suma = a[grado];

    for (int i = grado - 1; i >= 0; i--){
        suma = suma * n + a[i];
    }

    return suma;
}
