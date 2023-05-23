
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define SUTUN 5
#define SATIR 5

/*
Bu�ra Han Okcebe
 	
0 2 0 4 5
0 0 3 0 0
0 1 0 6 0
0 0 0 0 8
7 0 0 0 0

0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0
*/

int main(void){
	
	setlocale(LC_ALL, "Turkish");	
	int a, dgm, devam=1;
	FILE *p = NULL;
	int matDizi[SATIR][SUTUN];
	int Transpoz[SATIR][SUTUN];
	int i, j, say=0, say1=0;
	int durum = 0;

	
	if((p = fopen("matris.txt", "r")) != NULL){

		for(i = 0; i < SATIR; i++){
			for(j = 0; j < SUTUN; j++){

				fscanf(p, "%d", &matDizi[i][j]);
			}
		}printf("Graf Y�klendi\n");
	}else{
		printf("Txt dosyasi bulunamadi!");
	}
	fclose(p);
	
		do{
		printf("\nYapmak istediginiz islemi giriniz.\n\n");
		printf("1)Matris ��kt�s�n� g�ster.\n");
		printf("2)D���m giri� ��k�� derecelerini listele.\n");
		printf("3)Kenar say�s� hesapla.\n");
		printf("4)Kenar maliyetini hesapla\n");
		printf("5)D���m kom�ular� ve derecelerini g�ster\n");
		printf("6)Graf tam graf m�?\n");
		printf("7)Graf y�nl� m�?\n");
		printf("8)��k��\n");
		scanf("%d",&a);

		switch(a)
		{
			case 1:
				for(i = 0; i < SATIR; i++){
					for(j = 0; j < SUTUN; j++){
						printf("%d ", matDizi[i][j]);
					}
				printf("\n");			
				}	
			break;
		
			case 2:
				printf("Derecelerini istedi�iniz d���m�n numaras�n� giriniz.");
				scanf("%d",&dgm);
				say=0;
				say1=0;
				if(dgm<=SATIR){
					for(i = 0; i < SATIR; i++){
						if(matDizi[dgm][i]!=0){
							say++;
						}
					}
					for(i = 0; i < SUTUN; i++){
						if(matDizi[i][dgm]!=0){
							say1++;
						}
					}
					printf("\n%d. d���m�n giri� derecesi: %d ��k�� derecesi: %d\n", dgm, say1, say);
					printf("\n");			
				}else printf("Girdi�iniz derecede d���m bulunmamaktad�r.");
			break;
			
			case 3:
				say=0;
				for(i = 0; i < SATIR; i++){
					for(j = 0; j < SUTUN; j++){
						if(matDizi[i][j]!=0){
							say++;
						}
					}			
				}
				printf("\nToplam kenar say�s�: %d\n",say);
				printf("\n");
					
			break;
		
			case 4:
				say1=0;
				for(i = 0; i < SATIR; i++){
					for(j = 0; j < SUTUN; j++){
						if(matDizi[i][j]!=0){
							say1=say1+matDizi[i][j];
						}
					}			
				}
				printf("\nToplam kenar say�s�: %d\n",say1);
				printf("\n");

			break;
		
			case 5:
				say=0;
				printf("�stenen d���m�n kom�u d���mleri ve kenar maliyetlerini yazd�r.");
				scanf("%d",&dgm);

				if(dgm<=SATIR){
					printf("%d. d���m�n kom�ular�:  ",dgm);
					for(i = 0; i < SATIR; i++){
						if(matDizi[dgm][i]!=0){
							say++;
							printf(" - %d. d���m, maliyeti: %d  ",i,matDizi[dgm][i]);
						}
					}
				}else printf("Girdi�iniz derecede d���m bulunmamaktad�r.");
				
			break;
				
			case 6:
				durum = 0;
				for(i = 0; i < SATIR; i++){
					for(j = 0; j < SUTUN; j++){
						if(i!=j && matDizi[i][j]==0){
							durum = 1;
							break;		
						}					
					}
				}
				
				if(durum==1) printf("Tam ba�l� graf de�ildir.");
				else printf("Tam ba�l� grafd�r.");
				
			break;
				
			case 7:
				
				durum = 0 ; 
				for(i=0; i<SATIR; ++i){
        			for(j=0; j<SUTUN; ++j){
            			Transpoz[j][i] = matDizi[i][j];
        				}
        	   		}
        	   		
        	   	
        	   	for(i = 0; i < SATIR; i++){
					for(j = 0; j < SUTUN; j++){
						if(matDizi[i][j]!=Transpoz[i][j]){
							durum = 1;
							break;
						}
					}			
				}
				
				if(durum==1) printf("Graf y�nl�d�r.");
				else printf("Graf y�ns�zd�r.");
			
			break;
				
			case 8:
				printf("��k�� Yap�l�yor...");	
				devam = 0;
			break;
			
		
		}
	}while(devam == 1);

return 0;
}
