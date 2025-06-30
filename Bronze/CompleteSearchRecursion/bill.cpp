#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Rect {
    int w, h;
    char label;
};


bool tryLayout(int n, vector<Rect> rects, vector<string> &result) {
    result.assign(n, string(n, ' '));
    // Case 1: All in one row
    if (rects[0].h == rects[1].h && rects[1].h == rects[2].h && rects[0].h == n &&
        rects[0].w + rects[1].w + rects[2].w == n) {
        int col = 0;
        for (auto &r : rects) {
            for (int i = 0; i < r.h; ++i)
                for (int j = 0; j < r.w; ++j)
                    result[i][col + j] = r.label;
            col += r.w;
        }
        return true;
    }

    // Case 2: All in one column
    if (rects[0].w == rects[1].w && rects[1].w == rects[2].w && rects[0].w == n &&
        rects[0].h + rects[1].h + rects[2].h == n) {
        int row = 0;
        for (auto &r : rects) {
            for (int i = 0; i < r.h; ++i)
                for (int j = 0; j < r.w; ++j)
                    result[row + i][j] = r.label;
            row += r.h;
        }
        return true;
    }

    // Case 3: One fills top, others below side by side
    for (int i = 0; i < 3; ++i) {
        Rect top = rects[i];
        Rect r1 = rects[(i + 1) % 3];
        Rect r2 = rects[(i + 2) % 3];

        if (top.h == n && top.w == n) continue; // Already tried full square

        if (top.h + max(r1.h, r2.h) == n && r1.w + r2.w == n && top.w == n && r1.h <= n && r2.h <= n) {
            // Place top
            for (int i = 0; i < top.h; ++i)
                for (int j = 0; j < top.w; ++j)
                    result[i][j] = top.label;
            // Place bottom row
            for (int i = 0; i < r1.h; ++i)
                for (int j = 0; j < r1.w; ++j)
                    result[top.h + i][j] = r1.label;
            for (int i = 0; i < r2.h; ++i)
                for (int j = 0; j < r2.w; ++j)
                    result[top.h + i][r1.w + j] = r2.label;
            return true;
        }
    }

    return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    vector<pair<int, int>> r1 = {{x1, y1}, {y1, x1}};
    vector<pair<int, int>> r2 = {{x2, y2}, {y2, x2}};
    vector<pair<int, int>> r3 = {{x3, y3}, {y3, x3}};

    int totalArea = x1 * y1 + x2 * y2 + x3 * y3;
    int n = sqrt(totalArea);
    if (n * n != totalArea) {
        cout << -1 << endl;
        return 0;
    }

    for (auto a : r1) {
        for (auto b : r2) {
            for (auto c : r3) {
                vector<Rect> rects = {
                    {a.first, a.second, 'A'},
                    {b.first, b.second, 'B'},
                    {c.first, c.second, 'C'}
                };
                vector<string> result;
                if (tryLayout(n, rects, result)) {
                    cout << n << endl;
                    for (string &row : result)
                        cout << row << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
