
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int nRows, nCols;
    cin >> nRows >> nCols;
    vector<vector<char>> field(nRows, vector<char>(nCols));
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> field[i][j];
        }
    }
    vector<vector<tuple<int, int>>> components;
    vector<vector<int>> dist(nRows, vector<int>(nCols, -1));

    queue<tuple<int, int >> q;
    int k = 0;


    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (field[i][j] == '.') {
                queue<tuple<int, int>> q;
                q.push({i, j});
                vector<tuple<int,int>> component;
                while (!q.empty()) {
                    auto[row, col] = q.front();
                    q.pop();
                    if (row < 0 || row >= nRows) continue;
                    if (col < 0 || col >= nCols) continue;
                    if (dist[row][col] >-1) continue;
                    if (field[row][col] == '*') continue;
                    dist[row][col] = k;
                    component.push_back({row, col});
                    q.push({row - 1, col});
                    q.push({row + 1, col});
                    q.push({row, col - 1});
                    q.push({row, col + 1});

                }
                components.push_back(component);
                component.clear();
                k++;


            }

        }
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (field[i][j] == '.') {
                cout << '.';
            } else {
                set<int> neighbours;
                if (i - 1 >= 0) {
                    if (dist[i - 1][j] != -1) neighbours.insert(dist[i - 1][j]);
                }
                if (i + 1 < nRows) {
                    if (dist[i + 1][j] != -1) neighbours.insert(dist[i + 1][j]);
                }
                if (j - 1 >= 0) {
                    if (dist[i][j - 1] != -1) neighbours.insert(dist[i][j - 1]);
                }
                if (j + 1 < nCols) {
                    if (dist[i][j + 1] != -1) neighbours.insert(dist[i][j + 1]);
                }
                int answer = 1;

                for (int l: neighbours) {
                    answer+=components[l].size()%10;
                }
                cout<<answer%10;

            }

        }
        cout << "\n";
    }

    return 0;
}