#include <stdio.h>
#include <math.h>

int main() {
    float tutar, odenen;

    // Kullanıcıdan ürün tutarı ve ödenen parayı alma
    printf("Urun tutarini giriniz (TL): ");
    scanf("%f", &tutar);

    printf("Odenen parayi giriniz (TL): ");
    scanf("%f", &odenen);

    // Kayan noktalı sayı (float) hassasiyet hatasını önlemek için round() ile kuruşa çeviriyoruz
    int kurus = (int)round((odenen - tutar) * 100.0);

    // Banknot Hesaplamaları (Kuruş cinsinden: 200 TL = 20000 kr, vb.)
    int k200 = kurus / 20000; kurus %= 20000;
    int k100 = kurus / 10000; kurus %= 10000;
    int k50  = kurus / 5000;  kurus %= 5000;
    int k20  = kurus / 2000;  kurus %= 2000;
    int k10  = kurus / 1000;  kurus %= 1000;
    int k5   = kurus / 500;   kurus %= 500;
    int k1   = kurus / 100;   kurus %= 100;

    // Madeni Para Hesaplamaları
    int m50  = kurus / 50;   kurus %= 50;
    int m25  = kurus / 25;   kurus %= 25;
    int m10  = kurus / 10;   kurus %= 10;
    int m5   = kurus / 5;    kurus %= 5;
    int m1   = kurus;        // Kalan son 1 kuruşlar

    // Toplam Küpür Sayısı (Hocanın istediği ek kural)
    int toplam_kupur = k200 + k100 + k50 + k20 + k10 + k5 + k1 + m50 + m25 + m10 + m5 + m1;

    // Sonuçları Ekrana Yazdırma
    printf("\n=== PARA USTI DETAYLARI ===\n");
    printf("200 TL : %d adet\n", k200);
    printf("100 TL : %d adet\n", k100);
    printf("50 TL  : %d adet\n", k50);
    printf("20 TL  : %d adet\n", k20);
    printf("10 TL  : %d adet\n", k10);
    printf("5 TL   : %d adet\n", k5);
    printf("1 TL   : %d adet\n", k1);
    printf("50 Kr  : %d adet\n", m50);
    printf("25 Kr  : %d adet\n", m25);
    printf("10 Kr  : %d adet\n", m10);
    printf("5 Kr   : %d adet\n", m5);
    printf("1 Kr   : %d adet\n", m1);
    printf("---------------------------\n");
    printf("Toplam Verilen Kupur Sayisi: %d\n", toplam_kupur);

    return 0;
}