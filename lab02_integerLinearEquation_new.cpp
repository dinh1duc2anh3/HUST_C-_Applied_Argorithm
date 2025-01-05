#include <iostream>

#define N 100

using namespace std;
int n,M,f = 0 , cnt = 0;
int a[N],t[N],x[N];

void solution(){
    if (f == M){
        cnt++;
    }
}

void Try(int k){
    for (int v = 1; v <= (M- f - (t[n] - t[k])) /a[k] ; v++){
        x[k] = v;
        f = f + x[k] * a[k];
        if (k == n-1) {
            solution();
        }
        else Try(k+1);
        f = f - x[k]*a[k];
    }
}


int main(){
    //input
    cin >> n >> M;
    for (int i=0; i<n; i++){
        cin >> a[i];

    }

    //khoi tao t[] prefix sum
    t[0] = a[0];
    for (int i=1; i<n; i++){
        t[i] = a[i]+ t[i-1];
    }

    //solve
    Try(0);

    cout << cnt;

    return 0;
}
