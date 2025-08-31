#include <stdio.h>
#include <math.h>

float calcularAreaRectangulo(float largo, float altura) {
	return largo * altura;
}

float calcularPerimetroRectangulo(float largo, float altura) {
	return 2 * (largo + altura);
}

float calcularDiagonalRectangulo(float largo, float altura) {
	return sqrtf(largo * largo + altura * altura); 
}

float calcularAreaCirculo(float rad) {
	return 3.14 * rad * rad;   
}

float calcularPerimetroCirculo(float rad) {
	return 2 * 3.14 * rad;
}

void imprimirResultados(float area, float perimetro) {
	printf("El valor del �rea es: %.2f\n", area);
	printf("El valor del per�metro es: %.2f\n", perimetro);
}

int main() {
	int opcion;
	float largo, altura, rad;
	float area, perimetro;
	
	do{
	printf("Elija una opci�n:\n1: Calcular rect�ngulo\n2: Calcular c�rculo\n");
	scanf("%d", &opcion);
	
	switch (opcion) {
	case 1:
		printf("Rect�ngulo seleccionado\n");
		
		printf("Ingrese el largo: ");
		scanf("%f", &largo);
		
		printf("Ingrese la altura: ");
		scanf("%f", &altura);
		
		area = calcularAreaRectangulo(largo, altura);
		perimetro = calcularPerimetroRectangulo(largo, altura);
		
		imprimirResultados(area, perimetro);
		
		printf("La diagonal vale: %.2f\n", 
			   calcularDiagonalRectangulo(largo, altura));
		break;
		
	case 2:
		printf("C�rculo seleccionado\n");
		
		printf("Ingrese el radio: ");
		scanf("%f", &rad);
		
		area = calcularAreaCirculo(rad);
		perimetro = calcularPerimetroCirculo(rad);
		
		imprimirResultados(area, perimetro);
		break;
		
	default:
		printf("\nOpci�n no valida\n");
		break;
	}
	} while (opcion != 1 && opcion != 2);
	
	return 0;
}
