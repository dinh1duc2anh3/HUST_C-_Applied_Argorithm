#include <iostream>
using namespace std;

#define MAX 100005

long long n;
long long a[MAX];
long long res;

void input(){
    cin >> n;
    for (long long i=0; i<n; i ++){
        cin >> a[i];
    }
}

void solve(){
    long long cnt =0;
    for (long long i =0; i <n; i ++){
        if (a[i]< a[i-1] ) cnt ++;
    }
    res = cnt;
}

long long main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    cout << res+1;
    return 0;

}
