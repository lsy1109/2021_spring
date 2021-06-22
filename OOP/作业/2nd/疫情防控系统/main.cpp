#include <iostream>
#include "School.h"
#include "Student.h"

using namespace std;
int main(){
	int n;
	cin >> n;
	School tsinghua(n);
	for (int i = 0; i < n; ++ i){
		Student s;
		cin >> s;
		tsinghua.add_member(s);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++ i)//如果查询不到，那就返回一个空的学生，然后在输出重载的时候如果是空的，那就cout<<找不到
	//注意到你对[]重载后，返回的是student的引用，故而你要重载的是student的<<符号
	{
		int type;
		cin >> type;
		if (type == 0){
			int sid;
			cin >> sid;
			cout << tsinghua[sid];
		}
		else if (type == 1) {
			string name;
			cin >> name;
			cout << tsinghua[name];
		}
		else if (type == 2){
			char province;
			cin >> province;
			cout << tsinghua[province];
		}
	}
	return 0;
}