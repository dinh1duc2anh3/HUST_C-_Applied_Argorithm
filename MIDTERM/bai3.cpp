#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 20

int n;
bool visited[MAX];
int x[MAX]; 
int cnt;
//	x[0] = H, x[1] = U, x[2] = S, x[3] = T
//  x[4] = O, x[5] = I, x[6] = C 


void input(){
    cin >> n;
    
    for (int i=0; i<MAX; i++){
    	visited[i] = false;
	}
	cnt =0;

}

bool check(int a, int i) {
    if (a == 0 && i == 0) return false; // x[0] không du?c là 0
    if (a == 2 && i == 0) return false; // x[2] không du?c là 0
    if (visited[i]) return false; // i dã du?c s? d?ng
    return true;
}

int solution(){
	int hust = x[0] * 1000 + x[1]*100 + x[2]*10 + x[3];
	int soict = x[2]*10000 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3];
	
	if (hust + soict == n){
		cnt++;
	}
}

void TRY(int a){
	for (int i=0; i<10; i++){
		if (check(a,i)){
			visited[i] = true;
			x[a] = i;
			if (a == 6) {
				solution();
			}
			else TRY(a+1);
			
			visited[i] = false;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    
    while (T>0){
    	input();
    	TRY(0);
    	cout<<cnt<<endl;
    	T--;
	}
	
	return 0;
    

}

