#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
int H, W, n;
int h[MAX], w[MAX];
bool mark[MAX][MAX]; // ��nh d?u c�c � d� du?c s? d?ng

// H�m ki?m tra xem c� th? d?t m?t h�nh ch? nh?t t?i v? tr� (x, y) kh�ng
bool canPlace(int x, int y, int hi, int wi) {
    // Ki?m tra xem h�nh ch? nh?t c� n?m trong gi?i h?n kh�ng
    if (x + hi > H || y + wi > W) return false;

    // Ki?m tra xem c�c � d� b? chi?m chua
    for (int i = x; i < x + hi; i++) {
        for (int j = y; j < y + wi; j++) {
            if (mark[i][j]) return false;
        }
    }
    return true;
}

// ��nh d?u ho?c b? d�nh d?u c�c � c?a h�nh ch? nh?t
void place(int x, int y, int hi, int wi, bool value) {
    for (int i = x; i < x + hi; i++) {
        for (int j = y; j < y + wi; j++) {
            mark[i][j] = value;
        }
    }
}

// H�m backtracking
bool Try(int k) {
    // N?u d� d?t h?t c�c h�nh ch? nh?t, tr? v? true
    if (k == n) return true;

    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            // Th? d?t h�nh ch? nh?t kh�ng xoay
            if (canPlace(x, y, h[k], w[k])) {
                place(x, y, h[k], w[k], true);
                if (Try(k + 1)) return true;
                place(x, y, h[k], w[k], false);
            }

            // Th? d?t h�nh ch? nh?t xoay 90 d?
            if (canPlace(x, y, w[k], h[k])) {
                place(x, y, w[k], h[k], true);
                if (Try(k + 1)) return true;
                place(x, y, w[k], h[k], false);
            }
        }
    }

    return false; // Kh�ng th? d?t h�nh ch? nh?t th? k
}

int main() {
    // �?c d? li?u d?u v�o
    cin >> H >> W;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }

    // Kh?i t?o m?ng d�nh d?u
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            mark[i][j] = false;
        }
    }

    // G?i h�m backtracking v� in k?t qu?
    if (Try(0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
