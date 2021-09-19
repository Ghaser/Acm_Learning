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

​		我们开创一个全为0的a数组，若一个数等于x，便把其a数组中所占位置加一，即a[x]+=1；

​		显然sum(x)是为对数组中1-x的元素进行求和，而我们需要求的逆序数是为在当前输入下大于x的元素

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

## luogu-P3605 Promotion Counting P

​	本题类似于P1908逆序对，不过由线性关系变为了本题中的树上关系。

​	本题中使用的离散化算法相对于P1908中使用的离散化算法较为简便。

​	我们在本题中使用ans[ ]表示各个节点的最终答案，显然有
$$
ans[x]=x的下属中比x强的=树状数组考虑下属后强于x的-原来比x强的
$$


```c++
#include<bits/stdc++.h>
using namespace std;
// 有一点求逆序对的味道？
// 采用树状数组 依次加入树状数组会出现与自己上司的同事比较的情况
// 如何改变？

int n;
int p[100005],b[100005],ans[100005],c[100005];
vector<int> Edge[100005]; // 常见的两种存图方式：vector以及链式前向星

int lowbit(int x){
    return x&(-x);
}

int sum(int i){
    int s=0;
    while(i>=1){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

void add(int i,int v){
    while(i<=n){
        c[i]+=v;
        i+=lowbit(i);
    }
}


void dfs(int x){
    ans[x]=-(sum(n)-sum(p[x]));// 减去原来就强于x的，避免后续加上
    						// 此处包含同事的下属，同事等内容
    for(auto i:Edge[x]){ //遍历vectorEdge[x]中的所有元素
        				// 即访问其所有的子节点
        dfs(Edge[x][i]);
    }
    ans[x]+=sum(n)-sum(p[x]);
    add(p[x],1);
}


int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>p[i];
        b[i]=p[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        p[i]=lower_bound(b+1,b+n+1,p[i])-b;
        // 离散化方法之一,得到离散化数组p
    }
    for(int i=2;i<=n;i++){
        int fa;
        cin>>fa;
        Edge[fa].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }


    return 0;
}
```

## luogu-P1972 HH的项链

我们考察实例:

1 2 1 3

对于第一个1，insert(1,1)；表示第一个位置出现了一个不一样的数字，此时树状数组所表示的每个位置上的数字（不是它本身的值而是它对应的每个位置上的数字）是：1 0 0 0

对于第二个2，insert(2,1)；此时树状数组表示的每个数字是1 1 0 0

对于第三个1，因为之前出现过1了，因此首先把那个1所在的位置删掉insert(1,-1),然后在把它加进来insert(3,1)。此时每个数字是0 1 1 0

如果此时有一个询问[2,3]，那么直接求sum(3)-sum(2-1)=2就是答案。

所以显然我们依据询问的右区间来维护树状数组, 每次树状数组仅维护到询问右区间, 当且仅当右区间变大我们才做进一步维护

值得注意, 我们需要记录上一个该数字出现的位置同时记录其是否出现过.

```c++
#include<bits/stdc++.h>
using namespace std;

int n,q;
int a[1000005],c[1000005],ans[1000005];
struct query{
    int l,r,ith;
}ask[1000005];
struct poi{
    int vis,last;
}jud[1000005];
// 求给定查询区间中贝壳的种类数
// 对于每一次查询,如果右边出现x,则左边的x就没有作用
// 把询问按照r进行排序,r每进一步,则树状数组的维护更进一步
bool cmp(query x,query y){
    return x.r<y.r;
}


int lowbit(int x){
    return x&(-x);
}

int sum(int i){
    int s=0;
    while(i>=1){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

void add(int i,int v){
    while(i<=n){
        c[i]+=v;
        i+=lowbit(i);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>ask[i].l>>ask[i].r;
        ask[i].ith=i;
    }   
    sort(ask+1,ask+q+1,cmp);
    int cnt=1;
    for(int i=1;i<=q;i++){
        while(cnt<=ask[i].r){
            if(jud[a[cnt]].vis==1){
                add(jud[a[cnt]].last,-1);
                jud[a[cnt]].last=cnt;
                add(cnt,1);
            }else if(jud[a[cnt]].vis==0){
                jud[a[cnt]].last=cnt;
                jud[a[cnt]].vis=1;
                add(cnt,1);
            }
            cnt++;
        }
        if(cnt==ask[i].r+1){
            ans[ask[i].ith]=sum(ask[i].r)-sum(ask[i].l-1);
        }
        
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }

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

# 分治

## luogu P1429 平面最近点对 

- 分治算法经典题
- 运用递归的思想，我们可以不断将当前区间划分成两个分开计算
- 考虑区间[l,r] 我们将其分为[l,mid]与[mid+1,r]，记录两个区间中分别的最短距离
- 然后我们再考虑两个节点分别来自两个区间的情况
- 而这两个节点之间距离要满足小于ans，则显然其之间x距离必定小于ans
- 但此处我们可以找距离mid距离小于ans的点(减小代码复杂度)
- 将这些点存储后进行计算即可

```c++
#include<bits/stdc++.h>
using namespace std;

