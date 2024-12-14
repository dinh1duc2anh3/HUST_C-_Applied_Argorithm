#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 100005

int n;
int p[MAX];
string s;
queue<int> hanh_lang;
stack<int> chuong;
int a[MAX];

void input(){
    cin >> n;
    for (int i=0; i<n; i ++){
        cin >> a[i];
    }
    for ( int i =n-1; i >=0; i--){
        chuong.push(a[i]);
    }

    cin >> s;
}

void solve(){
    int len =s.length();
    for (int i=0; i<len; i++){
        if (s[i] == 'C'){
            if (!chuong.empty()){
                int tmp_C = chuong.top();
                chuong.pop();
                hanh_lang.push(tmp_C);
            }
        }
        else {
            if (!hanh_lang.empty()){
                int tmp_H = hanh_lang.front();
                hanh_lang.pop();
                chuong.push(tmp_H);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    
    while (!chuong.empty()){
    	cout <<  chuong.top() << " ";
        chuong.pop();
	}
    return 0;

}

