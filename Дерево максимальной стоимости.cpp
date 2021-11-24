#include <bits/stdc++.h>

using namespace std;


#include <algorithm>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nV;
    cin >> nV;
    vector<long long> weight(nV + 1, 0);
    for (int i = 1; i < nV + 1; ++i) {
        cin >> weight[i];
    }
    vector<vector<int>> adj(nV + 1);
    for (int i = 1; i < nV; ++i) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<long long> sums(nV + 1, 0);

    function<long long (int, int)> dfs = [&](int u, int p) {
        long long suma = 0; // сумма всех стоимостей в поддереве;
        for (int v: adj[u]) {
            if (v == p) continue;
            suma += dfs(v, u);
        }
        suma += weight[u];
        sums[u] = suma;
        return sums[u];
    };
    sums[1] = dfs(1, 0);

    queue<tuple<int, int>> q;
    vector<bool> visited(nV + 1, false);

    q.push({1, 0});
    long long ans = 0;
    while (!q.empty()) {
        auto[v, dist] = q.front();
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        ans += dist * weight[v];

        for (auto i: adj[v]) {
            q.push({i, dist + 1});
        }
    }

    vector<long long> anses(nV + 1, 0);
    queue<tuple<int, int, int>> q2;
    anses[1] = ans;
    q2.push({1, 1, 0});
    vector<bool> visited2(nV + 1, false);
    while (!q2.empty()) {
        auto[v, parent, dist] = q2.front();
        q2.pop();
        if (visited2[v]) continue;
        visited2[v] = true;
        if (v != 1) {

            anses[v] = anses[parent] + sums[parent] - 2 * sums[v];
            sums[v] = sums[parent];
        }
        for (auto i: adj[v]) {
            q2.push({i, v, dist + 1});
        }
    }

    cout << *max_element(anses.begin(), anses.end());

}
