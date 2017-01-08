#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define random(x)(rand()%x)
using namespace std;
class Knap
{
	friend int Knapsack(int p[],int w[],int c,int n );
    public:
      void print()
	   {
		   for(int m=1;m<=n;m++)

		   {
			   cout<<bestx[m]<<" ";
		   }
		   cout<<endl;
	  };
private:
       int Bound(int i);
       void Backtrack(int i);
       int c;//��������
       int n; //��Ʒ��
       int *w;//��Ʒ��������
       int *p;//��Ʒ��ֵ����
       int cw;//��ǰ����
       int cp;//��ǰ��ֵ
       int bestp;//��ǰ����ֵ
	   int *bestx;//��ǰ���Ž�
       int *x;//��ǰ��
};
int Knap::Bound(int i)
{

 //�����Ͻ�

       int cleft=c-cw;//ʣ������
       int b=cp;
   //����Ʒ��λ������ֵ�ݼ���װ����Ʒ
    while(i<=n&&w[i]<=cleft)
	{
		cleft-=w[i];
          b+=p[i];
		  i++;
	}
	//װ������
    if(i<=n)
       b+=p[i]/w[i]*cleft;
        return b;
}
void Knap::Backtrack(int i)
{
	if(i>n)
	{
		if(bestp<cp)
		{
			for(int j=1;j<=n;j++)
				bestx[j]=x[j];
			bestp=cp;
		}
		return;
	}
	if(cw+w[i]<=c) //����������
	{
		x[i]=1;
		cw+=w[i];
         cp+=p[i];
         Backtrack(i+1);
         cw-=w[i];
         cp-=p[i];
	}
	if(Bound(i+1)>bestp)//����������
    {
		x[i]=0;
		Backtrack(i+1);
	}
}
class Object
{
	friend int Knapsack(int p[],int w[],int c,int n);
    public:
       int operator<=(Object a)const
       {
		   return (d>=a.d);
       }
	private:
       int ID;
       float d;
};
int Knapsack(int p[],int w[],int c,int n)
{
 //ΪKnap::Backtrack��ʼ��
       int W=0;
       int P=0;
       int i=1;
       Object *Q=new Object[n];
       for(i=1;i<=n;i++)
       {
            Q[i-1].ID=i;
            Q[i-1].d=1.0*p[i]/w[i];
            P+=p[i];
            W+=w[i];
       }
       if(W<=c)
              return P;//װ��������Ʒ
       //����Ʒ��λ��������
       float f;
       for( i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
         if(Q[i].d<Q[j].d)
         {
           f=Q[i].d;
           Q[i].d=Q[j].d;
           Q[j].d=f;
         }
        }
       Knap  K;
       K.p = new int[n+1];
       K.w = new int[n+1];
       K.x = new int[n+1];
       K.bestx = new int[n+1];
       K.x[0]=0;
       K.bestx[0]=0;
       for( i=1;i<=n;i++)
       {
            K.p[i]=p[Q[i-1].ID];
            K.w[i]=w[Q[i-1].ID];
       }
       K.cp=0;
       K.cw=0;
       K.c=c;
       K.n=n;
       K.bestp=0;
       //��������
       K.Backtrack(1);
       K.print();
       delete [] Q;
       delete [] K.w;
       delete [] K.p;
       return K.bestp;
}
int main()
{
	int *p;
    int *w;
    int c=0,sumw=0;
	int n=0;
    int i=0;
    cout<<"�����뱳���ܸ���:"<<endl;
    cin>>n;
       p=new int[n+1];
       w=new int[n+1];
       p[0]=0;
       w[0]=0;

       for(i=1;i<=n;i++)
    {
        p[i]=1+rand()%101;
        cout<<"���������Ʒ��ֵ��"<<p[i]<<endl;
        //limitw+=v[i];
    }
    //���������Ʒ������

    for(i=1;i<=n;i++)
    {
        w[i]=1+rand()%101;
        sumw+=w[i];
        cout<<"���������Ʒ������"<<w[i]<<endl;
    }
    c=sumw/2;
    cout<<"����������Ϊ:"<<c<<endl;
    cout<<"����װ�µ���Ʒ���Ϊ��"<<endl;
    cout<<"���ݷ��������ܼ�ֵΪ:"<<Knapsack(p,w,c,n)<<endl;
}

