#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <stack>
#include <ctime>
using namespace std;

struct Snack {
    string nama;
    string kategori;
    int harga;
    float rating;

    Snack(string n, string k, int h, float r){
        nama = n;
        kategori = k;
        harga = h;
        rating = r;
    }

    float rasio(){
        return rating / harga;
    }
};

stack<Snack> historySnack;

vector<Snack> daftarSnack = {
    {"Kerupuk", "gurih" , 5000, 5.0},
    {"Wafer" , "manis" , 10000, 4.6},
    {"Rujak" , "campuran" , 7000, 4.7},
    {"Es Campur" , "campuran", 8000, 4.5},
    {"Tahu Crispy", "gurih" , 5000, 3.0},
    {"Untir-untir", "manis" , 9000, 4.2},
    {"Keripik singkong", "gurih", 10000, 4.0},
    {"Kacang mix", "campuran", 12000, 3.8},
    {"Soes kering", "manis", 15000, 4.4},
    {"Basreng", "pedas", 7000, 5.0},
    {"Keripik kaca", "pedas", 8500, 4.6},
    {"Keripik piscok", "manis", 10000, 4.8},
    {"Makaroni", "pedas", 8000, 4.1},
    {"Keripik pangsit", "pedas", 7000, 4.3},
    {"Semprong", "gurih", 9000, 3.7},
    {"Lemper","gurih",1000,4.0},
    {"Risol","campuran",1000,4.1},
    {"Bakpia","manis",10000,5.0},
    {"Roti Bakar","campuran",10000,4.5},
    {"Permen","manis",500,2.0},
    {"Martabak","campuran",5000,4.0},
    {"Telur gulung","gurih",1000,4.3},
    {"Kuaci","gurih",500,3.5},
    {"Regginang","gurih",5000,4.2},
    {"Donut","campuran",2000,4.6},
    {"Bakso","campuran",12000,4.5},
    {"Somay","campuran",1000,4.5},
    {"Nabati","manis",3000,4.1},
    {"Es teler","manis",5000,4.2},
    {"Es teh","manis",3000,4.6},
    {"Es buah","manis",7000,4.8},
    {"Yakult","campuran",4000,5.0},
    {"Kopi","manis",4000,4.3},
    {"Seblak","pedas",10000,3.5},
    {"Nastar","manis",2000,5.0},
    {"Cireng","gurih",5000,3.9}
};

bool comparerating(Snack a , Snack b){
    return a.rating > b.rating;
}

void tampilkanMenu() {
    cout << "========== MENU CAMILAN ===========\n";
    cout << "1. Lihat Semua Snack\n";
    cout << "2. Lihat Snack Berdasarkan Kategori\n";
    cout << "3. Lihat Riwayat Snack terakhir\n";
    cout << "4. Lihat Snack Berdasarkan Harga\n";
    cout << "5. Rekomendasi Snack hari ini\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu: ";
}

void merge(vector<Snack>& arr , int kiri , int mid , int kanan){
    vector<Snack> arrkiri(arr.begin() + kiri, arr.begin()+ mid + 1);
    vector<Snack> arrkanan(arr.begin() + mid + 1 , arr.begin() + kanan + 1);
    int i = 0 , j = 0 , k = kiri;

    while(i < arrkiri.size() && j < arrkanan.size()){
        if(comparerating(arrkiri[i],arrkanan[j])){
            arr[k++] = arrkiri[i++];
        }else{
            arr[k++] = arrkanan[j++];
        }
    }
    while(i < arrkiri.size()) arr[k++] = arrkiri[i++];
    while(j < arrkanan.size()) arr[k++] = arrkanan[j++];
}

void Mergesort(vector<Snack>& arr, int kiri, int kanan) {
    if (kiri >= kanan) {
        return;
    }
    int mid = (kiri + kanan) / 2;
    Mergesort(arr, kiri, mid);
    Mergesort(arr, mid + 1, kanan);
    merge(arr, kiri, mid, kanan);
}

void lihatSnack() {
    system("cls");
    cout << "\n== Daftar Snack ==\n";
    if (daftarSnack.empty()) {
        cout << "(Belum ada snack)\n";
    } else {
        for (size_t i = 0; i < daftarSnack.size(); ++i) {
            cout << i+1 << ". " << daftarSnack[i].nama << " - " << daftarSnack[i].kategori << " - Rp" << daftarSnack[i].harga << "\n";
        }

        int pilihanSnack;
        cout << "\nPilih snack yang ingin dilihat (1 - " << daftarSnack.size() << "): ";
        cin >> pilihanSnack;
        cin.ignore(); 

        if (pilihanSnack >= 1 && pilihanSnack <= daftarSnack.size()) {
            Snack dilihat = daftarSnack[pilihanSnack - 1];
            historySnack.push(dilihat); 
            cout << "\nKamu melihat: " << dilihat.nama << " - " << dilihat.kategori << " - Rp" << dilihat.harga << " Rating: "<< dilihat.rating << "\n";
        } else {
            cout << "\nPilihan tidak valid.\n";
        }

        cout << "\nTekan enter untuk melanjutkan....\n";
        cin.get();
        system("cls");
    }
    
}

