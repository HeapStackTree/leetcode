#include <stdlib.h>
#include <stdio.h>
int main() {
    int i = 3;
    void *a = (void *)malloc(sizeof(int) * 1);
    a = &i;
    printf("%d", *(int *)a);
    return 0;
}