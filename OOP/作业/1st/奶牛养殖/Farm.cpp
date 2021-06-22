#include <iostream>
#include "Cow.h"
#include "Farm.h"
#include <string>
using namespace std;

        void Farm::addCow(Cow n)
        {
            Name[k]=n.name;
            L[k]=n.l;
            U[k]=n.u;
            M[k]=n.m;
            Record[k]=0;
            milkproduct[k]=0;
            k++;
        }
        void Farm::supply(string s, int a)
        {
             for(int i=0; i<Farm::n;i++)//这里为啥要用大写不是小写farm
             {
                     if(s==Name[i])
                     {
                             Record[i]+=a;
                             break;
                     }
             }   
        }
        void Farm::startMeal()
        {
                for(int i=0;i<Farm::n;i++)
                {
                        if(Record[i]<L[i]&&Record[i]!=0)
                        {
                                milkproduct[i]+=M[i]/2;
                                Record[i]=0;
                        }
                         if(Record[i]>=L[i]&&Record[i]<=U[i])
                        {
                                milkproduct[i]+=M[i];
                                Record[i]=0;
                        }
                        if(Record[i]==0)
                        {
                                milkproduct[i]+=0;
                        }
                        if(Record[i]>U[i])
                        {
                                milkproduct[i]+=M[i];
                                Record[i]-=U[i];
                        }
                }
        }
        void Farm::produceMilk()
        {
                return;
        }
        double Farm::getMilkProduction()
        {       double m=0;
              for(int i=0;i<Farm::n;i++)
              {
                      m+=milkproduct[i];
              }  
              return m;
        }