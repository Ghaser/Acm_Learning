#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000000+10;
int n,k,maxh,minh,maxt,mint; 
int maxq[MAXN],minq[MAXN],num[MAXN];
int maxans[MAXN],minans[MAXN];

int main()
{

    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int maxhead=0,minhead=0,maxtail=0,mintail=0;
        for (int i=0;i<n;i++)
        {
            //删除下标超出范围的队首元素 
            if (maxhead<maxtail && maxq[maxhead]<=i-k) maxhead++;
            /*填空1内容：仿照上一句完成最小值的求取*/
            
            
            scanf("%d",&num[i]);
           
            /*删除队尾元素*/ 
            while (maxhead<maxtail && num[maxq[maxtail-1]]<=num[i]) maxtail--;maxtail++;
            maxq[maxtail-1]=i;
            /*填空2内容：仿照上一句完成最小值的求取*/
            
            maxans[i]=num[maxq[maxhead]];
            /*填空3内容：仿照上一句完成最小值的求取*/            
        }
        for (int i=k-1;i<n;i++) cout<<minans[i]<<' ';cout<<endl;
        for (int i=k-1;i<n;i++) cout<<maxans[i]<<' ';cout<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

