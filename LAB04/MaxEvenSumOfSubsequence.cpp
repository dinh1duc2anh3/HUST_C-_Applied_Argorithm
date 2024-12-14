#include <iostream>

using namespace std;


#define N 10000

int a[N],s[N], f[2];
int n;
int res =-1e18;

void proc(){
    int tmp;
    for (int i=1; i<=n; i++){
        s[i] = s[i-1]+a[i];
    }
    f[1] = 1e18;

    for (int i=1; i<= n; i++){
        tmp = abs(s[i]) % 2;
        if (f[tmp] != 1e18 ) res = max (res, s[i] - f[tmp]);
        f[tmp] = min (f[tmp] , s[i]);
    }
    if (res == -1e18) cout << "not_found\n";
    else cout << res <<endl;

}

void input(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

int main(){

    input();
    proc();
    return 0;
}
