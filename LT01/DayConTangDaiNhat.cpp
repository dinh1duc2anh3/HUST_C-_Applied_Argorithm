#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 20

using namespace std;

int n, ans, pos; // n: so luong phan tu, ans: do dai LIS, pos: vi tri ket thuc LIS
int a[MAX], mem[MAX]; // a: mang dau vao, mem: mang ghi nho (quy hoach dong)

// Ham tinh do dai day con tang dai nhat ket thuc tai vi tri i
int LIS(int i) {
    if (mem[i] != -1) return mem[i]; // Neu da tinh truoc, tra ve ket qua luu trong mem

    int res = 1; // LIS tai vi tri i co it nhat 1 phan tu (chinh no)
    for (int j = 1; j <= i - 1; j++) { // Duyet qua cac vi tri truoc i
        if (a[j] < a[i]) { // Neu phan tu truoc nho hon phan tu hien tai
            res = max(res, 1 + LIS(j)); // Cap nhat do dai LIS
        }
    }
    mem[i] = res; // Luu ket qua vao mem
    return res;
}

int main() {
    // Nhap so luong phan tu va mang dau vao
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Khoi tao mang mem voi gia tri -1 (chua tinh)
    fill(mem, mem + MAX, -1);

    // Tinh do dai LIS va vi tri ket thuc
    ans = 0;
    pos = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < LIS(i)) { // Neu tim thay do dai lon hon
            ans = LIS(i);   // Cap nhat do dai LIS
            pos = i;        // Cap nhat vi tri ket thuc
        }
    }

    // Hien thi do dai LIS
    cout << "Length of LIS: " << ans << endl;

    // Truy vet day con tang dai nhat
    stack<int> stk; // Stack de luu cac phan tu cua LIS
    int i = pos;
    for (int k = 0; k < ans; k++) {
        stk.push(a[i]); // Them phan tu vao stack
        for (int j = i - 1; j >= 1; j--) { // Tim phan tu truoc trong LIS
            if (a[j] < a[i] && mem[i] == mem[j] + 1) {
                i = j; // Cap nhat vi tri
                break;
            }
        }
    }

    // Hien thi day con tang dai nhat
    cout << "LIS: ";
    while (!stk.empty()) {
        cout << stk.top() << ' '; // In cac phan tu trong stack
        stk.pop();
    }
    cout << endl;

    return 0;
}

