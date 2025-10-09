#include <iostream>
using namespace std;

// fungsi untuk menukar dua buah elemen
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// fungsi untuk memilih pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // pivot
    int i = low;
    int j = high; // indeks elemen yang lebih kecil
    while (true){
        while(i <= high && arr[i] <= pivot) 
        i++;

        while(j >= low && arr[j] > pivot) 
        j--;

        if(i < j){
            break;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j; // mengembalikan indeks pivot
}

// fungsi rekursif
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // mempartisi array

        // memanggil quickSort secara rekursif pada sub-array
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Panggil fungsi Quick Sort untuk mengurutkan data
    quickSort(data, 0, n - 1);

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}