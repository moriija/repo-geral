#include "ep.h"
#include "limits.h"
#include <stdio.h>
#include <stdlib.h>

int peso_min = INT_MAX;
int *grau_vert;
int *arestas_usadas; // Vetor para marcar as arestas usadas no ciclo.
int *solucao_arestas;
int *visitados;

/** @brief Esta função é importante para que o corretor automático inclua 
 * corretamente a autoria do EP. Deve retornar Nome e NUSP separados por 
 * ponto-e-virgula, sem pular linhas no meio nem no final.
 */
char *autor(void) {
    return "Isabella Cremonezi Morija;14579951";
}

int outro_extremo(struct grafo *g, int aresta, int v_atual) {
    return (g->A[3 * aresta] == v_atual) ? g->A[3 * aresta + 1] : g->A[3 * aresta];
}

int conecta_vertice(struct grafo *g, int aresta, int v_atual) {
    return (g->A[3 * aresta] == v_atual || g->A[3 * aresta + 1] == v_atual);
}

int calcula_peso(struct grafo *g) {
    int peso = 0;
    for (int i = 0; i < g->M; i++) {
    if (arestas_usadas[i]) 
            peso += g->A[3 * i + 2];
    }
    return peso;
}

void marca_aresta(int aresta, int v1, int v2) {
    arestas_usadas[aresta] = 1; 
    grau_vert[v1]++;
    grau_vert[v2]++;
}

void desmarca_aresta(int aresta, int v1, int v2) {
    arestas_usadas[aresta] = 0;
    grau_vert[v1]--;
grau_vert[v2]--;
}

void atualiza_solucao(struct grafo *g) {
    peso_min = calcula_peso(g);
    // Atualiza automaticamente, pois arestas_usadas já reflete a solução.
}

int valida_aresta(struct grafo *g, int aresta, int v_atual) {
    if (arestas_usadas[aresta]) return 0;
    if (grau_vert[g->A[3 * aresta]] >= 2 || grau_vert[g->A[3 * aresta + 1]] >= 2) return 0;
    return 1;
}

int fechamento_ciclo(struct grafo *g, int v_atual, int v_inicial) {
    int menor_peso = INT_MAX, melhor_aresta = -1;
    for (int i = 0; i < g->M; i++) {
        if (conecta_vertice(g, i, v_atual) && outro_extremo(g, i, v_atual) == v_inicial) {
            if (g->A[3 * i + 2] < menor_peso) {
                menor_peso = g->A[3 * i + 2];
                melhor_aresta = i;
            }
        }
    }
    return melhor_aresta;
}

int busca_ciclo(struct grafo *g, int nivel, int v_atual, int v_inicial) {
if (nivel == g->N) {
        int ciclo = fechamento_ciclo(g, v_atual, v_inicial);
        if (ciclo != -1) {
            marca_aresta(ciclo, g->A[3 * ciclo], g->A[3 * ciclo + 1]);
            int peso_total = calcula_peso(g);

            if (peso_total < peso_min) {
                atualiza_solucao(g);

                for (int i = 0; i < g->M; i++) solucao_arestas[i] = arestas_usadas[i];
            }
            
            desmarca_aresta(ciclo, g->A[3 * ciclo], g->A[3 * ciclo + 1]);
            return 1;
        }
        return 0;
    }

    int achou = 0;
    for (int i = 0; i < g->M; i++) {
        if (!arestas_usadas[i] && conecta_vertice(g, i, v_atual)) {
            int prox_v = outro_extremo(g, i, v_atual);

            if (!visitados[prox_v] && valida_aresta(g, i, v_atual)) {
                marca_aresta(i, v_atual, prox_v);
                visitados[prox_v] = 1;

                achou |= busca_ciclo(g, nivel + 1, prox_v, v_inicial);

                desmarca_aresta(i, v_atual, prox_v);
    visitados[prox_v] = 0;
            }
        }
    }
    return achou;
}

int iniciaEexecuta(struct grafo *g, int v_inicial) {
    grau_vert = calloc(g->N, sizeof(int)); 
    arestas_usadas = calloc(g->M, sizeof(int));
    solucao_arestas = calloc(g->M, sizeof(int));
    visitados = calloc(g->N, sizeof(int));

    visitados[v_inicial] = 1;

    int resultado = busca_ciclo(g, 1, v_inicial, v_inicial);

    for (int i = 0; i < g->M; i++) {
        g->S[i] = solucao_arestas[i];
    }

    free(visitados);
    free(grau_vert);

    return resultado;
}

void termina() {
    free(arestas_usadas);
    free(solucao_arestas);
}
