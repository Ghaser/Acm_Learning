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
            //ɾ���±곬����Χ�Ķ���Ԫ�� 
            if (maxhead<maxtail && maxq[maxhead]<=i-k) maxhead++;
            /*���1���ݣ�������һ�������Сֵ����ȡ*/
            
            
            scanf("%d",&num[i]);
           
            /*ɾ����βԪ��*/ 
            while (maxhead<maxtail && num[maxq[maxtail-1]]<=num[i]) maxtail--;maxtail++;
            maxq[maxtail-1]=i;
            /*���2���ݣ�������һ�������Сֵ����ȡ*/
            
            maxans[i]=num[maxq[maxhead]];
            /*���3���ݣ�������һ�������Сֵ����ȡ*/            
        }
        for (int i=k-1;i<n;i++) cout<<minans[i]<<' ';cout<<endl;
        for (int i=k-1;i<n;i++) cout<<maxans[i]<<' ';cout<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

