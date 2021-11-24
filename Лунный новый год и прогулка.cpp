#include <bits/stdc++.h>

using namespace std;

template<typename T>
using PriorityQueue = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nVert, nEdges;
    cin >> nVert >> nEdges;


    vector<vector<pair<int, int>>> adj(1 + nVert);
    for (int i = 0; i < nEdges; i++) {
        int u, v, cost;
        cin >> u >> v;
        adj[u].push_back({v, v});
        adj[v].push_back({u, u});
    }
    vector<bool> dist(1 + nVert, false); //посещена ли вершина
    vector<int> ans;
    PriorityQueue<tuple<int, int>> pq; //
    pq.push({1, 1}); // заносим стартовую вершину
    while (!pq.empty()) {
        // Вынимаем первый элемент из очереди:
        auto[currDist, currVert] = pq.top();


        pq.pop();
        // Если уже посещали с лучшим расстоянием, то скипаем:
        if (dist[currVert]) continue;
        dist[currVert] = true;
        // Иначе отмечаем текущее расстояние и вершину, из которой пришли:
        ans.push_back(currDist);
        // Заносим в очередь все смежные вершины:
        for (auto[nextVert, cost]: adj[currVert]) {
            pq.push({cost, nextVert});
        }
    }
    // Выводим ответ:
    for (auto s: ans) {
        cout << s << " ";
    }
    return 0;
}