#include <stdio.h>
#include <math.h>		// If you can't compile, try with flag -lm

int main(){				// Descomentar para ingresar datos desde consola
	float nSemestres;
	unsigned short creditos = 1, grade;
	//printf("Cantidad de semestres activos?\n");
	scanf("%f", &nSemestres);
	unsigned int sum = 0;
	float cred_a = 0, cred_t = 0;
	float pa;
	while (creditos != 0){		// 0 creditos para terminar
		//printf("Ingrese los creditos de una asignatura\n");
		scanf("%hu", &creditos);
		if (creditos == 0){
			break;
		}
		//printf("Ingrese la nota final de dicha asignatura\n");
		scanf("%hu", &grade);
		sum += creditos * grade;
		if (grade>=55){			// Asume nota de aprobacion 55
			cred_a += creditos;
		}
		cred_t += creditos;
	}
	pa = 100 *sum / (14 * pow(nSemestres, 1.04)) * (cred_a / cred_t);
	printf("Su prioridad es: %f", pa);
	return 1;
}