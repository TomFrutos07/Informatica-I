#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int cuantas_piezas(int max) {
	int n;
	do {
		printf("Cuántas piezas ingresará? ");
		if (scanf("%d", &n) != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
			n = -1;
			continue;
		}
	} while (n < 0 || n > max);
	return n;
}

int rectificable(float diametro, float valor) {
	return diametro > valor;
}

int rechazada(float diametro, float valor) {
	return diametro < valor;
}

void cargar_piezas(float *p, int n) {
	for (int i = 0; i < n; ++i) {
		float val;
		int leido;
		do {
		    printf("Ingrese diámetro de pieza %d: ", i);
			leido = scanf("%f", &val);
			if (leido != 1) {
				int c;
				while ((c = getchar()) != '\n' && c != EOF) {}
				val = -1.0f;
				printf("Entrada inválida. Ingrese un número positivo.\n");
				continue;
			}
			if (val < 0.0f)
				printf("Valor negativo no permitido. Intente otra vez.\n");
		} while (val < 0.0f);
		*(p + i) = val;
	}
}

int contar(int (*criterio)(float, float), float valor, float *p, int n) {
	int cuenta = 0;
	for (int i = 0; i < n; ++i)
		if (criterio(*(p + i), valor))
			++cuenta;
	return cuenta;
}

float* reservar_memoria(int n) {
	if (n <= 0)
		return NULL;
	float *mem = malloc((size_t)n * sizeof(float));
	if (!mem) {
		fprintf(stderr, "Error: no se pudo reservar memoria.\n");
		exit(EXIT_FAILURE);
	}
	return mem;
}

void segregar(int (*criterio)(float, float), float valor, float *p, int n, float *q) {
	int j = 0;
	for (int i = 0; i < n; ++i)
		if (criterio(*(p + i), valor)) {
			if (q)
				*(q + j) = *(p + i);
			++j;
	}
}

void mostrar_piezas(char *mensaje, float *p, int n) {
	printf("\nPiezas %s:\n\n", mensaje);
	for (int i = 0; i < n; ++i)
		printf("Diámetro: %.2f\n\n", *(p + i));
}

int main(void) {
	float diametros[TAM] = {0};
	float max = 12, min = 10;
	int n = cuantas_piezas(TAM);
	
	cargar_piezas(diametros, n);
	
	int n_rectificar = contar(rectificable, max, diametros, n);
	float *p_rectificables = reservar_memoria(n_rectificar);
	segregar(rectificable, max, diametros, n, p_rectificables);
	
	int n_rechazar = contar(rechazada, min, diametros, n);
	float *p_rechazadas = reservar_memoria(n_rechazar);
	segregar(rechazada, min, diametros, n, p_rechazadas);
	
	mostrar_piezas("rectificables", p_rectificables, n_rectificar);
	mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);
	
	free(p_rectificables);
	free(p_rechazadas);
	
	return 0;
}
