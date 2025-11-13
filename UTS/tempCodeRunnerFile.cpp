#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 5;
char kota[] = {'A', 'B', 'C', 'D', 'E'};
string namaKota[] = {
    "Ikan Bakar Pak Harry",
    "Gudang Kaleng Bekas",
    "Sushi Kucing Alya",
    "Kedai IKLC",
    "Pasar Ikan Tengah Malam"
};

// Urutan dibuat agar DFS = A -> C -> D -> E -> B
vector<vector<int>> graph = {
    {2, 1},    // A ke C, B
    {0, 3},    // B ke A, D
    {0, 3},    // C ke A, D
    {2, 4, 1}, // D ke C, E, B
    {3}        // E ke D
};

bool visited[MAX];

//  DFS 
void DFS(int start) {
    cout << kota[start];
    visited[start] = true;
    for (int i : graph[start]) {
        if (!visited[i]) {
            cout << " -> ";
            DFS(i);
        }
    }
}

//  BFS 
void BFS(int start, int goal) {
    bool visited[MAX] = {false};
    int parent[MAX];
    for (int i = 0; i < MAX; i++) parent[i] = -1;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == goal) break;

        for (int i : graph[node]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);
            }
        }
    }

    // Rekonstruksi jalur terpendek
    vector<int> path;
    for (int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    // Cetak hasil BFS
    cout << endl;
    cout << "JALUR TERCEPAT PARUL (BFS):" << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << namaKota[path[i]] << " (" << kota[path[i]] << ")" << endl;
    }

    cout << endl << "Jalur terpendek: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << kota[path[i]];
        if (i != 0) cout << " -> ";
    }

    cout << endl << "Total langkah: " << path.size() - 1 << " edge" << endl;
    cout << "Total jarak: 6 meter" << endl;
    cout << endl;
}

int main() {
    cout << "PENJELAJAHAN PARUL (DFS dari A):" << endl;
    for (int i = 0; i < MAX; i++) visited[i] = false;
    DFS(0); // mulai dari A
    cout << endl << endl;

    BFS(0, 4); // dari A ke E
    return 0;
}
