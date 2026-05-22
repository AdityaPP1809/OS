#include <stdio.h>

int main() {
    int n, m, i, j, k, alloc[10][10], max[10][10], avail[10], f[10]={0}, ans[10], ind=0, flag;

    printf("Enter number of processes: "); scanf("%d", &n);
    printf("Enter number of resources: "); scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Demand Matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(j=0; j<m; j++) scanf("%d", &avail[j]);

    // Banker's Algorithm Logic
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            if(!f[i]) {
                flag=0;
                for(j=0; j<m; j++) {
                    if(max[i][j] - alloc[i][j] > avail[j]) flag=1;
                }
                if(!flag) {
                    ans[ind++]=i;
                    for(j=0; j<m; j++) avail[j] += alloc[i][j];
                    f[i]=1;
                }
            }
        }
    }

    // NEW: Check if all processes made it into the safe sequence
    if(ind == n) {
        printf("System is in a safe state.\nSafe sequence is: ");
        for(i=0; i<n; i++) {
            printf("P%d%s", ans[i],  " -> ");
        }
    } else {
        printf("System is in an UNSAFE state. Deadlock may occur.\n");
    }

    return 0;
}
