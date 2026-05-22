#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

int buf[N], in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t m;

void* prod(void* p) {
    int x = 0;
    while (1) {
        sem_wait(&empty);
        pthread_mutex_lock(&m);

        buf[in] = x;
        printf("Produced: %d at buffer[%d]\n", x++, in);
        in = (in + 1) % N;

        pthread_mutex_unlock(&m);
        sem_post(&full);
    }
}

void* cons(void* p) {
    int x;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&m);

        x = buf[out];
        printf("Consumed: %d from buffer[%d]\n", x, out);
        out = (out + 1) % N;

        pthread_mutex_unlock(&m);
        sem_post(&empty);
    }
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&m, NULL);

    pthread_create(&p, NULL, prod, NULL);
    pthread_create(&c, NULL, cons, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}
