#include <iostream>
#include <algorithm>         //muốn sort thì cần thư viện này

#define N 100001

using namespace std;

int n,c,t;
int a[N];



bool check(int distance){
    int sl =1;
    int i =1, j=2;
    while (i <n){
        while (j <= n && a[j]-a[i] < distance) j++;
        if (j<=n) sl++;
        if (sl >=c) return true; // có thể lấy đủ c phần tử
        i =j;
        j++;
    }
    return false;
}

int MaxDistance(){
    int l = 0;
    int r = a[n]-a[1];

    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)) {
            l = mid +1;                 //?
        }
        else r = mid -1;
    }
    return r;  //tại sao return về r là xog ?
}


void solve(){
    sort(a+1,a+n+1);
    cout << MaxDistance() << endl;
}

void input(){
    cin >> t;
    while (t--){
        cin >> n >> c;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        solve();
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    return 0;
}

