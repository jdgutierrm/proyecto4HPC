
#include <stdio.h>

#define FILAS_MATRIZ_B 5
#define COLUMNAS_MATRIZ_B 10
#define FILAS_MATRIZ_A 5
#define COLUMNAS_MATRIZ_A 5


int main(void) {

  long int matrizA[FILAS_MATRIZ_A][COLUMNAS_MATRIZ_A] = {
    {19,11,44,15,45},
    {21,50,23,48,47},
    {36,13,27,11,21},
    {16,35,10,49,15},
    {45,33,16,37,44},
  };
  long int matrizB[FILAS_MATRIZ_B][COLUMNAS_MATRIZ_B] = {
    {2237,2345,2046,2958,2001,2485,2523,2987,2293,2767},
    {4886,3706,4800,4884,4252,4136,4325,4774,4265,3500},
    {10544,11650,10605,9137,10053,11259,10245,9405,10188,10143},
    {4729,4281,3828,4157,4463,4786,4835,3641,4347,3510},
    {1564,1712,2338,2258,2134,2274,1713,1860,1620,1661},
  };

  if (COLUMNAS_MATRIZ_A != FILAS_MATRIZ_B) {
    printf("Columnas de matriz A deben ser igual a filas de matriz B");
    return 0;
  }
  //Lugar en donde se almacena el resultado
  long producto[FILAS_MATRIZ_B][COLUMNAS_MATRIZ_B];

  // Necesitamos hacer esto por cada columna de la segunda matriz (B)
//omp_set_num_threads(NUM_THREADS); Con este comando definimos la cantidad de procesadores a ejecutar. este Comando fue necesario para implementación del análisis de resultados.
#pragma omp parallel for
  for (int a = 0; a < COLUMNAS_MATRIZ_B; a++) {
    // Dentro recorremos las filas de la primera (A)
    for (int i = 0; i < FILAS_MATRIZ_A; i++) {
      long int suma = 0;
      // Y cada columna de la primera (A)
      for (int j = 0; j < COLUMNAS_MATRIZ_A; j++) {
        // Multiplicamos y sumamos resultado
        suma += matrizA[i][j] * matrizB[j][a];
      }
      // Lo acomodamos dentro del producto
      producto[i][a] = suma;
    }
  }

  // Recorrer producto
  printf("Imprimiendo producto\n");
  for (int i = 0; i < FILAS_MATRIZ_A; i++) {
    for (int j = 0; j < COLUMNAS_MATRIZ_B; j++) {
      printf("%d ", producto[i][j]);
    }
    printf("\n");
  }
}
