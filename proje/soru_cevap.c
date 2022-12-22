#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "yas_hesaplama.c"
#define max_satir 100
#define max_sutun 50

void yanlis_deger(){

    FILE *yonlendirme;
    char karakter0[max_satir][max_sutun];
    int satir = 0, i;
    
    yonlendirme = fopen("yonlendirme.txt","r");

    while(!feof(yonlendirme) && !ferror(yonlendirme)){

        if(fgets(karakter0[satir], max_sutun, yonlendirme) != NULL){

            satir++;

        }

    }

    printf("Yanlis deger girdiniz!!\n");

    sleep(1);//çalışmakta olan dosyayı durdurma fonsiyonu. Girilen değer saniye olarak alınmakta

    system("cls");

    for(i = 0; i < 48; i++){//Yönlendirme yazısını kaydıran kısım

        printf("%s", karakter0[i]);
        usleep(40000);
        system("cls");

    }

    fclose(yonlendirme);

}

void soru_sor(char satirbaslangic,char satirbitis){

    FILE *sorular;
    char karakter[max_satir][max_sutun];
    int i, satir = 0;

    sorular = fopen("sorular.txt","r");//sorular değişkeni sorular.txt dosyasını okuma olarak açıyor

    //sorular.txt dosyasında bulunan verileri satır satır karakter dizisine aktarıyor

    while(!feof(sorular) && !ferror(sorular)){//!feof dosyanın sonuna geldiğinde 0 olan fonksiyon, !ferror dosyada oluşan sorunlar olduğunda 0 olan fonksiyon

        if(fgets(karakter[satir], max_sutun, sorular) != NULL){

            satir++;

        }

    }
    
    for(i = satirbaslangic; i < satirbitis; i++){

        printf("%s", karakter[i]);//satır satır alınan yazıları yazdırma

    }

    fclose(sorular);//açık olan dosyayı kapatıyor

}

