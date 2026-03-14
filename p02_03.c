#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* --- DEFINISI STRUKTUR --- */
// Struktur untuk data menu tetap
typedef struct {
    char nama[50];
    int harga;
} Menu;

// Struktur untuk menyimpan item yang dipesan
typedef struct {
    char nama[50];
    int jumlah;
    int subtotal;
} ItemPesanan;

/* --- VARIABEL GLOBAL --- */
Menu daftarMenu[5];
ItemPesanan keranjang[100];
int totalItemDipesan = 0;

/* --- PROTOTIPE FUNGSI --- */
void inisialisasiMenu();
void tampilkanMenu();
void pesanMenu();
void lihatTotal();
void pembayaran();
void bersihkanBuffer();

int main() {
    int pilihan;
    inisialisasiMenu();

    do {
        printf("\n==========================================\n");
        printf("   KAFETARIA INSTITUT TEKNOLOGI DEL\n");
        printf("==========================================\n");
        printf("1. Daftar Menu\n");
        printf("2. Pesan Makanan/Minuman\n");
        printf("3. Lihat Total Pesanan\n");
        printf("4. Pembayaran\n");
        printf("5. Keluar\n");
        printf("------------------------------------------\n");
        printf("Pilih menu (1-5): ");
        
        // Proteksi input agar tidak looping jika user memasukkan huruf
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid! Masukkan angka.\n");
            bersihkanBuffer();
            continue;
        }

        switch (pilihan) {
            case 1: tampilkanMenu(); break;
            case 2: pesanMenu(); break;
            case 3: lihatTotal(); break;
            case 4: pembayaran(); break;
            case 5: printf("Keluar... Mauliate!\n"); break;
            default: printf("Pilihan menu tidak tersedia.\n");
        }
    } while (pilihan != 5);

    return 0;
}

// Mengisi Array of Struct Menu dengan data sesuai permintaan
void inisialisasiMenu() {
    strcpy(daftarMenu[0].nama, "Pisang Kulit Lumpiah"); daftarMenu[0].harga = 10000;
    strcpy(daftarMenu[1].nama, "Pisang Coklat");       daftarMenu[1].harga = 10000;
    strcpy(daftarMenu[2].nama, "Roti Isi Ayam");       daftarMenu[2].harga = 15000;
    strcpy(daftarMenu[3].nama, "Cappuccino");          daftarMenu[3].harga = 8000;
    strcpy(daftarMenu[4].nama, "Es Teh");              daftarMenu[4].harga = 5000;
}

void tampilkanMenu() {
    printf("\n--- DAFTAR MENU ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %-20s | Rp %d\n", i + 1, daftarMenu[i].nama, daftarMenu[i].harga);
    }
}

void pesanMenu() {
    int pilihanMenu, qty;
    tampilkanMenu();
    printf("\nMasukkan nomor menu: ");
    scanf("%d", &pilihanMenu);

    // Validasi apakah nomor menu ada dalam array
    if (pilihanMenu < 1 || pilihanMenu > 5) {
        printf("Menu tidak ditemukan!\n");
        return;
    }

    printf("Jumlah pesanan: ");
    scanf("%d", &qty);

    if (qty <= 0) {
        printf("Jumlah pesanan minimal 1!\n");
        return;
    }

    // Memasukkan ke dalam Array of Struct keranjang
    int index = pilihanMenu - 1;
    strcpy(keranjang[totalItemDipesan].nama, daftarMenu[index].nama);
    keranjang[totalItemDipesan].jumlah = qty;
    keranjang[totalItemDipesan].subtotal = daftarMenu[index].harga * qty;
    
    totalItemDipesan++;
    printf("Pesanan ditambahkan ke daftar.\n");
}

void lihatTotal() {
    if (totalItemDipesan == 0) {
        printf("\nBelum ada pesanan.\n");
        return;
    }

    int grandTotal = 0;
    printf("\n--- DAFTAR PESANAN ANDA ---\n");
    for (int i = 0; i < totalItemDipesan; i++) {
        printf("%-20s x %d = Rp %d\n", keranjang[i].nama, keranjang[i].jumlah, keranjang[i].subtotal);
        grandTotal += keranjang[i].subtotal;
    }
    printf("---------------------------\n");
    printf("Total yang harus dibayar: Rp %d\n", grandTotal);
}

void pembayaran() {
    if (totalItemDipesan == 0) {
        printf("\nTidak ada tagihan yang harus dibayar.\n");
        return;
    }

    int totalTagihan = 0;
    for (int i = 0; i < totalItemDipesan; i++) {
        totalTagihan += keranjang[i].subtotal;
    }

    int uang;
    printf("\nTotal Tagihan: Rp %d\n", totalTagihan);
    printf("Masukkan Uang Pembayaran: Rp ");
    scanf("%d", &uang);

    if (uang < totalTagihan) {
        printf("Uang tidak cukup! Kurang: Rp %d\n", totalTagihan - uang);
    } else {
        printf("Pembayaran Berhasil!\n");
        printf("Kembalian: Rp %d\n", uang - totalTagihan);
        // Reset pesanan untuk sesi berikutnya
        totalItemDipesan = 0;
    }
}

void bersihkanBuffer() {
    while (getchar() != '\n');
}