#include <stdio.h>
#include <math.h>		// If you can't compile, try with flag -lm

double redondear(double  *n1){
	double real, fraction, aux;
	real = *n1;
	real *= 1000;
	fraction = modf(real, &aux);
	real = aux / 1000;
	fraction *= 10;
	fraction = modf(fraction, &aux);
	if (aux >= 5){
		real += 0.001;
	}
	return real;
}

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
	pa = redondear(&pa);
	printf("Su prioridad es: %lf \n", pa);
	return 1;
}