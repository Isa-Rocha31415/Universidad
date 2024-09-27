//algoritmo 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "libarram.h"

#define N 3 // clases 

int main() {
    int P[N]; 
    int n; 
    float md, de; 
    double d; // Tiempo de produccion
    double t_total = 0;
    double t_rapido = 0, t_normal = 0, t_lento = 0;
    float M[N-1]; 

    srand(time(NULL)); //  semilla aleatoria

    do {
        printf("Ingrese el número de productos: ");
        scanf("%d", &n);
    } while (n < 1);

    do {
        printf("Ingrese la media: ");
        scanf("%f", &md);
        printf("Ingrese la desviación estándar: ");
        scanf("%f", &de);
    } while (md <= 0 || de <= 0);

    for (int i = 0; i < N-1; i++) {
        printf("Ingrese el rango %d: ", i+1);
        scanf("%f", &M[i]);
    }

    for (int i = 0; i < N; i++) {
        P[i] = 0;
    }

    clock_t start_time = clock();

    // ### Clasificación de productos ###
    for (int i = 0; i < n; i++) {
        d = dist_norm(md, de);  // Simular tiempo 
        t_total += d;  // acumulamos el tiemop total

        // Clasificar usando operaciones bit a bit
        int x = (d < M[0]) << 2;
        x |= (d >= M[0] && d < M[1]) << 1;
        x |= (d >= M[1]);

        switch (x) {
            case 4: // si es rapido
                P[0]++;
                t_rapido += d;
                break;
            case 2: // normal
                P[1]++;
                t_normal += d;
                break;
            case 1: // lento
                P[2]++;
                t_lento += d;
                break;
        }
    }
