#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n, T, a[N], b[N], id[N], ans[N], tot;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n), tot = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), id[a[i]] = i;
        for (int i = n, p; i >= 1; i--) {
            if (!tot || a[i] > b[tot])b[++tot] = a[i], ans[i] = tot;
            else {
                p = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
                ans[i] = ans[id[b[p]]], b[p] = a[i];
            }
        }
        printf("%d\n", tot);
        for (int i = 1; i <= n; i++)
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
