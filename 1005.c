#include <stdio.h>

int main() {

    float A, B, MEDIA;
    scanf("%f\n%f", &A, &B);
    MEDIA = ((A * 3.5) + (B * 7.5)) / 11;
    printf("MEDIA = %.5lf\n", MEDIA);

    return 0;
}
