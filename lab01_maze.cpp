#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//di chuyen len xuong trai phai
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


bool is_valid(int x, int y, int n, int m, const vector<vector<int>> &maze,const vector<vector<bool>> &visited ){
    return (x >= 0 && x < n && y >=0 && y < m && !visited[x][y]&& maze[x][y] == 0);
}

int bfs(int start_x, int start_y, int n, int m, const vector<vector<int>>& maze){
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    queue<pair<pair<int,int>,int>> q;  //((x,y) , steps)

    q.push({{start_x,start_y},0});
    visited[start_x][start_y] = true;

    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        //check xem da ra khoi maze chua
        if (x ==0 || x == n-1 || y == 0 || y == m-1){
            return steps;
        }

        //di chuyen 4 huong
        for (int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid(new_x,new_y,n,m,maze,visited)){
                visited[new_x][new_y] = true;
                q.push({{new_x,new_y},steps+1});
            }
        }


    }
    //ko the thoat ra duoc
    return -2;
}

int main (){

    //input
    int n,m,r,c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> maze(n,vector<int>(m));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> maze[i][j];
        }
    }

    //bfs de tim duong di ngan nhat
    int result = bfs(r-1,c-1,n,m,maze);


    cout << result+1<<endl;
    return 0;
}
