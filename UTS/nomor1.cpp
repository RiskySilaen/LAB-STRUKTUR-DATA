#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data pasien hewan
struct Pasien {
    string nama;
    string jenis;
    string umur;
    int tingkatDarurat;
};


// Kelas Queue menggunakan Dynamic Array
class QueueDarurat {
private:
    Pasien* data;     
    int kapasitas;    
    int jumlah;      

public:
    QueueDarurat(int kap = 5) {
        kapasitas = kap;
        jumlah = 0;
        data = new Pasien[kapasitas];
    }

    // Fungsi untuk menambah ukuran array jika penuh
    void resize() {
        kapasitas *= 2;
        Pasien* temp = new Pasien[kapasitas];
        for (int i = 0; i < jumlah; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
    }

    // Fungsi untuk menambah pasien ke antrian
    void enqueue(Pasien p) {
        if (jumlah == kapasitas) resize();
        data[jumlah++] = p;
    }

    // Fungsi untuk menampilkan urutan prioritas pasien
    void tampilkanAntrian() {
        // Urutkan berdasarkan tingkat darurat (descending)
        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                if (data[j].tingkatDarurat < data[j + 1].tingkatDarurat) {
                    // untuk tukar posisi
                    Pasien temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        // untuk menampilkan berapa tingkat darurat setiap pasien
        cout << endl;
        for (int i = 0; i < jumlah; i++) {
            cout << data[i].nama << " (" << data[i].umur << ") - Darurat " << data[i].tingkatDarurat << endl;

        }
    }

    ~QueueDarurat() {
        delete[] data;
    }
};

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;
    cin.ignore();

    QueueDarurat antrian;
    for (int i = 0; i < n; i++) {
        Pasien p;
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, p.nama);
        cout << "Jenis hewan: ";
        getline(cin, p.jenis);
        cout << "Umur: ";
        getline(cin, p.umur);

        cout << "Tingkat darurat (1-5): ";
        cin >> p.tingkatDarurat;
        cin.ignore();

        antrian.enqueue(p);
    }

    antrian.tampilkanAntrian();
    return 0;
}
