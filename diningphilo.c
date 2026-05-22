#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];

void* phil(void* n) {
    int id = *(int*)n;
    int L = id, R = (id + 1) % N;

    while (1) {
        printf("P%d thinking\n", id);
        sleep(1);

        if (id % 2 == 0) {
            pthread_mutex_lock(&forks[L]);
            pthread_mutex_lock(&forks[R]);
        } else {
            pthread_mutex_lock(&forks[R]);
            pthread_mutex_lock(&forks[L]);
        }

        printf("P%d eating\n", id);
        sleep(2);

        pthread_mutex_unlock(&forks[L]);
        pthread_mutex_unlock(&forks[R]);
    }
}

int main() {
    pthread_t t[N];
    int id[N];

    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
        id[i] = i;
        pthread_create(&t[i], NULL, phil, &id[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);
}
