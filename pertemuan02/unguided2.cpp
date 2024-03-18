/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;

// Program input array tiga dimensi
int main() {

    // Deklarasi ukuran array
    int sizeI_2124, sizeJ_2124, sizeK_2124;

    // Input ukuran array
    cout << "Masukkan ukuran array (i, j, k): ";
    cin >> sizeI_2124 >> sizeJ_2124 >> sizeK_2124;

    // Deklarasi array
    int array[sizeI_2124][sizeJ_2124][sizeK_2124];

    // Input elemen oleh pengguna dengan perulangan for
    for (int i = 0; i < sizeI_2124; i++) { 
        for (int j = 0; j < sizeJ_2124; j++) { 
            for (int k = 0; k < sizeK_2124; k++) { 
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = "; // Meminta input elemen kepada pengguna
                cin >> array[i][j][k];
            }
        }
        cout << endl;
    }
    
    // Output Array berdasarkan inputan pengguna dengan perulangan for
    for (int i = 0; i < sizeI_2124; i++) {
        for (int j = 0; j < sizeJ_2124; j++) {
            for (int k = 0; k < sizeK_2124; k++) {
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << array[i][j][k] << endl; // Menampilkan data array
            }
        }
    }
    cout << endl;

    // Tampilan array dengan perulangan for
    for (int i = 0; i < sizeI_2124; i++) {
        for (int j = 0; j < sizeJ_2124; j++) {
            for (int k = 0; k < sizeK_2124; k++) {
                cout << array[i][j][k] << ends; // Menampilkan array
            }
            cout << endl;
        }
        cout << endl;
    }
}
