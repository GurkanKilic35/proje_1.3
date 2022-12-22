#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define max_satir 100
#define max_sutun 50

void olum_yasi_yazdirma(int yas, int tahmin){

    if(yas < tahmin){

        printf("Tahmini olum yasiniz %ddir!!", tahmin);

    }
    else{

        printf("Tahmini olarak 2 yil icinde vefat edeceksiniz!!");

    }

}

void yas_hesaplama(int sonuc, int yas){

    FILE *hesaplama;
    char karakter[max_satir][max_sutun];
    int i, j, satir = 0;

    hesaplama = fopen("hesaplama.txt","r");

    while(!feof(hesaplama) && !ferror(hesaplama)){

        if(fgets(karakter[satir], max_sutun, hesaplama) != NULL){

            satir++;

        }

    }

    system("color 7");

    for(i = 0; i < 85; i++){//hesaplaniyor yazısını kaydıran kısım

        printf("%s", karakter[i]);
        usleep(60000);
        system("cls");

    }

    system("color 7");

    for(j = 0; j < 5; j++){//kurukafanın yanıp sönmesini sağlayan kısım

        system("cls");

        if(sonuc > 1180 && sonuc <= 1310){

            olum_yasi_yazdirma(yas,50);

        }
        else if(sonuc > 1050 && sonuc <= 1180){

            olum_yasi_yazdirma(yas,55);

        }
        else if(sonuc > 925 && sonuc <= 1050){

            olum_yasi_yazdirma(yas,60);

        }
        else if(sonuc > 800 && sonuc <= 925){

            olum_yasi_yazdirma(yas,65);

        } 
        else if(sonuc > 665 && sonuc <= 800){

            olum_yasi_yazdirma(yas,70);

        } 
        else if(sonuc > 550 && sonuc <= 665){

            olum_yasi_yazdirma(yas,75);

        } 
        else if(sonuc > 425 && sonuc <= 550){

            olum_yasi_yazdirma(yas,80);

        } 
        else if(sonuc > 300 && sonuc <= 425){

            olum_yasi_yazdirma(yas,85);

        }
        else if(sonuc > 175 && sonuc <= 300){

            olum_yasi_yazdirma(yas,90);

        }
        else if(sonuc >= 90 && sonuc <= 175){

            olum_yasi_yazdirma(yas,95);

        }

        printf("\n");

        usleep(100000);//tahmini ölüm yaşını yazdıktan sonra 0,1 saniye bekliyor
       
        for(i = 85; i < 93; i++){

            printf("%s", karakter[i]);//kurukafayı yazdırıyor

        }

        printf("\n");

        usleep(500000);//kurukafanın yazılı olarak 0,5 saniye bekliyor

        //for döngüsüne gidip ekranı sildiriyor

    }

    fclose(hesaplama);

}