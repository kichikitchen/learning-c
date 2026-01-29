#include <stdio.h>

void sum_range(int min, int max, int *out){
    if(out == NULL) return;

    if(min > max){
        int tmp = min;
        min = max;
        max = tmp;
    }

    *out = 0;
    for(int i = min; i <= max; i++){
        *out += i;
    }
}

int main(void){
    int out;
    sum_range(50, 100, &out);
    printf("%d\n", out);
    return 0;
}