void kategoriSnack(){
    string InputKategori;
    cout << "Masukkan kategori snack (contoh: gurih, manis, pedas, campuran): ";
    getline(cin, InputKategori);
    system("cls");

    vector<Snack> rating;
    for (Snack snack : daftarSnack){
        if (snack.kategori == InputKategori){
            rating.push_back(snack);
        }
    }

    bool ditemukan = false;
    cout << "\n== Snack Kategori " << InputKategori << " ==\n";
    for (Snack snack : daftarSnack){
        if (snack.kategori == InputKategori){
            cout << "- " << snack.nama << " - Rp" << snack.harga << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan){
        cout << ("Tidak ada kategori snack tersebut.\n");
    }

    int pilihan;
    cout << "\nKamu ingin lihat rating atau tidak?\n";
    cout << "1. Lihat berdasarkan rating tertinggi\n";
    cout << "2. Kembali ke menu utama\n";
    cout << "Pilih: ";
    cin >> pilihan;
    cin.ignore();
    system("cls");

    if (pilihan == 1) {
        Mergesort(rating, 0, rating.size() - 1);

        cout << "\n== Snack Kategori " << InputKategori << " (Urut Berdasarkan Rating Tertinggi) ==\n";
        for (Snack snack : rating){
            cout << "- " << snack.nama << " - Rp" << snack.harga << " - Rating: " << snack.rating << "\n";
        }

        cout << "\nTekan Enter untuk kembali ke menu...\n";
        cin.get();
        system("cls");
    }
    cout << endl;
}  

void lihatSnackTerakhir(){
    system("cls");
    if (historySnack.empty()) {
        cout << "Belum ada snack yang dilihat.\n";
    } else {
        Snack terakhir = historySnack.top();
        cout << "Snack terakhir yang dilihat:\n";
        cout << "- " << terakhir.nama << " - " << terakhir.kategori << " - Rp" << terakhir.harga << "\n";
    }
    cout << "\nTekan enter untuk kembali ke menu...\n";
    cin.get();
    system("cls");
}

void BerdasarkanHarga() {
    system("cls");
    int hargaMin, hargaMax;
    cout << "Masukkan rentang harga min: ";
    cin >> hargaMin;
    cout << "Masukkan rentang harga max: ";
    cin >> hargaMax;
    cin.ignore();

    vector<Snack> hasil;
    for (Snack snack : daftarSnack) {
        if (snack.harga >= hargaMin && snack.harga <= hargaMax) {
            hasil.push_back(snack);
        }
    }

    if (hasil.empty()) {
        cout << "\nTidak ada snack dalam rentang harga tersebut.\n";
    } else {
        cout << "\n== Snack dalam Rentang Harga Rp" << hargaMin << " - Rp" << hargaMax << " ==\n";
        for (Snack snack : hasil) {
            cout << "- " << snack.nama << " - Rp" << snack.harga << " - Rating: " << snack.rating << "\n";
        }
    }

    cout << "\nTekan enter untuk kembali ke menu...\n";
    cin.get();
}

void snackhari() {
    system("cls");
    cout << "============= SNACK HARI INI =============\n";
    srand(time(0));

    int randomIndex = rand() % daftarSnack.size();
    Snack rekomendasi = daftarSnack[randomIndex];

    cout << " Rekomendasi spesial untuk kamu hari ini:\n\n";
    cout << " NAMA   : " << rekomendasi.nama << "\n";
    cout << " KATEGORI : " << rekomendasi.kategori << "\n";
    cout << " HARGA  : Rp" << rekomendasi.harga << "\n";
    cout << " RATING : " << rekomendasi.rating << "/5.0\n\n";
    cout << "Coba sekarang juga dan rasakan kenikmatannya!\n";
    cout << "=============================================\n";
    cout << "Snack ini cocok untuk kamu yang suka " << rekomendasi.kategori << ".\n";

    cout << "\nTekan enter untuk kembali...";
    cin.get();
}

int main(){

    int pilihan;
    do{
        tampilkanMenu();

        if (!(cin >> pilihan)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "=== Input tidak valid! ===\n\n";
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            system("cls");
            continue;
        }

        cin.ignore();

        switch(pilihan){
            case 1:
                lihatSnack();
                break;
            case 2:
                kategoriSnack();
                system("cls");
                break;
            case 3:
                lihatSnackTerakhir();
                break;
            case 4:
                BerdasarkanHarga();
                system("cls");
                break;
            case 5:
                snackhari();
                system("cls");
                break;
            case 6:
                cout << "Terima kasih telah melihat menu kami!!\n";
                cout << "Sampai jumpa lagi!\n";
                cin.get();
                system("cls");
                break;
            default:
                cout << "=== Pilihan tidak valid! ===\n\n";
                cout << "Tekan Enter untuk melanjutkan...\n";
                cin.get();
                system("cls");
                break;
        }
    }
    while(pilihan != 6);

    return 0;
}