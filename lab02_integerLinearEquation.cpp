#include <iostream>
using namespace std;

const int MAXN = 100;

int n,M,a[MAXN] , X[MAXN] , t[MAXN], f=0, countSolution = 0;


void initT(){
    t[1] = a[1];
    for (int i =2; i <= n; i ++){
        t[i] = t[i-1] + a[i];
    }
}


void solution(){
    if (f==M){
        countSolution++;
    }
}

void TRY(int k){
    int v;
    for (v=1; v <= (M-f- (t[n]-t[k]))  / a[k]; v++){
        X[k] = v;
        f+= a[k]*X[k];

        if (k == n){
            solution();
        } else {
            TRY(k+1);
        }

        f-= a[k]*X[k];
    }
}


int main(){
    cin >> n >> M;
    for (int i=1; i<=n; i++){
        cin>> a[i];
    }

    initT();

    TRY(1);

    cout << countSolution << endl;

    return 0;
}
