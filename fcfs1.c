#include<stdio.h>
int main()
{
    int i,j,n,avg_ct,avg_tat,avg_wt,time=0;
    int at[20],bt[20],ct[20],tat[20],wt[20],p[20];

    printf("enter the number of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("enter at%d :",i+1);
        scanf("%d",&at[i]);
        printf("enter bt%d :\n",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(time<at[i]){
            time=at[i];
        }
        ct[i]=time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        time=ct[i];
        avg_ct+=ct[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    avg_ct=avg_ct/n;
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("the avrages %d %d %d",avg_ct,avg_tat,avg_wt);
    return 0;
}
