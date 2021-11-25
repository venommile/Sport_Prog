#include <bits/stdc++.h>

using namespace std;

int main() {
    int soldiers, requests;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> soldiers >> requests;
    vector<vector<int>> adj(1 + soldiers);

    for (int i = 2; i < soldiers+1 ; i++) {
        int v;
        cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    vector<int> tree;
    vector<int> size(soldiers+1);
    vector<int> index(soldiers+1);
    tree.push_back(0);
    function<void(int, int)> dfs =

            [&](int u, int p) {
                // ВХОД в вершину u
                int begin = (int) tree.size();
                tree.push_back(u);
                // ПЕРЕБОР ИСХОДЯЩИХ РЁБЕР
                for (int v: adj[u]) {
                    if (v == p) continue;
                    // переход в дочернюю вершину u
                    dfs(v, u);
                    // возврат из вершины u
                }
                // ВЫХОД из вершины u
                int end = (int) tree.size();
                size[u] = end - begin;
                index[u] = tree.size()-size[u];
            };
    dfs(1,0);


    for (int i = 0; i < requests; ++i) {
        int u,count;
        cin >>u >>count;
        if (size[u]>=count){
            cout <<tree[index[u]+count-1] <<endl;
        }

        else{
            cout << -1 <<endl;
        }



    }


}