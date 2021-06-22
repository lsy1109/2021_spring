#pragma once
#include "wrapper_counter.h"

class AbstractWrapper {
	string uid;
public:
	string type_;
	AbstractWrapper(string t) {
		type_ = t;
		uid = WrapperCounter::getUID(type_);
	}
	virtual string type() = 0;
	virtual string to_string() = 0;
	friend ostream &operator <<(ostream &out, AbstractWrapper *w) {
		return out << w->uid << ": " << w->to_string();
	}
	virtual ~AbstractWrapper() {};
};

class IntegerWrapper : public AbstractWrapper {
	int *ptr;
public:
	IntegerWrapper(int *ptr)
		: AbstractWrapper("int"), ptr(ptr) {}
	virtual string type() { return "int"; }
	virtual string to_string() {
		return std::to_string(*ptr);
	}
	~IntegerWrapper() { if (ptr != 0) delete ptr; else return; }
};

class StringWrapper : public AbstractWrapper {
protected:
	char *ptr;
	int len;
public:
	StringWrapper(char *ptr, int len, string s = "string")
		: AbstractWrapper(s), ptr(ptr), len(len) {}
	~StringWrapper() { if (ptr != 0) delete[] ptr; else return; }
	int length() { return len; }
	virtual string type() { return "string"; }
	virtual string to_string() {
		return string(ptr, len);
	}
};

class ChineseStringWrapper : public StringWrapper {
	// 用三个char表示一个汉字
public:
	ChineseStringWrapper(char *ptr, int len) : StringWrapper(ptr, len, "chineseString") {}
	virtual string type() { return "chineseString"; }
	int length(bool rawChars = true) {
		// 如果rawChars为false，则返回中文字符数；否则返回实际char数组长度
		if (rawChars) return len;
		else return len / 3;
	}
	~ChineseStringWrapper() {}
};
