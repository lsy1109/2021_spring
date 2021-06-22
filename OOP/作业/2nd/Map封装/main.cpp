#include <iostream>
#include "Pair.h"
#include "Map.h"
using namespace std;

void test(){
    int n, k;
    cin >> n >> k;
    Map map(n);
    const Map & cmap = map;//cmap是map的引用（别名），但是cmap是const，所以cmap不能被修改。也就是，修改map时cmap会同步被修改；但是cmap本身是const类型，不能被修改。
    int query;
    string key;
    int val;//这三个变量都是输入用的临时变量，不要在意
    for(int i = 0; i < k; ++i){
        cin >> query;
        if(query == 1){
            cin >> key;
            cout << map[key] << endl;//map[key]返回的是引用，这样你修改map[key]的时候，map里面的对象就被修改了，这就是‘能读能写’的含义（而不只是能读）
        }
        else if(query == 2){
            cin >> key >> val;
            map[key] = val;//这里的map[key]返回的是引用。我把val赋值给返回的引用。
        }
        else if(query == 3){
            cin >> key;
            cout << cmap[key] << endl;//重载cmap的[]和map的[]；实际上因为cmap是const对象，只能调用const成员函数，所以你写两种重载函数，一个给const用的const重载，一个给一般成员用的一般重载
        }
    }//构造map传入的是n，需要在map里开n大小的pair数组；data是表头；在中括号里，调用pair时，需要调用pair的public函数；
    cout << map.size() << endl;
}

int main(){
    test();
    return 0;
}