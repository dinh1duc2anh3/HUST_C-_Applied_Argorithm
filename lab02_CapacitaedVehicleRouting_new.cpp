#include <iostream>
#include <climits>

using namespace std;

#define N 100

int n, K, Q; // Số điểm cần giao hàng, số xe, sức chứa
int d[N];    // d[i]: số lượng hàng của khách i
int c[N + 1][N + 1]; // c[i][j]: chi phí từ i -> j

bool visited[N]; // visited[i]: khách hàng i đã được ghé thăm hay chưa
int load[N];     // load[k]: tải hiện tại của xe k
int minCost = INT_MAX; // Tổng chi phí nhỏ nhất
int curCost = 0;       // Tổng chi phí hiện tại

void input() {
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++) visited[i] = false;
}

bool checkAllVisited(){
    for (int i=1; i<=n; i++){
        if (!visited[i]) return false;
    }
    return true;
}

void Try(int k, int curPos) {
    if (checkAllVisited()) { // Nếu tất cả các ddiem đã đi xong
        curCost += c[curPos][0]; // Chi phí quay về kho
        minCost = min(minCost, curCost);
         curCost -= c[curPos][0]; // Hoàn tác
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && load[k] + d[i] <= Q) { // Nếu khách hàng i chưa được phục vụ và xe k còn đủ chỗ
            visited[i] = true;
            load[k] += d[i];
            curCost += c[curPos][i]; // Di chuyển từ curPos tới i
            if (curCost < minCost){
                Try(k, i); // Tiếp tục ghé thăm khách hàng tiếp theo
            }

            // Backtrack
            curCost -= c[curPos][i];
            load[k] -= d[i];
            visited[i] = false;
        }
    }

    // Quay lại kho sau khi đã ghé thăm xong các khách hàng
    if (curPos != 0) {
        curCost += c[curPos][0]; // Quay về kho
        if (curCost < minCost){
            Try(k + 1, 0);           // Chuyển sang xe tiếp theo
        }

        curCost -= c[curPos][0]; // Hoàn tác
    }
}

int main() {
    input();
    Try(1, 0); // Bắt đầu từ xe 1 tại kho
    cout << minCost << endl;
    return 0;
}
