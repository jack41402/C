#include<stdio.h>
#include<string.h>

#define MAX_HEX_LENGTH 16

void print_add(char*, char*, char*);
void print_char(int, char);
int  get_len(char*);

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
			
		int carry = 0;
		for(int i=0; i<MAX_HEX_LENGTH + 1; i++) {
			sum_dec = (n1%16 + n2%16 + carry) % 16;
			carry = (n1%16 + n2%16 + carry) / 16;
			if(sum_dec < 10)
				sum[i] = sum_dec + '0';
			else
				sum[i] = sum_dec - 10 + 'A';
			n1/=16;
			n2/=16;
		}
		
		print_add(num1, num2, sum);	
		
		sscanf(num1, "%llX", &n1);
		sscanf(num2, "%llX", &n2);
		printf("\n%llu + %llu = %llu", n1, n2, n1+n2);
		if(get_len(sum) > 16)
			printf("    ****Overflow!!!");
		printf("\n\n");
	}
	return 0;
}


void print_add(char* n1, char* n2, char* sum) {
	int max_len = get_len(sum);
	
	print_char(max_len - strlen(n1) + 2, ' ');
	printf("%s\n+", n1);
	
	print_char(max_len - strlen(n2) + 1, ' ');
	printf("%s\n", n2);
	
	print_char(max_len + 2, '-');
	printf("\n");
	
	print_char(2, ' ');
	for(int i = max_len-1; i>=0; i--)
		printf("%c", sum[i]);
}


void print_char(int num, char c) {
	for(int i=0; i<num; i++)
		printf("%c", c);
} 


int get_len(char* sum) {
	int flag = 0, num_len = 0;
	for(int i=MAX_HEX_LENGTH; i>=0; i--) {
		if(!flag && sum[i] != '0')
			flag = 1;
		
		if(flag)
			num_len++;
	}
	return num_len;
}

