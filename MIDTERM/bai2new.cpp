#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 100005

long long n;
long long p[MAX];
string s;
queue<long long> hanh_lang;
stack<long long> chuong;
long long a[MAX];

void input(){
    cin >> n;
    for (long long i=0; i<n; i ++){
        cin >> a[i];
    }
    for ( long long i =n-1; i >=0; i--){
        chuong.push(a[i]);
    }

    cin >> s;
}

void solve(){
    long long len =s.length();
    for (long long i=0; i<len; i++){
        if (s[i] == 'C'){
            if (!chuong.empty()){
                long long tmp_C = chuong.top();
                chuong.pop();
                hanh_lang.push(tmp_C);
            }
        }
        else {
            if (!hanh_lang.empty()){
                long long tmp_H = hanh_lang.front();
                hanh_lang.pop();
                chuong.push(tmp_H);
            }
        }
    }
}

long long main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    while (!chuong.empty()){
    	cout <<  chuong.top() << " ";
        chuong.pop();
	}
    return 0;

}

