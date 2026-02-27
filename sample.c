#include<stdio.h>
int main(){
    int n,x;
    int f=0;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int ar[n];
    for(int i=0;i<n;i++){
        printf("enter no:");
        scanf("%d",&ar[i]);
    }
    printf("enter the number to search:");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(ar[i]==x){
            printf("found\n");
            f=1;
        }
    }
    int l=0,h=n-1,m=(l+h)/2;
    while(l<=m&&h>=m){
        if(ar[m]==x){
            printf("found using BS");
            f=1;
            break;
        }
        else if(ar[m]<x){
            l=m+1;
            m=(l+h)/2;
        }
        else if(ar[m]>x){
            h=m-1;
            m=(l+h)/2;
        }
    }
    if(f=0){
        printf("num not found");
    }
}
