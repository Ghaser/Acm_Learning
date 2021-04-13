#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> v1,v2;
map<string,bool> prt,vis;

int main(){
    ios::sync_with_stdio(0);
    int t,n,m;
    cin>>t;
    while(t--){
        string s;
        v1.clear();
        v2.clear();
        vis.clear();
        prt.clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>s;
            v1.push_back(s);
        }
        for(int i=1;i<=m;i++){
            cin>>s;
            v2.push_back(s);
        }
        for(int i=0;i<m;i++){
            string a="";
            for(char &c : v2[i]){
                if(c=='/')prt[a]=1;//保护操作
                a+=c;
            }
        }
        int ans=n; //开始操作，判断能否合并k个文件（删除文件夹）
        for(int i=0;i<n;i++){
            string a="";
            for(char &c : v1[i]){
                if(c=='/'){
                    if(!prt[a]){//从头开始遍历，先找到的一定是可以使用的最上级文件
                        if(vis[a])ans--;
                        else vis[a]=1;
                        break;
                    }
                }
                a+=c;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}