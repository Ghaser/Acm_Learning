#include <bits/stdc++.h>
using namespace std;
inline double ct(double x, double pos, double v) {
    //当前处于pos，要覆盖[0,x]，速度v的最短时间
    return (min(pos, x - pos) + x) / v;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        double n, p1, v1, p2, v2;
        scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
        if (p1 > p2) {  // 按左右排序
            swap(p1, p2);
            swap(v1, v2);
        }
        // 情况1 : 一个人走完所有
        double ans = min(ct(n, p1, v1), ct(n, p2, v2));
        // 情况2 : 对穿
        ans = min(ans, max((n - p1) / v1, p2 / v2));
        // 情况3 : 在两者之间找一个点，一人负责一边
        double left = p1, right = p2;
        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2;
            double time_left = ct(mid, p1, v1);
            double time_right = ct(n - mid, p2 - mid, v2);
            ans = min(ans, max(time_left, time_right));
            if (time_left > time_right) {
                right = mid;
            } else {
                left = mid;
            }
        }
        printf("%.10f\n", ans);
    }
    return 0;
}