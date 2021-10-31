#include "header.h"
float **mult_m(float **A,float **B,int n){
	float **C;
	C=(float **)malloc(n*sizeof(float*));
	for (int i=0;i<n ;i++)
		C[i]=(float *)malloc(n*sizeof(float));
	int i;
	int j;
	for (i=0;i<n ;i++){
		for (j=0;j<n ;j++){
			C[i][j]=0;
			for (int k=0;k<n ;k++)
				 C[i][j] += A[i][k] * B[k][j];
		}
	}
	return C;
}
