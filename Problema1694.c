#include <stdio.h>
#include <math.h>

int primo (int n){
	if(n == 0 || n == 1) return 0;
	int a = 2;
	while(a <= sqrt(n)){
		if(n % a == 0) return 0;
	}
	return 1;
}

int comb(int a, int b){
	int result = 1, i;
	for(i = b+1; i <= a; i++)
		result *= i;
	return result;
}

int main(){
	
	int N, M, K;
	while(1){
		int i, j, total = 0;
		scanf("%d %d %d", &N, &M, &K);
		if(N == 0 && M == 0 && K == 0) break;
		int matriz[N][M];
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				matriz[i][j] = primo(i*M + j) ? -1 : i*M + j; 
		int cont;
		if(K <= M){
				for(i = 0; i < N; i++){
					cont = 0;
					for(j = 0; j < M; j++){
						if(matriz[i][j] != -1)
							cont++;
					}
					if(cont >= K)
						total += comb(cont, K);
				}
		}
		if(K <= N){
				for(i = 0; i < M; i++){
					cont = 0;
					for(j = 0; j < N; j++){
						if(matriz[j][i] != -1)
							cont++;
					}
					if(cont >= K)
						total += comb(cont, K);
				}
		}
		printf("%d", total);
	}
	
	return 0;
}
