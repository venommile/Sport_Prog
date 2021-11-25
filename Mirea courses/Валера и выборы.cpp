#include <bits/stdc++.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int nV;
    cin >> nV;
    vector<vector<pair<int, int>>> adj(1 + nV);
    for (int i = 0; i < nV - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    vector<int> broken_roads;
    function<bool(int, int, bool)> dfs =

            [&](int u, int p, bool isBroken) {
                // ВХОД в вершину u
                bool flag = false;// чинили ли мы вершину в поддереве

                for (auto[v, weight]: adj[u]) {
                    if (adj[u].size() == 1 && weight == 2 && u != 1) {
                        broken_roads.push_back(u);
                        return true;
                    }
                    if (v == p) continue;
                    flag = flag | dfs(v, u, weight == 2);
                }
                if (!flag && isBroken) {
                    broken_roads.push_back(u);
                    return true;
                }
                return flag;


            };

    dfs(1, 0, false);
    cout << broken_roads.size() << endl;
    for (auto city: broken_roads) {
        cout << city << " ";
    }

}