#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) { //fungsi untuk menggabungkan array yang sudah terurut
   
    int n1 = mid - left + 1; //n1 sebagai jumlah elemen di sebelah kiri
    int n2 = right - mid;    //n2 sebagai jumlah elemen di sebelah kanan

    vector<int> L(n1), R(n2); //tempat sementara untuk simpan data kiri dan kanan

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; //L[i] adalah tempat sementara untuk simpan data bagian kiri
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; //R[j] adalah tempat sementara untuk simpan data bagian kanan


    int i = 0; //index awal elemen bagian kiri  
    int j = 0; //index awal elemen bagian kanan
    int k = left; //index awal array utama yang akan digabungkan


    while (i < n1 && j < n2) { //jalankan perulangan sampai semua elemen diperiksa
        if (L[i] <= R[j]) { //jika elemen kiri lebih kecil atau sama
            arr[k] = L[i]; //maka elemen kiri dimasukkan ke array utama
            i++; //lanjut ke elemen berikutnya (pada bagian kiri)
        } else { //jika elemen kanan lebih kecil
            arr[k] = R[j]; //maka elemen kanan dimasukkan ke array utama
            j++;  //lanjut ke elemen berikutnya (pada bagian kanan)
        }
        k++; //geser ke elemen berikutnya pada array utama
    }

    // Jika masih ada sisa elemen di L, masukkan semuanya ke array utama
    while (i < n1) { 
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika masih ada sisa elemen di R, masukkan semuanya ke array utama
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right) //memeriksa berapa isi array, jika hanya 1 elemen atau bahkan tidak ada
        return; //maka berhenti dan mengembalikan nilai tersebut

    int mid = left + (right - left) / 2; // mencari titik tengah untuk membagi array

    mergeSort(arr, left, mid); // Rekursif untuk bagian kiri
    mergeSort(arr, mid + 1, right); // Rekursif untuk bagian kanan
   
    merge(arr, left, mid, right); //panggil fungsi merge (untuk menggabungkan bagian yg sudah terurut)
}


void printArray(const vector<int>& arr) { //fungsi untuk menampilkan setiap elemen array
    for (int i = 0; i < arr.size(); i++) { //dimulai dari index 0 hingga index terakhir
        cout << arr[i] << " "; //tampilkan setiap elemen dengan spasi
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n; // Input jumlah elemen array
   
    vector<int> data(n); // Deklarasi vector dengan ukuran n (jumlah yang dimasukkan user)
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i]; // Input tiap elemen array
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data); // tampilkan array sebelum diurutkan
   
    mergeSort(data, 0, n - 1); // Panggil fungsi mergesort dari indeks 0 sampai n-1
   
    cout << "Array setelah diurutkan: ";
    printArray(data); // tampilkan array setelah diurutkan
   
    return 0;
}
