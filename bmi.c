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

    printf("Condición:\n");
    printf("<18.5 Bajo peso\n");
    printf("18.5 a 24.9 Normal\n");
    printf("25.0 a 29.9 Sobrepeso\n");
    printf(">=30 Obesidad\n");

    return 0;
}
