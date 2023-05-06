#include <errno.h>

int kontrol(int argc, char *argv[])
{
	uint32_t Fl, Fu, Fs, N;

    if (argc < 5)
    {
        printf("Dogru kullanim: %s <input_wav_dosyasi> <alt_frekans> <ust_frekans> <filtre_katsylrnn_sayisi>\n", argv[0]);
        return 1;
    }

    if ((sscanf(argv[2], "%u", &Fl) != 1) || (sscanf(argv[3], "%u", &Fu) != 1))
	{
		printf("Error: Alt Frekans ve Ust Frekans degerleri int olmalidir!");
		return 1;
	}

    char *son;
    long deger;
	errno = 0;
    deger = strtol(argv[4], &son, 10);

    if (errno != 0 || *son != '\0' || son == argv[4])
    {
        printf("Error: Filtre katsayilarinin sayisi int olmalidir.\n");
        return 1;
    }

    if ((Fu-Fl) <= 0)
    {
        printf("Alt Frekans degeri Ust Frekans degerinden daha dusuk olmalidir.\n");
        return 1;
    }
    return 0;
}