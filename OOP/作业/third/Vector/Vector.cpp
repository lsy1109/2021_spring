#include"Vector.h"
#include "Node.h"
Vector::Vector(int n)
{
	capacity = n;
	array = new Node[n];
	len = 0;
}

Vector::~Vector()
{
	if (array != nullptr) { delete[]array; }
}

Vector::Vector(const Vector& other)//拷贝构造函数如何拷贝一个指针？
{
	capacity = other.capacity;
	len = other.len;
	array = new Node[other.capacity];//注意到这里的大小是capacity而非len。array的大小实际上是容量，而len是目前储存的量。关键是，你在赋值容器的时候不可能减少容积啊，所以这里的参数是capcity而非len
	for (int i = 0; i < len; i++)
	{
		array[i] =other.array[i];
	}
}

Vector::Vector(Vector&& other):array(other.array),capacity(other.capacity),len(other.len)//初始化列表需要加冒号
{
	other.array = nullptr;
	other.len = 0;//移动构造函数由于移动之后不可再使用other.array(为什么不可接下来解释)，故而要将other.array置空。并且要清除other.len，以免内存泄漏。注意到我们只是将other.array置空，并没有delete other.array。回顾上文，我们使用delete就会清除掉other.array指向的内存区域，而这片内存区域是我还要使用的。这就是移动构造函数的本质，内存不变但是指针改变。
}

Vector&Vector::operator=(const Vector& other)//既然是要拷贝赋值，那就得所有东西一样哇
{
	if (this != &other) 
		//建议拷贝的时候检测是否相同，检测的原理本质上就是检测地址是否相同
		if (this->array != nullptr)
		{
			delete[]array;
		}
	this->capacity = other.capacity;
	this->len = other.len;
	array = new Node[capacity];
		for (int i = 0; i < len; i++)
		{
			this->array[i] = other.array[i];
		}
		return *this;
}

Vector&Vector::operator=(Vector&& other)
{
	if (this != &other) {
		if (this->array != nullptr)//this是vector的指针，我要判断的是array是否为空
		{
			delete[]array;//delete的意义就是释放指针指向的内存区域
		}
		this->array = other.array;
		this->capacity = other.capacity;
		this->len = other.len;
		other.array = nullptr;
		other.len = 0;//系统会检查是否清0；
	}
	return *this;
}

Node& Vector::operator [] (int pos)//返回值+命名空间+名字
{
	return array[pos];
}
void Vector::append(int value)
{
	this->len++;
	array[this->len-1] = value;//注意到这里当然是len-1；
}//append和insert都要len++
void Vector::insert(int pos, int value)
{
	for (int i = len; i>pos; i--)//这里可能有问题，应该重点debug
		//起点应该是len还是len-1？
		//注意到这里虽然用左值的拷贝赋值也没有问题，但是题目强调了拷贝和移动的效率区别，故而应该使用移动赋值
		//而移动赋值只能对右值进行，所以需要把左值手动转化为右值，也就是用std::move函数
	{
		array[i] = std::move(array[i - 1]);//在这一段的赋值逻辑，应该从从后往前覆盖，不然前面的数据会被抹除
	}
	array[pos] = value;
	len++;
	return;//这里记得+return，不加会如何？
	//不加啥事没有，因为void自动带有return；
}
void Vector::swap(int pos1, int pos2)//善用move,这里用move同样可以把左值转为右值
{
	Node tmp = std::move(array[pos1]);
	array[pos1] = std::move(array[pos2]);
	array[pos2] = std::move(tmp);
}
void Vector:: dilatation()
{
	this->capacity *= 2;
	Node* tmp = new Node[this->capacity];
	for (int i = 0; i < len; i++)
	{
		tmp[i] = std::move(array[i]);
	}
	if (array != nullptr) { delete[]array; }//把array这个地址指向的内存给释放了，但是array还存着那个地址，只不过不能用了也不应该再用了
	this->array = tmp;//我现在把array指向的地址改为tmp的地址
}
int Vector::getlen()
{
	return this->len;
}