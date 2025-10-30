/*
Nama: Risky Jonalson Silaen
NIM: 241401010
*/

#include <iostream>
using namespace std;

#define N 9  // Ukuran standar papan Sudoku

// Fungsi untuk mencetak papan Sudoku
void printBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << board[row][col] << " ";
            // Tambahkan garis pemisah vertikal setiap 3 kolom
            if (col == 2 || col == 5)
                cout << "| ";
        }
        cout << endl;
        // Tambahkan garis pemisah horizontal setiap 3 baris
        if (row == 2 || row == 5) {
            for (int i = 0; i < 21; i++)
                cout << "-";
            cout << endl;
        }
    }
}

// Fungsi untuk memvalidasi penempatan angka di posisi tertentu
bool isValid(int board[N][N], int row, int col, int num) {
    // Periksa baris - apakah angka sudah ada di baris yang sama
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;  // Angka sudah ada di baris
        }
    }
    
    // Periksa kolom - apakah angka sudah ada di kolom yang sama
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;  // Angka sudah ada di kolom
        }
    }
    
    // Periksa kotak 3x3 - apakah angka sudah ada dalam kotak kecil
    int startRow = row - row % 3;  // Hitung indeks awal baris kotak 3x3
    int startCol = col - col % 3;  // Hitung indeks awal kolom kotak 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;  // Angka sudah ada dalam kotak 3x3
            }
        }
    }
    
    return true;  // Angka valid untuk ditempatkan
}

// Fungsi untuk menyelesaikan Sudoku menggunakan DFS dengan backtracking
bool solveSudoku(int board[N][N]) {
    // Lakukan iterasi melalui setiap sel dalam papan
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            // Cari sel yang masih kosong (nilai 0)
            if (board[row][col] == 0) {
                // Coba semua angka dari 1 sampai 9 untuk sel kosong ini
                for (int num = 1; num <= 9; num++) {
                    // Periksa apakah angka ini valid di posisi saat ini
                    if (isValid(board, row, col, num)) {
                        // Tempatkan angka yang valid ke dalam sel
                        board[row][col] = num;
                        
                        // REKURSI: Panggil fungsi solveSudoku secara rekursif
                        // untuk menyelesaikan sisa papan dengan angka yang baru ditempatkan
                        if (solveSudoku(board)) {
                            return true;  // Jika berhasil, return true
                        }
                        
                        // BACKTRACKING: Jika rekursi gagal (tidak menemukan solusi)
                        // Kembalikan nilai sel menjadi 0 (kosong) dan coba angka berikutnya
                        board[row][col] = 0;
                    }
                }
                // Jika tidak ada angka 1-9 yang valid untuk sel ini
                // Kembalikan false untuk trigger backtracking ke sel sebelumnya
                return false;
            }
        }
    }
    // BASE CASE: Jika semua sel sudah terisi (tidak ada yang 0)
    // Berarti Sudoku sudah terselesaikan, return true
    return true;
}

int main() {
    // Inisialisasi papan Sudoku awal
    // Angka 0 merepresentasikan sel yang kosong
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    cout << "Papan Sudoku Awal:" << endl;
    printBoard(board);
    cout << endl;
    
    // Coba selesaikan Sudoku
    if (solveSudoku(board)) {
        cout << "Solusi Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan!" << endl;
    }
    
    return 0;
}