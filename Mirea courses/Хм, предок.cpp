#include <bits/stdc++.h>

#define isz(x) (int)(x).size()
using namespace std;

int main() {
    // чтение исходного графа:
    ios::sync_with_stdio(false);
    ifstream in("ancestor.in"); // создаем объект класса ifstream
    int n, q;
    in >> n;
    int head = 0;
    vector<vector<int>> next(1 + n);
    for (int i = 1; i <= n; i++) {
        int p;
        in >> p;
        if (p==0){
            head = i;
        }
        next[p].push_back(i);
    }
    // запускаем dfs. Внутри dfs запоминаем порядок обхода dfs, времена входа и выхода в вершины:
    vector<int> dfs_order, tin(1 + n), tout(1 + n);
    function<void(int)> dfs = [&](int u) {
        // при входе в вершину добавляем её в вектор, где будем хранить порядок,
        // и запоминаем начало её поддерева как подотрезка в этом векторе:
        dfs_order.push_back(u);
        tin[u] = isz(dfs_order) - 1;
        // посещаем все поддеревья:
        for (int v: next[u]) dfs(v);
        // теперь все поддеревья посещены, запоминаем конец поддерева вершины u:
        tout[u] = isz(dfs_order) - 1;
    };
    dfs(head);
    in >> q;
    ofstream out("ancestor.out");
    while (q-- > 0) {
        int u, v;
        in >> u >> v;
        if (tin[u] <= tin[v] && tout[u] >= tin[v]) {
            out << 1 << endl;
        } else {
            out << 0 << endl;
        }
    }
}