void soru_cevap(){

    char cevap[15];
    int sonuc = 0, i, yas;

    system("color 1");

    do{

        soru_sor(0,1);
        
        scanf("%d", &yas);

        if(yas < 1 || yas > 150){

            yanlis_deger();

        }

    }
    while(yas < 1 || yas > 150);

    system("cls");

    system("color 2");

    do{

        soru_sor(1,6);

        scanf("%d", &cevap[0]);

        switch(cevap[0]){

            case 1:
                sonuc += 50;
                break;
            case 2:
                sonuc += 40;
                break;
            case 3:
                sonuc += 30;
                break;
            case 4: 
                sonuc += 20;
                break;
            default:
                yanlis_deger();
                break;
            
        }

        system("cls");

    }
    while(cevap[0] < 1 || cevap[0] > 4);
    
    system("color 3");

    do{

        soru_sor(6,12);

        scanf("%d", &cevap[1]);

        switch(cevap[1]){

            case 1:
                sonuc += 60;
                break;
            case 2:
                sonuc += 80;
                break;
            case 3:
                sonuc += 20;
                break;
            case 4:
                sonuc += 40;
                break;
            case 5:
                sonuc += 100;
                break;
            default:
                yanlis_deger();
                break;
        
        }

        system("cls");

    }
    while(cevap[1] < 1 || cevap[1] > 5);

    system("color 4");

    do{

        soru_sor(12,15);

        scanf("%d", &cevap[2]);

        if(cevap[2] == 1){

            system("cls");

            do{

                printf("Ne siklikla sigara icersin?\n");
                printf("1-) Haftada 1 paketten az\n");
                printf("2-) Haftada 2-4 paket\n");
                printf("3-) Haftada 5-7 paket\n");
                printf("4-) Haftada 7 paketten fazla\n");
                scanf("%d", &cevap[3]);

                switch(cevap[3]){

                    case 1:
                        sonuc += 40;
                        break;
                    case 2:
                        sonuc += 60;
                        break;
                    case 3:
                        sonuc += 120;
                        break;
                    case 4:
                        sonuc += 200;
                        break;
                    default:
                        yanlis_deger();
                        break;

                }

                system("cls");
                
            }
            while(cevap[3] < 1 || cevap[3] > 4);

        }
        else if(cevap[2] == 2){

            do{

                system("cls");

                printf("Sigara icilen ortamlarda bulunur musun?\n");
                printf("1-) Evet\n");
                printf("2-) Hayir\n");
                scanf("%d", &cevap[4]);

                if(cevap[4] == 1){

                    sonuc += 20;

                }
                else if(cevap[4] == 2);
                else{

                    yanlis_deger();

                }

            }
            while(cevap[4] < 1 || cevap[4] > 2);

        }
        else{

            yanlis_deger();

        }

        system("cls");
        
    }
    while(cevap[2] < 1 || cevap[2] > 2);

    system("color 5");

    do{

        soru_sor(15,18);

        scanf("%d", &cevap[5]);

        if(cevap[5] == 1){

            do{

                system("cls");

                printf("Ne siklikla alkol tuketirsin?\n");
                printf("1-) Ayda 1-2 defa\n");
                printf("2-) Haftada 1-2 defa\n");
                printf("3-) Her gun\n");
                scanf("%d", &cevap[6]);
                
                switch(cevap[6]){

                    case 1:
                        sonuc += 40;
                    case 2:
                        sonuc += 80;
                    case 3:
                        sonuc += 150;
                        break;
                    default:
                        yanlis_deger();
                        break;

                }

            }
            while(cevap[6] < 1 || cevap[6] > 3);

            system("cls");

        }
        else if(cevap[5] == 2);
        else{

            yanlis_deger();

        }

        system("cls");

    }
    while(cevap[5] < 1 || cevap[5] > 2);
    
    system("color 6");
    
    do{

        soru_sor(18,23);

        scanf("%d", &cevap[7]);

        switch(cevap[7]){

            case 1:
                sonuc += 80;
                break;
            case 2:
                sonuc += 50;
                break;
            case 3:
                sonuc += 30;
                break;
            case 4:
                break;
            default:
                yanlis_deger();
                break;

        }

        system("cls");

    }
    while(cevap[7] < 1 || cevap[7] > 4);

    system("color 1");

    do{

        soru_sor(23,27);

        scanf("%d", &cevap[8]);

        switch(cevap[8]){

            case 1:
                sonuc += 80;
                break;
            case 2:
                sonuc += 50;
                break;
            case 3:
                sonuc += 10;
                break;
            default:
                yanlis_deger();
                break;
        
        }

        system("cls");

    }
    while(cevap[8] < 1 || cevap[8] > 3);

    system("color 2");
    
    do{

        soru_sor(27,31);

        scanf("%d", &cevap[9]);

        switch(cevap[9]){

            case 1:
                sonuc += 300;
                break;
            case 2:
                break;
            case 3:
                sonuc += 30;
                break;
            default:
                yanlis_deger();
                break;

        }

        system("cls");

    }
    while(cevap[9] < 1 || cevap[9] > 3);

    system("color 3");

    do{

        soru_sor(31,35);
       
        scanf("%d", &cevap[10]);

        switch(cevap[10]){

            case 1:
                sonuc += 120;
                break;
            case 2:
                sonuc += 50;
                break;
            case 3:
                sonuc += 20;
                break;
            default:
                yanlis_deger();
                break;

        }

        system("cls");

    }
    while(cevap[10] < 1 || cevap[10] > 3);

    system("color 4");

    do{

        soru_sor(35,40);

        scanf("%d", &cevap[11]);

        switch(cevap[11]){

            case 1:
                sonuc += 20;
                break;
            case 2:
                sonuc += 40;
                break;
            case 3:
                sonuc += 60;
                break;
            case 4:
                sonuc += 100;
                break;
            default:
                yanlis_deger();
                break;

        }

        system("cls");

    }
    while(cevap[11] < 1 || cevap[11] > 4);

    system("color 5");

    do{

        soru_sor(40,45);
        
        printf("\n");

        scanf("%d", &cevap[12]);

        switch(cevap[12]){

            case 1:
                sonuc += 100;
                break;
            case 2:
                break;
            case 3:
                sonuc += 70;
                break;
            case 4:
                sonuc += 130;
                break;
            default:
                yanlis_deger();
                break;

        }

        system("cls");

    }
    while(cevap[12] < 1 || cevap[12] > 4);

    yas_hesaplama(sonuc, yas);

}