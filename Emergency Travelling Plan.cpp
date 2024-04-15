#include <iostream>

using namespace std;

#define MAX 1000 // Maximum value for distances

struct Queue {
    int items[MAX];
    int front, rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
        }
        else {
            if (front == -1) front = 0;
            rear++;
            items[rear] = value;
        }
    }

    int dequeue() {
        int item;
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        else {
            item = items[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
            return item;
        }
    }
};

class Graph {
private:
    int** adj; // Adjacency matrix for road connections
    int** air; // Adjacency matrix for aerial connections
    int* distances; // Store distances from source
    int* prev; // Store previous nodes in the shortest path
    int numVertices; // Number of vertices in the graph

public:
    Graph(int vertices) {
        numVertices = vertices;

        adj = new int* [numVertices];
        air = new int* [numVertices];
        distances = new int[numVertices];
        prev = new int[numVertices];

        for (int i = 0; i < numVertices; ++i) {
            adj[i] = new int[numVertices];
            air[i] = new int[numVertices];
            distances[i] = MAX;
            prev[i] = -1;

            for (int j = 0; j < numVertices; ++j) {
                adj[i][j] = 0; // Initialize road connections to 0
                air[i][j] = 0; // Initialize aerial connections to 0
            }
        }
    }

    // Add a road connection between two vertices
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        //   adj[v][u] = 1; // Assuming it's an undirected graph
    }

    // Add an aerial connection between two vertices
    void addAirEdge(int u, int v) {
        air[u][v] = 1;
    }

    // Utility function to print the shortest path from source to destination
    void printPath(int src, int dest) {
        if (src == dest) {
            cout << src << " ";
            return;
        }
        printPath(src, prev[dest]);
        cout << dest << " ";
    }

    // Perform Breadth-First Search to find the shortest path
    int bfs(int src, int dest) {
        // Initialize distances array with a large value (MAX)
        for (int i = 0; i < numVertices; i++) {
            distances[i] = MAX;
        }

        Queue q;
        distances[src] = 0;
        q.enqueue(src);

        while (!q.isEmpty()) {
            int u = q.dequeue();

            for (int i = 0; i < numVertices; i++) {
                if (adj[u][i] == 1 || air[u][i] == 1) {
                    int v = i;
                    if (air[u][i] == 1 && distances[v] > distances[u]) {
                        distances[v] = distances[u];
                        prev[v] = u;
                        q.enqueue(v);
                    }
                    else if (adj[u][i] == 1 && distances[v] > distances[u] + 1) {
                        distances[v] = distances[u] + 1;
                        prev[v] = u;
                        q.enqueue(v);
                    }
                }
            }
        }

        cout << "Path: ";
        printPath(src, dest);
        cout << endl;

        return distances[dest]; // Return the shortest distance to the destination
    }
};

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, m;
        cout << "Enter the number of cities: ";
        cin >> n;
        cout << "Enter the number of aerial routes: ";
        cin >> m;

        Graph g(n); // Create a graph with 'n' vertices

        // Assuming cities are connected sequentially by roads
        for (int i = 0; i < n - 1; i++) {
            g.addEdge(i, i + 1); // Connect cities with roads
        }

        cout << "Enter the aerial route for city " << ":" << endl;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g.addAirEdge(u, v); // Add aerial routes between cities
        }

        // Find the shortest path from city 1 to the last city (n)
        int days = g.bfs(0, n - 1);
        days = (days / 6) + (m / 2);
        cout << "Shortest days from city 1 to city " << n << ": " << days << endl;
    }

    return 0;
}