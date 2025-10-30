#include <iostream>
#include <vector>
#include <queue>
Using namespace std;

class Graph {
private:
    Int numVertices;
    Vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    Void addEdge(int i, int j) {
        // i dan j dikurang satu supaya sesuai dengan angka di gambar
        i--;
        j--;
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1; // karena graf tidak berarah
        } else {
            Cout << "Indeks simpul tidak valid." << endl;
        }
    }

    Void printAdjMatrix() {
        Cout << "Adjacency Matrix:" << endl;
        For (int i = 0; i < numVertices; i++) {
            For (int j = 0; j < numVertices; j++) {
                Cout << adjMatrix[i][j] << " ";
            }
            Cout << endl;
        }
    }
    
    // ----- BAGIAN BFS -----
    Void bfs(int startVertex) {
        Vector<bool> visited(numVertices, false);
        Queue<int> q;

        // Tandai simpul awal sudah dikunjungi dan masukkan ke antrian
        Visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Traversal (dari vertex " << startVertex << "):" << endl;

        // TODO: isi logika BFS di bawah ini bersama-sama!
        // 1. Tandai simpul awal sudah dikunjungi dan masukkan ke antrian
        // 2. Selama antrian belum kosong:
        //    - Ambil simpul terdepan (front)
        //    - Cetak simpulnya
        //    - Kunjungi semua tetangga yang belum dikunjungi
        //      dan masukkan ke antrian

        while (!q.empty()) {
            // Ambil simpul terdepan
            int currentVertex = q.front();
            q.pop();

            cout << currentVertex + 1 << " ";

            // Kunjungi semua tetangga yang belum dikunjungi
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};

Int main() {
    Graph g(8);

    // Parameter fungsi addEdge sekarang menerima angka sesuai gambar
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 8);

    // Cetak adjacency matrix untuk melihat representasi graf
    g.printAdjMatrix();
    cout << endl;

    // Panggil fungsi BFS mulai dari vertex 0 (yakni simpul 1)
    g.bfs(0);

    return 0;
}

