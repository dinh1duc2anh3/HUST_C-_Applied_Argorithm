#include <iostream>
#include <climits>
#define N 100
using namespace std;

int n, cap; // n: số lượng điểm, cap: sức chứa tối đa
int x[N]; // Phương án di chuyển
bool appear[N]; // Đánh dấu điểm đã đi qua
int c[2 * N + 1][2 * N + 1]; // Ma trận chi phí
int load; // Số khách hiện tại trên xe
int f; // Chi phí hiện tại
int f_best; // Chi phí tốt nhất
int x_best[N]; // Phương án tốt nhất
int cmin; // Chi phí nhỏ nhất giữa hai điểm

void input() {
    cin >> n >> cap;
    cmin = INT_MAX;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    }
}

void solution() {
    if (f + c[x[2 * n]][0] < f_best) {
        f_best = f + c[x[2 * n]][0];
        for (int i = 1; i <= 2 * n; i++) {
            x_best[i] = x[i];
        }
    }
}

bool check(int v, int k) {
    if (appear[v]) return false;
    if (v <= n && load + 1 > cap) return false; // Quá tải
    if (v > n && !appear[v - n]) return false;  // Trả khách chưa được đón
    return true;
}

void Try(int k) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(v, k)) {
            x[k] = v;
            f += c[x[k - 1]][x[k]];
            if (v <= n) load += 1; else load -= 1;

            appear[v] = true;

            if (k == 2 * n) {
                solution();
            } else if (f + (2 * n + 1 - k) * cmin < f_best) {
                Try(k + 1);
            }

            f -= c[x[k - 1]][x[k]];
            if (v <= n) load -= 1; else load += 1;
            appear[v] = false;
        }
    }
}

void solve() {
    load = 0;
    f = 0;
    f_best = INT_MAX; // Sửa giá trị khởi tạo
    for (int i = 1; i <= 2 * n; i++) {
        appear[i] = false;
    }
    x[0] = 0;
    Try(1);
    cout << f_best << endl;
}

int main() {
    input();
    solve();
    return 0;
}
