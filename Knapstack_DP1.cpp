#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define num 1000 //�����Ʒ��
#define random(x)(rand()%x)
using namespace std;

int V[1000][2000];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ
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
            printf("����װ�µ���Ʒ���Ϊ:\n");
            for(i=1;i<=n;i++)
                printf("%d ",x[i]);
            printf("\n");
            return V[n][C];

}

int main()
{
    int s,sumw=0;//��õ�����ֵ
    int w[num];//��Ʒ������
    int v[num];//��Ʒ�ļ�ֵ
    int x[num];//��Ʒ��ѡȡ״̬
    int N,i;
    int C;//�����������

    cout<<"�����뱳���ܸ���:";
    cin>>N;
    for(int i=1;i<=N;i++)
        x[i]=0;

    for(int i=1; i<=N; i++)
    {
        v[i]=1+rand()%101;
        cout<<"���������Ʒ��ֵ��"<<v[i]<<endl;
    }
    cout<<endl;

    for(int i=1; i<=N; i++)
    {
        w[i]=1+rand()%101;
        sumw+=w[i];
        cout<<"���������Ʒ������"<<w[i]<<endl;
    }
    cout<<endl;

    C=sumw/2;
    cout<<"����������Ϊ:"<<C<<endl;

    s=KnapSack(N,w,v,x,C);

    printf("��̬�滮�����������Ʒ��ֵΪ:\n");
    printf("%d\n",s);


}
