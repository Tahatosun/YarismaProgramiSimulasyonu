#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Anamenu();
void istatistikAltmenusu();
void YeniYarisma();
void Cikis();
void siralama(int [][4],int);
void SonucYazdir(int [][4],int);

int main()
{
    Anamenu();
    return 0;
}
void Cikis()
{
        char cevap;
        printf("Cikmak istediginizden emin misiniz ?");
        scanf("%s",&cevap);

                switch(cevap)
                {
                case 'e':
                case 'E':
                    exit(0);
                    break;
                case 'h' :
                case 'H':
                    Anamenu();
                    break;
                default:
                    printf("GECERSIZ SECIM YAPTINIZ!\n");
                    Cikis();

                }
}
void Anamenu()
{
    int secim;

    printf("\tANA MENU\n");
    printf("1. Yeni Yarisma Duzenleme\n");
    printf("2. Son Duzenlenen Yarismanin Istatistiklerini Goruntuleme\n");
    printf("3. Cikis\n");
    printf("Seciminizi giriniz:");
    scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            //yeni yarisma fonksiyonu
            YeniYarisma();
            break;
        case 2:
            //istatistik alt menusu fonksiyonu
            istatistikAltmenusu();
            break;
        case 3:
            Cikis();
                break;
        default:
            printf("\nGecersiz secim yaptiniz!\n\n");

            Anamenu();
            break;


        }
}
void YeniYarisma()
{

    int yarismaciSayisi,randSayi,randomKontrol,haftasayisi;
    int i,j, a,b,c,randomsayaci; //Döngüler için sayaç tanimlamasi


    do
    {
        i=0;
        printf("Yarismaci sayisini giriniz(5-20):");
        scanf("%d",&yarismaciSayisi);

        if(yarismaciSayisi<5 || yarismaciSayisi>20){
                printf("Gecersiz deger girdiniz!\n");
                i=1;
        }


    }while(i!=0);

    do
    {
        i=0;
        printf("Hafta sayisi giriniz(en az 3):");
        scanf("%d",&haftasayisi);

        if(haftasayisi<3)
        {
            printf("Gecersiz deger girdiniz!\n");
            i=1;
        }

    }while(i!=0);

    int HaftalikSeyirciPuanlamasi[yarismaciSayisi];
    int GenelSeyirciPuanlamasi[yarismaciSayisi];

    int Haftalikkocpuanlamasi[yarismaciSayisi][yarismaciSayisi];
    int GenelKocpuanlamasi[yarismaciSayisi][yarismaciSayisi];

    int HaftalikSonuclar[yarismaciSayisi][4];
    int GenelSonuclar[yarismaciSayisi][4];
    int randomSayidizisi[3];


    for(i=0;i<yarismaciSayisi;i++)//Genel Koc Puanlamasi dizisinin ilk degelerini '0' yaptik
    {
        for(j=0;j<yarismaciSayisi;j++)
        {
            GenelKocpuanlamasi[i][j]=0;
        }
    }

    for(i=0; i<yarismaciSayisi; i++)//Genel Seyirci Puanlamasi dizisinin ilk degerlerini '0' yaptik
    {
        GenelSeyirciPuanlamasi[i]=0;
    }

    for(i=0; i<yarismaciSayisi; i++)//Genel Sonuclar dizisinin ilk degerlerini '0' yaptik
    {
        for(j=0; j<4; j++)
        {
            GenelSonuclar[i][j]=0;
        }
    }


    srand(time(NULL));
    for(c=0;c<haftasayisi;c++)
    {
        for(i=0;i<yarismaciSayisi;i++)//Haftalik Koc Puanlamasi dizisinin ilk degerlerini '0' yaptik
        {
            for(j=0;j<yarismaciSayisi;j++)
            {
                    Haftalikkocpuanlamasi[i][j]=0;
            }
        }

        for(i=0; i<yarismaciSayisi; i++)//Haftalik Seyirci Puanlamasi dizisinin ilk degerlerini '0' yaptik
        {
            HaftalikSeyirciPuanlamasi[i]=0;
        }

        for(i=0; i<yarismaciSayisi; i++)//Haftalik Sonuclar dizisinin ilk degerlerini '0' yaptik
        {
            for(j=0; j<4; j++)
            {
                    HaftalikSonuclar[i][j]=0;
            }
        }




        for(a=0; a<yarismaciSayisi; a++)//Her Kocun rastgele yarismacilara puanlarini vermesini saglayan kod blogu
        {

            for(i=0;i<3;i++)//randomsayidizisi elemanlarini -1 e esitledik.
            randomSayidizisi[i]=-1;


            randomsayaci=0;
            while(randomsayaci!=3) //random sayi uretme
            {
                randomKontrol=0;

                randSayi=rand()%yarismaciSayisi;

                for(i=0; i<3; i++) //randomSayidizisi'nin her elemanýna bakar eðer üretilen sayi dizide var ise randomkontrol "1" olur
                {
                    if(randomSayidizisi[i]==randSayi || randSayi==a)
                        randomKontrol=1;
                }

                if(randomKontrol==1) //eger randomKontrol=1 ise assagidaki islemleri yapmadan while döngüsünü basa alir
                {
                    continue;
                }


                randomSayidizisi[randomsayaci]=randSayi;
                randomsayaci++;
            }

            for(i=0;i<3;i++)//
            {
                b=randomSayidizisi[i];
                Haftalikkocpuanlamasi[a][b]=1+i;
            }

        }


            //Random sayi seyirciler icin---------------------

        for(i=0;i<3;i++)//randomsayidizisi elemanlarini -1 e esitledik.
            randomSayidizisi[i]=-1;


            randomsayaci=0;
        while(randomsayaci!=3) //random sayi uretme
        {
                randomKontrol=0;

                randSayi=rand()%yarismaciSayisi;

            for(i=0; i<3; i++) //randomSayidizisi'nin her elemanina bakar eger üretilen sayi dizide var ise randomkontrol "1" olur
            {
                if(randomSayidizisi[i]==randSayi)
                        randomKontrol=1;
            }

            if(randomKontrol==1) //eger randomKontrol=1 ise assagidaki islemleri yapmadan while döngüsünü basa alir
            {
                    continue;
            }


                randomSayidizisi[randomsayaci]=randSayi;
                randomsayaci++;
        }


        for(i=0;i<3;i++)
        {
            b=randomSayidizisi[i];
            HaftalikSeyirciPuanlamasi[b]=(i+1)*(yarismaciSayisi-1);
        }
        //-----------------------------------------------------------------------------------------------------------------------



        for(i=0; i<yarismaciSayisi;i++)//Haftalik seyirci puanlamasi dizisini genel seyirci puanlamasi dizisine atadik
        {
            GenelSeyirciPuanlamasi[i]=GenelSeyirciPuanlamasi[i]+HaftalikSeyirciPuanlamasi[i];
        }

        for(i=0;i<yarismaciSayisi;i++)//Haftalik koc puanlamasi dizisini genel koc puanlamasi dizisine atadik
        {
            for(j=0;j<yarismaciSayisi;j++)
            {
                GenelKocpuanlamasi[i][j]=GenelKocpuanlamasi[i][j]+Haftalikkocpuanlamasi[i][j];
            }
        }


        for(i=0; i<yarismaciSayisi; i++)
        {
            HaftalikSonuclar[i][0]=i+1;
        }

        for(i=0; i<yarismaciSayisi; i++)//Her yarismacinin koclardan aldiklari toplam puani haftalik sonuc dizisine atadik
        {
            a=0;
            for(j=0; j<yarismaciSayisi; j++)
            {
                a+=Haftalikkocpuanlamasi[j][i];
            }
            HaftalikSonuclar[i][1]=a;
        }

        for(i=0; i<yarismaciSayisi; i++)// Her Yarismacinin seyircilerden aldiklari toplam puani haftalik sonuc dizisine atadik
        {
            HaftalikSonuclar[i][2]=HaftalikSeyirciPuanlamasi[i];
        }
        for(i=0; i<yarismaciSayisi;i++)
        {
            HaftalikSonuclar[i][3]=HaftalikSonuclar[i][1]+HaftalikSonuclar[i][2];
        }
        for(i=0; i<yarismaciSayisi; i++)
        {
            GenelSonuclar[i][0]=i+1;
        }
        for(i=0; i<yarismaciSayisi; i++)
        {
            a=0;
            for(j=0; j<yarismaciSayisi; j++)
            {
                a+=GenelKocpuanlamasi[j][i];
            }
            GenelSonuclar[i][1]=a;
        }
        for(i=0; i<yarismaciSayisi; i++)
        {
            GenelSonuclar[i][2]=GenelSeyirciPuanlamasi[i];
        }
        for(i=0; i<yarismaciSayisi;i++)
        {
            GenelSonuclar[i][3]=GenelSonuclar[i][1]+GenelSonuclar[i][2];
        }



        siralama(HaftalikSonuclar,yarismaciSayisi);//Haftalik sonuclari buyukten kucuge siraladik

        siralama(GenelSonuclar,yarismaciSayisi);//Genel sonuclari buyukten kucuge siraladik


        printf("%d.haftanin sonuclari:\n",c+1);
        printf("\tSira No");
        printf("\t\t\tYarismaci No");
        printf("\t\tKoc Puani");
        printf("\t\tSeyirci Puani");
        printf("\t\tToplam Puan");
        printf("\n");

        SonucYazdir(HaftalikSonuclar,yarismaciSayisi);

        printf("\n");
        printf("%d.hafta sonunda genel durum:\n",c+1);
        printf("\tSira No");
        printf("\t\t\tYarismaci No");
        printf("\t\tKoc Puani");
        printf("\t\tSeyirci Puani");
        printf("\t\tToplam Puan");
        printf("\n");

        SonucYazdir(GenelSonuclar,yarismaciSayisi);


    }

Anamenu();

}

