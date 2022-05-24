/*
Prim’s algorithm has the property that the edges in the set A always form a single tree.
The tree starts from an arbitrary root vertex r.
Grow the tree until it spans all the vertices in V. 
At each step, a light edge is added to the tree A that connects A to an isolated vertex of GA = (V, A).
*/

/*       
INITIAL GRAPH:
  V1,V2,V3,V4,V5,V6,V7 
V1[0, 2, 4, 1, 0, 0, 0]
V2[2, 0, 0, 3, 10,0, 0]
V3[4, 0, 0, 2, 0, 5, 0]
V4[1, 3, 2, 0, 7, 8, 4]
V5[0,10, 0, 7, 0, 0, 6]
V6[0, 0, 5, 8, 0, 0, 1]
V7[0, 0, 0, 4, 6, 1, 0]
*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 7

int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << "V" <<parent[i]+1 << " - " << "V" << i+1 << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = {{ 0, 2, 4, 1, 0, 0, 0},
                       {2, 0, 0, 3, 10, 0, 0}, 
                       {4, 0, 0, 2, 0, 5, 0},
                       {1, 3, 2, 0, 7, 8, 4},
                       {0, 10, 0, 7, 0, 0, 6},
                       {0, 0, 5, 8, 0, 0, 1},
                       {0, 0, 0, 4, 6, 1, 0}};

    primMST(graph);

    return 0;    
}
