#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k;
ll x;
ll tmp;
int op;
priority_queue<int, vector<int>, less<int> > q;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (q.size() == k && q.top() > x) {
            q.pop();
            q.push(x);
        }
        else if (q.size() < k) {
            q.push(x);
        }
    }
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> tmp;
            if (q.size() == k && q.top() > x) {
                q.pop();
                q.push(x);
            }
            else if (q.size() < k) {
                q.push(x);
            }           
        }
        else {
            if (q.size() < k) {
                cout << "-1" << "\n";
            }
            else {
                cout << q.top() << "\n";
            }
        }
    }
    return 0;
}