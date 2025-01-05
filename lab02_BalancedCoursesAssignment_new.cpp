#include <iostream>
#include <vector>

#define N 100
using namespace std;

int m;
int n;
vector<int> T[N]; //T[i] la danh sach cac giao vien co the day duoc mon i
bool conflict[N][N]; //ma tran cac mon conflict
int load[N];
int x[N]; //x[i] : gv se day mon i

int res;

void input(){
    cin >> m >> n;
    for (int t =1; t<=m; t++){
        int k;
        cin >> k;
        for (int j=1; j<=k; j++){
            int c;
            cin >> c;
            T[c].push_back(t);
        }
    }
    int K;
    //khoi tao mang conflict toan false
    for (int i=1; i<= n; i++){
        for (int j=1; j<= n; j++){
            conflict[i][j] = false;
        }
    }

    //doc mang conflict
    cin >> K;
    for (int k =1; k<= K; k++){
        int i,j;
        cin >>i  >>j;
        conflict[i][j] = true ;
        conflict[j][i] = true;
    }
}

void solution(){
    int maxLoad = 0;
    for (int t=1; t<=m ; t++){
        maxLoad = max(maxLoad , load[t]);
    }
    if (maxLoad <res) res = maxLoad;
}

bool check(int t, int k){
    for ( int i =1; i <= k-1 ; i++){
        // neu nhu mon k conflict voi mon i va mon i duoc gan cho gv t truoc do roi thi false
        if (x[i] == t && conflict[i][k]) return false;

    }
    return true;
}

void Try(int k){
    for (int i =0; i< T[k].size() ; i++){
        int t=T[k][i];
        if (check(t,k)){
            x[k] = t;
            load[t]+= 1;
            if (k == n) solution();
            else {
                if (load[t] < res){
                    Try(k+1);
                }
            }
            load[t] -= 1;
        }
    }
}

int main(){
    input();
    //khoi tao mang load cua cac gv
    for(int t= 1; t<= m; t++){
        load[t] = 0;
    }

    res = 1e9;
    Try(1);
    cout << res;


    return 0;
}
