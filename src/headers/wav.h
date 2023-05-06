// wav.h
#pragma once

// WAV dosyasi baslik yapisi
typedef struct
{
    char riff[4];
    uint32_t overall_size;
    char wave[4];
    char fmt_yigin_isaretleyicisi[4];
    uint32_t fmt_uzunluk;
    uint16_t format_tipi;
    uint16_t kanal_sayisi;
    uint32_t ornekleme_orani;
    uint32_t byte_orani;
    uint16_t blok_hizalama;
    uint16_t ornek_basina_bit;
    char veri_yigin_basligi[4];
    uint32_t veri_buyuklugu;
} wav_baslik;

void wav_oku(const char *dosya_adi, wav_baslik *baslik, double **giris_ornekleri)
{
    FILE *fp = fopen(dosya_adi, "rb");

    if (fp == NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }

    fread(baslik, sizeof(wav_baslik), 1, fp);

    uint32_t ornek_sayisi = baslik->veri_buyuklugu / (baslik->ornek_basina_bit / 8);
    *giris_ornekleri = (double *)malloc(sizeof(double) * ornek_sayisi);

    for (uint32_t i = 0; i < ornek_sayisi; i++)
    {
        int32_t ornek = 0;
        fread(&ornek, baslik->ornek_basina_bit / 8, 1, fp);
        (*giris_ornekleri)[i] = (double)ornek;
    }

    fclose(fp);
}

void wav_yaz(const char *dosya_adi, wav_baslik *baslik, double *cikis_ornekleri)
{
    FILE *fp = fopen(dosya_adi, "wb");

    if (fp == NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }

    fwrite(baslik, sizeof(wav_baslik), 1, fp);

    uint32_t ornek_sayisi = baslik->veri_buyuklugu / (baslik->ornek_basina_bit / 8);

    for (uint32_t i = 0; i < ornek_sayisi; i++)
    {
        int32_t ornek = (int32_t)cikis_ornekleri[i];
        fwrite(&ornek, baslik->ornek_basina_bit / 8, 1, fp);
    }

    fclose(fp);
}