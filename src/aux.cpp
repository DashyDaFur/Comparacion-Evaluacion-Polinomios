t#include <iostream>
#include <fstream>
#include <cstdlib>
#include "aux.hpp"

using namespace std;

void Pause()
{
    cout << "Presiona ENTER para finalizar el programa...";
    cin.ignore();
    cin.get();
}

int aleatorio(int inicio, int fin)
{
    return inicio + rand() % (fin - inicio + 1);
}

double* GenerarPolinomioAleatorio(int grado)
{
    double* a = new double[grado + 1];

    for (int i = 0; i <= grado; i++){
        a[i] = aleatorio(-10, 10);
    }

    // Asegurar que el coeficiente de mayor grado no sea cero
    do{
        a[grado] = aleatorio(-10, 10);
    } while (a[grado] == 0);

    return a;
}

void ExportarCSV(const vector<vector<double>>& datos, const string& nombre)
{
    ofstream archivo(nombre);

    if (!archivo.is_open()){
        cerr << "Error al abrir/crear el archivo: " << nombre << endl;
        Pause();
        return;
    }

    archivo << "Grado,Tiempo Estandar,Tiempo Horner" << endl;

    for (int i = 0; i < datos.size(); ++i){
        const vector<double>& fila = datos[i];
        archivo << fila[0] << ',' << fila[1] << ',' << fila[2] << endl;
    }

    archivo.close();

    cout << "Resultados guardados exitosamente en " << nombre << endl;
}
