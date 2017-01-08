#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define num 1000 //最多物品数
#define random(x)(rand()%x)
using namespace std;

int V[1000][2000];//前i个物品装入容量为j的背包中获得的最大价值
int max(int a,int b)
{
   if(a>=b)
       return a;
   else return b;
}

int KnapSack(int n,int w[],int v[],int x[],int C)
{
    int i,j;
    for(i=0;i<=n;i++)
        V[i][0]=0;
    for(j=0;j<=C;j++)
        V[0][j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=C;j++)
            {
                if(j<w[i])
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
            }
            j=C;
            for(i=n;i>0;i--)
            {
                if(V[i][j]>V[i-1][j])
                {
                    x[i]=1;
                    j=j-w[i];
                }
                else
                    x[i]=0;
            }
            printf("背包装下的物品编号为:\n");
            for(i=1;i<=n;i++)
                printf("%d ",x[i]);
            printf("\n");
            return V[n][C];

}

int main()
{
    int s,sumw=0;//获得的最大价值
    int w[num];//物品的重量
    int v[num];//物品的价值
    int x[num];//物品的选取状态
    int N,i;
    int C;//背包最大容量

    cout<<"请输入背包总个数:";
    cin>>N;
    for(int i=1;i<=N;i++)
        x[i]=0;

    for(int i=1; i<=N; i++)
    {
        v[i]=1+rand()%101;
        cout<<"随机产生物品价值："<<v[i]<<endl;
    }
    cout<<endl;

    for(int i=1; i<=N; i++)
    {
        w[i]=1+rand()%101;
        sumw+=w[i];
        cout<<"随机产生物品重量："<<w[i]<<endl;
    }
    cout<<endl;

    C=sumw/2;
    cout<<"背包总容量为:"<<C<<endl;

    s=KnapSack(N,w,v,x,C);

    printf("动态规划产生的最大物品价值为:\n");
    printf("%d\n",s);


}
