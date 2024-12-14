#include <iostream>
using namespace std;

#define MAX 100005

int n;
int a[MAX];
int res;

void input(){
    cin >> n;
    for (int i=0; i<n; i ++){
        cin >> a[i];
    }
}

void solve(){
    int cnt =0;
    for (int i =0; i <n; i ++){
        if (a[i]< a[i-1] ) cnt ++;
    }
    res = cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    cout << res+1;
    return 0;

}
