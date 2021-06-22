/**
 * COPYRIGHT NOTICE
 * Copyright (c) 2019, Institute of CG & CAD, Tsinghua University.
 * All Rights Reserved.
 *
 * @file    main.cpp
 * @brief   Write your own code here.
 *
 * @version 1.3
 * @author  Jackie Pang
 * @e-mail: 15pengyi@gmail.com
 * @date    2012/10/11
 * @reviser	Gong Chao
 * @date	2014/10/13
 * @e-mail:	gcdofree@gmail.com
 * @reviser	Zhang Mingdong
 * @date	2017/10/10
 * @e-mail:	zhangmd14@mails.tsinghua.edu.cn
 * @reviser	Xiao Dong
 * @date	2019/03/18
 * @e-mail:	xiaodong14ry@163.com
 */

#include <iostream>
#include "USSolver.h"
#include<string.h>
int d[110],fa[110],vis[110];
int v,e;
int p[110],q[1010],r[1010];
int tot;
void USSolver::Solve(std::istream &inputStream, std::ostream &outputStream)
{
	//请在此填充代码
	//输入输出方式: inputStream<<in, outputStream>>out等
	inputStream>>v>>e;
	for(int i=0;i<=v;i++)
		inputStream>>p[i];
	for(int i=0;i<e;i++)
		inputStream>>q[i];
	for(int i=0;i<e;i++)
		inputStream>>r[i];
	memset(d,0x3f,sizeof(d));
	d[0]=0;
	for(int i=1;i<=v;i++){
		int x=-1;
		for(int j=0;j<v;j++)
			if(vis[j]==0&&(x==-1||d[j]<d[x]))x=j;
		vis[x]=1;
		if(x!=0){
			outputStream<<"["<<fa[x]<<"->"<<x<<"]";
			tot+=d[x];
		}
		d[x]=0;
		for(int j=p[x];j<p[x+1];j++)
			if(d[x]+r[j]<d[q[j]]){
				d[q[j]]=d[x]+r[j];
				fa[q[j]]=x;
			}
	}
	outputStream<<" "<<tot;
}



int main(int argc, char *argv[])
{
	//可在此更改测试文件
    std::string fileName = "Test404.txt"; 
    
    USSolver unofficialSolver(fileName);
    const std::string unofficialAnswer = unofficialSolver.GetAnswer();

    std::cout << "Your Answer:\n" << unofficialAnswer << std::endl;
	//system("pause");
}