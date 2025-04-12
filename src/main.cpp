#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <string>
#include "../include/aux.hpp"
#include "../include/metodos.hpp"

// -- Valores configurables --
#define REPETICIONES 1000
#define GRADO_INICIAL 10
#define GRADO_FINAL 1000
#define INCREMENTO 10

using namespace std;
using namespace std::chrono;

int main()
{
    // Inicia la semilla para números aleatorios
    srand(time(NULL));

    vector<vector<double>> resultados;

    cout << "Iniciando experimentacion de tiempos..." << endl;

    for (int grado = GRADO_INICIAL; grado <= GRADO_FINAL; grado += INCREMENTO){

        // Generar polinomio aleatorio
        double* polinomio = GenerarPolinomioAleatorio(grado);

        // Generar x aleatorio no nulo en [-10, 10]
        double x;
        do {
            x = aleatorio(-10, 10);
        } while (x == 0);

        // Medir tiempo método Estándar
        auto inicio = steady_clock::now();
        for (int i = 0; i < REPETICIONES; i++){
            EvaluarPolinomioEstandar(polinomio, grado, x);
        }
        auto fin = steady_clock::now();
        duration<double> tiempo_manual = (fin - inicio) / REPETICIONES;

        // Medir tiempo método Horner
        inicio = steady_clock::now();
        for (int i = 0; i < REPETICIONES; i++){
            EvaluarPolinomioHorner(polinomio, grado, x);
        }
        fin = steady_clock::now();
        duration<double> tiempo_horner = (fin - inicio) / REPETICIONES;

        // Guardar resultados en el vector
        resultados.push_back({static_cast<double>(grado), tiempo_manual.count(), tiempo_horner.count()});

        delete[] polinomio;

        // Muestra el progreso cada 100 grados
        if (grado % 100 == 0){
            cout << "Progreso: " << grado << '/' << GRADO_FINAL << " grados completados" << endl;
        }
    }

    ExportarCSV(resultados, "tiempos_polinomios.csv");

    Pause();
    return 0;
}
