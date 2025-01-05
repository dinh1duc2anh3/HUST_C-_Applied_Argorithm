#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxN = 999 + 100;
const int oo = 1e9+7;

int   n,m,r,c;
vector<vector<int>> maze;
vector<vector<bool>> visited;

int dx[] = {1, 0 , -1 , 0};
int dy[] = {0, 1 , 0 , -1 };

queue<pair<pair<int,int>,int>> qe;  //((x,y) , steps)


bool is_valid(int x, int y, int n, int m,  vector<vector<int>> &maze , vector<vector<bool>> &visited){
    return ( x >= 0 && x < n && y>=0 && y<m && !visited[x][y] && maze[x][y] == 0 );
}

int solve(){
    //cho diem khoi dau vao trong queue
    qe.push({{r,c},0});
    visited[r][c] = true;

    while (!qe.empty()){
        int x = qe.front().first.first;
        int y = qe.front().first.second;
        int step = qe.front().second;
        qe.pop();

        //check xem da ra khoi maze chua
        if (x ==0 || x == n-1 || y == 0 || y == m-1){
            return step;
        }

        for (int i=0; i<4; i++){
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;
            if (is_valid(new_x,new_y,n,m,maze,visited)){
                qe.push({{new_x, new_y},step + 1});
                visited[new_x][new_y] = true;
            }
        }
    }
    return -2;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(0);

    //input
    cin >>n >>m >>r>>c;
    // bien (4,5) ve (3,4) theo dung chi so
    r--;
    c--;

    //khoi tao kich thuoc
    maze.resize(n,vector<int>(m));
    visited.resize(n, vector<bool>(m,false));

    for (int i=0; i<n; i++){
        for (int j= 0; j < m; j++){
            cin >> maze[i][j];
        }
    }


    //solve
    int ans = solve();
    cout << ans+1 <<endl;
    return 0;
}


