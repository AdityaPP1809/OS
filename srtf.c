#include <stdio.h>

int main()
{
    int n,atat,awt,i,time=0,completed=0,smallest;
    int at[20],bt[20],rt_bt[20];
    int ct[20],tat[20],wt[20],rt[20];
    int first_start[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);

        rt_bt[i] = bt[i];
        first_start[i] = -1;
    }

    while(completed < n)
    {
        smallest = -1;
        int min = 9999;
        for(i=0;i<n;i++)
        {
            if(at[i] <= time && rt_bt[i] > 0 && rt_bt[i] < min)
            {
                min = rt_bt[i];
                smallest = i;
            }
        }

        if(smallest == -1)
        {
            time++;
            continue;
        }
        if(first_start[smallest] == -1)
        {
            first_start[smallest] = time;
            rt[smallest] = time - at[smallest];
        }

        rt_bt[smallest]--;
        time++;

        if(rt_bt[smallest] == 0)
        {
            completed++;
            ct[smallest] = time;

            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            atat+=tat[smallest];
            awt+=wt[smallest];
        }
    }
    atat=atat/n;
    awt=awt/n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    printf("the avrages %d %d",atat,awt);
    return 0;
}
