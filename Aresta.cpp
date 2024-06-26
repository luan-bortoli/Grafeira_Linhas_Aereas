/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      Luan Bortoli / Winicius Eduardo Girardi
 * Matricula: 2121101061 / 2021101064
 */

#include "Aresta.h"
#include <iostream>

using namespace std;

Aresta::Aresta(int v1, int v2, int peso) : v1(v1), v2(v2), peso(peso) {}

string Aresta::to_string() {
  return std::to_string(v1) + " " + std::to_string(v2);
}