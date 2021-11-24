
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <algorithm>
#include <iterator>


int main() {

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int nRows, nCols;
    cin >> nRows >> nCols;
    int start_row, start_col;
    cin >> start_row >> start_col;
    int max_x, max_y;
    cin >> max_y>>max_x;
    start_row--;
    start_col--;

    vector<vector<char>> field(nRows, vector<char>(nCols));
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> field[i][j];

        }
    }
    const int INF = (int) 1e9;
    using vi = vector<tuple<int, int>>;   // тип вектора целых чисел
    using vvi = vector<vi>;   // тип вектора векторов целых чисел
    vvi dist(nRows, vi(nCols, {INF, INF}));
    deque<tuple<int, int, int, int>> q;
    q.push_back({start_row, start_col, 0, 0});
//    vector<vector<char>> me(nRows, vector<char>(nCols, '.'));
    int counter = 0;
    while (!q.empty()) {
        auto[row, col, xs, ys] = q.front();
        q.pop_front();
        if (row < 0 || row >= nRows) continue;
        if (col < 0 || col >= nCols) continue;
        if (field[row][col] == '*') continue;
        if (xs > max_x || ys > max_y) continue;
        auto[x, y] = dist[row][col];
        if (x <= xs && y <= ys) continue;
        if (x == INF && y == INF) {
            counter++;
            dist[row][col] = {xs, ys};
//            cout << row << " " << col << endl;
//            me[row][col] = '+';
        }
        q.push_front({row + 1, col, xs, ys});
        q.push_front({row - 1, col, xs, ys});
        q.push_back({row, col + 1, xs + 1, ys});
        q.push_back({row, col - 1, xs, ys + 1});
    }
    cout << counter<<endl;
//    for (auto i: me) {
//        for (auto j: i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }

    return 0;
}