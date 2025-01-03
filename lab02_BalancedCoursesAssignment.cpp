#include <iostream>
using namespace std;

//each teacher can teach a list of courses
//pairs of conflicting 2 courses that cant be assigned to the same teacher




#define N 50

vector<int> T[N];       // List of courses each teacher can teach
int n, m;               // n courses, m teachers
bool conflict[N][N];    // Matrix to mark conflicting courses
int x[N];               // x[i] is the teacher assigned to course i
int load[N];            // load[i] is the number of courses assigned to teacher i
int res;                // Minimum maximum load of teachers

bool check(int t,int k){
    for (int i=1; i<k; i++){
        if (x[i] == t && conflict[i][k]){
            return false;
        }
    }
}

void Try(int k){
    for (i=0; i<T[k].size() ; i++){
        int t = T[k][i];
        if (check(t,k)){
            x[k]=t;  //assign course k is taught by teacher t
            load[t] += 1;
            if (k == n) solution();
            else {
                if (load[t] < res) Try(k+1);
            }
            load[t] -= 1;
        }
    }
}

void input(){
    cin >> m >> n;
    for (int t = 1; t <=m; t++){
        int k ; cin >> k;
        for (int j=1; j <=k ;j ++){
            int c;
            cin >>c;
            T[c].push_back(t);
        }
    }

    int K;
    for (int i=1; i <=n; i++){
        for (int j=1; j <=n; j ++){
            conflict[i][j] = false;
        }
    }
    cin >> K;
    for (int k=1; k <= K; k++){
        int i,j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }
}

int main(){
    input();
    for (int i=1; t <= m; t ++) load[t] = 0;
    res = 9999;
    Try(1);
    cout << res;
    return 0;
}
