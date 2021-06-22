//
//  main.cpp
//  Prim
//
//  Created by 曹菡雯 on 2021/5/4.
//

#include <iostream>
using namespace std;

bool mark[102];
int p[102];
int q[1002];
int r[1002];
int W[102];
int pre[102];
int seq[102];
int cnt=0;
int tree=0;

void cinChart(int v,int e){
    for (int i=0;i<=v;i++){
        cin>>p[i];
    }
    for (int i=0;i<=e-1;i++){
        cin>>q[i];
    }
    for (int i=0;i<e;i++){
        cin>>r[i];
    }
}

void Init(int v){
    for (int i=0;i<v;i++){
        W[i]=0x7fffffff;
    }
}

void update(int u){
    for (int i=p[u];i<=p[u+1];i++){
        if (!mark[q[i]] && W[q[i]]>r[i]){
            W[q[i]]=r[i];
            pre[q[i]]=u;
        }
    }
}

int findNext(int v){
    int tmp=0x7fffffff;
    int id=0;
    for (int i=0;i<v;i++){
        if (!mark[i] && tmp>W[i]){
            tmp=W[i];
            id=i;
        }
    }
    return id;
}


void Prim(int v){
    mark[0]=true;
    for (int i=p[0];i<=p[1];i++){
        W[q[i]]=r[i];
        pre[q[i]]=0;
    }
    seq[0]=0;
    cnt++;
    for (int i=1;i<v;i++){
        int id=findNext(v);
        mark[id]=true;
        seq[cnt]=id;
        cnt++;
        update(id);
        tree+=W[id];
    }
}

void printTree(int v){
    for (int i=1;i<v;i++){
        cout<<"["<<pre[seq[i]]<<"->"<<seq[i]<<"]";
    }
    cout<<" "<<tree<<endl;
}

int main() {
    int v,e;
    cin>>v>>e;
    cinChart(v,e);
    Init(v);
    Prim(v);
    printTree(v);
    return 0;
}
