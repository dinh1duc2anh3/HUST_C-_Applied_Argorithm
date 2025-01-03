#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring> // De dung memset

#define N 20

using namespace std;

int n;
string x, y;
int mem[N][N];

// Ham tinh do dai cua LCS
int LCS(int i, int j) {
    if (i == 0 || j == 0) return 0; // Neu mot trong hai chuoi rong, LCS = 0
    if (mem[i][j] != -1) return mem[i][j]; // Neu da tinh truoc, tra ve gia tri

    int res = 0;
    res = max(res, LCS(i - 1, j));   // Bo ky tu cuoi cua x
    res = max(res, LCS(i, j - 1));   // Bo ky tu cuoi cua y
    if (x[i - 1] == y[j - 1]) {      // Neu ky tu cuoi giong nhau
        res = max(res, LCS(i - 1, j - 1) + 1);
    }
    return mem[i][j] = res;          // Luu ket qua vao mang ghi nho
}

// Ham truy vet tim LCS bang vong lap
void iterTrace() {
    int i = x.size();
    int j = y.size();

    stack<char> stk; // Luu cac ky tu thuoc LCS
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) { // Neu ky tu khop
            stk.push(x[i - 1]);     // Them ky tu vao stack
            i--; j--;               // Lui ca hai chi so
        } else if (mem[i - 1][j] >= mem[i][j - 1]) { 
            i--; // Lui chi so x neu mem[i-1][j] >= mem[i][j-1]
        } else {
            j--; // Lui chi so y neu mem[i][j-1] > mem[i-1][j]
        }
    }

    // In day LCS
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
}

int main() {
    // Nhap hai chuoi x va y
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;

    // Khoi tao mang mem voi -1
    memset(mem, -1, sizeof(mem));

    // Goi ham LCS va in ket qua
    cout << "Length of LCS: " << LCS(x.size(), y.size()) << endl;

    // Truy vet de in ra LCS
    cout << "LCS: ";
    iterTrace();

    return 0;
}

