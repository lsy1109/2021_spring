#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


struct Friend {
    int id;
    vector<string>message;//朋友的vector数组储存聊天记录，这里从最旧到最新
    Friend(int t):id(t){};
    Friend(){};
    bool operator==(const Friend& other){
        return (id==other.id);
    }
};


int main(){
    int N,M;
    cin>>N;
    list<Friend>fri;//按照最新到最旧顺序储存朋友
    for (int i=0;i<N;i++){
        Friend tmp;
        cin>>tmp.id;
        getchar();//吸收id后面的空格
        char c;
        string temp;
        temp.clear();
        while ((c=getchar())>' '){//当还没有换行的时候
            if (c!='/'){
                temp=temp+c;
            }
            else{
                tmp.message.push_back(temp);
                temp.clear();
            }
        }//while循环结束后temp还储存着最后一句话捏
        tmp.message.push_back(temp);
        fri.push_front(tmp);
    }
    cin>>M;
    for (int i=0;i<M;i++){
        int tmpid;
        cin>>tmpid;
        list<Friend>::iterator it=find(fri.begin(),fri.end(),Friend(tmpid));
        if (it==fri.end()){
            Friend tmp;
            tmp.id=tmpid;
            string temp;
            getchar();
            getline(cin,temp);
            tmp.message.push_back(temp);
            fri.push_front(tmp);
        }
        else {
            Friend tmp=*it;
            fri.erase(it);
            string temp;
            getchar();
            getline(cin,temp);
            tmp.message.push_back(temp);
            fri.push_front(tmp);
        }
    }
    //cout
    //cout<<"size of list"<<fri.size()<<endl;
    for (list<Friend>::iterator it=fri.begin();it!=fri.end();++it){
        cout<<it->id<<endl;
        for (int i=(it->message.size())-1;i>=0;i--){
            cout<<it->message[i]<<endl;
        }
    }

    return 0;
}