void istatistikAltmenusu()
{

    int secim;
    printf("\tISTATISTIK ALT MENUSU\n");
    printf("1. Sadece koclarin puanlamasi dikkate alindiginda genel durumun listelenmesi\n");
    printf("2. Sadece seyircilerin puanlamasi dikkate alindiginda genel durumun listelenmesi\n");
    printf("3. Yarismacilarin her hafta aldiklarıi toplam puanlarin listelenmesi \n");
    printf("4. Yarismacilarin her koctan aldiklari toplam puanlarin listelenmesi \n");
    printf("5. Ana Menu \n");
    printf("Seciminizi giriniz:");
    scanf("%d",&secim);

    switch(secim)
    {
        case 1:
            //1.istatistik fonksiyonu

            break;
        case 2:
            //2.istatistik fonksiyonu
            break;
        case 3:
            //3.istatistik fonksiyonu
            break;
        case 4:
            //4.istatistik fonksiyonu
            break;
        case 5:
            Anamenu();
            break;
        default:
            printf("GECERSIZ SECIM YAPTINIZ!\n");
            istatistikAltmenusu();
                break;
    }

}

void siralama(int x[][4],int a)//Buyukten kucuge siralama fonksiyonu
{
    int g1,g2,g3,g4;
    int i,j;
                for(i=0;i<a;i++)
                {
                    for(j=0;j<a;j++)
                    {
                        if(x[i][3]>x[j][3])
                        {
                            g1=x[j][3];
                            g2=x[j][2];
                            g3=x[j][1];
                            g4=x[j][0];
                            x[j][3]=x[i][3];
                            x[j][2]=x[i][2];
                            x[j][1]=x[i][1];
                            x[j][0]=x[i][0];
                            x[i][3]=g1;
                            x[i][2]=g2;
                            x[i][1]=g3;
                            x[i][0]=g4;
                        }
                         else if(x[i][3]==x[j][3])
                        {
                            if(x[i][1]>x[j][1])
                            {
                                g1=x[j][3];
                                g2=x[j][2];
                                g3=x[j][1];
                                g4=x[j][0];
                                x[j][3]=x[i][3];
                                x[j][2]=x[i][2];
                                x[j][1]=x[i][1];
                                x[j][0]=x[i][0];
                                x[i][3]=g1;
                                x[i][2]=g2;
                                x[i][1]=g3;
                                x[i][0]=g4;

                            }
                            else if(x[i][3]==x[j][3])
                            {
                                if(x[i][0]<x[j][0])
                                {
                                    g1=x[j][3];
                                    g2=x[j][2];
                                    g3=x[j][1];
                                    g4=x[j][0];
                                    x[j][3]=x[i][3];
                                    x[j][2]=x[i][2];
                                    x[j][1]=x[i][1];
                                    x[j][0]=x[i][0];
                                    x[i][3]=g1;
                                    x[i][2]=g2;
                                    x[i][1]=g3;
                                    x[i][0]=g4;

                                }
                            }
                        }
                    }
                }
}

void SonucYazdir(int dizi[][4],int satir)
{
    int i,j;
      for(i=0; i<satir; i++)
        {
            printf("\t%d",i+1);
            for(j=0;j<4;j++)
            {

                printf("\t\t\t%d" ,dizi[i][j]);

            }
                printf("\n");
        }
}

