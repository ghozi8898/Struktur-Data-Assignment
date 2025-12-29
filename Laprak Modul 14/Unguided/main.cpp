#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    /* Insert Node */
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    /* Connect Node */
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'E'));

    cout << "Graph (Adjacency List):" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS Traversal: ";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));

    cout << "\n\nBFS Traversal: ";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));

    cout << endl;
    return 0;
}
