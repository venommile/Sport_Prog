#include <bits/stdc++.h>

using namespace std;

bool comp1(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first <= b.first;
}

bool comp2(pair<long long, long long> a, pair<long long, long long> b) {
    return a.second <= b.second;
}

int main() {
    long long nV;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> nV;
    vector<vector<long long>> adj(1 + nV);

    for (long long i = 1; i < nV; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> weight(1 + nV, 0);
    for (long long i = 1; i < nV + 1; ++i) {
        cin >> weight[i];

    }
    vector<pair<long long, long long>> moves(nV + 1);
    function<void(long long, long long)> dfs =

            [&](long long u, long long p) {
                vector<pair<long long, long long>> children;
                for (long long v: adj[u]) {
                    if (v == p) continue;
                    dfs(v, u);
                    children.push_back(moves[v]);
                }
                children.emplace_back(0, 0);
                auto[count_rise, _] = *max_element(children.begin(), children.end(), comp1);
                auto[__, count_reduce] = *max_element(children.begin(), children.end(), comp2);
                weight[u] += count_rise - count_reduce;
                if (weight[u] > 0) {
                    moves[u] = {count_rise, count_reduce + weight[u]};
                } else {
                    moves[u] = {count_rise + abs(weight[u]), count_reduce};
                }

            };

    dfs(1, 0);
    cout << moves[1].first + moves[1].second;


    return 0;


}