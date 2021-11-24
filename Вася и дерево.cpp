#include <bits/stdc++.h>

#define isz(x) (int)(x).size()
using namespace std;

#include <algorithm>

int main() {
    // чтение исходного графа:
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nV;
    cin >> nV;
    vector<vector<int>> adj(1 + nV);
    for (int i = 0; i < nV - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    queue<tuple<int, int>> q;
    q.push({1, 0});
    vector<int> m_depth(nV + 1, -1);
    while (!q.empty()) {
        auto[v, cost] = q.front();
        q.pop();
        if (m_depth[v] != -1) continue;
        m_depth[v] = cost;
        for (auto u: adj[v]) {
            q.push({u, cost + 1});
        }
    }

    int req;
    cin >> req;
    vector<vector<pair<long long, long long>>> actions(nV + 1);
    for (int i = 0; i < req; ++i) {
        int v;
        long long d, x;
        cin >> v >> d >> x;
        if (d > nV) {
            d = nV;
        }
        actions[v].emplace_back(d, x);

    }
    vector<long long> weight(nV + 1, 0);
    vector<long long> changesByDepth(2 * nV + 2, 0);//  на всякий случай,чтобы не забуллить глубину
    function<void(int, int, long long)> dfs =

            [&](int u, int p, long long sum) {
                for (auto i: actions[u]) {
                    sum += i.second;
                    changesByDepth[i.first + m_depth[u] + 1] -= i.second;
                }

                sum += changesByDepth[m_depth[u]];
                weight[u] = sum;
                for (int v: adj[u]) {
                    if (v == p) continue;
                    dfs(v, u, sum);
                }
                for (auto i: actions[u]) {
                    sum -= i.second;
                    changesByDepth[i.first + m_depth[u] + 1] += i.second;
                }

            };
    dfs(1, 0, 0);
    for (int i = 1; i < weight.size(); ++i) {
        cout << weight[i] << " ";
    }

}