// 给定n个点，找出一对点的距离在所有的点对中最小
// 分治算法经典题目

struct node{
    double x,y;
}a[200005],p[200005];

int n;
double dis(node x,node y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

bool cmpx(node x,node y){
    return x.x<y.x;
}

bool cmpy(node x,node y){
    return x.y<y.y;
}

double merge(int l,int r){
    if(r==l)return 123456789;
    if(r==l+1){
        return dis(a[l],a[r]);
    }
    int mid=(l+r)>>1;
    double ans=min(merge(l,mid),merge(mid+1,r));

    int cnt=0;
    for(int i=l;i<=r;i++){
        if(a[i].x>=a[mid].x-ans&&a[i].x<=a[mid].x+ans){
            p[++cnt]=a[i];
        }
    }
    sort(p+1,p+cnt+1,cmpy);
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            double len=dis(p[i],p[j]);
            if(len>ans)break;
            ans=min(ans,len);
        }
    }
    return ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1,cmpx);
    printf("%.4lf",merge(1,n));


    return 0;
}
```

# DP

## 树形DP

#### luogu-P3047 [USACO12FEB]Nearby Cows G

- 给定一颗n个点的数，其点带权，对于每个节点求出距离它不超过k的所有节点权值和m_i

- 采用换根法进行求解

- **第一次dfs**：我们先从根节点开始向下进行dfs，对于每一个节点在dfs过程中记录其父亲，我们记录节点周围点权和时不考虑

- **第二次dfs**：函数开始计算每一个节点的ans(范围内点权和)，对于第一个节点，其没有父亲节点，该计算必然正确。而我们随后遍历当前节点的子节点，接下来我们要计算子节点的范围内点权和，但我们前面在dfs中并没有考虑来自父亲部分（即当前节点）的点权和，由于这里我们需要结合存储父亲节点的f[x] [i]函数进行考虑。但是其父亲节点（当前节点）的范围内点权和无疑有部分来自接下来计算的子节点，我们需要先减去来自自身的部分，再对自己（儿子节点）的f[x] [i]进行更新。并且再访问完子节点后，还需要进行回溯，防止其余兄弟节点的计算出错。

- 两次dfs后，我们得到的ans自然便是正确答案。

  ```c++
  #include<bits/stdc++.h>
  using namespace std;
  #define maxn 100005
  struct edge{
      int to,nxt;
  }e[maxn<<1];
  int head[maxn];
  int n,k;
  int c[maxn];  //表示每个点的权值
  int f[maxn][25];  // 表示距离点i为j的点权和
  int ans[maxn];
  int cnt=0;
  void addedge(int x,int y){
      e[++cnt].to=y;
      e[cnt].nxt=head[x];
      head[x]=cnt;
  }
  
  //在now的贡献中减去pre的贡献
  void cut(int now,int pre){
      for(int i=1;i<=k;i++){
          f[now][i]-=f[pre][i-1];
      }
  }
  
  //把pre的贡献加到now上
  void link(int now,int pre){
      for(int i=1;i<=k;i++){
          f[now][i]+=f[pre][i-1];
      }
  }
  
  void dfs1(int x,int fa){
      f[x][0]=c[x]; // 自己的权值计入距离为0的权值
      for(int i=head[x];i;i=e[i].nxt){
          int y=e[i].to;
          if(y==fa) continue; // 预处理时我们只考虑其孩子节点
          dfs1(y,x);
          for(int j=1;j<=k;j++){
              f[x][j]+=f[y][j-1]; // 父亲节点距离j等于其儿子节点距离j-1
          }
      }
  }
  
  void dfs2(int x,int fa){
      for(int i=0;i<=k;i++){
          ans[x]+=f[x][i]; 
      }
      for(int i=head[x];i;i=e[i].nxt){
          int y=e[i].to;
          if(y==fa) continue;
          // 现在要以y作为根节点，需要把原本没统计的部分(父亲的部分)计入
          // 而父亲的部分显然需要先减去父亲中来自自身的部分
          // 是所谓换根法
          cut(x,y);
          link(y,x);
  
          dfs2(y,x);
  
          cut(y,x);
          link(x,y);
      }
  }
  
  
  int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin>>n>>k;
  
      for(int i=1;i<n;i++){
          int u,v;
          cin>>u>>v;
          addedge(u,v);
          addedge(v,u);
      }
      for(int i=1;i<=n;i++){
          cin>>c[i];
      }
      dfs1(1,0);
      dfs2(1,0);
      for(int i=1;i<=n;i++){
          cout<<ans[i]<<endl;
      }
      return 0;
  }
  
  
  ```


### luogu-P2585 三色二叉树

- 首先我们考虑如何进行所给二叉树的存储，题目中所给为一“二叉树序列”，是使用递归定义的，所以我们在建树时考虑递归

- 由于是二叉树，我们大可不必使用邻接表，直接用二维数组tr来记录每一个节点的左右儿子节点编号

  ```c++
  int build(){
      // 注意build中不可以直接使用cnt作为变量
      // cnt作为全局变量，在递归的时候会改变其值
      // 进而导致建树无法成功
      cnt++;
      int now=cnt;
      if(s[now]=='1'){ //只有一个节点默认为左节点
          tr[now][0]=build();
      }else if(s[now]=='2'){
          tr[now][0]=build();
          tr[now][1]=build();
      }
      return now;
  }
  ```

- 在完成建树之后，我们需要考虑的便是如何进行树形dp

- 我们先考虑状态，所给状态的值的含义我们很自然的联想到子树中绿色节点的数目，而借此我们很轻松的能够得到状态**dp[x] [1/0]**，其第一维代表当前节点，而第二维以1/0来表明当前节点是否为绿色，方便实现dp

- 在得出状态后，我们很自然的能写出对应的dfs函数

  ```c++
  void dfs(int x){  // 本题关键部分，树形dp进行求解
      int lson=tr[x][0],rson=tr[x][1];
      if(!lson&&!rson){ // 叶子节点
          dp1[x][0]=dp2[x][0]=0;  // 没有子树叶子节点非绿自然无绿
          dp1[x][1]=dp2[x][1]=1;  // 叶子节点绿色显然为1
          return;
      }
      if(lson)dfs(lson);
      if(rson)dfs(rson); // 优先往下遍历，根据底层的绿色节点数才能推出上层的绿色节点数目
      dp1[x][0]=max(dp1[lson][0]+dp1[rson][1],dp1[lson][1]+dp1[rson][0]);
      dp1[x][1]=1+dp1[lson][0]+dp1[rson][0];  //父亲绿色，儿子必然可能绿色
      dp2[x][0]=min(dp2[lson][1]+dp2[rson][0],dp2[lson][0]+dp2[rson][1]);
      dp2[x][1]=1+dp2[lson][0]+dp2[rson][0];
  }
  ```

  

- 本题中父亲节点与儿子节点间的递推关系较为简单

- 下给出完成代码

  ```c++
  #include<bits/stdc++.h>
  using namespace std;
  #define maxn 500005
  // 对于一个子节点，其与儿子节点颜色不同，也与父亲节点颜色不同
  // 求染成绿色节点的最大个数和最小个数
  // 树形dp  dfs
  // 使用什么来描述状态？ 
  // 定义数组dp[x][1/0] 表示在x选择绿色(1)或不选绿色(0)的情况下子树中绿色节点的最大个数
  // 如何实现dfs? 
  // 给定的二叉树序列如何进行处理？
  // 怎么建树并进行存储
  // 根据题目中所给条件，采用dfs进行建树
  
  int tr[maxn][2]; // 第二维0表示左儿子，1表示右儿子
  int dp1[maxn][2],dp2[maxn][2];
  string s;
  int cnt=0;
  int build(){
      // 注意build中不可以直接使用cnt作为变量
      // cnt作为全局变量，在递归的时候会改变其值
      // 进而导致建树无法成功
      cnt++;
      int now=cnt;
      if(s[now]=='1'){ //只有一个节点默认为左节点
          tr[now][0]=build();
      }else if(s[now]=='2'){
          tr[now][0]=build();
          tr[now][1]=build();
      }
      return now;
  }
  
  void dfs(int x){  // 本题关键部分，树形dp进行求解
      int lson=tr[x][0],rson=tr[x][1];
      if(!lson&&!rson){ // 叶子节点
          dp1[x][0]=dp2[x][0]=0;  // 没有子树叶子节点非绿自然无绿
          dp1[x][1]=dp2[x][1]=1;  // 叶子节点绿色显然为1
          return;
      }
      if(lson)dfs(lson);
      if(rson)dfs(rson); // 优先往下遍历，根据底层的绿色节点数才能推出上层的绿色节点数目
      dp1[x][0]=max(dp1[lson][0]+dp1[rson][1],dp1[lson][1]+dp1[rson][0]);
      dp1[x][1]=1+dp1[lson][0]+dp1[rson][0];  //父亲绿色，儿子必然可能绿色
      dp2[x][0]=min(dp2[lson][1]+dp2[rson][0],dp2[lson][0]+dp2[rson][1]);
      dp2[x][1]=1+dp2[lson][0]+dp2[rson][0];
  }
  
  int main(){
      cin>>s;
      s='0'+s; // 使得s能从1开始访问
      build();
      //cout<<tr[2][0]<<endl;
      dfs(1);
      cout<<max(dp1[1][0],dp1[1][1])<<' '<<min(dp2[1][0],dp2[1][1])<<endl;
  
      return 0;
  }
  ```


### luogu-P2014 选课

- **题目描述：**要求选择的M门课程获得的学分最大，部分课程的学习前提需要有其他课程的学习。
- 我们考虑如如何进行树形dp，首先我们需要先进行状态的确定。首先，状态的值显然是子树中所能获得的最大学分，因而我们状态中显然有一维是当前节点（正常树形dp都具备这一维）
- 而选课的总数有上限，显然选课数目也是状态中的一维

### luogu-P3177 树上染色

- **题目描述：**给定一颗有n个节点且边带权的树，要求将树中k个顶点染成黑色，其余点为白色，定义收益为黑点两两间的距离和加上白点两两间的距离和，问收益的最大值为多少

- 采用邻接表来存储树

- 很容易推导出本题中dp的状态
  $$
  dp[x][j]
  $$

- 表示根为x的子树有k个节点染成黑色时的最大收益

- 而我们可以推出状态转移方程：
  $$
  dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k]+val)
  $$

- 其中val为连接x,v的边的权值

- 我们可以得到val的计算公式
  $$
  val=[k*(m-k)+(size[v]-k)*(n-m-size[v]-k)]*e[i].w
  $$

- 即（左边黑色顶点 * 右边黑色顶点+左边白色顶点+右边白色顶点）* 权值

- 之后的dfs类似树形背包问题，第一层转移需要倒叙转移，保证不会重复转移（类似01背包压掉一维后的倒叙转移）

  ```c++
  #include<bits/stdc++.h>
  using namespace std;
  #define maxn 2005
  #define ll long long
  // n个节点的树
  // 选择k个节点染成黑色，其余顶点为白色
  // 收益值定义为两两黑点之间的距离和加上两两白点之间的距离和
  // 求收益的最大值
  // 本题优点类似于选课
  // 状态：dp[x][j]  以x为根的子树中有j个节点染成黑色的最大收益
  // 状态转移方程：dp[x][j]=max(dp[x][j],dp[x][j-k]+f[v][k]+val)
  // 其中val为当前连接x，v的边所带来的收益
  // 对于一条边，其价值等于（左边黑色顶点*右边黑色顶点+左边白色顶点+右边白色顶点）*权值
  
  struct edge{
      int u,v,w,nxt;
  }e[maxn<<2];
  int cnt=0;
  int head[maxn<<2];
  void addedge(int u,int v,int w){
      e[++cnt].u=u;
      e[cnt].v=v;
      e[cnt].w=w;
      e[cnt].nxt=head[u];
      head[u]=cnt;
  }
  
  ll dp[maxn][maxn];
  int n,m;
  int size[maxn<<2];// 记录每颗子树的大小
  
  void dfs(int x,int fa){
      size[x]=1;
      dp[x][0]=dp[x][1]=0;
      for(int i=head[x];i;i=e[i].nxt){
          int v=e[i].v;
          if(v==fa)continue;
          dfs(v,x);
          size[x]+=size[v]; //先通过dfs当前子树大小进行更新
                          // 使其能够用于后续计算
          for(int j=min(m,size[x]);j>=0;j--){  //注意此处j需要倒叙枚举
              if(dp[x][j]!=-1){
                  dp[x][j]+=(ll)dp[v][0]+size[v]*(n-m-size[v])*e[i].w;
              }
              for(int k=min(j,size[v]);k>0;k--){
                  if(dp[x][j-k]==-1)continue;
                  ll val=((ll)k*(m-k)+(size[v]-k)*(n-m-size[v]+k))*e[i].w;
                  dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k]+val);
              }
          }
      }
  }
  
  int main(){
      memset(dp,-1,sizeof dp);
      cin>>n>>m;
      m=min(m,n-m);
      for(int i=1;i<n;i++){
          int u,v,w;
          cin>>u>>v>>w;
          addedge(u,v,w);
          addedge(v,u,w); //需要双向建图？
      } 
      dfs(1,0);
      cout<<dp[1][m]<<endl;
  
      return 0;
  }
  ```

  ### 

### luogu-P1272 重建道路

- **题目描述：**给定一颗有N个顶点的树，求使之变为恰有P个顶点的子树需要删去的最少边数

- 树形背包DP经典题目

- 状态定义：dp[x] [j] 以x为根的子树，保留j个节点需要去除的最少边数

- 状态转移方程：
  $$
  dp[x][j]=min(dp[x][j],dp[x][j-k]+dp[v][k]-2)
  $$

- 我们在初始化过程中将dp[x] [1]初始化为deg[x]（x的度），等于是删除了所有与x节点相连的边，此时我们在状态转移过程中，我们需要恢复这一条边的连接，而这条边对顶点x和顶点v的度数均有贡献，在dp[x]与dp[v]中均占有1，故我们此处应该减2

- 最后值得注意的便是最后得到的子树不一定与原树同根，因而我们需要双向建边。

  ```c++
  #include<bits/stdc++.h>
  using namespace std;
  #define maxn 155
  // 给定一颗有N个节点的树
  // 去掉尽可能少的边，使得原树恰好仅剩P个顶点
  // 树形背包dp
  // 状态 dp[x][j] 以x为根的子树，保留j个节点去除的最少边数
  // 状态转移方程
  // dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k])
  // 注意本题中原本根节点和获得的子树对应的根节点不一定相同
  // 因此在本题中我们需要双向建边
  
  struct edge{
      int u,v,nxt;
  }e[maxn<<2];
  int cnt=0;
  int head[maxn<<2];
  int ans=1234567;
  void addedge(int u,int v){
      e[++cnt].u=u;
      e[cnt].v=v;
      e[cnt].nxt=head[u];
      head[u]=cnt;
  }
  int n,p;
  int dp[maxn][maxn];
  int deg[maxn];
  void dfs(int x,int fa){
      dp[x][1]=deg[x]; //初始化
      for(int i=head[x];i;i=e[i].nxt){
          int v=e[i].v;
          if(v==fa)continue;
          dfs(v,x);
          for(int j=p;j>=1;j--){
              for(int k=1;k<j;k++){
                  dp[x][j]=min(dp[x][j],dp[x][j-k]+dp[v][k]-2);
              }
          }
      }
  }
  
  int main(){
      memset(dp,0x3f,sizeof dp);
      cin>>n>>p;
      for(int i=1;i<n;i++){
          int u,v;
          cin>>u>>v;
          addedge(u,v);
          addedge(v,u);
          deg[u]++;
          deg[v]++;
      }
      dfs(1,0);
      for(int i=1;i<=n;i++){
          ans=min(ans,dp[i][p]);
      }
      cout<<ans<<endl;
  
  
      return 0;
  }
  ```

  

## 状态压缩动态规划

### luogu-P1879 Corn Fields G

- **题目描述：**给定一个M行N列的长方形，部分格子可供选择，从这些格子里进行选择，且选择的格子间不能有公共边，求选择方案数。

- 状态定义：dp[state] [i] 

- 表示在状态为state时，到达第i行符合条件的方案数

- state是二进制数，代表一行的方案情况

- state值为1代表这块地被选中，状态为0代表未被选中

- 本题中我们先进行初始化，通过init()找出一行内满足任意相邻两格不同时为1的所有state并记录

- 而为使后续操作方便，我们同样用二进制数来存储地图

- amap数组的的每个元素代表一行的状态

- 0表示这块土地可选，而1表示这块土地不可选

- 状态转移方程
  $$
  dp[state][i]=Σdp[pre][i-1]
  $$

- pre为该行前一行的状态

```c++
#include<bits/stdc++.h>
using namespace std;
#define mod 100000000
int n,m,cnt;
int amap[15],dp[100000][20],state[600];

