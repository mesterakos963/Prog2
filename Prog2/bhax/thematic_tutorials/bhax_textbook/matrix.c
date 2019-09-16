#include <stdio.h>
 #include <stdlib.h>		// malloc()

int main(void)
{
	const int db = 5;

	double **matrix;
	printf("Mutato cime: %p\n", &matrix);

	hm = (double **)malloc(db * sizeof(double));
	printf("Sorok tombjenek cime: %p\n", matrix);

	for (int i = 0; i < db; i++)
		matrox[i] = (double *)malloc(db * sizeof(double));
	printf("Elso sor cime: %p\n", matrix[0]);

	for (int i = 0; i < db; i++) {
		printf("|");
		for (int j = 0; j < db; j++) {
			matrix[i][j] = (i + 1) / (j + 1);
			printf("%.2f  ", matrix[i][j]);
		}
		printf("|\n");
	}

	return 0;
}