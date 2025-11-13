#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk Linked List
struct Film {
    string judul;
    int tahun;
    int rating;
    Film* next;
};

// Head linked list
Film* head = nullptr;

// Fungsi untuk menambah film di belakang (seperti daftar film lama)
void tambahBelakang(string judul, int tahun, int rating) {
    Film* baru = new Film{judul, tahun, rating, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Film* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
}

// Fungsi untuk menghapus film berdasarkan judul
void hapusFilm(string target) {
    if (head == nullptr) {
        cout << "Daftar film kosong!\n";
        return;
    }

    Film* temp = head;
    Film* prev = nullptr;

    // Jika film pertama adalah target
    if (temp != nullptr && temp->judul == target) {
        head = temp->next;
        delete temp;
        return;
    }

    // Cari film berdasarkan judul
    while (temp != nullptr && temp->judul != target) {
        prev = temp;
        temp = temp->next;
    }

    // Jika tidak ditemukan
    if (temp == nullptr) return;

    // Hapus node
    prev->next = temp->next;
    delete temp;
}

void tampilkanDaftar() {

    Film* temp = head;
    int count = 0;

    while (temp != nullptr) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
        count++;
    }

    cout << "\nTotal film tersisa: " << count << endl << endl; // spasi bawah
}

int main() {
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string judul;
        int tahun, rating;

        cout << "\nFilm " << i << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        tambahBelakang(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, target);
        hapusFilm(target);
        cout << endl;
    }

    tampilkanDaftar();
    return 0;
}
