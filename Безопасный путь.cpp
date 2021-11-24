
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int nRows, nCols, distance;
    cin >> nRows >> nCols >> distance;
    vector<vector<char>> field(nRows, vector<char>(nCols));
    int finish_row = 0, finish_col = 0;
    int start_row = 0, start_col = 0;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> field[i][j];
            if (field[i][j] == 'S') {
                start_row = i;
                start_col = j;
                field[i][j] = '.';

            } else if (field[i][j] == 'F') {
                finish_row = i;
                finish_col = j;
                field[i][j] = '.';
            } else if (field[i][j] == 'M') {
                q.push({i, j, 0});
                field[i][j]='.';
            }

        }

    }
    vector<vector<int>> dist(nRows, vector<int>(nCols, -1));
    while (!q.empty()) {
        auto[row, col, currDist] = q.front();
        q.pop();
        // если вышли за пределы поля, то скипаем:
        if (row < 0 || row >= nRows) continue;
        if (col < 0 || col >= nCols) continue;
        // если расстояние уже меньше текущего, то скипаем:
        if (dist[row][col] != -1) continue;
        // если вообще клетка недоступна для посещения, то скипаем:
        if (field[row][col] == 'M') continue;
        if (currDist > distance) continue;
        dist[row][col] = currDist;
        field[row][col] = '#';
        q.push({row - 1, col, currDist + 1});
        q.push({row + 1, col, currDist + 1});
        q.push({row, col - 1, currDist + 1});
        q.push({row, col + 1, currDist + 1});
    }
//    for (auto i: dist){
//        for (auto j: i){
//            cout<<j;
//        }
//        cout<<"\n";
//    }
    vector<vector<int>> dist2(nRows, vector<int>(nCols, -1));
    q.push({finish_row, finish_col, 0});
    while (!q.empty()) {
        auto[row, col, currDist] = q.front();

        q.pop();

        if (row < 0 || row >= nRows) continue;
        if (col < 0 || col >= nCols) continue;

        if (dist2[row][col] != -1) continue;
        if (field[row][col] == '#') continue;
        dist2[row][col] = currDist;
        q.push({row - 1, col, currDist + 1});
        q.push({row + 1, col, currDist + 1});
        q.push({row, col - 1, currDist + 1});
        q.push({row, col + 1, currDist + 1});
    }

    cout << dist2[start_row][start_col];
    return 0;
}