#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCutMaterial(int H, int W, int n, const vector<pair<int, int>>& rectangles) {
    int total_area = 0;

    for (const auto& rect : rectangles) {
        total_area += rect.first * rect.second;
    }

    // Kiểm tra xem tổng diện tích của các hình chữ nhật nhỏ có vượt quá diện tích của hình chữ nhật lớn không
    if (total_area > H * W) {
        return false;
    }

    // Kiểm tra khả năng sắp xếp theo chiều cao hoặc chiều rộng
    int total_height = 0;
    int total_width = 0;
    int max_height = 0;
    int max_width = 0;

    for (const auto& rect : rectangles) {
        total_height += rect.first;
        total_width += rect.second;
        max_height = max(max_height, rect.first);
        max_width = max(max_width, rect.second);
    }

    // Kiểm tra sắp xếp mà không xoay
    if (total_height <= H && max_width <= W) {
        return true;
    }
    if (total_width <= W && max_height <= H) {
        return true;
    }

    // Kiểm tra sắp xếp với xoay chiều
    total_height = 0; // reset total height
    total_width = 0;  // reset total width
    max_height = 0;   // reset max height
    max_width = 0;    // reset max width

    for (const auto& rect : rectangles) {
        total_height += rect.second; // dùng chiều rộng làm chiều cao
        total_width += rect.first;    // dùng chiều cao làm chiều rộng
        max_height = max(max_height, rect.second); // chiều rộng là chiều cao lớn nhất
        max_width = max(max_width, rect.first);    // chiều cao là chiều rộng lớn nhất
    }

    // Kiểm tra sắp xếp với chiều xoay
    if (total_height <= H && max_width <= W) {
        return true;
    }
    if (total_width <= W && max_height <= H) {
        return true;
    }

    return false;
}

int main() {
    int H, W;
    cin >> H >> W;
    int n;
    cin >> n;

    vector<pair<int, int>> rectangles(n);
    for (int i = 0; i < n; ++i) {
        cin >> rectangles[i].first >> rectangles[i].second;
    }

    // Kết quả
    cout << (canCutMaterial(H, W, n, rectangles) ? 1 : 0) << endl;

    return 0;
}
