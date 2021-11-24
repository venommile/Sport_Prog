#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r1, r2;
    cin >> n >> r1 >> r2;

    vector<int> cities(n + 1, 0);
    vector<int> cities2(n + 1, 0);
    cities[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (i != r1) {
            cin >> cities[i];
            cities2[i] = cities[i];
        }
    }

    int last = r2;
    int curr_vers = cities[last];
    while (last != r1) {
        cities2[curr_vers] = last;
        last = curr_vers;
        curr_vers = cities[curr_vers];

    }
    for (int i = 1; i < n + 1; ++i) {
        if (i != r2) {
            cout << cities2[i] << " ";
        }

    }

}