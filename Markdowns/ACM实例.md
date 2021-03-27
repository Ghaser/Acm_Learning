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

