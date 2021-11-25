#include <bits/stdc++.h>

using namespace std;

int main() {
    long long nV;
    cin >> nV;
    long long suma = 0;
    vector<vector<pair<long long, long long>>> adj(1 + nV);
    for (long long i = 0; i < nV - 1; i++) {
        long long u, v, cost;
        cin >> u >> v >> cost;
        suma += cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
    suma *= 2;
    long long ans = 0;

    vector<long long> cost_subtree;
    cost_subtree.push_back(0);

    function<void(long long, long long, long long)> dfs =

            [&](long long u, long long p, long long cost_to) {
                ans += cost_to;


                for (auto[v, weight]: adj[u]) {
                    if (adj[u].size() == 1 && u != 1) {
                        cost_subtree.push_back(ans);
                    }
                    if (v == p) continue;

                    // переход в дочернюю вершину u
                    dfs(v, u, weight);
                    // возврат из вершины u
                }
                // ВЫХОД из вершины u
                ans -= cost_to;

            };

    dfs(1, 0, 0);

    cout << suma - *max_element(cost_subtree.begin(), cost_subtree.end());


}