#ifndef AUX_HPP_INCLUDED
#define AUX_HPP_INCLUDED

#include <vector>
#include <string>

void Pause();
int aleatorio(int inicio, int fin);
double* GenerarPolinomioAleatorio(int grado);
void ExportarCSV(const std::vector<std::vector<double>>& datos, const std::string& nombre);

#endif // AUX_HPP_INCLUDED
