#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
using namespace std;
#define For(a,b,c,d) for(register int a=b;a<=c;a+=d) 
const int my[ 4 ] = { 0 , 1 , 0 , -1 } , mx[ 4 ] = { -1 , 0 , 1 , 0 } ; //每个方向的移动规则 
int n , m , maze[ 60 ][ 60 ] ;
bool vis[ 20000 ] ; //记录访问过的位置 
inline int fun( int a , int b , int c ) { return c * 2700 + a * 51 + b ;} //返回每种情况唯一对应的key值 
struct pos { //每个位置的信息 
    int x , y ; //坐标 
    int f ; //方向 
    int mov ; //已移动时间 
} ;
std::queue<pos> que ; 
inline bool zq( int x , int y ) { //判断是否撞上障碍物 
    if( maze[ x ][ y ] || maze[ x + 1 ][ y ] || maze[ x ][ y + 1 ] || maze[ x + 1 ][ y + 1 ] )
        return 1 ;
    return 0 ;
}
inline void bfs() {
    int x , y , tx , ty , f , d , mov , lx , ly ;
    char c ;
    scanf("%d %d %d %d %c" , &x , &y , &tx , &ty , &c );
    switch( c ) {
        case 'N': f = 0 ;
            break ;
        case 'E': f = 1 ;
            break ;
        case 'S': f = 2 ;
            break ;
        case 'W': f = 3 ;
            break ;
    }
    pos temp ;
    temp.x = x , temp.y = y , temp.f = f , temp.mov = 0 ;
    que.push( temp ) ;
    cout<<zq(9,2)<<'A'<<endl;
    while( !que.empty() ) {
        temp = que.front() ;
        que.pop() ;
        x = temp.x , y = temp.y , f = temp.f , d = fun( x , y , f ) , mov = temp.mov ;
        if( x == tx && y == ty ) { //判断是否是重点 
            printf("%d %d",mov,f) ;
            exit( 0 ) ;
        }
        if( vis[ d ] ) //判断是否被访问过 
            continue ;
        //cout<<x<<' '<<y<<endl;
        vis[ d ] = 1 ;
        temp.mov ++ ;
        temp.f = ( f + 4 - 1 ) % 4 ; //左转 
        que.push( temp ) ;
        temp.f = ( f + 4 + 1 ) % 4 ; //右转 
        que.push( temp ) ;
        temp.f = f ;
        For( i , 1 , 3 , 1 ) { //向前移动 
            lx = x + mx[ f ] * i , ly = y + my[ f ] * i ;
            if(lx==9&&ly==2){
                cout<<"aaaa"<<endl;
            }
            if( lx <= 0 || ly <= 0 || lx >= n || ly >= m || zq( lx , ly ) )
                break ;
            temp.x = lx ;
            temp.y = ly ;
            if(lx==9&&ly==2){
                cout<<temp.f<<endl;
            }
            que.push( temp ) ;
        }
    }
    printf("-1");  
}
int main() { //主函数 
    scanf("%d %d" , &n , &m ) ;
    For( i , 1 , n , 1 ) {
        For( j , 1 , m , 1 ) {
            scanf("%d", &maze[ i ][ j ] );
        }
    }
    bfs() ;
    return 0;
}