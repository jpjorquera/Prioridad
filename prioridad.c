#include <stdio.h>
#include <math.h>		// If you can't compile, try with flag -lm

int main(){				// Descomentar para ingresar datos desde consola
	double nSemestres;
	unsigned short creditos = 1;
	short grade;
	//printf("Cantidad de semestres activos?\n");
	scanf("%lf", &nSemestres);
	unsigned int sum = 0;
	float cred_a = 0, cred_t = 0;
	double pa;
	while (creditos != 0){		// 0 creditos para terminar
		//printf("Ingrese los creditos de una asignatura\n");
		scanf("%hu", &creditos);
		if (creditos == 0){
			break;
		}
		//printf("Ingrese la nota final de dicha asignatura\n");
		scanf("%hd", &grade);
		if (grade == -1){			// Deportivos
			printf("depor\n");
			cred_a += creditos;
		}
		else {
			sum += creditos * grade;
			if (grade>=55){			// Asume nota de aprobacion 55
				cred_a += creditos;
			}
		}
		cred_t += creditos;
	}
	pa = 100 *sum / (14 * pow(nSemestres, 1.06)) * (cred_a / cred_t);
	printf("Su prioridad es: %lf \n", pa);
	return 1;
}