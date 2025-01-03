#include <iostream>
#include <vector>

using namespace std;

#define MAX 10

int H,W,n;
int h[MAX],w[MAX];
bool mark[MAX][MAX];
bool done;

bool canPlace(int x, int y, int hi, int wi){ //kiem tra xem co dat duoc hcn co kich thuoc (wi,hi) vao luoi, 
//tinh hcn tu diem trai duoi co toa do (x,y) -> diem tren cung phai co toa do (x+wi,y+hi)
	if (x+hi > H || y+wi > W) return false; //kiem tra xem co vuot ra khoi bien ko
	
	for (int i =x; i<x+hi; i++){
		for (int j=y; j<y+wi; j++){
			if (mark[i][j]) return false; //kiem tra xem co overlap ko
		}
	}
	
	return true;
}

void place (int x, int y, int hi, int wi, bool value){ //dat hcn kich thuoc wi,hi vao toa do x,y
	for (int i=x ; i<x+hi; i++){
		for (int j=y; j<y+wi; j++){
			mark[i][j] = value;
		}
	}
}

void Try(int k){
	
	if (done ) return ;
	if (k == n) { // neu tat ca hcn da duoc dat xog
        done = true;
        return;
    }
	for (int x=0; x<H; x++){
		for (int y=0; y<W; y++){
			if (canPlace(x,y,h[k],w[k])){ //neu dat duoc hcn thu k ko xoay
				place(x,y,h[k],w[k],true);
				Try(k+1);
				place(x,y,h[k],w[k],false);
			}
			
			if (canPlace(x,y,w[k],h[k])){ //neu dat duoc hcn thu k co xoay
				place(x,y,w[k],h[k],true);
				Try(k+1);
				place(x,y,w[k],h[k],false);
			}
		}
	}
}


int main(){
	cin >> H >> W;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> h[i] >> w[i];
	}
	
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			mark[i][j] = false;
		}
	}
	
	Try(0);
	if (done) cout << 1 << endl;
	else cout << 0 << endl;
	
	return 0;
}
