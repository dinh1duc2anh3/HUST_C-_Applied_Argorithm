#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 1000005

int n,k;
int best_len = 0;
int a[MAX];
int cnt;

double res,sum,max;

void input(){
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >>a[i];
	}
	
}

double solve(int start,int len){
	sum =0;
	for (int j =start; j < start+len; j++){
		
			sum += a[j];
		
	}
	return sum;
}

void solution(){
	for (int len =k; len<=n; len++){
		for (int i=0; i < n-len; i ++){
			double tmp = solve(i,len);
			if (tmp > res){
				res = tmp;
				best_len = len;
			}
		}
	}
	
}

int main(){       
	ios_base::sync_with_stdio(false); cin.tie(NULL);                              
	input();
	solution();
    cout << res/best_len;
    
	return 0;
    

}

