#include<bits/stdc++.h>
using namespace std;
//纯粹的模拟题？
//暴力计算，算出每一种情况，再进行比较
//计算耗时相对较小
inline double ct(double x, double pos, double v) {
    //当前处于pos，要覆盖[0,x]，速度v的最短时间
    return (min(pos, x - pos) + x) / v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        double n,p1,v1,p2,v2,s1,s2,s3;
        double ans1,ans2=1e9,ans3,ans0;
        cin>>n>>p1>>v1>>p2>>v2;
        if(p1>p2){
            swap(p1,p2);
            swap(v1,v2);
        }
        s1=p1;
        s2=p2-p1;
        s3=n-p2;
        //情况一：一个人走完所有
        ans1=min((s1+n)/v1,(s3+n)/v2);
        ans1=min(ans1,(n+s2+s3)/v1);
        ans1=min(ans1,(s1+s2+n)/v2);
        //注意p1可以到右边点的距离更短
        //全面考虑四种不同情况

        //情况二：各自折返，再一起向中间走（x）
        //忽略向中间走再折返的情况
        //情况二：约定一个中间点，一起向中间
        //使用二分答案(两人走的时间最为接近)计算出这一个中间点
        /*
        double l=p1,r=p2;
        for(int i=0;i<=100;i++){//i的上限实在不会写。。
            double mid=(l+r)/2;
            double tl=(min(p1,mid-p1)+mid)/v1;
            double tr=(min(s3,n-mid-s3)+n-mid)/v2;
            ans2=min(ans2,min(tl,tr));
            if(tl>tr){
                tr=mid;
            }else{
                tl=mid+1;
            }
            if(l>=r)break;
        }
        */
       //  注意两个人在中间点相遇应该使用二分答案寻找中间点
       //其中 二分的次数是一个瑕疵
        double left = p1, right = p2;
        for (int i = 0; i < 100; i++) {
            double mid = (left + right) / 2;
            double time_left = ct(mid, p1, v1);
            double time_right = ct(n - mid, p2 - mid, v2);
            ans2 = min(ans2, max(time_left, time_right));
            if (time_left > time_right) {
                right = mid;
            } else {
                left = mid;
            }
        }
        //情况三:两人直接向前冲
        ans3=max((s2+s3)/v1,(s1+s2)/v2);
        
        
        //合并求最小
        ans0=min(ans1,ans2);
        ans0=min(ans0,ans3);
        printf("%.10f\n",ans0);
    }


    return 0;
}