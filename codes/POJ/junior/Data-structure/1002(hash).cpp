#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int n;

int change(char ch) {
	if(ch=='A' || ch=='B' || ch=='C')
		return 2;
	if(ch=='D' || ch=='E' || ch=='F')
		return 3;
	if(ch=='G' || ch=='H' || ch=='I')
		return 4;
	if(ch=='J' || ch=='K' || ch=='L')
		return 5;
	if(ch=='M' || ch=='N' || ch=='O')
		return 6;
	if(ch=='P' || ch=='R' || ch=='S')
		return 7;
	if(ch=='T' || ch=='U' || ch=='V')
		return 8;
	if(ch=='W' || ch=='X' || ch=='Y')
		return 9;
}

int main(){
    cin>>n;
    


    return 0;
}