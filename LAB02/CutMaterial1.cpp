#include <iostream>
#include <vector>

using namespace std;

class MaterialCutter {
private:
    int H, W;
    vector<pair<int, int>> pieces;
    vector<vector<int>> grid;

    bool canPlace(int piece_h, int piece_w, int start_i, int start_j) {
        if (start_i + piece_h > H || start_j + piece_w > W) {
            return false;
        }

        // Check if the entire piece area is available (0 means available)
        for (int i = start_i; i < start_i + piece_h; i++) {
            for (int j = start_j; j < start_j + piece_w; j++) {
                if (grid[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    void placePiece(int piece_h, int piece_w, int start_i, int start_j, int value) {
        for (int i = start_i; i < start_i + piece_h; i++) {
            for (int j = start_j; j < start_j + piece_w; j++) {
                grid[i][j] = value;
            }
        }
    }

    bool tryBothOrientations(int piece_h, int piece_w, int start_i, int start_j) {
        // Try normal orientation
        if (canPlace(piece_h, piece_w, start_i, start_j)) {
            placePiece(piece_h, piece_w, start_i, start_j, 1);
            return true;
        }

        // Try rotated orientation if dimensions are different
        if (piece_h != piece_w && canPlace(piece_w, piece_h, start_i, start_j)) {
            placePiece(piece_w, piece_h, start_i, start_j, 1);
            return true;
        }

        return false;
    }

    bool backtrack(int piece_idx) {
        if (piece_idx == pieces.size()) {
            return true;
        }

        int curr_h = pieces[piece_idx].first;
        int curr_w = pieces[piece_idx].second;

        // Try all possible positions
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == 0) {  // If position is available
                    if (tryBothOrientations(curr_h, curr_w, i, j)) {
                        if (backtrack(piece_idx + 1)) {
                            return true;
                        }
                        // If placing this piece doesn't lead to solution,
                        // remove it and try other positions
                        placePiece(curr_h, curr_w, i, j, 0);
                        if (curr_h != curr_w) {
                            placePiece(curr_w, curr_h, i, j, 0);
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    MaterialCutter(int height, int width) : H(height), W(width) {
        grid = vector<vector<int>>(H, vector<int>(W, 0));
    }

    void addPiece(int h, int w) {
        pieces.push_back({h, w});
    }

    bool canCut() {
        // Calculate total area of all pieces
        int total_area_pieces = 0;
        for (const auto& piece : pieces) {
            total_area_pieces += piece.first * piece.second;
        }

        // Quick check - if total area exceeds material
        if (total_area_pieces > H * W) {
            return false;
        }

        return backtrack(0);
    }
};

int main() {
    // Read rectangle dimensions
    int H, W;
    cin >> H >> W;

    // Read number of pieces
    int n;
    cin >> n;

    MaterialCutter cutter(H, W);

    // Read dimensions of each piece
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        cutter.addPiece(h, w);
    }

    // Output result
    cout << (cutter.canCut() ? 1 : 0) << endl;

    return 0;
}
