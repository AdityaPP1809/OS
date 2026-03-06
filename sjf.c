#include <stdio.h>

int main()
{
    int n,i,atat,awt,time=0,completed=0;
    int at[20],bt[20],ct[20],tat[20],wt[20],rt[20],p[20];
    int visited[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(completed < n)
    {
        int min_bt = 9999;
        int pos = -1;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && at[i] <= time && bt[i] < min_bt)
            {
                min_bt = bt[i];
                pos = i;
            }
        }
        if(pos == -1)
        {
            time++;
            continue;
        }

        rt[pos] = time - at[pos];
        time += bt[pos];
        ct[pos] = time;
        tat[pos] = ct[pos] - at[pos];
        wt[pos] = tat[pos] - bt[pos];
        atat+=tat[pos];
        awt+=wt[pos];

        visited[pos] = 1;
        completed++;
    }
    atat=atat/n;
    awt=awt/n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    printf("the avrages %d %d",atat,awt);

    return 0;
}
