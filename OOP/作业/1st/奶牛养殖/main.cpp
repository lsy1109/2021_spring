#include <iostream>
#include <string>
#include "Cow.h"
#include "Farm.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    Farm farm(n);//小写的farm只是类的变量名，你的大写Farm是类名
    string name;
    int l, u, m;
    for(int i = 0; i < n; ++i){
        cin >> name >> l >> u >> m;
        Cow cow(name, l, u, m);//新增加一个牛，录入信息，一头牛的name，l，u，m；第一个Cow是类名，第二个是变量名，括号是调用的意思，调用构造函数
        //int i=1;int i(1);这两个是等价的，就是定义一个Cow对象你需要写构造函数
        farm.addCow(cow);//一个farm里面有n头牛，然后每次添加一头牛。
    }

    int k;
    cin >> k;
    int t;
    int a;
    for(int i = 0; i < k; ++i){//k天，给t头牛，投喂了a饲料
        cin >> t;
        for(int j = 0; j < t; ++j){
            cin >> name >> a;
            farm.supply(name, a);//supply需要记录第几天投入，到record里面，
            //所以你的farm的类里面就要写上天数和a
            //艹！你是SB叭，每次循环都会算一次product，所以你记个寂寞的k？？？
        }
        farm.startMeal();
        farm.produceMilk();
    }
    printf("%.1f", farm.getMilkProduction());
    return 0;
}