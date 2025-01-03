#include <iostream>
#include <algorithm>
#include <utility>

#define N 100001

using namespace std;

int n;
int last = -1;
int cnt = 0; //nhớ initialize biến cnt =0 trước khi dùng, tránh lỗi

pair<int,int> a[N];

void input(){
    cin >> n;
    for (int i=0; i <n; i ++){
        cin >> a[i].first >> a[i].second;
    }
}

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

void solve(){
    sort(a,a+n,cmp); //từ a đến a+n thay vì a+1 tới a+n+1 vì index bắt đầu từ 0->n-1
    for (int i=0; i < n; i++){
        if (a[i].first > last){  // tùy vào điều kiện giao mà >= hoặc >
            cnt++;
            last = a[i].second;
        }
    }
    cout << cnt <<endl;
}

int main(){
    input();
    solve();

    return 0;
}
