#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
 * Class representing a directed graph using adjacency lists.
 */
class Graph {
    int V;                // Number of vertices
    list<int>* adj;       // Array of adjacency lists

public:
    Graph(int V);         // Constructor
    void addEdge(int v, int w);         // Adds a directed edge from v to w
    void display();                    // Displays the adjacency list
    int BFS(int s, int e);             // Returns shortest path length from s to e, or 0 if no path
};

/*
 * Constructor: Initializes the graph with V vertices.
 * Creates an array of lists to represent adjacency lists for each vertex.
 */
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];  // dynamically allocate adjacency list array
}

/*
 * Adds a directed edge from vertex v to vertex w.
 * Ensures both v and w are within bounds before inserting.
 */
void Graph::addEdge(int v, int w) {
    if (v < V && w < V)
        adj[v].push_back(w);
}

/*
 * Displays the adjacency list of the graph.
 */
void Graph::display() {
    for (int v = 0; v < V; v++) {
        cout << "vertex v: " << v << " - ";
        for (int n : adj[v]) {
            cout << n << ", ";
        }
        cout << endl;
    }
}

/*
 * Performs Breadth-First Search to find the shortest path length
 * from start vertex s to end vertex e.
 * Returns: number of edges in the shortest path, or 0 if no path exists.
 */
int Graph::BFS(int s, int e) {

    /* * * * * * * * * * * * * * * * * * * * * * * *
     *
     * Your Brilliant solution code here!
     * 
     * * * * * * * * * * * * * * * * * * * * * * * */
    if (s < 0 || e < 0 || s >= V || e >= V) return 0;
    vector<int> vis(V, 0);
    vector<int> d(V, -1);
    list<int> q;
    vis[s] = 1;
    d[s] = 0;
    q.push_back(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        if (x == e) {
            return d[x];
        }
        for (int y : adj[x]) {
            if (y >= 0 && y < V) {
                if (vis[y] == 0) {
                    vis[y] = 1;
                    d[y] = d[x] + 1;
                    q.push_back(y);
                }
            }
        }
    }

    // Return 0 if target vertex was not reachable
    return 0;
}

/*
 * Main function: builds the graph from user input, runs BFS,
 * and displays the result.
 */
int main() {
    int size, count, start, end;

    // Prompt for number of vertices
    cout << "Enter the number of vertices: ";
    cin >> size;

    Graph g(size);  // create graph

    // Input edges for each vertex
    for (int i = 0; i < size; i++) {
        cout << "\nEnter number of edges from vertex " << i << ": ";
        cin >> count;

        cout << "Enter " << count << " adjacent vertices for vertex " << i << ": ";
        for (int j = 0; j < count; j++) {
            int t;
            cin >> t;
            g.addEdge(i, t);
        }
    }

    // Input BFS start and end vertices
    cout << "\nEnter the starting vertex for BFS: ";
    cin >> start;

    cout << "Enter the target (ending) vertex for BFS: ";
    cin >> end;

    // Display the graph
    cout << "\nGraph adjacency list:\n";
    g.display();

    // Perform BFS and report results
    cout << "\nBFS Traversal from " << start << " to " << end << "...\n";
    int pathLength = g.BFS(start, end);

    if (pathLength > 0)
        cout << "Path exists to vertex " << end << " with length " << pathLength << endl;
    else
        cout << "Path does not exist to vertex " << end << endl;

    return 0;
}
