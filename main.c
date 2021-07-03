#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Arac{
	int plaka;
	char model[50];
	char renk[50];
	int ucret;
	_Bool musait;
};

struct Musteri{
	int musteri_no;
	char isim[50];
	char soyisim[50];
	char memleket[50];
};

struct Kiralama{
	int plaka;
	int musteri_no;
	char kiralama_tarihi[10];
	char iade_tarihi[10];
};

void arac_ekle(){
	struct Arac arac;	
	printf("Plaka giriniz: ");
	scanf("%d",&arac.plaka);
	printf("Renk giriniz: ");
	scanf("%s",&arac.renk);
	printf("Ucret (gunluk kiralik bedeli) giriniz: ");
	scanf("%d",&arac.ucret);
	printf("Musaitlik (1 veya 0) giriniz: ");
	scanf("%d",&arac.musait);
	FILE *dosya;
	dosya = fopen("arac.txt", "a+");
	fprintf(dosya,"\n%d\t%s\t%d\t%lld",arac.plaka,arac.renk,arac.ucret,arac.musait);
	fclose(dosya);
}

void arac_listele(){
	struct Arac arac;
	FILE *dosya;
	dosya = fopen("arac.txt", "r+");
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
		printf("\n%d\t%s\t%d\t%d",arac.plaka,arac.renk,arac.ucret,arac.musait);
	}
	fclose(dosya);
}

void arac_ara(){
	int i=0;
	struct Arac arac;
	struct Arac eslesme;
	printf("Plaka Giriniz: ");
	scanf("%d",&eslesme.plaka);	
	FILE *dosya;
	dosya = fopen("arac.txt", "r+");
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
		if(arac.plaka==eslesme.plaka){
			eslesme=arac;
			i++;
		}
	}
	fclose(dosya);
	if(i>0)
		printf("\n%d\t%s\t%d\t%d",eslesme.plaka,eslesme.renk,eslesme.ucret,eslesme.musait);
	else
		printf("HATA!! Arac Bulunamadi");
}

void arac_sil(){
	int plaka;
	printf("Plaka Giriniz: ");
	scanf("%d",&plaka);
	struct Arac arac;
	FILE *dosya,*dosya2;
	dosya = fopen("arac.txt", "r+");
	dosya2 = fopen("Temp.txt","a+");
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
		if(arac.plaka!=plaka){
			fprintf(dosya2,"\n%d\t%s\t%d\t%d",arac.plaka,arac.renk,arac.ucret,arac.musait);
		}
	}
	fclose(dosya);
	fclose(dosya2);
	remove("arac.txt");
	rename("Temp.txt","arac.txt");
}

void musteri_ekle(){
	struct Musteri musteri;	
	printf("Musteri no giriniz: ");
	scanf("%d",&musteri.musteri_no);
	printf("Ýsim giriniz: ");
	scanf("%s",&musteri.isim);
	printf("Soyisim giriniz: ");
	scanf("%s",&musteri.soyisim);
	printf("Memleket giriniz: ");
	scanf("%s",&musteri.memleket);
	FILE *dosya;
	dosya = fopen("musteri.txt", "a+");
	fprintf(dosya,"\n%d\t%s\t%s\t%s",musteri.musteri_no,musteri.isim,musteri.soyisim,musteri.memleket);
	fclose(dosya);
}

void musteri_listele(){
	struct Musteri musteri;
	FILE *dosya;
	dosya = fopen("musteri.txt", "r+");
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%s\t%s",&musteri.musteri_no,&musteri.isim,&musteri.soyisim,&musteri.memleket);
		printf("\n%d\t%s\t%s\t%s",musteri.musteri_no,musteri.isim,musteri.soyisim,musteri.memleket);
	}
	fclose(dosya);
}

void musteri_ara(){
	int i=0;
	struct Musteri musteri;
	struct Musteri eslesme;
	printf("Isim Giriniz: ");
	scanf("%s",&eslesme.isim);
	FILE *dosya;
	dosya = fopen("musteri.txt", "r+");
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%s\t%s",&musteri.musteri_no,musteri.isim,musteri.soyisim,musteri.memleket);
		if(!strcmp(musteri.isim,eslesme.isim)){
			eslesme=musteri;
			i++;
		}
	}
	fclose(dosya);
	if(i>0)
		printf("\n%d\t%s\t%s\t%s",eslesme.musteri_no,eslesme.isim,eslesme.soyisim,eslesme.memleket);
	else
		printf("HATA!! Kullanici Bulunamadi");
}

