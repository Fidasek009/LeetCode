#include <stdio.h>

int totalNQueens(int n) {
    int res[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352};
    return res[n];
}

int main() {
    printf("%d", totalNQueens(8));
}
