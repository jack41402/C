#include<stdlib.h>
#include<stdio.h>

void binary (int n){
    int i;
    for(i=0;i<32;i++){
        printf("%d", (n>>31-i)&1);
        if(i%4==3) printf(" ");
    }
}

void fulladder(int x, int y, int m, int *c, int*s){
    *s = (x^(y^m))^*c;
    *c = (x&(y^m))|(*c&(x^(y^m)));

}
int adder_subtractor (int X, int Y, int *c, int m, int *c2){
    int S = 0;
    int i,x,y,s;
    for(i=0;i<32;i++){
        x = (X>>i)&1;
        y = (Y>>i)&1;
        *c2 = *c;
        fulladder(x, y, m, c, &s);
        S = S|(s<<i);
    }
    return S;
}

int main (){
    setbuf(stdout, NULL);
    int X,Y,S,c,m,c2;
    char op;
    c = 0;
    printf("D:\\binary_adder_subtractor\n");
    while(1){
        printf("Enter \"X + Y\" or \"X - Y\" (X, Y: -2,147,483,648 to 2,147,483,647): ");
        scanf("%d %c %d",&X,&op,&Y);
        if(X == 0 && Y == 0){
            break;
        }
        if(op == '+'){
            m = 0;
        }
        else{
            m = 1;
        }
        c = m;
        S = adder_subtractor(X, Y, &c, m, &c2);
        printf("X = %-11d  Binary value: ",X);
        binary(X);
        printf("\nY = %-11d  Binary value: ",Y);
        binary(Y);
        printf("\nS = %-11d  Binary value: ",S);
        binary(S);
        if(m==0){
            if(X+Y == S) printf("\nCorrect! ");
            else printf("\nIncorrect! ");
            printf("Adder-subtractor operation test: %d + %d = %d",X,Y,X+Y);
        }
        else {
            if(X-Y == S) printf("\nCorrect! ");
            else printf("\nIncorrect! ");
            printf("Adder-subtractor operation test: %d - %d = %d",X,Y,X-Y);
        }
        if(c^c2 == 1) printf("\n**** The addition-subtraction operation is overflow.");

        printf("\n-----------------------------------------------------\n");

    }
    return 0;
}
