#include <stdio.h>
#include <unistd.h>// usleep, sleep fonksiyonunun çalışmasını sağlar
#include <stdlib.h>// system fonksiyonunun çalışmasını sağlıyor
#include "soru_cevap.c"//soru_cevap.c dosyasını bu dosyaya bağlıyor
#define max_satir 100
#define max_sutun 50

//Gürkan Kılıç      22181617005
//Bera Daştan       22181616010
//Asrın Jan Şengül  22181616066

void main(){

    int i;

    system("cls");//ekrandaki yazıları sildiren fonksiyon

    printf("Baslamak icin herhangi bir tusa basiniz\n");
    getch();

    system("cls");

    system("color 4");//ekrandaki yazıların rengini değiştiren fonksiyon

    for(i = 0; i < 5; i++){//çizgilerin yanıp sönmesini sağlayan kısım

        printf("-------------------------------------------\n");
        printf("Olum yasini tahmin eden teste hosgeldiniz!!\n");
        printf("-------------------------------------------\n");

        usleep(500000);//çalışmakta olan dosyayı durdurma fonksiyonu. Girilen değer mikrosaniye olarak alınmakta. mikrosaniye = saniye*10^-6

        system("cls");

        printf("\n");
        printf("Olum yasini tahmin eden teste hosgeldiniz!!\n\n");

        usleep(500000);

        system("cls");

    }

    soru_cevap();//soru_cevap fonksiyonunu çalıştırıyor.

}