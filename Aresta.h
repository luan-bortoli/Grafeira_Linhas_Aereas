/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      Luan Bortoli / Winicius Eduardo Girardi
 * Matricula: 2121101061 / 2021101064
 */

#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>
#include <string>

class Aresta {
public:
  const int v1;
  const int v2;
  const int peso;

  Aresta(int v1, int v2, int peso);

  std::string to_string();
};

#endif /* ARESTA_H */
