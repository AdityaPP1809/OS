#include <stdio.h>

int main() {
    int n, m, i, j, k, alloc[10][10], req[10][10], avail[10], f[10]={0}, ans[10], ind=0, flag;

    printf("Enter the number of processes: "); scanf("%d", &n);
    printf("Enter the number of resources: "); scanf("%d", &m);

    printf("Enter the allocation matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter the request matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &req[i][j]);

    printf("Enter the available resources:\n");
    for(j=0; j<m; j++) scanf("%d", &avail[j]);

    // Deadlock Detection Logic
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            if(!f[i]) {
                flag=0;
                // Check if process request can be met by available resources
                for(j=0; j<m; j++) {
                    if(req[i][j] > avail[j]) flag=1;
                }
                // If yes, process executes and releases its allocated resources
                if(!flag) {
                    ans[ind++]=i;
                    for(j=0; j<m; j++) avail[j] += alloc[i][j];
                    f[i]=1;
                }
            }
        }
    }

    // Output formatting
    if(ind == n) {
        printf("System is in safe state.\nSafe Sequence is: ");
        for(i=0; i<n; i++) {
            printf("P%d%s", ans[i],  " ");
        }
    } else {
        printf("Deadlock Detected in the system!\n");
        printf("The deadlocked processes are: ");
        // Loop through the finish array to find the 0s
        for(i=0; i<n; i++) {
            if(f[i] == 0) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    }return 0;
}
