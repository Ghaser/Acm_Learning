# DFS

## luogu—P1025 树的划分

注意深度优先搜索的应用

剪枝条件的寻找是本题的突破口

**sum+i\*(k-cur)<=n**

剩下的都是i（最小）的话会超出范围

```c++
#include<cstdio>

int n,k,cnt;

void dfs(int last,int sum,int cur)
{
    if(cur==k)
    {
        if(sum==n) cnt++;
        return;
    }
    for(int i=last;sum+i*(k-cur)<=n;i++)//剪枝，只用枚举到sum+i*(k-cur)<=n为止
        dfs(i,sum+i,cur+1);
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(1,0,0);
    printf("%d",cnt);
}
```

## luogu-P1118 Backward Digit Sums G/S

# Tire Tree

## POJ-2418  Hardwood Species(模板)

```c++
#include <iostream>
#include <cstring>
using namespace std;

int num = 0;
const int nameLen = 31;
const int childNum = 127;//字符最大的ascii码为126
//使用类 大可不必
struct node
{
    char name[nameLen];
    int count;
    bool ok ;
    node *child[childNum];
    node(){//同名构造函数
        count = 0;
        ok = false;
        for (int i = 0; i < childNum; ++i) child[i] = NULL;
    }
};
node root;

void insertNode(char s[nameLen])
{
    node *r = &root;
    int length = strlen(s);
    for (int i = 0; i < length; ++i){
        int intS = s[i];
        if(r->child[intS] == NULL) r->child[intS] = new node();
        r = r->child[intS];
    }
    strcpy(r->name,s);//在尾节点留下名字，便于输出
    r->count++;
    r->ok = true;
}

void outputTree(node *root)
{
    if(root->ok) printf("%s %.4f\n", root->name,root->count*100.0/num);
    for (int i = 0; i < childNum; ++i)
        if(root->child[i] != NULL) outputTree(root->child[i]);
}

int main()
{
    char s[31];
    while(gets(s))  insertNode(s),num++;
    outputTree(&root);
    return 0;
}
```

# Binary Indexed Tree

## luogu—P1908 逆序对

本题有两个关键点

**一，**树状数组如何能够统计逆序对的数目

​		我们先理清sum函数的作用——计算数组a中1到i的和（i为数组的输入）

​		以及add函数的作用——在a数组中实现单点更新

​		我们开创一个全为0的a数组，若一个数等于x，便把其a数组中所占位置加一

​		所以我们计算逆序对只需要用i（当前的输入的元素个数）-sum（x）（比x小的元素的个数）即可

**二**，进行离散化来避免树状数组空间不够的问题

​			

```c++
//  1 2 10000
//  1 2 3
//上面两个序列在本题是等效的，因为无论第三项是3还是10000，它都大于第一项和第二项
```

​		所以我们可以考虑数据离散化，先将数据排列，再用1~n分别对应n个数表示他们的相对大小

​		同时我们也需要考虑数据出现相同的情况

​		由于我们所求为逆序对，需要判断的是比x大的数，故我们可以将值相同的数以编号由小到大排队，标号小的数在离散化时会获得更小的新标号，就不会影响到后面的数了

```c++
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//无法直接使用树状数组
//需要进行离散化
ll c[500005],r[500005],n,ans;
struct point{
    int num,val;
}a[500005];
bool cmp(point x,point y){
    if(x.val==y.val){
        return x.num<y.num;
    }
    return x.val<y.val;
}

ll lowbit(ll x){
    return x&(-x);
}

ll sum(ll i){
    ll s=0;
    while(i>=1){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}


void add(ll i,ll v){
    while(i<=n){
        c[i]+=v;
        i+=lowbit(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;;
        a[i].num=i;
    }
    sort(a+1,a+1+n,cmp);//排序方便进行离散化
    for(int i=1;i<=n;i++){
        r[a[i].num]=i;
    }
    for(int i=1;i<=n;i++){
        add(r[i],1);
        ans+=i-sum(r[i]);
    }
    cout<<ans;


    return 0;
}
```

## luogu—P3368 树状数组二

​	本题为树状数组与差分思想的结合，运用树状数组实现成段更新，单点求和。

​	以数组前后两项的差通过add建树，则所得到的sum（x）则表示原数组第x项的值

​	而通过add（x，v），add（y+1，-v）即可实现所谓成段更新，本质是差分思想的运用

```c++
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500005
ll n,c[maxn],m;
ll lowbit(ll x){return x&(-x);}

void add(ll i,ll v){
    while(i<=n){
        c[i]+=v;
        i+=lowbit(i);
    }
}
ll sum(ll i){
    ll s=0;
    while(i){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

int main(){
    ll temp1,temp2=0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>temp1;
        add(i,temp1-temp2);//建树
        temp2=temp1;
    }
    for(int i=1;i<=m;i++){
        int a,x,y,z;
        cin>>a;
        if(a==1){
            cin>>x>>y>>z;
            add(x,z);
            add(y+1,-z);
        }else if(a==2){
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }


    return 0;
}
```

## luogu-P1966 火柴排序

​	本题的关键在于新建序列使得q[a[i]]=b[i],相对于以a[i]为关键字对序列b[i]进行排序

