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
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ar[i]==ar[j]){
                printf("duplicate found\n");
                f=1;
                break;
            }
        }
    }
    if(f==0){
        printf("no duplicates");
    }
}
