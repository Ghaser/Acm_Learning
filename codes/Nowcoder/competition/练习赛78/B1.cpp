#include<cstdio>
#include<algorithm>
#define ll long long 

using namespace std;

int n, m, a[2001], sum;
int xx[2001], now;
bool nd[2001];
ll ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &now);
        if (!nd[now]) {
            nd[now] = 1;
            ans += 1ll * sum;//把它放在最下面，那移动的费用就是上面所有球的质量和
            sum += a[now];
            xx[++xx[0]] = now;
            for (int j = xx[0] - 1; j >= 1; j--)//移到最上面
                swap(xx[j], xx[j + 1]);
        }
        else {
            for (int j = xx[0]; j >= 1; j--)
                if (xx[j] == now) {
                    for (int k = j - 1; k >= 1; k--) {//移到最上面
                        ans += 1ll * a[xx[k]];//统计移上去的费用
                        swap(xx[k], xx[k + 1]);
                    }

                    break;
                }
        }
    }

    printf("%lld", ans);

    return 0;
}