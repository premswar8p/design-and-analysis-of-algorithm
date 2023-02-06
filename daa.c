#include <stdio.h>

#define MAX 10

int weight[MAX];
int n, W, total = 0;

void print_container(int x[]) {
    printf("Container Load: ");
    for (int i = 0; i < n; i++)
        if (x[i]) printf("%d ", weight[i]);
    printf("\n");
}

void container_loader(int s, int k, int r, int x[]) {
    x[k] = 1;
    if (s + weight[k] == W) {
        print_container(x);
    }
    else if (s + weight[k] + weight[k+1] <= W) {
        container_loader(s + weight[k], k+1, r-weight[k], x);
    }
    if ((s + r - weight[k] >= W) && (s + weight[k+1] <= W)) {
        x[k] = 0;
        container_loader(s, k+1, r-weight[k], x);
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight of each item: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        total += weight[i];
    }
    printf("Enter the maximum weight of the container: ");
    scanf("%d", &W);
    int x[n];
    for (int i = 0; i < n; i++) x[i] = 0;
    container_loader(0, 0, total, x);
    return 0;
}
