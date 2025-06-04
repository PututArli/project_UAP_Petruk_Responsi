#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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