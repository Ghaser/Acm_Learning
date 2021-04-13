#include <iostream>
#include <string>
#include<map>
using namespace std;
char a[100000];
map<char,int> m;
int main()
{
  scanf("%s",a);
  for(int i=0;a[i]!='\0';i++){
      char temp=a[i];
      m[temp]++;
  }
  char ans;
  int max=-1;
  for(char a='a';a<='z';a++){
      if(m[a]>max){
          ans=a;
          max=m[a];
      }
  }
  cout<<ans<<endl;
  cout<<max<<endl;
  return 0;
}