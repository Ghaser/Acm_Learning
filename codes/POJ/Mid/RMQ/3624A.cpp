#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=200007;
int n,k,a[maxn];
int dp1[maxn][25], dp2[maxn][25];
void rmq_init(){
    for(int i = 1; i <= n; i++){
    	dp1[i][0] = a[i];
    	dp2[i][0] = a[i];
	}
    for(int j = 1; (1<<j) <= n; j++){
        for(int i = 1; i+(1<<j)-1 <= n; i++){
            dp1[i][j] = max(dp1[i][j-1], dp1[i+(1<<(j-1))][j-1]);
			dp2[i][j] = min(dp2[i][j-1], dp2[i+(1<<(j-1))][j-1]);
		}
    }
}
int rmq_max(int l, int r){
    int k=0;
    while(1<<(k+1) < r-l+2){
        k++;}
    return max(dp1[l][k],dp1[r-(1<<k)+1][k]);
}
int rmq_min(int l, int r){
    int k=0;
    while(1<<(k+1) < r-l+2){
        k++;
    }
    return min(dp2[l][k], dp2[r-(1<<k)+1][k]);
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    rmq_init();
	while(k--){ 
		int l, r;
		scanf("%d%d", &l, &r);
        printf("%d\n", rmq_max(l, r)-rmq_min(l, r));
    }
    return 0;
}