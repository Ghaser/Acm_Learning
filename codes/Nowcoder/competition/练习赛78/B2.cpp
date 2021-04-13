#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,y,z) for(x=y;x<=z;x++)
#define repp(x,y,z) for(x=y;x>=z;x--)
struct Node {
    ll val;
    ll id;
    bool operator < (const Node& opt) const {
        return val < opt.val;
    }
}T[2007];
int top = 0;
 
const int N = 2000 + 7;
ll n, m,i,j,k;
ll a[N], b[N];
bool vis[N];
vector<int> st;
 
int main() {
    cin>>n,m;
    for(int i=1;i<=n;i++)   cin>>a[i] ;
    rep(i, 1, m) {
        cin>>b[i];
        if (!vis[b[i]]) {
            T[++top] = { a[b[i]],b[i] }; // Node(val , id);
        }
        vis[b[i]] = 1;
    }
    ll ans = 0;
    rep(i, 1, m) {
        rep(j, 1, top) {
            if (T[j].id == b[i]) {
                Node tmp = T[j];
                repp(k, j, 2)   T[k] = T[k - 1];
                T[1] = tmp;
                break;
            }
            else ans += T[j].val;
        }
    }
    cout<<ans<<endl;
    return 0;
}