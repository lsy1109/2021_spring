#include <iostream>
#include <cstring>
using namespace std;

int rX[21];
int rY[21];//rY[i]表示第i个Y中元素和第几个X中元素配对（若孤立则为100
bool markY[21];//在试图给X中每个点找一个匹配点的时候，用这个数组记录Y里面的点有没有被找过
bool line[21][21];//i j间是否有边

void init(){
    for (int i=0;i<21;i++){
        rX[i]=100;
    }
    for (int i=0;i<21;i++){
        rY[i]=100;
    }
    for (int i=0;i<21;i++){
        markY[i]=false;
    }
    for (int i=0;i<21;i++){
        for (int j=0;j<21;j++){
            line[i][j]=false;
        }
    }
}

bool find(int t,int y){
    for (int i=0;i<y;i++){
        if (line[t][i] ==true && markY[i]==false){//遍历所有和t点关联、且没有被mark过的Y中的点
            markY[i]=true;//
            if (rY[i]==100 || find(rY[i],y)){//如果这个Y中的点还没有饱和，或者和这个点关联的点可以找到另一个对象
                rY[i]=t;
                rX[t]=i;
                return true;
            }
            
        }
    }
    return false;
}

int main() {
    int x,y,e;
    cin>>x>>y>>e;
    init();
    for (int i=0;i<e;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        line[tmp1][tmp2]=true;
    }
    int res[21];//记录哪些X中点饱和
    int cnt=0;
    for (int k=0;k<x;k++){//遍历X中每个元素
        memset(markY,false,sizeof(markY));//每次要先把mark数组清空
        if (find(k,y)){//如果找到了匹配的点
            res[cnt]=k;
            cnt++;
        }
    }
    //cout<<"总共匹配边为："<<cnt<<endl;
    for (int i=0;i<cnt;i++){
        cout<<res[i]<<" "<<rX[res[i]]<<endl;
    }
    return 0;
}
