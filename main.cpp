#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

// 10 vertices
const int v = 10;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void removeEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u][v] = 0;
    graph[v][u] = 0;
}


// BFS
vector<int> BFS(const vector<vector<int>>& graph, int src) {
    vector<int> res;
    vector<bool> visited(v + 1, false);
    queue<int> q;
    visited[src] = true;
    q.push(src);

       while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int i = 1; i <= v; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return res;
}

void rutaMasCortaBFS(const vector<vector<int>>& graph, int src) {
    vector<bool> visited(v + 1, false);
    vector<int> parent(v + 1, -1);
    queue<int> q;
    visited[src] = true;
    q.push(src);

    int salida_vertice = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == 9 || curr == 10) {
            salida_vertice = curr;
            break;
        }

        for (int i = 1; i <= v; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }

    if (salida_vertice == -1) {
    cout << "No existe una ruta de evacuacion." << endl;
    return;
}

   // reconstruir el camino
    vector<int> path;
    for (int i = salida_vertice; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());

    cout << "Ruta mas corta de V" << src << " a V" << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << "V" << path[i];
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "\nSalida encontrada: V" << salida_vertice;
    cout << "\nAristas: " << path.size() - 1 << endl;
}

int main() {

    vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);
    addEdge(graph, 7, 10);
    addEdge(graph, 8, 9);
    addEdge(graph, 8, 10);
    addEdge(graph, 9, 10);

    vector<int> resultado = BFS(graph, 1);

    for (int x : resultado) {
        cout << "V" << x << " ";
    }
    cout << endl;
    rutaMasCortaBFS(graph, 1);

    return 0;

}