void musteri_sil(){
	int no;
	printf("Musteri No Giriniz: ");
	scanf("%d",&no);
	struct Musteri musteri;
	FILE *dosya,*dosya2;
	dosya = fopen("musteri.txt", "r+");
	dosya2 = fopen("Temp.txt","a+");
	while(!feof(dosya)){
		fscanf(dosya,"\n%d\t%s\t%s\t%s",&musteri.musteri_no,&musteri.isim,&musteri.soyisim,&musteri.memleket);
		if(musteri.musteri_no!=no){
			fprintf(dosya2,"\n%d\t%s\t%s\t%s",musteri.musteri_no,musteri.isim,musteri.soyisim,musteri.memleket);
		}
	}
	fclose(dosya);
	fclose(dosya2);
	remove("musteri.txt");
	rename("Temp.txt","musteri.txt");
}

void kirala(){
	struct Arac arac;
	struct Musteri musteri;
	struct Kiralama kiralama;
	FILE *dosya,*dosya2,*dosya3,*dosya4;
	while(1){
		int i=0;
		int plaka;
		printf("Plaka Giriniz: ");
		scanf("%d",&plaka);
		dosya = fopen("arac.txt", "r+");
		while(!feof(dosya)){
			fscanf(dosya,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
			if(arac.plaka==plaka){
				i++;
				if(arac.musait==0){
					printf("Bu arac musait degil.\n");
				}
				else
					kiralama.plaka=arac.plaka;
			}
		}
		fclose(dosya);
		if(kiralama.plaka==plaka){
			dosya4 = fopen("Temp.txt", "a+");
			dosya = fopen("arac.txt", "r+");
			while(!feof(dosya)){
				fscanf(dosya,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
				if(arac.plaka==kiralama.plaka){
					arac.musait=0;
				}
				fprintf(dosya4,"\n%d\t%s\t%d\t%d",arac.plaka,arac.renk,arac.ucret,arac.musait);
			}
		fclose(dosya);
		fclose(dosya4);
		remove("arac.txt");
		rename("Temp.txt","arac.txt");
		break;
		}
		else if(i==0)
			printf("HATA!! Arac bulunamadi\n");
	}
	
	while(1){
		int no;
		printf("Musteri No Giriniz: ");
		scanf("%d",&no);	
		dosya2 = fopen("musteri.txt", "r+");
		while(!feof(dosya2)){
			fscanf(dosya2,"%d\t%s\t%s\t%s",&musteri.musteri_no,&musteri.isim,&musteri.soyisim,&musteri.memleket);
			if(musteri.musteri_no==no){
				kiralama.musteri_no=musteri.musteri_no;
			}
		}
		fclose(dosya2);
		if(kiralama.musteri_no==no)
			break;
	}
	int gun,ay,yil;
	printf("Tarih (GG.AA.YYYY) giriniz: ");
	scanf("%s",&kiralama.kiralama_tarihi);
	dosya3=fopen("kiralama.txt","a+");
	fprintf(dosya3,"\n%d\t%d\t%s",kiralama.plaka,kiralama.musteri_no,kiralama.kiralama_tarihi);
	fclose(dosya3);
}

void iade(){
	struct Arac arac,eslesmearac;
	struct Musteri musteri;
	struct Kiralama kiralama,eslesmekiralama;
	int plaka,ucret;
	int gun,gun1,ay,ay1,yil,yil1;
	char iade[10];
	FILE *dosya,*dosya2;
	while(1){
		printf("Plaka Giriniz: ");
		scanf("%d",&plaka);
		dosya = fopen("kiralama.txt", "r+");
		while(!feof(dosya)){
			fscanf(dosya,"%d\t%d\t%d.%d.%d",&kiralama.plaka,&kiralama.musteri_no,&gun,&ay,&yil);
			if(kiralama.plaka==plaka){
				eslesmekiralama=kiralama;
				dosya2 = fopen("arac.txt", "r+");
				while(!feof(dosya2)){
					fscanf(dosya2,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
					if(arac.plaka==eslesmekiralama.plaka){
						eslesmearac=arac;
						break;
					}
				}
				fclose(dosya2);
				break;
			}
		}
		fclose(dosya);
		if(plaka==eslesmekiralama.plaka)
			break;
		else
			printf("Hata!! Kirada arac bulunamadi\n");
	}
	while(1){
		printf("Iade tarihi(GG.AA.YYYY) giriniz: ");
		scanf("%d.%d.%d",&gun1,&ay1,&yil1);
		yil1*=12;
		ay1+=yil1;
		ay1*=30;
		gun1+=ay1;
		yil*=12;
		ay+=yil;
		ay*=30;
		gun+=ay;
		gun1-=gun;
		if(gun1==0){
			printf("Ucret=%d",eslesmearac.ucret);
			break;
		}
		else if(gun1>0){
			ucret=gun1*eslesmearac.ucret;
			printf("Ucret=%d",ucret);
			break;
		}
		else
			printf("Hata!! Negatif hesaplama bulundu\n");
	}
	while(1){
		if(eslesmearac.plaka==plaka){
		dosya2 = fopen("Temp.txt", "a+");
		dosya = fopen("arac.txt", "r+");
		while(!feof(dosya)){
			fscanf(dosya,"%d\t%s\t%d\t%d",&arac.plaka,&arac.renk,&arac.ucret,&arac.musait);
			if(arac.plaka==eslesmearac.plaka){
				arac.musait=1;
			}
			fprintf(dosya2,"\n%d\t%s\t%d\t%d",arac.plaka,arac.renk,arac.ucret,arac.musait);
		}
		fclose(dosya2);
		fclose(dosya);		
		remove("arac.txt");
		rename("Temp.txt","arac.txt");
		break;
		}
	}
	while(1){
		if(eslesmekiralama.plaka==plaka){
		dosya2 = fopen("Temp.txt", "a+");
		dosya = fopen("kiralama.txt", "r+");
		while(!feof(dosya)){
			fscanf(dosya,"%d\t%d\t%s",&kiralama.plaka,&kiralama.musteri_no,&kiralama.kiralama_tarihi);
			if(kiralama.plaka!=eslesmekiralama.plaka){
				fprintf(dosya2,"\n%d\t%d\t%s",kiralama.plaka,kiralama.musteri_no,kiralama.kiralama_tarihi);
			}
		}
		fclose(dosya2);
		fclose(dosya);		
		remove("kiralama.txt");
		rename("Temp.txt","kiralama.txt");
		break;
		}
	}
}

int main(int argc, char *argv[]) {
	int islem_no;
	while(1){
		printf("\n*******************ANA MENU*******************");
		printf("\n1. Arac Islemleri\n2. Musteri Islemleri\n3. Kiralama Islemleri\nYapmak istediginiz islemi giriniz: ");
		scanf("%d",&islem_no);
		if(islem_no==1){
			while(1){
				printf("\n*******************ARAC ISLEM MENU*******************");
				printf("\n\n1. Arac Ekle\n2. Arac Listele\n3. Arac Ara\n4. Arac Sil\n5. Cikis\nYapmak istediginiz islemi giriniz: ");
				scanf("%d",&islem_no);
				if(islem_no==1)
					arac_ekle();
				else if(islem_no==2)
					arac_listele();
				else if(islem_no==3)
					arac_ara();
				else if(islem_no==4)
					arac_sil();
				else if(islem_no==5){
					system("CLS");
					break;
				}
				else
					printf("Hatali Giris Yaptiniz.");
			}
		}
		else if(islem_no==2){
			while(1){
				printf("\n*******************MUSTERI ISLEM MENU*******************");	
				printf("\n\n1. Musteri Ekle\n2. Musterileri Listele\n3. Musteri Ara\n4. Musteri Sil\n5. Cikis\nYapmak istediginiz islemi giriniz:");
				scanf("%d",&islem_no);
				if(islem_no==1)
					musteri_ekle();
				else if(islem_no==2)
					musteri_listele();
				else if(islem_no==3)
					musteri_ara();
				else if(islem_no==4)
					musteri_sil();
				else if(islem_no==5){
					system("CLS");
					break;
				}
				else
					printf("Hatali Giris Yaptiniz.");
			}
		}
		else if(islem_no==3){			
			while(1){
				printf("\n*******************KIRALAMA ISLEM MENU*******************");
				printf("\n\n1. Kirala\n2. Iade\n3. Cikis\nYapmak istediginiz islemi giriniz:");
				scanf("%d",&islem_no);
				if(islem_no==1)
					kirala();
				else if(islem_no==2)
					iade();
				else if(islem_no==3){
					system("CLS");
					break;
				}
				else
					printf("\nHatali Giris Yaptiniz.");
			}
		}
		else
			printf("\nHatali Giris Yaptiniz.");
	}
	return 0;
}

