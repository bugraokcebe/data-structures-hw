#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define SUTUN 9
#define SATIR 9


struct Diziler {
	int data;
	int matDizi[SATIR][SUTUN];
	bool ziyaret[SATIR];
	struct Diziler *next;
}Dizi;

struct Diziler* front = NULL;
struct Diziler* rear = NULL;

struct Diziler* dugumOlustur(int x){
	struct Diziler* dugum =(struct Diziler*)malloc(sizeof(struct Diziler));
	dugum->data=x;
	dugum->next=NULL;
	return dugum;
}


void ekle(int x){

	struct Diziler* yeniDugum = dugumOlustur(x);
	if(front== NULL){
		front = yeniDugum;
		rear = yeniDugum;
	}	
	else{
		rear->next=yeniDugum;
		rear = yeniDugum;
	}
	
}

void cikart(){
	if(front==NULL){
		return;
	}
	
	if(front->next == NULL){
		front = NULL;
		rear = NULL;
	}
	else {
		struct Diziler* temp = front->next;
		free(front);
		front = temp;
	}
	
}

bool bosMu() {
	if(front == NULL){
		return true;
	}
	else{
		return false;
	}
}

void BFS(int root){
	int i;
	for(i=0;i<SATIR;i++){
		Dizi.ziyaret[i] = false ;
	}
	Dizi.ziyaret[root] = true;
	ekle(root);
	
	while(bosMu()== false){
		root = front->data;

		printf(" %d ",root);
		printf("-");		
		
		cikart();
		for(i = 0; i < SUTUN; i++){
			if(Dizi.ziyaret[i]== false && Dizi.matDizi[root][i]== 1){
				Dizi.ziyaret[i]=true;
				ekle(i);
			}
		}
	}
}
void matris(){
	FILE *p = NULL;
	//int matDizi[SATIR][SUTUN];
	int i, j;

	
	if((p = fopen("matris.txt", "r")) != NULL){

		for(i = 0; i < SATIR; i++){
			for(j = 0; j < SUTUN; j++){

				fscanf(p, "%d", &Dizi.matDizi[i][j]);
			}
		}printf("Graf Yüklendi\n");
	}else{
		printf("Txt dosyasi bulunamadi!");
	}
	fclose(p);
}

int main(){
	int a , deger, devam = 1;
	setlocale(LC_ALL, "Turkish");	
	matris();
		printf("\n");	
		for(int i = 0; i < SATIR; i++){
			for(int j = 0; j < SUTUN; j++){

				printf("%d ",Dizi.matDizi[i][j]);

			}
			printf("\n");
		}
		printf("\n");
		do{
			printf("\n1) Deðer Giriniz \n2) Çýkýþ\n");
			scanf("%d",&a);
			switch(a){
				case 1:
					printf("Hangi dereceden baþlamak istediðinizi yazýnýz 0 - 8 :");
					scanf("%d",&deger);
					printf("\n");
					BFS(deger);
					printf("\n\n");
					
				break;
				
				case 2:
					devam=0;
				break;
		
	}
		}while(devam == 1);
}
