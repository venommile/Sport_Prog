#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    int count;
    cin >> count;
    for (int l = 0; l < count; ++l) {

        int nV, k;
        cin >> nV >> k;
        vector<bool> visited(1 + nV, false);
        vector<set<int>> adj(1 + nV);
        queue<pair<int, int>> q;
        for (int i = 1; i < nV; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);

        }
        for (int i = 1; i < nV + 1; ++i) {
            if (adj[i].size() <= 1) {
                q.push({i, 0});
            }

        }
        int count_Vers = nV;

        while (!q.empty() && count_Vers > 0) {
            auto[vers, cost] = q.front();
            if (cost >= k) {
                break;
            }
            q.pop();
            if (visited[vers]) continue;

            if (adj[vers].size() <= 1) {
                visited[vers] = true;
                for (auto u: adj[vers]) {
                    adj[u].erase(vers);
                    if (adj[u].size() == 1) {
                        q.push({u, cost + 1});
                    }
                    adj[vers].erase(u);
                    break;
                }
                count_Vers--;

            }

        }

        cout << count_Vers << endl;
    }


}