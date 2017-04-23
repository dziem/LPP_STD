#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    graph G;
    createGraph(G);
    insertNode(G, alokasiNode("A"));
    insertNode(G, alokasiNode("B"));
    insertNode(G, alokasiNode("C"));
    insertNode(G, alokasiNode("D"));
    insertNode(G, alokasiNode("E"));
    insertNode(G, alokasiNode("F"));
    connectNode(G, "B", "C");
    connectNode(G, "A", "C");
    connectNode(G, "E", "B");
    connectNode(G, "E", "D");
    connectNode(G, "D", "C");
    connectNode(G, "D", "A");
    cout << "View graph" << endl;
    printGraph(G);
    cout << "Disconnect A dan C" << endl;
    disconnectNode(G, "A", "C");
    printGraph(G);
    cout << "Edit C menjadi X"<< endl;
    editNode(G, "C", "X");
    printGraph(G);
    cout << "Delete X" << endl;
    deleteNode(G, "X");
    printGraph(G);
    return 0;
}