void init(){
    cnt=0;
    for(int i=0;i<(1<<n);i++){
        if(!(i&i<<1))state[++cnt]=i;
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        for(int j==1;j<=n;j++){
            int x;
            cin>>x;
            if(!x)amap[i]=amap[i]|(1<<(n-j)); //amap使用二进制数表示每一行
        }
    }
    for(int i=1;i<=cnt;i++){ //对第一行的初始化
        if(state[i]&amap[1])continue;
        dp[i][1]=1; //只有当amap中为1的state都不为1时，方案才有效
    }
    for(int i=2;i<=m;i++){ //遍历行数
        for(int j=1;j<=cnt;j++){ //遍历上一行可能的state
            if(state[j]&amap[i-1])continue; // 在贫瘠地种草，排除
        	for(int k=1;k<=cnt;k++){ //遍历该行的state
                if(state[k]&amap[i])continue; //在贫瘠地种草
                if(state[k]&state[j])continue; //与上行在数值方向有相邻
            	dp[k][i]+=dp[j][i-1]; //状态转移方程
                dp[k][i]%=mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=cnt;i++){
        ans=(ans+dp[i][m])%mod;
    }
    cout<<ans;
}


```

### luogu-P1896 互不侵犯

- **题目描述:**给定一个N*N的棋盘，需要在其中放置K个国王，要求每个国王的上下左右及左上左下右上右下八个方向上不能有其他国王，求方案总数

- 典型的状态压缩动态规划题目，定义状态dp[state] [i] [m]

- 表示状态为state时，到达第i行且放置了m个国王的方案数

- 状态转移方程
  $$
  dp[state][i][m+num[k]]=\sum_{k=1}^{cnt}dp[pre][i-1][m]
  $$

- 值得注意的是我们每一行可以不只有放一个国王，在一行可以放多个国王的情况下我们必须记录当前状态中的国王数目(二进制1数目)

- ```c++
  #include<bits/stdc++.h>
  using namespace std;
  define ll long long
  int n,m,cnt=0; //cnt用来记录初始化中可行状态数，方便用于遍历
  int state[5000],num[5000];
  ll f[15][2000][100];
  
  void count(int x){
      while(x){
          num[cnt]+=x%2;
          x>>=1;
      }
  }// 用以统计一个状态下有几个国王，在初始化时完成
  
  void init(){
      for(int i=0;i<(1<<n);i++){
          if(!((i<<1)&i)){
              state[++cnt]=i;
              count(i); // 我们计算枚举成功的state中的国王个数
          }
      }
  }
  
  int main(){
      memset(f,0,sizeof f);
      cin>>n>>m;
      init();
      for(int i=1;i<=cnt;i++){
          if(num[i]>m)continue;
          f[i][1][num[i]]=1;
      }
      for(int i=2;i<=n;i++){ // 枚举行，已经对第一行初始化，从第二行开始
          for(int j=1;j<=cnt;j++){//枚举上一行状态
              for(int k=1;k<=cnt;k++){
                  if(state[j]&state[k])continue;
                  if((state[j]<<1)&state[k])continue;
                  if((state[j]>>1)&state[k])continue;//左下左下
                  for(int a=1;a<=m;a++){
                      if(num[k]+a>m)continue; //如果数目过多，忽略
                      f[i][k][num[k]+a]+=f[i-1][j][a];
                  }
              }
          }
      }
      for(int i=1;i<=n;i++){
          for(int j=0;j<=cnt;j++){
              ans+=f[i][j][m];
          }
      }
      cout<<ans<<endl;
      
      return 0;
  }
  
  
  ```

  

