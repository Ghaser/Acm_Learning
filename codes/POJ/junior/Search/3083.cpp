#include<iostream>
#include<string>
using namespace std;
//DFS 深度优先搜索
//输出 优先左转时走过的格子数，优先右转时走过的格子数，最短路径走过的格子数
string a[41];
int w,h;
void dfs(int x){

}//x为步数


int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>w>>h;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>a[i][j];
            }
        }//读入迷宫
        dfs(1);
    }

    return 0;
}
/*
########
#......#
#.####.#
#.####.#
#.####.#
#.####.#
#...#..#
#S#E####


*/