#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    int beratButet;

    while (1) {
        if (scanf("%s", kode) != 1 || strcmp(kode, "END") == 0) {
            break;
        }
        
        scanf("%d", &beratButet);

        char namaKota[20];
        int hargaPerKg = 0;

        if (strcmp(kode, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            hargaPerKg = 15000;
        } else if (strcmp(kode, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            hargaPerKg = 5000;
        } else if (strcmp(kode, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            hargaPerKg = 25000;
        } else if (strcmp(kode, "SBY") == 0) {
            strcpy(namaKota, "Surabaya");
            hargaPerKg = 20000;
        }

        int beratUcok = beratButet + 2; 
        int totalBerat = beratButet + beratUcok;
        int totalOngkos = totalBerat * hargaPerKg;
        char promo[100] = "Tidak ada promo";

        if (totalBerat > 10) {
            totalOngkos = totalOngkos * 0.9;
            strcpy(promo, "Diskon 10% (Total Berat > 10kg)");
        } else if (totalBerat > 5) {
            totalOngkos -= 5000;
            strcpy(promo, "Potongan Rp 5.000 (Total Berat > 5kg)");
        }

        printf("========= STRUK PEMBAYARAN DEL-EXPRESS =========\n");
        printf("Kota tujuan         : %s\n", namaKota);
        printf("Berat paket Butet   : %d kg\n", beratButet);
        printf("Berat paket Ucok    : %d kg\n", beratUcok);
        printf("Total berat         : %d kg\n", totalBerat);
        printf("Total ongkos kirim  : Rp %d\n", totalOngkos);
        printf("Informasi promo     : %s\n", promo);
        printf("================================================\n\n");
    }

    return 0;
}