#include<stdio.h>
int main(){
    int n;
    int f=0;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int ar[n];
    for(int i=0;i<n;i++){
        printf("enter no:");
        scanf("%d",&ar[i]);
    }
    int x=ar[0];
    int m=0;
    for(int i=1;i<n;i++){
        if(x>ar[i]){
            x=ar[i];
            m=i+1;
        }
    }
    printf("min num: %d \n",x);
    printf("at pos: %d",m);
}
