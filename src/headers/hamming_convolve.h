// hamming_convolve.h
#pragma once
#include <math.h>

#define PI 3.14159265358979323846

void FIR_bantgeciren_filtre_tasarla(uint32_t alt_frekans, uint32_t ust_frekans, 
                                    uint32_t ornekleme_orani, uint32_t katsayilarin_sayisi, 
                                    double *filtre_katsayilari)
{
    double Fn = ornekleme_orani / 2.0;
    double Wn1 = (double)alt_frekans / Fn;
    double Wn2 = (double)ust_frekans / Fn;
    double M = (katsayilarin_sayisi - 1) / 2.0;
    for (uint32_t i = 0; i < katsayilarin_sayisi; i++)
    {
        if (i == (uint32_t)M)
        {
            filtre_katsayilari[i] = (Wn2 - Wn1) / PI;
        } else
            {
                filtre_katsayilari[i] = (sin(Wn2 * PI * (i - M)) - sin(Wn1 * PI * (i - M))) / (PI * (i - M));
            }
        filtre_katsayilari[i] *= 0.54 - 0.46 * cos(2 * PI * i / (katsayilarin_sayisi - 1)); // Hamming window
    }
}

void konvolusyon(double *filtre_katsayilari, uint32_t katsayilarin_sayisi, 
                double *giris_ornekleri, double **cikis_ornekleri, uint32_t ornek_sayisi)
{
    *cikis_ornekleri = (double *)malloc(sizeof(double) * ornek_sayisi);
    uint32_t i, j, k;
    double tmp;
    for (k = 0; k < ornek_sayisi; k++)
    {
        tmp = 0;
        for (i = 0; i < katsayilarin_sayisi; i++)
        {
            j = k - i;
            if (j < ornek_sayisi)
            {
                tmp += filtre_katsayilari[i] * giris_ornekleri[j];
            }
        }
        (*cikis_ornekleri)[k] = tmp;
    }
}
