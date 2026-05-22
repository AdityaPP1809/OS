#include <stdio.h>

void FF(int p[], int n, int b[], int m) {
    int used[m];

    for(int i=0; i<m; i++)
        used[i] = 0;

    printf("\n--- First Fit Allocation ---\n");

    for(int i=0; i<n; i++) {
        int alloc = -1;

        for(int j=0; j<m; j++) {
            if(!used[j] && b[j] >= p[i]) {
                alloc = j;
                used[j] = 1;
                break;
            }
        }

        if(alloc != -1)
            printf("Process %d (%d) -> Block %d\n",
                   i+1, p[i], alloc+1);
        else
            printf("Process %d (%d) -> Not Allocated\n",
                   i+1, p[i]);
    }
}

void BF(int p[], int n, int b[], int m) {
    int used[m];

    for(int i=0; i<m; i++)
        used[i] = 0;

    printf("\n--- Best Fit Allocation ---\n");

    for(int i=0; i<n; i++) {
        int idx = -1;

        for(int j=0; j<m; j++) {
            if(!used[j] && b[j] >= p[i] &&
               (idx == -1 || b[j] < b[idx])) {
                idx = j;
            }
        }

        if(idx != -1) {
            used[idx] = 1;

            printf("Process %d (%d) -> Block %d\n",
                   i+1, p[i], idx+1);
        }
        else {
            printf("Process %d (%d) -> Not Allocated\n",
                   i+1, p[i]);
        }
    }
}

void WF(int p[], int n, int b[], int m) {
    int used[m];

    for(int i=0; i<m; i++)
        used[i] = 0;

    printf("\n--- Worst Fit Allocation ---\n");

    for(int i=0; i<n; i++) {
        int idx = -1;

        for(int j=0; j<m; j++) {
            if(!used[j] && b[j] >= p[i] &&
               (idx == -1 || b[j] > b[idx])) {
                idx = j;
            }
        }

        if(idx != -1) {
            used[idx] = 1;

            printf("Process %d (%d) -> Block %d\n",
                   i+1, p[i], idx+1);
        }
        else {
            printf("Process %d (%d) -> Not Allocated\n",
                   i+1, p[i]);
        }
    }
}

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int blocks[m], b1[m], b2[m], b3[m];

    printf("Enter size of each memory block:\n");

    for(int i=0; i<m; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &blocks[i]);

        b1[i] = b2[i] = b3[i] = blocks[i];
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    int p[n];

    printf("Enter size of each process:\n");

    for(int i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &p[i]);
    }

    FF(p, n, b1, m);
    BF(p, n, b2, m);
    WF(p, n, b3, m);

    return 0;
}
