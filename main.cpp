/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      Luan Bortoli / Winicius Eduardo Girardi
 * Matricula: 2121101061 / 2021101064
 */

#include "Aresta.h"
#include "Digrafo.h"
#include "Filapri_min.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  // C = Cidades atendidades - V = Voos da malha
  int c, v;
  cin >> c >> v;

  Digrafo d(c);

  for (int i = 0; i < v; i++) {
    //Voos da cidade de X para Y com custo Z
    int x, y, z;
    cin >> x >> y >> z;
    Aresta a(x, y, z);
    d.insere_aresta(a);
  }

  Digrafo dI = d.inverter_aresta();

  //Quantidade de destinos a serem reavaliados
  int r;
  cin >> r;

  for (int i = 0; i < r; i++) {
    //X = Avaliação da cidade - M = Valor maximo do custo
    int x, m;
    cin >> x >> m;
    dI.caminho_peso_minimo(x, m);
  }

  return 0;
}
