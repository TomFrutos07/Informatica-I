#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int cantEst;
	float nota, suma = 0;
	float maxNota = -1.0, minNota = 101.0;
	
	do {
		printf("Ingrese una cantidad de estudiantes: ");
		scanf("%d", &cantEst);
		if (cantEst <= 0) {
			printf("El numero debe ser positivo\n");
		}
	} while (cantEst <= 0);
	
	for (int i = 0; i < cantEst; i++) {
		do {
			printf("Ingrese la nota\n", i + 1);
			scanf("%f", &nota);
			
			if (nota < 0 || nota > 100) {
				printf("La nota debe ser entre 0 a 100\n");
			}
		} while (nota < 0 || nota > 100);
		
		suma += nota;
		
		if (nota > maxNota) {
			maxNota = nota;
		}
		if (nota < minNota) {
			minNota = nota;
		}
	}
	
	float promedio = suma / cantEst;
	
	printf("\nPromedio de las notas: %.2f\n", promedio);
	printf("Nota más alta: %.2f\n", maxNota);
	printf("Nota más baja: %.2f\n", minNota);
	
	return 0;
}
