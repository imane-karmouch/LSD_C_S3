#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Exercice 1
float polylagrange(float *X,float x, int i, int n){
	float L=1;
	for(int j=0;j<n;j++){
		if(i=!j)
		L=L*(x-X[j])/(X[i]-X[j]);
	}
	return L;
}
//Exercice 2
float interplagrange(float *X,float  x,int n,float (*f)(float)){
	float L=1;
	for(int i=0;i<n;i++){
		L=L+((*f)(X[i])*polylagrange(X,x,i));
	}
	return L;
}

//Exercice 3

float f1(float x){
    return sin(x);
}

float f2(float x){
    return exp(x);
}

float f3(float x){
    return 1/(1+x*x);
}

float* xlist(double a, float b, int n){
    float* arr = (double*)malloc(sizeof(double)*n+1);
    double j = a;
    int i = 0;
    while(j <= b){
        arr[i] = j;
        j += (b-a)/n;
        i++; 
    }
    arr[n]=b;
    return arr;
}

float* ylist(float* xlist,float(*f)(float),int n){
    float* arr =(float*)malloc(sizeof(float)*n+1);
    for(int i = 0 ; i < n+1 ; i++){
        arr[i] = f(xlist[i]);
    }
    return arr;
}

float* ylistInterp(float* xlist1,float* xlist2,float(*f)(float*,float(*)(float),float,int),int n,int m){
    float(*functions[])(float)={f1,f2,f3};
    int o = n * 10;
    float* arr =(float*)malloc(sizeof(float)*o+1);
    for(int i = 0 ; i < o+1 ; i++){
        arr[i] = f(xlist1,functions[m],xlist2[i],n);
    }
    return arr;
}

void freelist(float* list){
    free(list);
    return;
}
