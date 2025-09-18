#include <stdio.h>

#define TAM 100 

int precioMax(int codigos[], float precios[], int n) {
	int idMax = 0;
	for (int i = 1; i < n; i++) {
		if (precios[i] > precios[idMax]) {
			idMax = i;
		}
	}
	return idMax;
}

int precioMin(int codigos[], float precios[], int n) {
	int idMin = 0;
	for (int i = 1; i < n; i++) {
		if (precios[i] < precios[idMin]) {
			idMin = i;
		}
	}
	return idMin;
}

int validarCodigo() {
	int codigo;
	do {
		printf("Ingrese el codigo de barras (1-999999999): ");
		scanf("%d", &codigo);
		if (codigo < 1 || codigo > 999999999) {
			printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
		}
	} while (codigo < 1 || codigo > 999999999);
	return codigo;
}

float validarPrecio() {
	float precio;
	do {
		printf("Ingrese el precio: ");
		scanf("%f", &precio);
		if (precio < 0) {
			printf("Error. El precio no puede ser negativo\n");
		}
	} while (precio < 0);
	return precio;
}

int main(void) {
	int n;
	
	do {
		printf("Ingrese la cantidad de productos (max %d): ", TAM);
		scanf("%d", &n);
		if (n <= 0 || n > TAM) {
			printf("Error. La cantidad debe estar entre 1 y %d.\n", TAM);
		}
	} while (n <= 0 || n > TAM);
	
	int codigos[TAM];
	float precios[TAM];
	
	printf("\nIngrese %d productos, se solicitara el codigo y precio:\n\n", n);
	
	for (int i = 0; i < n; i++) {
		codigos[i] = validarCodigo();
		precios[i] = validarPrecio();
		printf("\n");
	}
	
	printf("\nCodigo  Precio\n");
	for (int i = 0; i < n; i++) {
		printf("%d %.2f\n", codigos[i], precios[i]);
	}
	
	int idMax = precioMax(codigos, precios, n);
	int idMin = precioMin(codigos, precios, n);
	
	printf("\nMas caro: [%d] %.2f\n", codigos[idMax], precios[idMax]);
	printf("Mas barato: [%d] %.2f\n", codigos[idMin], precios[idMin]);
	
	return 0;
}
