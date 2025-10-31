#include <stdio.h>
#include <stdlib.h>

#define TAM_NOMBRE_ESTUDIANTE 80
#define TAM_NOMBRE_MATERIA 80

typedef struct {
  char nombre[TAM_NOMBRE_MATERIA];
  int cantidad_parciales;
  int *parcial;
  float promedio;
} materia_t;

struct estudiante {
  int legajo;
  char nombre[TAM_NOMBRE_ESTUDIANTE];
  int cantidad_materias;
  materia_t *materia;
};

struct estudiante cargar_estudiante(void);
void imprimir_estudiante(struct estudiante);
materia_t* reservar_materias(int);
void liberar_materias(materia_t*, int);
int* reservar_parciales(int);
void liberar_parciales(int*);
void cargar_materia(materia_t*);
void cargar_parciales(materia_t*);
void calcular_promedio(materia_t*);

int main(void){
  struct estudiante est1;

  est1 = cargar_estudiante();

  for (int i = 0; i < est1.cantidad_materias; i++)
    cargar_materia(&est1.materia[i]);

  imprimir_estudiante(est1);

  for (int i = 0; i < est1.cantidad_materias; i++)
    liberar_parciales(est1.materia[i].parcial);

  liberar_materias(est1.materia, est1.cantidad_materias);

  return 0;
}

struct estudiante cargar_estudiante(void) {
  struct estudiante e;

  printf("Ingrese legajo del estudiante: ");
  scanf("%d", &e.legajo);

  printf("Ingrese nombre del estudiante: ");
  scanf(" %80[^\n]s", e.nombre);

  printf("¿Cuántas materias va a cargar? ");
  scanf("%d", &e.cantidad_materias);

  e.materia = reservar_materias(e.cantidad_materias);

  return e;
}

void imprimir_estudiante(struct estudiante e) {
  printf("%10d %s\n", e.legajo, e.nombre);

  for (int i = 0; i < e.cantidad_materias; i++) {
    printf("%s:", e.materia[i].nombre);
    for (int j = 0; j < e.materia[i].cantidad_parciales; j++)
      printf(" %d", e.materia[i].parcial[j]);
    printf(" Promedio: %.2f\n", e.materia[i].promedio);
  }
}

void cargar_materia(materia_t *p) {
  printf("Ingrese el nombre de la materia: ");
  scanf(" %80[^\n]s", p->nombre);
  printf("¿Cuántos parciales tiene %s? ", p->nombre);
  scanf("%d", &p->cantidad_parciales);

  p->parcial = reservar_parciales(p->cantidad_parciales);

  cargar_parciales(p);
}

void cargar_parciales(materia_t *p) {
  int nota;

  for (int i = 0; i < p->cantidad_parciales; i++) {
    do {
      printf("Ingrese calificación del %d° parcial (1-10): ", i + 1);
      if (scanf("%d", &nota) != 1) {
        printf("Entrada inválida. Por favor ingrese un número entre 1 y 10.\n");
        while (getchar() != '\n');
        nota = 0;
      } else if (nota < 1 || nota > 10) {
        printf("La nota debe estar entre 1 y 10.\n");
      }
    } while (nota < 1 || nota > 10);

    p->parcial[i] = nota;
  }

  calcular_promedio(p);
}

void calcular_promedio(materia_t *p) {
  int suma = 0;

  for (int i = 0; i < p->cantidad_parciales; i++)
    suma += p->parcial[i];

  if (p->cantidad_parciales > 0)
    p->promedio = (float)suma / p->cantidad_parciales;
  else
    p->promedio = 0.0f;
}

materia_t* reservar_materias(int n) {
  materia_t *p = NULL;

  p = malloc(n * sizeof(materia_t));
  if (p == NULL) {
    printf("No se pudo reservar memoria. Fin del programa.\n");
    exit(1);
  }

  return p;
}

int* reservar_parciales(int n) {
  int *p = NULL;

  p = malloc(n * sizeof(int));
  if (p == NULL) {
    printf("No se pudo reservar memoria. Fin del programa.\n");
    exit(1);
  }

  return p;
}

void liberar_parciales(int *p) {
  if (p != NULL)
    free(p);
}

void liberar_materias(materia_t *p, int n) {
  if (p != NULL)
    free(p);
}
