#include <stdlib.h>
#include <stdio.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   100
#define TRUE            1
#define FALSE           0

typedef int TipoValorVertice;
typedef int TipoValorAresta;
typedef struct TipoItem {
  TipoValorVertice Vertice;
  TipoValorAresta Aresta;
} TipoItem;
typedef struct TipoCelula* TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct TipoLista {
  TipoApontador Primeiro, Ultimo;
} TipoLista;
typedef struct TipoGrafo {
  TipoLista Adj[MAXNUMVERTICES + 1];
  TipoValorVertice NumVertices;
  TipoValorAresta NumArestas;
} TipoGrafo;
typedef short TipoValorTempo;
typedef enum { branco, cinza, preto } TipoCor;

TipoValorTempo d[MAXNUMVERTICES + 1], t[MAXNUMVERTICES + 1];
TipoCor Cor[MAXNUMVERTICES+1];
short Antecessor[MAXNUMVERTICES+1];

void FLVazia(TipoLista *Lista) {
  Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
}

char Vazia(TipoLista Lista) {
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem *x, TipoLista *Lista) {
  Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Item = *x;
  Lista->Ultimo->Prox = NULL;
}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2,
                  TipoValorAresta *Aresta, TipoGrafo *Grafo) {
  TipoItem x;
  x.Vertice = *V2;
  x.Aresta = *Aresta;
  Insere(&x, &Grafo->Adj[*V1]);
}

void FGVazio(TipoGrafo *Grafo) {
  short i;
  for (i = 0; i < Grafo->NumVertices; i++)
    FLVazia(&Grafo->Adj[i]);
}

char ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
  return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
  return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoValorVertice *Adj,
             TipoValorAresta *Aresta, TipoApontador *Prox,
             char *FimListaAdj) {
  *Adj = (*Prox)->Item.Vertice;
  *Aresta = (*Prox)->Item.Aresta;
  *Prox = (*Prox)->Prox;
  if (*Prox == NULL) *FimListaAdj = TRUE;
}

void ImprimeLista(TipoLista Lista) {
  TipoApontador Aux = Lista.Primeiro->Prox;
  while (Aux != NULL) {
    printf(" %d(%d)", Aux->Item.Vertice, Aux->Item.Aresta);
    Aux = Aux->Prox;
  }
}

void ImprimeGrafo(TipoGrafo *Grafo) {
  for (int i = 0; i < Grafo->NumVertices; i++) {
    printf("Vertice %d:", i);
    if (!Vazia(Grafo->Adj[i])) ImprimeLista(Grafo->Adj[i]);
    printf("\n");
  }
}

int DFS_Ciclo(TipoValorVertice u, TipoGrafo *grafo, TipoCor *cor) {
  cor[u] = cinza;
  TipoApontador aux;
  TipoValorVertice v;
  TipoValorAresta peso;
  char fimLista = FALSE;

  if (!ListaAdjVazia(&u, grafo)) {
    aux = PrimeiroListaAdj(&u, grafo);
    while (!fimLista) {
      ProxAdj(&u, &v, &peso, &aux, &fimLista);
      if (cor[v] == cinza) {
        return 1; // ciclo detectado
      }
      if (cor[v] == branco) {
        if (DFS_Ciclo(v, grafo, cor)) return 1;
      }
    }
  }

  cor[u] = preto;
  return 0;
}

int ciclo(TipoGrafo *grafo) {
  TipoCor cor[MAXNUMVERTICES + 1];
  for (int i = 0; i < grafo->NumVertices; i++) {
    cor[i] = branco;
  }

  for (int i = 0; i < grafo->NumVertices; i++) {
    if (cor[i] == branco) {
      if (DFS_Ciclo(i, grafo, cor)) {
        return 1;
      }
    }
  }

  return 0;
}

void TestaGrafo(int numVertices, int arestas[][3], int numArestas, const char* nome) {
  TipoGrafo grafo;
  grafo.NumVertices = numVertices;
  grafo.NumArestas = 0;
  FGVazio(&grafo);

  for (int i = 0; i < numArestas; i++) {
    TipoValorVertice v1 = arestas[i][0];
    TipoValorVertice v2 = arestas[i][1];
    TipoValorAresta peso = arestas[i][2];
    grafo.NumArestas++;
    InsereAresta(&v1, &v2, &peso, &grafo);
  }

  printf("==== %s ====\n", nome);
  ImprimeGrafo(&grafo);
  if (ciclo(&grafo))
    printf("Resultado: O grafo possui pelo menos um ciclo.\n\n");
  else
    printf("Resultado: O grafo é acíclico.\n\n");
}

int main() {
  // Grafo 1: Cíclico
  int arestas1[][3] = {
    {0, 1, 1},
    {1, 2, 1},
    {2, 0, 1}
  };

  // Grafo 2: Acíclico
  int arestas2[][3] = {
    {0, 1, 1},
    {1, 2, 1},
    {2, 3, 1}
  };

  // Grafo 3: Parcialmente cíclico
  int arestas3[][3] = {
    {0, 1, 1},
    {1, 2, 1},
    {2, 0, 1},
    {3, 4, 1}
  };

  TestaGrafo(3, arestas1, 3, "Grafo 1 (Cíclico)");
  TestaGrafo(4, arestas2, 3, "Grafo 2 (Acíclico)");
  TestaGrafo(5, arestas3, 4, "Grafo 3 (Ciclo Parcial)");

  return 0;
}
