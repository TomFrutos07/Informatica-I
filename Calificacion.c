#include <stdio.h>

int main() {
    int calificacion;

    printf("Ingrese su calificación:");
    scanf("%d", &calificacion);

    if (calificacion >= 90) {
        printf("Su calificación es: A\n");
    } else if (calificacion >= 80) {
        printf("Su calificaciónes: B\n");
    } else if (calificacion >= 70) {
        printf("Su calificación es: C\n");
    } else if (calificacion >= 60) {
        printf("Su calificación es: D\n");
    } else {
        printf("Su calificación es: F\n");
    }

    return 0;
}
