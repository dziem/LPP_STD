#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;
#define first(G) G.first
#define info(N) N->info
#define child(N) N->child
#define next(N) N->next
#define nil NULL
typedef string infotype;
typedef struct node *adrNode;
typedef struct adjacent *adrAdjacent;

struct node{
    infotype info;
    adrNode next;
    adrAdjacent child;
};
struct adjacent{
    infotype info;
    adrAdjacent next;
};
struct graph{
    adrNode first;
};

void createGraph(graph &G);
adrNode alokasiNode(infotype x);
adrAdjacent alokasiAdjacent(infotype x);
void insertNode(graph &G, adrNode P);
void insertAdjacent(adrNode N, adrAdjacent P);
adrNode findNode(graph G, infotype x);
adrAdjacent findAdjacent(adrNode N, infotype x);
void connectNode(graph &G, infotype a, infotype b);
void printGraph(graph G);
void editNode(graph G, infotype x, infotype y);
void deleteAdjacent(adrNode N, infotype x);
void disconnectNode(graph &G, infotype a, infotype b);
void deleteNode(graph &G, infotype x);

#endif // GRAPH_H_INCLUDED
