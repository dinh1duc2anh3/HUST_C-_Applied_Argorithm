#include <iostream>
#include <algorithm>

#define N 1000006

using namespace std;

int n;
int a[N];
int temp[N];
int const MOD = 1e9+7;

long long _merge(int l, int mid, int r){
    long long inv_count = 0;              //phải cho biến inv_count làm biến cục bộ vì mỗi đoạn lại tính rồi sau đó chi lấy giá trị, ko phải cộng biến toàn cục
    int i = l, j = mid+1;
    int k = l;   //reset k for each merge
    while ( i <= mid && j <= r ){
        if (a[i] > a[j]){
            temp[k++] = a[j++];
            inv_count = ( inv_count +  (mid -i +1) ) % MOD;
        }
        else temp[k++] = a[i++];
    }

    // copy những phần tử còn lại của nửa bên trái(nếu con) vào mảng tgian
    while (i<= mid ) temp[k++] = a[i++];

    // copy những phần tử còn lại của nửa bên trái(nếu con) vào mảng tgian
    while (j<=r) temp[k++] = a[j++];


    for (int i = l; i <= r; i++){
        a[i] = temp[i];
    }
    return inv_count;
}

long long mergeSort(int l, int r){
    long long inv_count = 0;
    if (l < r){
        int mid = (l+r)/2;
        inv_count = ( inv_count +  mergeSort(l,mid) ) % MOD;  //nhớ đề bài bảo kết quả phải mod 1e9+7 đó
        inv_count = (inv_count + mergeSort(mid +1, r) ) % MOD;
        inv_count = (inv_count + _merge(l,mid,r) ) % MOD;
    }
    return inv_count;
}

void input(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    input();

    cout << mergeSort(1,n) <<endl;
    return 0;
}

