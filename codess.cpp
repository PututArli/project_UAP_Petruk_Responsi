#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Snack {
    string nama;
    string kategori;
    int rating;
    int harga;

    Snack(string n, string k, int h, float r = 4.0){
        nama = n;
        kategori = k;
        rating = r;
        harga = h;
    }

    float rasio(){
        return rating / harga;
    }
};

vector<Snack> daftarSnack = {
    {"Kerupuk", "Gurih" , 5000},
    {"Wafer" , "Manis" , 10000},
    {"Rujak" , "Campuran" , 7000},
    {"Es Campur" , "Campuran", 8000},
    {"Tahu Crispy", "Gurih" , 5000}
};

bool comparerasio(Snack a , Snack b){
    return a.rasio() > b.rasio();
}

void tampilkanMenu() {
    cout << "=== MENU CAMILAN ===\n";
    cout << "1. Lihat Semua Snack\n";
    cout << "2. Lihat Snack Berdasarkan Kategori\n";
    cout << "3. Keluar\n";
    cout << "Pilih menu: ";
}

void merge(vector<Snack>& arr , int kiri , int mid , int kanan){
    vector<Snack> arrkiri(arr.begin() + kiri, arr.begin()+ mid + 1);
    vector<Snack> arrkanan(arr.begin() + mid + 1 , arr.begin() + kanan + 1);
    int i = 0 , j = 0 , k = kiri;

    while(i < arrkiri.size() && j < arrkanan.size()){
        if(comparerasio(arrkiri[i],arrkanan[j])){
            arr[k++] = arrkiri[i++];
        }else{
            arr[k++] = arrkanan[j++];
        }
    }
    while(i < arrkiri.size()) arr[k++] = arrkiri[i++];
    while(j < arrkanan.size()) arr[k++] = arrkanan[j++];
}

void Mergesort(vector<Snack> arr , int kiri, int kanan){
    if(kiri >= kanan){
        return;
    }
    int mid = (kiri+kanan)/2;
    Mergesort(arr,kiri,mid);
    Mergesort(arr, mid + 1, kanan);
    merge(arr, kiri,mid,kanan);
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
                lihatSnack();
                cin.ignore();
                cin.get();
                system("cls");
                break;
            
            case 2:
                //aku belum bikin fungsinya :v
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