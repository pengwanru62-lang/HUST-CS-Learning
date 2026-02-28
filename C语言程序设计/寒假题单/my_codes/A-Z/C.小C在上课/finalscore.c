#include <stdio.h>
int main(){
    unsigned int A, B, C;
    unsigned int score;
    scanf("%u %u %u", &A, &B, &C);
    score = A * 0.2 + B * 0.3 + C * 0.5;
    printf("%u", score);
}