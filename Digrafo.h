/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      Luan Bortoli / Winicius Eduardo Girardi
 * Matricula: 2121101061 / 2021101064
 */

#ifndef DIGRAFO_H
#define DIGRAFO_H

#include "Aresta.h"
#include <iostream>
#include <list>
#include <vector>

class Digrafo {
public:
  Digrafo(int num_vertices);
  int num_vertices();
  int num_arestas();
  void insere_aresta(Aresta e);
  bool possui_aresta(Aresta e);
  void alg_dijkstra(int s, std::vector<int> &pai, std::vector<int> &dp);
  void caminho_peso_minimo(int x, int m);
  Digrafo inverter_aresta();

private:
  int num_vertices_;
  int num_arestas_;
  void valida_vertice(int v);
  void valida_aresta(Aresta e);
  void valida_peso(int peso);
  std::vector<std::list<std::pair<int, int>>> lista_adj_;
};

#endif /* DIGRAFO_H */
