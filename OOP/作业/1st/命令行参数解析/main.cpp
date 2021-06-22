#include <iostream>
#include "Parser.h"

int main(int argc, char *argv[]) //你的*argv[]是一串以空格分割的字符串
//而argc表示以空格分割的参数的个数，比如说--one 1 --two 2，这里传入了四个参数
//但你需要在init函数里面把这四个参数解析为one=1.two=2
//同时，参入的参数还可能和add_argument里面的参数不同（错误读取）。需要你处理
//输入参数为整数。
//测试时的选项名称全部以 “--” 开头。
//get_argument中的参数全部添加过。
{   
    Parser parser = Parser();

    parser.add_argument("--one", 1, "First number");
    //中间的1是默认值，但是你传入的参数可以改变这个值
    parser.add_argument("--two", 2, "Next number");
    parser.add_argument("--three", 3, "Third number");

    parser.init(argc, argv);

    int a = parser.get_argument("one");
    int b = parser.get_argument("two");
    int c = parser.get_argument("three");

    std::cout << a + b * c << std::endl;

    return 0;
}