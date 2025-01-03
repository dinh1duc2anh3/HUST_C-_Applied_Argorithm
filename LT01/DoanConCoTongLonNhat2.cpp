//dung quy hoach dong
#include <iostream>
#include <vector>
#include <algorithm>

#define N 20

using namespace std;

int a[N];
int mem[N];
int n,ans;
bool  mark[N];
int start, end;

int MaxSum(int i){
	if (i == 1) {
		mem[i] = a[1];
		mark[i] = true;
		return a[1];
	}
	if (mark[i]) return mem[i];
	
	int res = max(a[i], a[i] + MaxSum(i-1));
	mark[i] = true;
	mem[i ] = res;
	return res;
}

//chi ra doan nao trong day tao ra tong lon nhat

//truy vet bang de quy
void Trace(int i){
	if (i!=1 && mem[i] == a[i]+mem[i-1]) {
		Trace(i-1);
	}
	cout << a[i]<<' ';
} 

//truy vet bang vong lap


int main(){
	cin >> n;
	
	for (int i=1; i<=n; i++){
		cin >>a[i];
	}
	
	for (int i=1; i<= n; i++){
		mark[i] = false;
		mem[i] = 0;
	}
	
	
	for (int i=1; i<=n; i++){
		int sum = MaxSum(i);
		if (sum > ans) {
			ans = sum;
			end = i; // cap nhat vi tri ket thuc cua doan co tong lon nhat
		}
	
	}
	
	//tim vi tri bat dau cua doan lon nhat bang vong lap thay vi de quy : start
	int tmpSum = 0;
	start = end;
	for(int i=end; i>= 1; i--){
		tmpSum += a[i];
		if (tmpSum == ans) {
			start = i;
			break;
		}
	}
	
	cout << ans<<endl;
	
	//in ra doan con co tong lon nhat
	for (int i = start; i <= end; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
	return 0;
}




