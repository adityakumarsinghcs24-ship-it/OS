#include <stdio.h>

typedef struct {
    int id;
    int burst;
    int deadline;
} Process;

void rms(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].deadline > p[j].deadline) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void edf(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].deadline > p[j].deadline) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void proportional(Process p[], int n, int totalTime) {
    for (int i = 0; i < n; i++) {
        float share = ((float)p[i].burst / totalTime) * 100;
    }
}

int main() {
    int n, totalTime = 0;

    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &p[i].id, &p[i].burst, &p[i].deadline);
        totalTime += p[i].burst;
    }

    rms(p, n);
    edf(p, n);
    proportional(p, n, totalTime);

    return 0;
}
