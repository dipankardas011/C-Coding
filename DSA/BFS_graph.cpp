/*Breadth First Search or BFS for a Graph
Difficulty Level : Easy
Last Updated : 04 Dec, 2020
GeeksforGeeks - Summer Carnival Banner
 
Breadth First Traversal (or Search) for a graph is similar to Breadth First Traversal of a tree (See method 2 of this post). The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex. 

For example, in the following graph, we start traversal from vertex 2. When we come to vertex 0, we look for all adjacent vertices of it. 2 is also an adjacent vertex of 0. If we don’t mark visited vertices, then 2 will be processed again and it will become a non-terminating process. A Breadth First Traversal of the following graph is 2, 0, 3, 1.*/
#include <iostream>
#include <list>

using namespace std;

class graph
{
    int v;
    list<int>* adj;
    public:
    graph(int V);
    void addedge(int v, int w);
    void BFS(int s);
};

graph::graph(int v)
{
    this->v=v;
    adj = new list<int>[v];
}

void graph::addedge(int v, int w)
{
    adj[v].push_back(w);
}
// s denoted the source/ root vertice
void graph::BFS(int s)
{
    bool* visited=new bool[graph::v];
    for(int i=0;i<graph::v;i++)
        visited[i]=false;

    list<int>queue;
    visited[s]=true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()) {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(i=adj[s].begin(); i!=adj[s].end();i++)
        {
            if(!visited[*i]) {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    graph g(4);

    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    return 0;
}