#include<stdio.h>
#include<string.h>

#define MAX_HEX_LENGTH 16

void print_mul(char*, char*, unsigned long long);
void print_char(int, char);
int  get_len(unsigned long long, int);

int main(){
	unsigned long long n1 = -1, n2 = -1;
	char sum[MAX_HEX_LENGTH + 2] = {};
	char num1[MAX_HEX_LENGTH + 1] = {}, num2[MAX_HEX_LENGTH + 1] = {};
	int sum_dec;
	while(1) {
		scanf("%s %s", num1, num2);
		if(strcmp(num1, "0") == 0 && strcmp(num2, "0") == 0)
            break;
        
        sscanf(num1, "%llX", &n1);
		sscanf(num2, "%llX", &n2);
		unsigned long long product = n1*n2;
		
		print_mul(num1, num2, product);
		
		sscanf(num1, "%llX", &n1);
		sscanf(num2, "%llX", &n2);
		printf("\n%llu * %llu = %llu", n1, n2, product);
		printf("\n\n");
	}
	return 0;
}


void print_mul(char* n1, char* n2, unsigned long long product) {
	int max_len = get_len(product, 16);
	
	print_char(max_len - strlen(n1) + 2, ' ');
	printf("%s\n*", n1);
	
	print_char(max_len - strlen(n2) + 1, ' ');
	printf("%s\n", n2);
	
	print_char(max_len + 2, '-');
	printf("\n");
	
	print_char(2, ' ');
	printf("%llX", product);
}


void print_char(int num, char c) {
	for(int i=0; i<num; i++)
		printf("%c", c);
}


int get_len(unsigned long long n, int base) {
	int num_len = 0;
    do {
        num_len++;
        n /= base;
    } while (n != 0);
	return num_len;
}
