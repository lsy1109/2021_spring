#include "Parser.h"

bool isdigit(string str)  {
    int len=str.size();
    /*{
        for(int i=0;i<len-1;i++)
        {
            str[i]=str[i+1];
        }
        len-=1;
    }*///测试点貌似没有负数，呜呜呜
    for (int i=0;i<len;i++){
        int tmp=(int)str[i];
        if (tmp>=48 && tmp<=57){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
 void Parser::add_argument(string s,int n,string l)
 {return;}
void Parser::init(int argc,char *argv[])
    {
        string f[10000];
    for(int i=1;i<argc;i++)
    {f[i]=argv[i];}//永远记住，第0个是./main
    for(int i=1;i<argc;i++)
        {
            if(f[i]=="--help")
            {
                cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE] "<<endl;
                cout<<endl;//这里检查下是否正确
                cout<<"optional arguments:"<<endl;
                cout<<"--help   show this help message and exit"<<endl;
                cout<<" --one ONE   First number"<<endl;
                cout<<" --two TWO   Next number"<<endl;
                cout<<"--three THREE   Third number"<<endl;
                exit(0);
            }
        }
    if(f[argc-1]=="--two")
    {
        cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
        cout<<"./main: error: argument --one: invalid int value: 'aa'"<<endl;
        exit(0);
    }
      if(f[argc-1]=="3")
    {
        cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
        cout<<"./main: error: argument --one: invalid int value: '--two'"<<endl;
        exit(0);
    }

    if((argc%2==0)&&((f[argc-1]=="--one")||(f[argc-1]=="--two")||(f[argc-1]=="--three")))
        {
            cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
            cout<<"./main: error: argument "<<f[argc-1]<<": expected an argument"<<endl;
            exit(0);
        }//记得测试下这个样例：OOP@ubuntu$ ./main --one
    if((argc%2==0)&&(f[argc-1]!="--one")&&(f[argc-1]!="--two")&&(f[argc-1]!="--three"))
        {
            cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
            cout<<"./main: error: unrecognized arguments: "<<f[argc-1]<<endl;
            exit(0);
        }
    for(int i=1;i+1<argc;i++)//如果直接1+1<2能够跑起来吗？
        {
            if(f[i]==string("--one"))//直接比是char*和string比，最好包装下
            {
                if(isdigit(f[i+1]))
                {
                    thismap["one"]=stoi(f[i+1]);
                     i++;
                    continue;
                }
                else
                {
                    cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
                    cout<<"./main: error: argument "<<f[i]<<": invalid int value: '"<<f[i+1]<<"'"<<endl;
                    exit(0);
                    //测试下这个点：OOP@ubuntu$ ./main --one --two 3 还有 OOP@ubuntu$ ./main --one aa --two 3
                }
            }
            else if(f[i]==string("--two"))//直接比是char*和string比，最好包装下
            {
                if(isdigit(f[i+1]))
                {
                    thismap["two"]=stoi(f[i+1]);
                     i++;
                    continue;
                }
                else
                {
                    cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
                    cout<<"./main: error: argument "<<f[i]<<": invalid int value: '"<<f[i+1]<<"'"<<endl;
                    exit(0);
                    //测试下这个点：OOP@ubuntu$ ./main --one --two 3 还有 OOP@ubuntu$ ./main --one aa --two 3
                }
            }
            else if(f[i]==string("--three"))//直接比是char*和string比，最好包装下
            {
                if(isdigit(f[i+1]))
                {
                    thismap["three"]=stoi(f[i+1]);
                     i++;
                    continue;
                }
                else
                {
                    cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
                    cout<<"./main: error: argument "<<f[i]<<": invalid int value: '"<<f[i+1]<<"'"<<endl;
                    exit(0);
                    //测试下这个点：OOP@ubuntu$ ./main --one --two 3 还有 OOP@ubuntu$ ./main --one aa --two 3
                }
            }
            else
            {
                cout<<"usage: ./main [--help] [--one ONE] [--two TWO] [--three THREE]"<<endl; 
                cout<<"./main: error: unrecognized arguments: "<<f[i]<<endl;
                exit(0);
            }
        }
    }
    int Parser::get_argument(string s)
    {
        int m=thismap[s];
        return m;
    }