```c++
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn 100005
#define mod 99999997
//联想到逆序对
//相对逆序对？
//新建序列即可实现相对逆序对
struct point{
    ll num,val;
}a[maxn],b[maxn];
ll n,ans=0;
ll a1[maxn],b1[maxn],p[maxn],c[maxn];
bool cmp(point x,point y){
    return x.val<y.val;
}
ll lowbit(ll x){
    return x&(-x);
}


void add(ll i,ll v){
    while(i<=n){
        c[i]+=v;
        c[i]%=mod;
        i+=lowbit(i);
    }
}
ll sum(ll i){
    ll s=0;
    while(i){
        s+=c[i];
        s%=mod;
        i-=lowbit(i);
    }
    return s;
}

int main(){
    //--------读入数据--------
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].num=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].val;
        b[i].num=i;
    }
    //-------离散相对化-------
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+1+n,cmp);//排序方便进行离散化
    /*for(int i=1;i<=n;i++){
        a1[a[i].num]=i;
        b1[b[i].num]=i;
    }*/
    for(int i=1;i<=n;i++){
        p[a[i].num]=b[i].num;
    }
    //------树状数组求解----
    for(int i=1;i<=n;i++){
        add(p[i],1);
        ans+=i-sum(p[i]);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
```

# GCD

## Nowcoder训练赛79 B 刀工对决

```c++
//思维题
//注意函数__gcd直接求解最小公倍数
//找到a，b的最小公因数
//然后除上这个数，再将a，b都化为非5，3的倍数即可
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r1,r2,gcd,ans=0;;
    cin>>n;
    while(n--){
        r1=0;
        r2=0;
        int a,b;
        cin>>a>>b;
        gcd=__gcd(a,b);
        a/=gcd;
        b/=gcd;
        while(a%5==0){
            r1++;
            a/=5;
            a*=3;
        }
        while(b%5==0){
            r1--;
            b/=5;
            b*=3;
        }
        r1=abs(r1);
        while(a%3==0){
            r2++;
            a/=3;
        }
        while(b%3==0){
            r2--;
            b/=3;
        }
        r2=abs(r2);
        if(a!=b){
            cout<<-1<<endl;
            return 0;
        }
        ans+=r1+r2;
    }
    cout<<ans<<endl;
    return 0;
}
```



# 贪心

## NowCoder  奇♂妙拆分

**题意**：一个自然数最多可以分解成多少个不同的因子。

**分析**

​	n最大为10^9，所以要考虑复杂度低于O(n)的算法

​	参考求数字质因数个数的方法：

```c++
int res = 0;
for (int i = 2; i * i <= A; i++) {
    while (A % i == 0) {
        A /= i;
        res++;
    }
}
//可能存在有且仅有一个大于根号A的质因数
if (A > 1) res++;
```

**注 意：n是动态的，不断在分解因子的过程中变化**

1.因为n(1除外)一定存在一个小于![img](https://www.nowcoder.com/equation?tex=%5Csqrt%7Bn%7D&preview=true)的因子，所以枚举到因子枚举到![img](https://www.nowcoder.com/equation?tex=%5Csqrt%7Bn%7D&preview=true)就可以了。
2.每找到一个因子就从n分离出来：![img](https://www.nowcoder.com/equation?tex=n%2F%3Di%3B&preview=true)
3.当![img](https://www.nowcoder.com/equation?tex=i*i%3D%3Dn&preview=true)时，有两个一样的未出现的因子，那么只能把这两个因子合并为![img](https://www.nowcoder.com/equation?tex=i*i&preview=true)算作一个因子。
4.当![img](https://www.nowcoder.com/equation?tex=i*i%3En&preview=true)时，（假设x是上一个分解的因子）表示没有比x还大的因子对了，就是比如![img](https://www.nowcoder.com/equation?tex=n%3Da%20*%20b%2Ca%3C%3Db&preview=true)，需要a和b都大于x，不然分解出b后分解a时一定会重，因为a小于分解出来的一些因子，说明a的因子包括a，前面已经出现过了。
5.所以如果![img](https://www.nowcoder.com/equation?tex=i*i%3E%3Dn&preview=true)，把他算作一个因子，不能再分解了。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll T, a;
    cin >> T;
    while (T--) {
        cin >> a;
        ll cnt = 1;//唯一的大于根号a的数
        for (ll i = 1; i*i < a; ++i)
            if (a % i == 0) a /= i, ++cnt;
        cout << cnt << endl;
    }
    return 0;
}
```

# 模拟

## ICPC2020shanghai -G- Gitignore

给定n个需要删除的目录，m个需要保护的目录，求删除最小次数

使用map(或set)和vector进行模拟

```c++
#include <bits/stdc++.h>
using namespace std;
int t, n, m;
vector<string> v1, v2;
map<string, bool> prt, vis;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        string s;
        v1.clear(), v2.clear(), vis.clear(), prt.clear();
        for (int i = 0; i < n; i++) cin >> s, v1.push_back(s);
        for (int i = 0; i < m; i++) cin >> s, v2.push_back(s);
        for (int i = 0; i < m; i++) {
            string s = "";
            for (char &c : v2[i]) {
                if (c == '/') prt[s] = 1;
                s += c;
            }
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (char &c : v1[i]) {
                if (c == '/') {
                    if (!prt[s]) {
                        if (vis[s]) --ans;
                        else vis[s] = 1;
                        break;
                    }
                }
                s += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```

