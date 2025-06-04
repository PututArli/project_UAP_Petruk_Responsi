#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Snack {
    char nama[50];
    string kategori;
    int harga;
};

vector<Snack> daftarSnack;

void tampilkanMenu() {
    cout << "=== MENU CAMILAN ===\n";
    cout << "1. Tambah Snack\n";
    cout << "2. Lihat Snack\n";
    cout << "3. Keluar\n";
    cout << "Pilih menu: ";
}

void tambahSnack() {
    Snack s;
    cout << "\n== Tambah Snack ==\n";
    cout << "Nama: ";
    cin.ignore();
    cin.getline(s.nama, 50);
    cout << "Kategori: ";
    getline(cin, s.kategori);
    cout << "Harga: ";
    cin >> s.harga;
    daftarSnack.push_back(s);
    cout << "Snack berhasil ditambahkan!\n\n";
}

void lihatSnack() {
    cout << "\n== Daftar Snack ==\n";
    if (daftarSnack.empty()) {
        cout << "(Belum ada snack)\n";
    } else {
        for (size_t i = 0; i < daftarSnack.size(); ++i) {
            cout << i+1 << ". " << daftarSnack[i].nama << " - " << daftarSnack[i].kategori << " - Rp" << daftarSnack[i].harga << "\n";
        }
    }
    cout << endl;
}

int main(){

    int pilihan;
    do{
        tampilkanMenu();
        cin >> pilihan;
        switch(pilihan){
            case 1:
                tambahSnack();
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 2:
                lihatSnack();
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 3:
                cout << "Keluar..\n";
                return 0;
            default:
                cout << " Pilihan tidak valid!\n";
        }
    }
    while(pilihan != 3);

    return 0;
}