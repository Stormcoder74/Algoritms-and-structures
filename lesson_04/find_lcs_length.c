#include <stdio.h>

int max(int a, int b){
    if(a >= b) return a;
    return b;
}

int lcs_length ( char *A , char *B)
{
    if (*A == '\0' || *B == '\0') return 0;
    else if (*A == *B) {
        int z = 1 + lcs_length(A + 1, B + 1);
        return z;
    }
    else {
        int x = lcs_length(A + 1, B);
        int y = lcs_length(A, B + 1);
        int r = max(x, y);
        return r;
    }
}

int main(){
    char a[] = {'g', 'e', 'e', 'k', 'b', 'r', 'a', 'i', 'n', 's', '\0'};
    char b[] = {'g', 'e', 'e', 'k', 'm', 'i', 'n', 'd', 's', '\0'};
    int result = lcs_length(&a, &b);
    printf("%d", result);
    return 0;
}