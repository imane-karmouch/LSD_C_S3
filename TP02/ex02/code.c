
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float dichotomie(float (*f)(float), float a, float b, int n){
	float m;
	for (int i=0;i<n ;i++){
		m =(a+b)/2;
	 	float res = (*f)(m);
		if (0 <= res)
			b=m;
		else
			a=m;
	}
	return m;
}
float newton(float (*f)(float), float (*g)(float), float m,int n){
	for (int i=0;i<n ;i++){
		float a = (*f)(m);
		float b = (*g)(m);
		m= m - a/b;
	}
	return m;
}
float f (float x){
	return x*x*2-1;
}
float g (float x){
	return 2*x;
}
float dichotomie2(float (*f)(float), float a, float b, double e){
	int n;
	n=((log(b-a)/e*log(2))+1;
	float m;
	m=dichotomie(f,a,b,n);
	return m;
}
int main(){
	float x;
	float a=1;
	float b=3;
	int n=90;
	//float m = dichotomie(f,a,b,n);*
	//float m=newton(f,g,1,90);
	
	printf("%lf",m);
	return 0;
}

