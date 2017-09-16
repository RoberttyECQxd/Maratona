#include <stdio.h>

int cont;

int fibCont(int n){
	cont++;
	if(n < 2) return n;
	return fibCont(n-1) + fibCont(n-2);
}

int main(){
	
	int N, X, num_calls;
	
	scanf("%d",&N);
	while(N--){
		cont = 0;
		scanf("%d", &X);
		num_calls = fibCont(X);
		printf("fib(%d) = %d calls = %d\n",X,cont,num_calls);
	}
	
	return 0;
}
