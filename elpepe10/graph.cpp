#include "graph.h"

void createGraph(graph &G){
    first(G) = nil;
}
adrNode alokasiNode(infotype x){
    adrNode N = new node;
    info(N) = x;
    next(N) = nil;
    child(N) = nil;
    return N;
}
adrAdjacent alokasiAdjacent(infotype x){
    adrAdjacent A = new adjacent;
    info(A) = x;
    next(A) = nil;
    return A;
}
void insertNode(graph &G, adrNode P){
    if(first(G) != nil){
        next(P) = first(G);
        first(G) = P;
    }else{
        first(G) = P;
    }
}
void insertAdjacent(adrNode N, adrAdjacent P){
    if(child(N) != nil){
        next(P) = child(N);
        child(N) = P;
    }else{
        child(N) = P;
    }
}
adrNode findNode(graph G, infotype x){
    adrNode P = nil;
    if(first(G) != nil){
        adrNode N = first(G);
        while(N != nil){
            if(info(N) == x){
                P = N;
            }
            N = next(N);
        }
    }
    return P;
}
adrAdjacent findAdjacent(adrNode N, infotype x){
    adrAdjacent P = nil;
    if(child(N) != nil){
        adrAdjacent A = child(N);
        while(A != nil){
            if(info(A) == x){
                P = A;
            }
            A = next(A);
        }
    }
    return P;
}
void connectNode(graph &G, infotype a, infotype b){
    adrNode A = findNode(G, a);
    adrNode B = findNode(G, b);
    adrAdjacent adjA = findAdjacent(A, b);
    adrAdjacent adjB = findAdjacent(B, a);
    if(adjA == nil && adjB == nil){
        insertAdjacent(A, alokasiAdjacent(b));
        insertAdjacent(B, alokasiAdjacent(a));
    }
}
void printGraph(graph G){
    if(first(G) != nil){
        adrNode P = first(G);
        while(P != nil){
            cout << "Node " << info(P) << ": ";
            adrAdjacent Q = child(P);
            while(Q != nil){
                cout << info(Q) << " ";
                Q = next(Q);
            }
            cout << endl;
            P = next(P);
        }
    }
}
void editNode(graph G, infotype x, infotype y){
    if(first(G) !=  nil){
        adrNode P = first(G);
        adrNode Q = findNode(G, x);
        if(Q != nil){
            while(P != nil){
                if(info(P) == x){
                    info(P) = y;
                }
                adrAdjacent R = child(P);
                while(R != nil){
                    if(info(R) == x){
                        info(R) = y;
                    }
                    R = next(R);
                }
                P = next(P);
            }
        }
    }
}
void deleteAdjacent(adrNode N, infotype x){
    if(child(N) != nil){
        adrAdjacent Q = findAdjacent(N, x);
        if(Q != nil){
            if(Q == child(N)){
                child(N) = next(Q);
            }else if(next(Q) == nil){
                adrAdjacent P = child(N);
                while(next(next(P)) != nil){
                    P = next(P);
                }
                next(P) = nil;
            }else{
                adrAdjacent P = child(N);
                while(next(P) != Q){
                    P = next(Q);
                }
                next(P) = next(Q);
                next(Q) = nil;
            }
        }
    }
}
void disconnectNode(graph &G, infotype a, infotype b){
    adrNode A = findNode(G, a);
    adrNode B = findNode(G, b);
    adrAdjacent adjA = findAdjacent(A, b);
    adrAdjacent adjB = findAdjacent(B, a);
    if(adjA != nil && adjB != nil){
        deleteAdjacent(A, b);
        deleteAdjacent(B, a);
    }
}
void deleteNode(graph &G, infotype x){
    if(first(G) != nil){
        adrNode P = findNode(G, x);
        adrNode Q = first(G);
        while(Q != nil){
            deleteAdjacent(Q, x);
            Q = next(Q);
        }
    }
}
