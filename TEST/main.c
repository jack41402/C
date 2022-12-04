#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/*
int max(int x, int y){
    if(x>y){
        return x;
    }
    return y;
}

int min(int x, int y){
    if(x<y){
        return x;
    }
    return y;
}

int mul(int n,int ra,int rb,int sa,int sb,int A[100][100],int B[100][100],int C[100][100]){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=max(0,i-ra-rb);j<=min(n-1,i+sa+sb);j++){
            C[i][j]=0;
            for(k=max(0,max(i-ra,j-sb));k<=min(n-1,min(i+sa,j+rb));k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

int main(){

    int n;
    int ra,sa,rb,sb;
    int i,j;
    int A[100][100],B[100][100],C[100][100];

    srand(0);

    printf("input n:");
    scanf("%d",&n);
    printf("\ninput ra,sa:");
    scanf("%d %d",&ra,&sa);
    printf("\ninput rb,sb:");
    scanf("%d %d",&rb,&sb);

    for(i=0;i<n;i++){
        for(j=max(0,i-ra);j<=min(n-1,i+sa);j++){
            A[i][j]=rand()%100+1;
        }
    }
    for(i=0;i<n;i++){
        for(j=max(0,i-rb);j<=min(n-1,i+sb);j++){
            B[i][j]=rand()%100+1;
        }
    }

    mul(n,ra,rb,sa,sb,A,B,C);

    printf("\n matrix A:\n");
    for(i=0;i<n;i++){
        for(j=0;j<max(0,i-ra);j++){
            printf("    ");
        }
        for(j=max(0,i-ra);j<=min(n-1,i+sa);j++){
            printf("%3d ",A[i][j]);
        }
        printf("\n");
    }

    printf("\n matrix B:\n");
    for(i=0;i<n;i++){
        for(j=0;j<max(0,i-rb);j++){
            printf("    ");
        }
        for(j=max(0,i-rb);j<=min(n-1,i+sb);j++){
            printf("%3d ",B[i][j]);
        }
        printf("\n");
    }

    printf("\n matrix C:\n");
    for(i=0;i<n;i++){
        for(j=0;j<max(0,i-ra-rb);j++){
            printf("      ");
        }
        for(j=max(0,i-ra-rb);j<=min(n-1,i+sa+sb);j++){
            printf("%5d ",C[i][j]);
        }
        printf("\n");
    }



    return 0;
}
*/
int min(int x,int y){
    if(x<y){
        return x;
    }
    return y;
}

void decom(int n,double A[100][100],double L[100][100],double U[100][100]){
    int i,j,k;
    for(k=0;k<n;k++){
        for(j=k;j<n;j++){
            U[k][j]=A[k][j];
        }
        for(i=k;i<n;i++){
            L[i][k]=A[i][k]/A[k][k];
        }
        for(i=k+1;i<n;i++){
            for(j=k+1;j<n;j++){
                A[i][j]=A[i][j]-L[i][k]*U[k][j];
            }
        }
    }

}

int main(){
    int n;
    double A[100][100],L[100][100],U[100][100];
    int i,j,k;
    double A1[100][100];
    int check;

    srand(0);
    printf("input n:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j]= (rand()%10000+1)/10000.0;
        }
    }


    decom(n,A,L,U);

    printf("\nmatrix A:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%8.4f ",A[i][j]);
        }
        printf("\n");
    }
    printf("\nmatrix L:\n");
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%8.4f ",L[i][j]);
        }
        printf("\n");
    }
    printf("\nmatrix U:\n");
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            printf("         ");
        }
        for(j=i;j<n;j++){
            printf("%8.4f ",U[i][j]);
        }
        printf("\n");
    }

    check=1;
    for(i=0;i<n && check;i++){
        for(j=0;j<n && check;j++){
            A[i][j]=0;
            for(k=0;k<=min(i,j);k++){
                A[i][j]+=L[i][k]*U[k][j];
            }
            check = check && (fabs(A[i][j]-A1[i][j]<0.0001));
        }
        if (!check) printf ("\n%d %d\n%8.4lf %8.4lf\n" , i , j  , A[i][j] , A1[i][j]) ;
    }
    if(check){
        printf("\nright!");
    }else{
        printf("\nwrong!");
    }
    printf("\nmatrix A:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%8.4f ",A[i][j]);
        }
        printf("\n");
    }
}