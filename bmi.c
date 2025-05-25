#include <stdio.h>

int main() {
  
    float altura, imc;
    int peso;
   
    printf("Ingrese su peso en kg: ");
    scanf("%d", &peso);
    printf("Ingrese su altura en metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("\nSu índice de masa corporal es: %.1f\n\n", imc);

       printf("Condición: ");
    if (imc < 18.5) {
        printf("Bajo peso\n");
    } else if (imc < 25.0) {
        printf("Normal\n");
    } else if (imc < 30.0) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidad\n");
    }
    return 0;
}
