

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <algorithm>
#include <iterator>

bool comp(double x, double y) {
    x = abs(x);
    y = abs(y);
    return abs(round(x) - x) < abs(round(y) - y);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<double> firs(n);

    for (int i = 0; i < n; i++) {
        cin >> firs[i];
    }

    sort(firs.begin(), firs.end(), comp);
    set<double> a;
    set<double> trees;
    queue<tuple<double, double>> q;
    for (auto i: firs) {
        if (i - round(i) != 0) {
            q.push({round(i), i});
        } else {
            q.push({round(i + 1), i});
            q.push({round(i - 1), i});
        }
        a.insert(i);
        trees.insert(i);
    }
    double dist = 0;
    int counter = 0;
    while (counter < m) {
        auto[x, fir] = q.front();
        q.pop();
        if (a.count(x)==0) {
            a.insert(x);
            counter++;
            dist += abs(x - fir);
            q.push({x + 1, fir});
            q.push({x - 1, fir});
        }

    }
    vector<int> ans;
    cout << (long long)dist<<endl;
    set_difference(a.begin(),a.end(),trees.begin(),trees.end(),back_inserter(ans));
    for (auto i: ans) {
        cout <<(long long) i << " ";
    }



    return 0;
}