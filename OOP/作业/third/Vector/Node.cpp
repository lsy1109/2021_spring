#include "Node.h"
long long int Node::num_createfunc = 0, Node::num_copyfunc = 0, Node::num_movefunc = 0;
long long int Node::num_copyassign = 0, Node::num_moveassign = 0, Node::num_delfunc = 0;
long long int Node::num_createfunc_default = 0;

Node::Node(int v): val(v) {
	num_createfunc++;
}//++的只是用来判断你有没有内存泄露
Node::Node(){
	num_createfunc_default++;
}
Node::~Node() {
	num_delfunc++;
}
Node::Node(const Node &y): val(y.val) {
	num_copyfunc++;
}//检测你用了多少次移动赋值，尽可能用移动赋值；注意到具体在这道题里面，因为node内部没有数组，copyfunc和movefucn没有显著效率区别；
//但是出题人为了强调一般拷贝比移动效率低，所以强行把拷贝的cost设为10，move设为1；
Node::Node(Node &&y): val(y.val) {
	y.val = 0;
	num_movefunc++;
}
Node& Node::operator=(const Node &y) {
	val = y.val;
	num_copyassign++;
	return *this;
}
Node& Node::operator=(Node &&y) {
	val = y.val;
	y.val = 0;
	num_moveassign++;
	return *this;
}//对node的拷贝构造赋值与移动赋值没有本质的效率区别

bool Node::operator!=(const Node & y){
	return val != y.val;
}

void Node::outputResult(int ref_ans) {
	std::cout << Node::num_createfunc_default << " " << Node::num_createfunc << " " << Node::num_copyfunc << " " << Node::num_movefunc << " " << Node::num_copyassign << " " << Node::num_moveassign << " " << Node::num_delfunc << std::endl;
	long long int tmp = (Node::num_createfunc+Node::num_copyfunc+Node::num_copyassign)*10+Node::num_movefunc+Node::num_moveassign+Node::num_createfunc_default;
	if (tmp <= ref_ans && Node::num_createfunc + Node::num_createfunc_default + Node::num_copyfunc + Node::num_movefunc == Node:: num_delfunc){
		std::cout << "YES" << std::endl;
	}	
	else{
		std::cout << "NO" << std::endl;
	}
}

std::istream& operator>>(std::istream& in, Node& x){
	std::cin >> x.val;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Node& x){
	std::cout << x.val;
	return out;
}
