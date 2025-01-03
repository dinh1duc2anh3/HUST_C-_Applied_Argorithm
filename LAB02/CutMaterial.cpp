#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
int H, W, n;
int h[MAX], w[MAX];
bool mark[MAX][MAX]; // Ðánh d?u các ô dã du?c s? d?ng

// Hàm ki?m tra xem có th? d?t m?t hình ch? nh?t t?i v? trí (x, y) không
bool canPlace(int x, int y, int hi, int wi) {
    // Ki?m tra xem hình ch? nh?t có n?m trong gi?i h?n không
    if (x + hi > H || y + wi > W) return false;

    // Ki?m tra xem các ô dã b? chi?m chua
    for (int i = x; i < x + hi; i++) {
        for (int j = y; j < y + wi; j++) {
            if (mark[i][j]) return false;
        }
    }
    return true;
}

// Ðánh d?u ho?c b? dánh d?u các ô c?a hình ch? nh?t
void place(int x, int y, int hi, int wi, bool value) {
    for (int i = x; i < x + hi; i++) {
        for (int j = y; j < y + wi; j++) {
            mark[i][j] = value;
        }
    }
}

// Hàm backtracking
bool Try(int k) {
    // N?u dã d?t h?t các hình ch? nh?t, tr? v? true
    if (k == n) return true;

    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            // Th? d?t hình ch? nh?t không xoay
            if (canPlace(x, y, h[k], w[k])) {
                place(x, y, h[k], w[k], true);
                if (Try(k + 1)) return true;
                place(x, y, h[k], w[k], false);
            }

            // Th? d?t hình ch? nh?t xoay 90 d?
            if (canPlace(x, y, w[k], h[k])) {
                place(x, y, w[k], h[k], true);
                if (Try(k + 1)) return true;
                place(x, y, w[k], h[k], false);
            }
        }
    }

    return false; // Không th? d?t hình ch? nh?t th? k
}

int main() {
    // Ð?c d? li?u d?u vào
    cin >> H >> W;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }

    // Kh?i t?o m?ng dánh d?u
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            mark[i][j] = false;
        }
    }

    // G?i hàm backtracking và in k?t qu?
    if (Try(0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
