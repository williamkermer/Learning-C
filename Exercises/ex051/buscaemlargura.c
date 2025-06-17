#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXNUMVERTICES  100
#define FALSE           0
#define TRUE            1
#define INFINITO        INT_MAX

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoItem {
  TipoValorVertice Vertice;
  TipoPeso Peso;
} TipoItem;

typedef struct TipoCelula* TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct TipoLista {
  TipoApontador Primeiro, Ultimo;
} TipoLista;
typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;
typedef struct TipoGrafo {
  TipoLista Adj[MAXNUMVERTICES + 1];
  TipoValorVertice NumVertices;
  int NumArestas;
} TipoGrafo;
typedef short  TipoValorTempo;
typedef enum {
  branco, cinza, preto
} TipoCor;

int i;
TipoValorVertice V1, V2;
TipoPeso Peso;
TipoItem x;

void FLVazia(TipoLista *Lista) {
  Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
} 

short ListaVazia(TipoLista Lista) {
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem *x, TipoLista *Lista) {
  Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Item = *x;
  Lista->Ultimo->Prox = NULL;
}

void FFVazia(TipoFila *Fila) {
  Fila->Frente = (TipoApontador)malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
}

short FilaVazia(TipoFila Fila) {
  return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila) {
  Fila->Tras->Prox =(TipoApontador)malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item) {
  TipoApontador q;
  if (FilaVazia(*Fila)) {
    printf(" Erro   fila esta  vazia\n");
    return;
  }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
}  

void ImprimeFila(TipoFila Fila) {
  TipoApontador Aux = Fila.Frente->Prox;
  while (Aux != NULL) {
    printf("%3d (%d) ", Aux->Item.Vertice, Aux->Item.Peso);
    Aux = Aux->Prox;
  }
}  

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo) {
  TipoItem x;
  x.Vertice = *V2;
  x.Peso = *Peso;
  Insere(&x, &Grafo->Adj[*V1]);
}

void FGVazio(TipoGrafo *Grafo) {
  for (short i = 0; i <= Grafo->NumVertices - 1; i++)
    FLVazia(&Grafo->Adj[i]);
}

short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
  return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
  return (Grafo->Adj[*Vertice].Primeiro->Prox);
}  

void ProxAdj(TipoValorVertice *Vertice, TipoValorVertice *Adj,
             TipoPeso *Peso, TipoApontador* Prox, short *FimListaAdj) {
  *Adj = (*Prox)->Item.Vertice;
  *Peso = (*Prox)->Item.Peso;
  *Prox = (*Prox)->Prox;
  if (*Prox == NULL)
    *FimListaAdj = TRUE;
}

void ImprimeLista(TipoLista Lista) {
  TipoApontador Aux = Lista.Primeiro->Prox;
  while (Aux != NULL) {
    printf("%d (%d)  ", Aux->Item.Vertice, Aux->Item.Peso);
    Aux = Aux->Prox;
  }
} 

void ImprimeGrafo(TipoGrafo *Grafo) {
  for (int i = 0; i <= Grafo->NumVertices - 1; i++) {
    printf("Vertice %2d: ", i);
    if (!ListaVazia(Grafo->Adj[i]))
      ImprimeLista(Grafo->Adj[i]);
    putchar('\n');
  }
} 

void VisitaBfs(TipoValorVertice u, TipoGrafo *Grafo, 
               int *Dist, TipoCor *Cor, int *Antecessor) {
  TipoValorVertice v;
  TipoApontador Aux;
  short FimListaAdj;
  TipoPeso Peso;
  TipoItem Item;
  TipoFila Fila;

  Cor[u] = cinza;
  Dist[u] = 0;
  FFVazia(&Fila);
  Item.Vertice = u;
  Item.Peso = 0;
  Enfileira(Item, &Fila);

  while (!FilaVazia(Fila)) {
    Desenfileira(&Fila, &Item);
    u = Item.Vertice;
    if (!ListaAdjVazia(&u, Grafo)) {
      Aux = PrimeiroListaAdj(&u, Grafo);
      FimListaAdj = FALSE;
      while (!FimListaAdj) {
        ProxAdj(&u, &v, &Peso, &Aux, &FimListaAdj);
        if (Cor[v] != branco) continue;
        Cor[v] = cinza;
        Dist[v] = Dist[u] + 1;
        Antecessor[v] = u;
        Item.Vertice = v;
        Item.Peso = Peso;
        Enfileira(Item, &Fila);
      }
    }
    Cor[u] = preto;
  }
}

void ImprimeCaminho(TipoValorVertice Origem, TipoValorVertice v,
TipoGrafo *Grafo, int *Dist , TipoCor *Cor, int *Antecessor) {
  if (Origem == v) {
    printf("%d ", Origem);
    return;
  }
  if (Antecessor[v] == -1)
    printf("Nao existe caminho de %d ate %d\n", Origem, v);
  else {
    ImprimeCaminho(Origem, Antecessor[v], Grafo, Dist, Cor, Antecessor);
    printf("%d ", v);
  }
}

int main() {
  TipoGrafo G;
  TipoValorVertice NVertices = 6;
  G.NumVertices = NVertices;
  G.NumArestas = 0;
  FGVazio(&G);

  int arestas[][2] = {
    {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5},
    {0, 4} // criando vários caminhos possíveis
  };

  for (i = 0; i < 7; i++) {
    V1 = arestas[i][0]; V2 = arestas[i][1]; Peso = 1;
    InsereAresta(&V1, &V2, &Peso, &G);
    InsereAresta(&V2, &V1, &Peso, &G);
    G.NumArestas++;
  }

  printf("\nGrafo criado:\n");
  ImprimeGrafo(&G);

  int Dist[MAXNUMVERTICES + 1];
  TipoCor Cor[MAXNUMVERTICES + 1];
  int Antecessor[MAXNUMVERTICES + 1];

  for (i = 0; i < G.NumVertices; i++) {
    Cor[i] = branco;
    Dist[i] = INFINITO;
    Antecessor[i] = -1;
  }

  VisitaBfs(0, &G, Dist, Cor, Antecessor);

  printf("\nCaminhos testados:\n");
  ImprimeCaminho(0, 5, &G, Dist, Cor, Antecessor); printf("\n");
  ImprimeCaminho(0, 1, &G, Dist, Cor, Antecessor); printf("\n");
  ImprimeCaminho(0, 3, &G, Dist, Cor, Antecessor); printf("\n");
  ImprimeCaminho(0, 4, &G, Dist, Cor, Antecessor); printf("\n");
  ImprimeCaminho(1, 5, &G, Dist, Cor, Antecessor); printf("\n");

  return 0;
}
