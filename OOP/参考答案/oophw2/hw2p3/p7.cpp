class Test{
    int data;
    const int const_data = 0;
    static int static_data;
public:
    static void func(int x) {data = x;}
    static void func(int x) {static_data = x;}
};
int Test::static_data = 0;