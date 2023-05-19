#include <stdlib.h>
#include<time.h>
#include <stdio.h>
typedef enum{true, false}boolean;
void deplasare(int a[],int s, int d){
    boolean bul;
    int i,j,x;
    i=s;j=2*i;x=a[i];bul=false;
    while(j<=d&&bul==false){
        if(j<d)
            if(a[j]<a[j+1]) j=j+1;
        if(x<a[j]) {a[i]=a[j]; i=j; j=2*i;}
        else bul=true;
    }
    a[i]=x;
}
void Heapsort(int a[],int n){
    int s,d,aux;
    s=(n-1)/2+1; d=n-1;
    while(s>1) {s--; deplasare(a,s,n-1);}
    while(d>1) {aux=a[1];a[1]=a[d];a[d]=aux;d--;deplasare(a,1,d);};
}
 void generare(int a[], int n){
     int i;
     srand(time(NULL));
     for(i=0;i<n;i++)
        a[i]=rand()%100;
 }
 int biti(int x,int k,int i){
     return ~((~0)<<i)&(x>>k);
 }
 void radix_interschimbare(int a[], int s, int d, int b){
     int i,j;
     int aux;
     if(s<d&&b>=0){
         i=s;j=d;
         do{
             while(i!=j&&biti(a[i],b,1)==0)i++;
             while(i!=j&&biti(a[j],b,1)==1)j--;
             aux=a[i];a[i]=a[j];a[j]=aux;
         }while(i!=j);
         if(biti(a[d],b,1)==0)
            j++;
        radix_interschimbare(a,s, j-1, b-1);
        radix_interschimbare(a,j, d, b-1);
     }

 }
void radix_direct(int a[], int n){
int b=8*sizeof(int),m=4,Nr[16], trecere,i, t[20],poz;
for(trecere=0;trecere<b/m;trecere++){
	for(i=0;i<16;i++)   Nr[i]=0;
	for(i=0;i<n;i++)    Nr[biti(a[i],m*trecere,m)]++;
	for(i=1;i<16;i++)   Nr[i]=Nr[i]+Nr[i-1];
	for(i=n-1;i>=0;i--) //{poz=biti(a[i],m*trecere,m);t[Nr[poz]-1]=a[i];Nr[poz]--};
	                    t[--Nr[biti(a[i],m*trecere,m)]]=a[i];
	for(i=0;i<n;i++)    a[i]=t[i];

}
}
void shell_sort(int a[], int n){
    int h[3]={5,3,1};
    int i,j,k,t,aux;
    for(t=0;t<3;t++){
        k=h[t];
        for(i=k;i<n;i++){
            aux=a[i];
            j=i-k;
            while(j>=0&&aux<a[j]){
                a[j+k]=a[j];
                j=j-k;
            }
            a[j+k]=aux;
    }    }
}
void quick_sort(int a[],  int s, int d){
    int i,j,aux,x;
    i=s;j=d; x=a[(s+d)/2];
    do{
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<=j){aux=a[i];a[i]=a[j];a[j]=aux;i=i+1;j=j-1;}

    }while(i<=j);
    if(s<j) quick_sort(a,s,j);
    if(i<d) quick_sort(a,i,d);
}
 void afisare(int a[],int n){
     int i;
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
     printf("\n");
 }
 int main(void){
     int a[20];
     int n=20;
     generare(a,n);
     afisare(a,n);
     //Heapsort(a,n);//sortare secventa [1, n-1]
     //radix_interschimbare(a,0,n-1,8*sizeof(int)-1);
     //radix_direct(a,n);
     //shell_sort(a,n);
     quick_sort(a,0,n-1);
     afisare(a,n);
 }
