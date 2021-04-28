#include<stdio.h>
#include<typeinfo.h>
#include<malloc.h>
int main() {
    int *a,*b;
    int c;
    c = 100;
    a = &c;
    b = &c;
    free(a);
    printf("%d",c+100);
    return 0;
}
