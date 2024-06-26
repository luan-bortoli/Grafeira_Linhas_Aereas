/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      Luan Bortoli / Winicius Eduardo Girardi
 * Matricula: 2121101061 / 2021101064
 */
#include "Digrafo.h"
#include "Filapri_min.h"
#include <climits>
#include <iostream>
#include <string>

using namespace std;

Digrafo::Digrafo(int num_vertices) {
  if (num_vertices <= 0) {
    throw(invalid_argument("Erro no construtor de Digrafo(int): o numero de "
                           "vertices deve ser maior que zero."));
  }

  num_vertices_ = num_vertices;
  num_arestas_ = 0;
  lista_adj_.resize(num_vertices);
}

int Digrafo::num_vertices() { return num_vertices_; }

int Digrafo::num_arestas() { return num_arestas_; }

bool Digrafo::possui_aresta(Aresta e) {
  for (pair<int, int> &v : lista_adj_[e.v1]) {
    if (v.first == e.v2) {
      return true;
    }
  }
  return false;
}

void Digrafo::insere_aresta(Aresta e) {
  try {
    valida_aresta(e);
  } catch (...) {
    throw_with_nested(runtime_error("Erro na operacao insere_aresta(Aresta): "
                                    "a aresta " +
                                    e.to_string() + " eh invalida!"));
  }

  if (!possui_aresta(e) && (e.v1 != e.v2)) {
    lista_adj_[e.v1].push_back(make_pair(e.v2, e.peso));
    num_arestas_++;
  }
}

void Digrafo::alg_dijkstra(int s, std::vector<int> &pai, std::vector<int> &dp) {
  dp.resize(num_vertices_, INT_MAX);
  pai.resize(num_vertices_, -1);
  dp[s] = 0;

  Filapri_min<int> fila(num_vertices_);
  for (int i = 0; i < num_vertices_; i++) {
    fila.insere(i, dp[i]);
  }

  while (!fila.vazia()) {
    pair<int, int> u = fila.remove();
    if (dp[u.first] != INT_MAX) {
      for (pair<int, int> &v : lista_adj_[u.first]) {
        if (dp[v.first] > dp[u.first] + v.second) {
          dp[v.first] = dp[u.first] + v.second;
          pai[v.first] = u.first;
          fila.diminui_prio(v.first, dp[v.first]);
        }
      }
    }
  }
}
//X = Avaliação da cidade - M = Valor maximo do custo
void Digrafo::caminho_peso_minimo(int x, int m) {
  vector<int> dp;
  vector<int> pai;
  alg_dijkstra(x, pai, dp);

  for (int i = 0; i < num_vertices_; i++) {
    if (i != x) {
      if (dp[i] <= m) {
        //Custo da viagem + , + viagens com esse custo total minimo u para x
        cout << i << ": " << dp[i] << ", ";
        int j = i;
        while (pai[j] != -1) {
          cout << j << " ";
          j = pai[j];
        }
        cout << j << "\n";
      } else {
        //Custo minimo for maior que o valor maximo encontrado / ou não tenha sequência
        cout << i << ": economicamente inviavel ate " << x << "\n";
      }
    }
  }
}

Digrafo Digrafo::inverter_aresta() {
  Digrafo digrafo_inverso(num_vertices_);
  for (int v = 0; v < num_vertices_; v++) {
    for (pair<int, int> &w : lista_adj_[v]) {
      digrafo_inverso.insere_aresta(Aresta(w.first, v, w.second));
    }
  }
  return digrafo_inverso;
}

void Digrafo::valida_aresta(Aresta e) {
  valida_vertice(e.v1);
  valida_vertice(e.v2);
  valida_peso(e.peso);
}

void Digrafo::valida_vertice(int v) {
  if (v < 0 || v >= num_vertices_) {
    throw out_of_range("Indice de vertice invalido: " + to_string(v));
  }
}

void Digrafo::valida_peso(int p) {
  if (p < 0) {
    throw out_of_range("Peso invalido: " + to_string(p));
  }
}