#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define max 1000 //�����Ʒ��
#define random(x)(rand()%x)
using namespace std;


void sort (int n,float a[max],float b[max]) //����ֵ�ܶ�����
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
    float c1; //c1Ϊ����ʣ���װ������
    int i;
    sort(n,v,w); //��Ʒ����ֵ�ܶ�����
    c1=limitw;
    for(i=1;i<=n;i++)
    {
        if(w[i]>c1)
            break;
        x[i]=1; //x[i]Ϊ1ʱ����Ʒi�ڽ���
        c1=c1-w[i];
    }
}
int main()
{
    int n,i,x[max],sumw=0;
    float v[max],w[max],totalv=0,totalw=0,limitw=0;
    cout<<"�����뱳���ܸ���:";
    cin>>n;
    //��Ʒѡ��������ʼ��Ϊ0
    for(i=1;i<=n;i++)
        x[i]=0;
    //���������Ʒ��ֵ
    for(i=1;i<=n;i++)
    {
        v[i]=1+rand()%101;
        cout<<"���������Ʒ��ֵ��"<<v[i]<<endl;
        //limitw+=v[i];
    }
    //���������Ʒ������
    for(i=1;i<=n;i++)
    {
        w[i]=1+rand()%101;
        sumw+=w[i];
        cout<<"���������Ʒ������"<<w[i]<<endl;
    }
    limitw=sumw/2;
    cout<<"����������Ϊ:"<<limitw<<endl;
    //̰���㷨
    knapsack (n,limitw,v,w,x);
    cout<<"����װ�µ���Ʒ���Ϊ��"<<endl;
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
    cout<<"���뱳����������Ϊ��"<<totalw<<endl; //������װ��������
    cout<<"̰���㷨����������ܼ�ֵΪ��"<<totalv<<endl; //�������ܼ�ֵ
}
