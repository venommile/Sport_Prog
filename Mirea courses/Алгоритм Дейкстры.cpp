#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <algorithm>
#include <iterator>

template<typename T>
using PriorityQueue = priority_queue<T, vector<T>, greater<T>>;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(1 + n);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});

    }
    vector<int> path(1 + n, 0);
    const int64_t INF = 1e18L;
    vector<int64_t> dist(1 + n, INF);
    PriorityQueue<tuple<int64_t, int, int>> pq;// очередь с приоритетами, тройки (расстояние, текущая вершина, предыдущая вершина)
    pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto[distance, currV, lastV] = pq.top();
        pq.pop();
        if (distance >= dist[currV]) continue;
        path[currV] = lastV;
        dist[currV] = distance;
        for (auto[curr, cost]: adj[currV]) {
            pq.push({distance + cost, curr, currV});
        }
    }
    if (dist[n] == INF) {
        cout << -1;

    } else {
        vector<int> ans;
        int End = n;
        while (End!= 0) {
            ans.push_back(End);
            End = path[End];
        }
        reverse(ans.begin(),ans.end());
        for(auto i: ans){
            cout<<i <<" ";

        }
    }


    return 0;
}