#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nRows, nCols, k;

    cin >> nRows >> nCols >> k;
    vector<set<int> > field_rows(nRows);
    vector<set<int>> field_cols(nCols);
    const int INF = (int) 10e8;

    vector<vector<char>> field(nRows, (vector<char>(nCols)));
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            cin >> field[row][col];
            field_cols[col].insert(row);

            field_rows[row].insert(col);
        }
        field_rows[row].insert(-1);
        field_rows[row].insert(INF);

    }

    for (int col = 0; col < nCols; col++) {
        field_cols[col].insert(-1);
        field_cols[col].insert(INF);

    }
    int startRow, startCol;
    int finishRow, finishCol;


    vector<vector<int>> dist(nRows, vector(nCols, INF));

    cin >> startRow >> startCol >> finishRow >> finishCol;
    startRow--;
    startCol--;

    queue<tuple<int, int, int>> q; // distance, row, col;
    q.push({startRow, startCol, 0});

    while (!q.empty()) {

        auto[row, col, distance] = q.front();


        q.pop();
        if (row < 0 || row >= nRows) continue;
        if (col < 0 || col >= nCols) continue;
        if (dist[row][col] <= distance) continue;
        if (field[row][col] == '#') continue;
        dist[row][col] = distance;

        auto col1 = field_rows[row].lower_bound(col);
        col1--;
        auto col2 = field_rows[row].lower_bound(col - k);
        col2--;


        while (col1 != col2) {
            if (*col1 < 0 || *col1 >= nCols) break;
            if (field[row][*col1] == '#') break;
            q.push({row, *col1, distance + 1});
            auto thrdleg = col1;
            col1--;
            field_rows[row].erase(*thrdleg);
            field_cols[*thrdleg].erase(row);

        }


        col1 = field_rows[row].lower_bound(col);

        col2 = field_rows[row].lower_bound(col + k + 1);
        while (col1 != col2) {
            if (*col1 < 0 || *col1 >= nCols) break;
            if (field[row][*col1] == '#') break;
            auto thrdleg = col1;
            q.push({row, *col1, distance + 1});
            col1++;
            field_rows[row].erase(*thrdleg);
            field_cols[*thrdleg].erase(row);
        }

        auto row1 = field_cols[col].lower_bound(row);
        --row1;
        auto row2 = field_cols[col].lower_bound(row-k);
        row2--;
        while (row1!=row2){
            if (*row1 < 0 || *row1 >= nRows) break;
            if (field[*row1][col] == '#') break;
            auto thrdleg = row1;
            q.push({*row1,col, distance+1});
            row1--;
            field_rows[*thrdleg].erase(col);
            field_cols[col].erase(*thrdleg);


        }
        row1 = field_cols[col].lower_bound(row);
        row2 = field_cols[col].lower_bound(row+k+1);
        while (row1!=row2){
            if (*row1 < 0 || *row1 >= nRows) break;
            if (field[*row1][col] == '#') break;
            auto thrdleg = row1;
            q.push({*row1,col, distance+1});
            row1++;
            field_rows[*thrdleg].erase(col);
            field_cols[col].erase(*thrdleg);


        }
//
//        auto row1 = field_cols[col].lower_bound(row-1);
//        auto row2 = field_cols[col].lower_bound(row-k-1);
//        while (row1 != row2) {
//            if (*row1 < 0 || *row1 >= nRows) break;
//            if (field[row][*row1] == '#') break;
//            q.push({row, *row1, distance + 1});
//            auto thrdleg = row1;
//            row1--;
//            field_rows[row].erase(*thrdleg);
//            field_cols[*thrdleg].erase(row);
//
//        }
//        row1 = field_cols[col].lower_bound(row+1);
//        row2 = field_cols[col].lower_bound(row+k+1);
//        while (row1 != row2) {
//            if (*row1 < 0 || *row1 >= nRows) break;
//            if (field[row][*row1] == '#') break;
//            q.push({row, *row1, distance + 1});
//            auto thrdleg = row1;
//            row1++;
//            field_rows[row].erase(*thrdleg);
//            field_cols[*thrdleg].erase(row);
//
//        }

    }

    if (dist[finishRow - 1][finishCol - 1] == INF) {
        cout << -1;
    } else {
        cout << dist[finishRow - 1][finishCol - 1];
    }
    return 0;
}