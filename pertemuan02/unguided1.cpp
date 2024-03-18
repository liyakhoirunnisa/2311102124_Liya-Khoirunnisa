/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;

// Program untuk mencari nomor genap dan ganjil berdasarkan data array yang diinputkan
int main() {

    // Deklarasi array untuk menyimpan 10 angka dari inputan pengguna
    int data_2124[10];

    // Meminta pengguna untuk memasukkan 10 angka dengan perulangan for
    cout << "Masukkan 10 angka: ";
    for(int i = 0; i < 10; i++) {
        cin >> data_2124[i];
    }

    // Menampilkan data array yang telah diinputkan pengguna dengan perulangan for
    cout << "Data Array: ";
    for(int i = 0; i < 10; i++) {
        cout << data_2124[i] << " "; // Menampilkan data array
    }
    cout << endl;

    // Menampilkan nomor genap dari data array yang telah diinputkan pengguna dengan perulangan for
    cout << "Nomor Genap: ";
    for(int i = 0; i < 10; i++) {
        if(data_2124[i] % 2 == 0) {
            cout << data_2124[i] << ", "; // menampilkan nomor genap

        }
    }
    cout << endl;

    // Menampilkan nomor ganjil dari data array yang telah diinputkan pengguna dengan perulangan for
    cout << "Nomor Ganjil: ";
    for(int i = 0; i < 10; i++) {
        if(data_2124[i] % 2 != 0) {
            cout << data_2124[i] << ", "; // Menampilkan nomor ganjil
        }
    }
    cout << endl;

    return 0;
}
