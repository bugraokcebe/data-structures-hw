
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define SUTUN 5
#define SATIR 5

/*
Buðra Han Okcebe
 	
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
		}printf("Graf Yüklendi\n");
	}else{
		printf("Txt dosyasi bulunamadi!");
	}
	fclose(p);
	
		do{
		printf("\nYapmak istediginiz islemi giriniz.\n\n");
		printf("1)Matris çýktýsýný göster.\n");
		printf("2)Düðüm giriþ çýkýþ derecelerini listele.\n");
		printf("3)Kenar sayýsý hesapla.\n");
		printf("4)Kenar maliyetini hesapla\n");
		printf("5)Düðüm komþularý ve derecelerini göster\n");
		printf("6)Graf tam graf mý?\n");
		printf("7)Graf yönlü mü?\n");
		printf("8)Çýkýþ\n");
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
				printf("Derecelerini istediðiniz düðümün numarasýný giriniz.");
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
					printf("\n%d. düðümün giriþ derecesi: %d çýkýþ derecesi: %d\n", dgm, say1, say);
					printf("\n");			
				}else printf("Girdiðiniz derecede düðüm bulunmamaktadýr.");
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
				printf("\nToplam kenar sayýsý: %d\n",say);
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
				printf("\nToplam kenar sayýsý: %d\n",say1);
				printf("\n");

			break;
		
			case 5:
				say=0;
				printf("Ýstenen düðümün komþu düðümleri ve kenar maliyetlerini yazdýr.");
				scanf("%d",&dgm);

				if(dgm<=SATIR){
					printf("%d. düðümün komþularý:  ",dgm);
					for(i = 0; i < SATIR; i++){
						if(matDizi[dgm][i]!=0){
							say++;
							printf(" - %d. düðüm, maliyeti: %d  ",i,matDizi[dgm][i]);
						}
					}
				}else printf("Girdiðiniz derecede düðüm bulunmamaktadýr.");
				
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
				
				if(durum==1) printf("Tam baðlý graf deðildir.");
				else printf("Tam baðlý grafdýr.");
				
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
				
				if(durum==1) printf("Graf yönlüdür.");
				else printf("Graf yönsüzdür.");
			
			break;
				
			case 8:
				printf("Çýkýþ Yapýlýyor...");	
				devam = 0;
			break;
			
		
		}
	}while(devam == 1);

return 0;
}
