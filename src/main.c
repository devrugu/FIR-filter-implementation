#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "headers/ciz.h"               //sinyal cizim islemi
#include "headers/hamming_convolve.h"  //FIR filtre olusturma ve konvolusyon islemi
#include "headers/wav.h"               //wave dosyasi okuma yazma islemi
#include "headers/kontrol.h"           //error kontrolleri

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Dogru Kullanim: %s <giris_dosyasi.wav> <alt_frekans> <ust_frekans> <katsayilarin_sayisi>\n", argv[0]);
        return 1;
    }

    if (kontrol(argc, argv))
        return 1;

    const char *dosya_adi = argv[1];
    uint32_t alt_frekans = atoi(argv[2]);
    uint32_t ust_frekans = atoi(argv[3]);
    uint32_t katsayilarin_sayisi = atoi(argv[4]);

    wav_baslik baslik;
    double *giris_ornekleri;
    double *cikis_ornekleri;

    wav_oku(dosya_adi, &baslik, &giris_ornekleri);

    double *filtre_katsayilari = (double *)malloc(sizeof(double) * katsayilarin_sayisi);

    //filtre olustur
    FIR_bantgeciren_filtre_tasarla(alt_frekans, ust_frekans, baslik.ornekleme_orani, katsayilarin_sayisi, filtre_katsayilari);

    uint32_t ornek_sayisi = baslik.veri_buyuklugu / (baslik.ornek_basina_bit / 8);
    konvolusyon(filtre_katsayilari, katsayilarin_sayisi, giris_ornekleri, &cikis_ornekleri, ornek_sayisi);
    wav_yaz("cikis.wav", &baslik, cikis_ornekleri);

    orijinal_sinyal_ciz(ornek_sayisi, giris_ornekleri);
    filtrelenmis_sinyal_ciz(ornek_sayisi, cikis_ornekleri);
    //filtreyi_ciz(katsayilarin_sayisi, filtre_katsayilari);

    system("orijinal_sinyal.png");
    system("filtrelenmis_sinyal.png");

    free(giris_ornekleri);
    free(cikis_ornekleri);
    free(filtre_katsayilari);

    return 0;
}
