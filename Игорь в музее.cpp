#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int nRows, nCols;
    int count;
    cin >> nRows >> nCols >> count;
    vector<vector<char>> field(nRows, vector<char>(nCols));
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> field[i][j];
        }
    }
    vector<vector<tuple<int, int>>> components;
    vector<vector<int>> dist(nRows, vector<int>(nCols, -1));
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (field[i][j] == '.') {
                if (dist[i][j] == -1) {
                    q.push({i, j, 0});
                    vector<tuple<int, int>> component;

                    long long counter = 0;

                    while (!q.empty()) {
                        auto[row, col, curr] = q.front();
                        q.pop();
                        if (row < 0 || row >= nRows) continue;
                        if (col < 0 || col >= nCols) continue;
                        // если расстояние уже меньше текущего, то скипаем:
                        if (dist[row][col] > -1) continue;
                        // если вообще клетка недоступна для посещения, то скипаем:
                        if (field[row][col] == '*') {
                            counter++;
                            continue;
                        }
                        // иначе обрабатываем клетку и добавляем соседей:
                        dist[row][col] = curr;
                        component.push_back({row, col});

                        q.push({row - 1, col, 0});
                        q.push({row + 1, col, 0});
                        q.push({row, col - 1, 0});
                        q.push({row, col + 1, 0});

                    }
                    for (auto w: component) {
                        auto[it_row, it_col] = w;
                        dist[it_row][it_col] = counter;
                    }
                    component.clear();
                }
            }
        }

    }
    for (int i = 0; i < count; i++) {
        int a, b;
        cin >> a >> b;
        cout << dist[a - 1][b - 1] << "\n";

    }

    return 0;
}
