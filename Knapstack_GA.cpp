#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max 1000 //最多物品数
#define random(x)(rand()%x)
using namespace std;


void sort (int n,float a[max],float b[max]) //按价值密度排序
{
    int j,h,k;
    float t1,t2,t3,c[max];
    for(k=1;k<=n;k++)
        c[k]=a[k]/b[k];
    for(h=1;h<n;h++)
        for(j=1;j<=n-h;j++)
            if(c[j]<c[j+1])
            {
                t1=a[j];a[j]=a[j+1];a[j+1]=t1;
                t2=b[j];b[j]=b[j+1];b[j+1]=t2;
                t3=c[j];c[j]=c[j+1];c[j+1]=t3;
            }
}

void knapsack(int n,float limitw,float v[max],float w[max],int x[max])
{
    float c1; //c1为背包剩余可装载重量
    int i;
    sort(n,v,w); //物品按价值密度排序
    c1=limitw;
    for(i=1;i<=n;i++)
    {
        if(w[i]>c1)
            break;
        x[i]=1; //x[i]为1时，物品i在解中
        c1=c1-w[i];
    }
}
int main()
{
    int n,i,x[max],sumw=0;
    float v[max],w[max],totalv=0,totalw=0,limitw=0;
    cout<<"请输入背包总个数:";
    cin>>n;
    //物品选择情况表初始化为0
    for(i=1;i<=n;i++)
        x[i]=0;
    //随机产生物品价值
    for(i=1;i<=n;i++)
    {
        v[i]=1+rand()%101;
        cout<<"随机产生物品价值："<<v[i]<<endl;
        //limitw+=v[i];
    }
    //随机产生物品的重量
    for(i=1;i<=n;i++)
    {
        w[i]=1+rand()%101;
        sumw+=w[i];
        cout<<"随机产生物品重量："<<w[i]<<endl;
    }
    limitw=sumw/2;
    cout<<"背包总容量为:"<<limitw<<endl;
    //贪心算法
    knapsack (n,limitw,v,w,x);
    cout<<"背包装下的物品编号为："<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<x[i];
        if(x[i]==1)
        {
            totalw=totalw+w[i];
            totalv=totalv+v[i];
        }

    }
    cout<<endl;
    cout<<"放入背包的总重量为："<<totalw<<endl; //背包所装载总重量
    cout<<"贪心算法产生的最大总价值为："<<totalv<<endl; //背包的总价值
}
