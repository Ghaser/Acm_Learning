# 类（Class）

### 概念	

类属于用户自定义的数据类型，类的定义包含两部分，一部分为类的属性，另一部分为它所拥有的方法。

​	基类、派生类、子类

### 定义

```c++
class //类名
{
    public:
    //公共的行为或属性
    private:
    //内部的行为或属性
};
```

注：1.类名需遵循一般命名规则

​		2.public和private为属性/方法限制的关键字，前者可被外界直接访问或调用。后者不能被外界访问或调用

​			一般来说类的属性成员都应设置为private，public只留给被外界调用的函数接口

​			变量声明通常都在private当中。

​		3.**注意结束部分有分号！！**

### 实现

​	**1、在类定义时定义成员函数**

​	

```c++
#include<iostream>
using namespace std;

class Point{
    public:
    	void setPoint(int x,int y){
            xPos=x;
            xPos=y;
        }
    	void printPoint() //实现printPoint函数
 
    {
 
        cout<< "x = " << xPos << endl;
 
        cout<< "y = " << yPos << endl;
 
    }
	private:
    	int xPos;
    	int yPos;
};

int main(){
    Point M;
    M.setPoint(10,20);
    M.printPoint();
    return 0;
}
```

​	与类的定义相比，在类内实现函数不再是在类内声明，而是直接将函数进行定义，且在类内定义成员函数时，编辑器会默认争取将其定义为inline函数。

​	**2、在类外定义成员函数**

​	在类外定义成员函数通过在类内进行声明，然后在类外通过作用域操作符：：进行实现

```c++
#include <iostream>
 
using namespace std;
 
class Point
 
{
 
    public:
 
    void setPoint(int x, int y); //在类内对成员函数进行声明
 
    void printPoint();
 
 
    private:
 
    int xPos;
 
    int yPos;
 
};
 
void Point::setPoint(int x, int y) //通过作用域操作符 '::' 实现setPoint函数
 
{
 
    xPos = x;
 
    yPos = y;
 
}
 
void Point::printPoint() //实现printPoint函数
 
{
 
    cout<< "x = " << xPos << endl;
 
    cout<< "y = " << yPos << endl;
 
}
 
int main()
 
{
 
    Point M; //用定义好的类创建一个对象 点M
 
    M.setPoint(10, 20); //设置 M点 的x,y值
 
    M.printPoint(); //输出 M点 的信息
 
 
    return 0;
 
}
```



​		依 setPoint 成员函数来说, 在类内声明的形式为 **void setPoint(int x, int y);** 那么在类外对其定义时函数头就应该是 **void Point::setPoint(int x, int y)** 这种形式, 其返回类型、成员函数名、参数列表都要与类内声明的形式一致。

# 重载运算符

​	分类：普通运算符重载（“+”、“-”、“*”、“/”）、前置运算符重载（“++”，“--”）、后置运算符重载（“>>”）、提取运算符重载（”<<")

​	

```C++
<返回类型说明符>operator<运算符符号>(<参数表>){
    <函数体>
}
```

# Virtual

## 虚函数