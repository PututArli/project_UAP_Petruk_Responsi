# project_UAP_Petruk_Responsi

KELOMPOK 3

Ketua Kelompok:
1. Wisnu Wira Winata (2417051035)

Anggota Kelompok: 
1. Rafael Putut Arli (2417051042)
2. Miqdad Dzakiy Arroyan (2417051044)
3. Athallah Wildan Rafi (2417051004)

Judul ide: Sistem Rekomendasi Paket Camilan Berdasarkan Preferensi Pelanggan.
Divide:
Semua data camilan dibagi ke dalam beberapa kelompok berdasarkan kategori rasa, contohnya:
- Pedas
- Manis
- Gurih
- Campuran
Hal ini dilakukan agar proses pengurutan dan pemilihan lebih fokus dan sesuai dengan selera pelanggan.

Conquer:
Setiap kelompok kategori camilan (misalnya semua yang pedas) akan diurutkan berdasarkan rasio kepuasan terhadap harga (misalnya rating ÷ harga).
Pengurutan dilakukan menggunakan Merge Sort, yaitu:
- Data dibagi dua secara rekursif sampai ukurannya kecil.
- Masing-masing bagian diurutkan.
Tujuannya adalah menempatkan camilan yang paling "worth it" di posisi teratas untuk memudahkan pemilihan.

Combine:
Setelah semua camilan dalam kategori terurut, program akan:
- Memilih kombinasi terbaik dari camilan-camilan tersebut 
- Dan batas anggaran (misalnya maksimal Rp20.000)