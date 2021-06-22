class B {
public:
    B(int i) {}
};

class A {
private:
    int a = 1;
    char c = 'c';
    B b = a; // (2)
public:
    A() = default; // (1)
    A(int i):a(i) {}
    A(char ch) = delete; // (3)
};

int main() {
    A a(1);
    return 0;
}