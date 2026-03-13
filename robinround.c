#include <stdio.h>

int main() {
    float atat,awt;
    int n, i, time = 0, quantum;
    int at[20], bt[20], rem_bt[20];
    int ct[20], tat[20], wt[20], rt[20], start[20];
    int queue[100], front = 0, rear = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
        start[i] = -1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int remain = n;
    int visited[20] = {0};
    while(remain > 0) {
        for(i=0; i<n; i++) {
            if(at[i] <= time && rem_bt[i] > 0 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if(front == rear) {
            time++;
            continue;
        }

        int idx = queue[front++];

        if(start[idx] == -1) {
            start[idx] = time;
            rt[idx] = time - at[idx];
        }

        if(rem_bt[idx] > quantum) {
            time += quantum;
            rem_bt[idx] -= quantum;
        } else {
            time += rem_bt[idx];
            rem_bt[idx] = 0;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            atat+=tat[idx];
            awt+=wt[idx];
            remain--;
        }

        for(i=0; i<n; i++) {
            if(at[i] <= time && rem_bt[i] > 0 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
        if(rem_bt[idx] > 0) {
            queue[rear++] = idx;
        }
    }
    atat=atat/n;
    awt=awt/n;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
    printf("the avrages TAT %f WT %f",atat,awt);
    return 0;
}

