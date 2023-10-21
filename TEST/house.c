#include <stdio.h>

int main(void){
	int a,b,c,i,k;
	a=16;
	for(i=0;i<a;i++){
		printf(" ");
	}
	for(i=0;i<a;i++){
		printf("@");
	}
	printf("\n");
	int j=16;
	for(i=16;i>0;i--){
		for(k=i-1;k>0;k--){
			printf(" ");
		}
		printf("@");
		for(k=1;k<=j;k++){
			printf("*");
		}
		printf("@");
		j=j+2;
		printf("\n");
	}
	a=48;
	for(i=0;i<a;i++){
		printf("@");
	}
	printf("\n");
	for(i=1;i<=32;i++){
		if(i<=6||i>=25&&i<=30){
			printf("   %%");
			printf("%%");
			for(k=0;k<38;k++){
				printf(" ");
			}
			printf("%%");
			printf("%%");
		}

		else if(i==7||i==11||i==15||i==19){
			printf("   %%");
			printf("%%");
			for(k=1;k<=38;k++){
				if(k==1||k==2||k==12||k==13||k==26||k==27||k==37||k==38){
					printf(" ");
				}
				else if(k>=3&&k<=11||k>=28&&k<=36){
					printf("=");
				}
				else if(k>=14&&k<=25){
					printf("@");
				}
			}
			printf("%%");
			printf("%%");
		}
		else if(i>=8&&i<=10||i>=12&&i<=14||i>=16&&i<=18){
			printf("   %%");
			printf("%%");
			for(k=1;k<=38;k++){
				if(k==1||k==2||k==12||k==13||k==26||k==27||k==37||k==38){
					printf(" ");
				}
				else if(k>=4&&k<=6||k>=8&&k<=10||k>=29&&k<=31||k>=33&&k<=35){
					printf(" ");
				}
				else if(k==3||k==11||k==28||k==36){
					printf("=");
				}
				else if(k==7||k==32){
					printf("+");
				}
				else{
					printf("@");
				}
			}
			printf("%%");
			printf("%%");
		}
		else if(i>=20&&i<=24){
			printf("   %%");
			printf("%%");
			for(k=1;k<=38;k++){
				if(k>=14&&k<=25){
					printf("@");
				}
				else{
					printf(" ");
				}
			}
			printf("%%");
			printf("%%");
		}
		else{
			printf("   ");
			for(k=1;k<=42;k++){
				printf("%%");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}

