#include <iostream>
using namespace std;

#define MAX 100

int N;
int cap;
int A[2*MAX+1][2*MAX+1];

int x[MAX];
int x_best[MAX];
int appear[2*MAX+1];
int load;
int f;
int f_best;
int cmin;

void input() {
    cin >> N >> cap;
    cmin = 100000;
    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            cin >> A[i][j];
            if (i != j && cmin > A[i][j]) cmin = A[i][j];
        }
    }
}

int check(int v, int k) {
    if (appear[v] == 1) return 0;
    if (v > N) {
        if (!appear[v - N]) return 0;
    } else if (load + 1 > cap) return 0;
    return 1;
}

void solution() {
    if (f + A[x[2 * N]][0] < f_best) {
        f_best = f + A[x[2 * N]][0];
        for (int i = 0; i <= 2 * N; i++) {
            x_best[i] = x[i];
        }
        cout << "update best " << f_best << endl;
    }
}

void Try(int k) {
    for (int v = 1; v <= 2 * N; v++) {
        if (check(v, k)) {
            x[k] = v;
            f += A[x[k - 1]][x[k]];
            if (v <= N) load += 1;
            else load -= 1;
            appear[v] = 1;
            if (k == 2 * N) solution();
            else {
                if (f + (2 * N + 1 - k) * cmin < f_best)
                    Try(k + 1);
            }
            if (v <= N) load -= 1;
            else load += 1;
            appear[v] = 0;
            f -= A[x[k - 1]][x[k]];
        }
    }
}

void solve() {
    load = 0;
    f = 0;
    f_best = 100000;
    for (int i = 1; i <= 2 * N; i++) appear[i] = 0;
    x[0] = 0;
    Try(1);
    cout << f_best;
}

void print() {
    for (int i = 0; i <= 2 * N; i++) cout << x_best[i] << " ";
}

int main() {
    input();
    solve();
    print();
    return 0;
}
