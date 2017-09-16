#include <iostream>
#include <math.h>

using namespace std;

int primo (int n){
    if(n == 0 || n == 1) return 0;
    int a = 2;
    while(a <= sqrt(n)){
        if(n % a == 0) return 0;
        a++;
    }
    return 1;
}

long long int fat(int n){
    long long int result = 1;
    int i;
    for(i = 2; i <= n; i++)
        result *= i;
    return result;
}

long long int comb(int a, int b){
    long long int result = 1;
    int i;
    if(b > a- b){
        for(i = b+1; i <= a; i++)
            result *= i;
        result /= fat(a - b);
    }else{
        for(i = a - b + 1; i <= a; i++)
            result *= i;
        result /= fat(b);
    }
    return result;
}


int main(){

    int N, M, K;
    while(1){
        int i, j;
        long long total = 0;
        cin >> N;
        cin >> M;
        cin >> K;
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
        if(K <= N && K > 1){
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
        cout << total << endl;
    }

    return 0;
}
