/* Handling Disconnected Graph 

Solution: This will happen by handling a corner case. 
The above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex as in the case of a Disconnected graph. To do complete DFS traversal of such graphs, run DFS from all unvisited nodes after a DFS. 
The recursive function remains the same.
Algorithm: 
Create a recursive function that takes the index of node and a visited array.
Mark the current node as visited and print the node.
Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.
Run a loop from 0 to number of vertices and check if the node is unvisited in previous DFS then call the recursive function with current node.*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    void DFSutil(int v);
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);

    void DFS();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSutil(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            DFSutil(*i);
}

void Graph::DFS()
{
    for(auto i:adj)
        if(visited[i.first]==false)
            DFSutil(i.first);
}

int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS();
 
    return 0;
}