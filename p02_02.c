#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definisi struktur data barang
struct Barang {
    char nama[50];
    int stok;
};

int main() {
    int n, i;
    int total_stok_kategori = 0;
    char kategori_dicari[50];

    printf("=== Program Penghitung Stok Gudang ===\n\n");

    // 1. Input Jumlah Total Data (N)
    printf("Masukkan jumlah jenis barang (N): ");
    if (scanf("%d", &n) != 1) {
        printf("Input tidak valid.\n");
        return 1;
    }
    getchar(); // Membersihkan buffer newline setelah scanf

    struct Barang daftar_barang[n];

    // 2. Input Deret Stok (Nama dan Jumlah)
    for (i = 0; i < n; i++) {
        printf("\nData barang ke-%d\n", i + 1);
        printf("Nama Barang (misal: Gula): ");
        fgets(daftar_barang[i].nama, sizeof(daftar_barang[i].nama), stdin);
        
        // Menghilangkan karakter newline (\n) di akhir input string
        daftar_barang[i].nama[strcspn(daftar_barang[i].nama, "\n")] = 0;

        printf("Jumlah Stok (pcs): ");
        scanf("%d", &daftar_barang[i].stok);
        getchar(); // Membersihkan buffer
    }

    // 3. Input Kategori Barang yang Dicari
    printf("\n------------------------------------\n");
    printf("Masukkan kategori barang yang dicari: ");
    fgets(kategori_dicari, sizeof(kategori_dicari), stdin);
    kategori_dicari[strcspn(kategori_dicari, "\n")] = 0;

    // 4. Proses Pencarian dan Penjumlahan
    int ditemukan = 0;
    for (i = 0; i < n; i++) {
        // Menggunakan stricmp (khusus Windows/MinGW) untuk perbandingan case-insensitive
        if (stricmp(daftar_barang[i].nama, kategori_dicari) == 0) {
            total_stok_kategori += daftar_barang[i].stok;
            ditemukan = 1;
        }
    }

    // Output Hasil
    printf("\n====================================\n");
    if (ditemukan) {
        printf("Total stok untuk '%s' adalah: %d pcs\n", kategori_dicari, total_stok_kategori);
    } else {
        printf("Kategori '%s' tidak ditemukan dalam data.\n", kategori_dicari);
    }
    printf("====================================\n");

    return 0;
}