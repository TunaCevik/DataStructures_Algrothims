#include <stdio.h>

// Bir sayının belirli bir dizide kaç kez tekrarlandığını bulan fonksiyon
int tekrarSayisiBul(int dizi[], int boyut, int aranan) {
    int tekrarSayisi = 0;
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) {
            tekrarSayisi++;
        }
    }
    return tekrarSayisi;
}
//önceden yoksa ekliyor
// Bir sayının belirli bir dizide tekrar edip etmediğini kontrol eden fonksiyon
int tekrarEdiyorMu(int dizi[], int boyut, int aranan) {
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) {
            return 1; // Eğer aranan sayı dizide bulunursa 1 döndür
        }
    }
    return 0; // Bulunmazsa 0 döndür
}

int main() {
    int dizi1[] = {1, 2, 3, 3, 3, 1, 2};
    int dizi2[] = {2, 2, 2, 2, 8, 6, 8};
    int dizi3[] = {3, 3, 3, 9, 10, 10, 10};
    int dizi4[] = {1, 1, 1, 7, 9, 9, 9};
    
    int boyut1 = sizeof(dizi1) / sizeof(dizi1[0]);
    int boyut2 = sizeof(dizi2) / sizeof(dizi2[0]);
    int boyut3 = sizeof(dizi3) / sizeof(dizi3[0]);
    int boyut4 = sizeof(dizi4) / sizeof(dizi4[0]);
    
    // Her dizi için en fazla boyut kadar tekrar edebilir
    int tekrarEdenlerDizi1[boyut1];
    int tekrarEdenlerDizi2[boyut2];
    int tekrarEdenlerDizi3[boyut3];
    int tekrarEdenlerDizi4[boyut4];
    int tekrarSayilariDizi1[boyut1];
    int tekrarSayilariDizi2[boyut2];
    int tekrarSayilariDizi3[boyut3];
    int tekrarSayilariDizi4[boyut4];
    
    int tekrarEdenlerIndex1 = 0;
    int tekrarEdenlerIndex2 = 0;
    int tekrarEdenlerIndex3 = 0;
    int tekrarEdenlerIndex4 = 0;

    // Dizi 1 için tekrar edenleri bul ve diziye ekle
    for (int i = 0; i < boyut1; i++) {
        if (tekrarEdiyorMu(tekrarEdenlerDizi1, tekrarEdenlerIndex1, dizi1[i]) == 0) {
            int tekrarSayisi = tekrarSayisiBul(dizi1, boyut1, dizi1[i]);
            tekrarEdenlerDizi1[tekrarEdenlerIndex1] = dizi1[i];
            tekrarSayilariDizi1[tekrarEdenlerIndex1] = tekrarSayisi;
            tekrarEdenlerIndex1++;
        }
    } 

    // Dizi 2 için tekrar edenleri bul ve diziye ekle
    for (int i = 0; i < boyut2; i++) {
        if (tekrarEdiyorMu(tekrarEdenlerDizi2, tekrarEdenlerIndex2, dizi2[i]) == 0) {
            int tekrarSayisi = tekrarSayisiBul(dizi2, boyut2, dizi2[i]);
            tekrarEdenlerDizi2[tekrarEdenlerIndex2] = dizi2[i];
            tekrarSayilariDizi2[tekrarEdenlerIndex2] = tekrarSayisi;
            tekrarEdenlerIndex2++;
        }
    }

    // Dizi 3 için tekrar edenleri bul ve diziye ekle
    for (int i = 0; i < boyut3; i++) {
        if (tekrarEdiyorMu(tekrarEdenlerDizi3, tekrarEdenlerIndex3, dizi3[i]) == 0) {
            int tekrarSayisi = tekrarSayisiBul(dizi3, boyut3, dizi3[i]);
            tekrarEdenlerDizi3[tekrarEdenlerIndex3] = dizi3[i];
            tekrarSayilariDizi3[tekrarEdenlerIndex3] = tekrarSayisi;
            tekrarEdenlerIndex3++;
        }
    }

    // Dizi 4 için tekrar edenleri bul ve diziye ekle
    for (int i = 0; i < boyut4; i++) {
        if (tekrarEdiyorMu(tekrarEdenlerDizi4, tekrarEdenlerIndex4, dizi4[i]) == 0) {
            int tekrarSayisi = tekrarSayisiBul(dizi4, boyut4, dizi4[i]);
            tekrarEdenlerDizi4[tekrarEdenlerIndex4] = dizi4[i];
            tekrarSayilariDizi4[tekrarEdenlerIndex4] = tekrarSayisi;
            tekrarEdenlerIndex4++;
        }
    }

    // Dizi 1 için tekrar edenleri ve tekrar sayılarını yazdır
    printf("Dizi 1 icin tekrar eden sayilar ve tekrar sayilari:\n");
    for (int i = 0; i < tekrarEdenlerIndex1; i++) {
        printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi1[i], tekrarSayilariDizi1[i]);
    }

    // Dizi 2 için tekrar edenleri ve tekrar sayılarını yazdır
    printf("\nDizi 2 icin tekrar eden sayilar ve tekrar sayilari:\n");
    for (int i = 0; i < tekrarEdenlerIndex2; i++) {
        printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi2[i], tekrarSayilariDizi2[i]);
    }

    // Dizi 3 için tekrar edenleri ve tekrar sayılarını yazdır
    printf("\nDizi 3 icin tekrar eden sayilar ve tekrar sayilari:\n");
    for (int i = 0; i < tekrarEdenlerIndex3; i++) {
        printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi3[i], tekrarSayilariDizi3[i]);
    }

    // Dizi 4 için tekrar edenleri ve tekrar sayılarını yazdır
    printf("\nDizi 4 icin tekrar eden sayilar ve tekrar sayilari:\n");
    for (int i = 0; i < tekrarEdenlerIndex4; i++) {
        printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi4[i], tekrarSayilariDizi4[i]);
    }

    return 0;
}
