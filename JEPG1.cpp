#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath.h>
#include <memory.h>

using namespace std;
const int NUM=8;
const double PI=3.1415926;
void DCT(short input[NUM][NUM])
{
    int i,j,p,q;
    short output[NUM[NUM];
    double cu,cv;
    for(p=0; p<NUM; p++)
    {
        for(q=0; q<NUM; q++)
        {
            if(p==0)
                cu=1.0/sqrt(2);
            else
                cu=1;
            if(q==0)
                cv=1.0/sqrt(2);
            else
                cv=1;

            double temp=0.0;
            for(i=0; i<NUM; i++)
            {
                for(j=0; j<NUM; j++)
                {
                    temp+=input[i][j]*cos((2*i+1)*p*PI/16)*cos((2*j+1)*q*PI/16);
                }
            }

            output[p][q]=0.25*cu*cv*temp;
        }
    }
    cout<<"变换后数据为:"<<endl;
    PRINT(output);
    cout<<endl;
    memset(input,0,NUM*NUM*sizeof(short));
    memcpy(input,output,NUM*NUM*sizeof(short));
}
void IDCT(short input[NUM][NUM])
{
    int i,j,p,q;
    short output[NUM[NUM];
    double cu,cv;
    for(i=0; i<NUM; i++)
    {
        for(j=0; j<NUM; j++)
        {
            double temp=0.0;
            for(p=0; p<NUM; p++)
            {
                for(q=0; q<NUM; q++)
                {
                    if(p==0)
                        cu=1.0/sqrt(2);
                    else
                        cu=1;
                    if(q==0)
                        cv=1.0/sqrt(2);
                    else
                        cv=1;
                    temp+=cu*cv*input[p][q]*cos((2*i+1)*p*PI/16)*cos((2*j+1)*q*PI/16);
                }
            }
            output[i][j]=0.25*temp;
        }
    }
    cout<<"反变换数据为:"<<endl;
    PRINT(output);
    cout<<endl;
    memset(input,0,NUM*NUM*sizeof(short));
    memcpy(input,output,NUM*NUM*sizeof(short));
}


void QUAN(short input[NUM][NUM])
{
    short quantable[NUM][NUM] =
    {
        {16,11,10,16,24,40,51,61},
        {12,12,14,19,26,58,60,55},
        {14,13,16,24,40,57,69,56},
        {14,17,22,29,51,87,80,62},
        {18,22,37,56,68,109,103,77},
        {24,35,55,64,81,104,113,92},
        {49,64,78,87,103,121,120,101},
        {72,92,95,98,112,100,103,99}
    };
    cout<<"色差量化表为："<<endl;
    PRINT(quantable);
    cout<<endl;
    short output[NUM][NUM];
    for(i=0;i<NUM;i++)
    {
        for(j=0;j<NUM;j++)
        {
            output[i][j]=short round(input[i][j]/quantable[i][j]);
        }
    }
    cout<<"量化后的数据为："<<endl;
    PRINT(output);
    cout<<endl;
    memset(input,0,NUM*NUM*sizeof(short));
    memcpy(input,output,NUM*NUM*sizeof(short));
}

void NIQUAN(short input[NUM][NUM])
{
    short quantable[NUM][NUM] =
    {
        {16,11,10,16,24,40,51,61},
        {12,12,14,19,26,58,60,55},
        {14,13,16,24,40,57,69,56},
        {14,17,22,29,51,87,80,62},
        {18,22,37,56,68,109,103,77},
        {24,35,55,64,81,104,113,92},
        {49,64,78,87,103,121,120,101},
        {72,92,95,98,112,100,103,99}
    };
    short niquantable[NUM][NUM];
    for(i=0;i<NUM;i++)
    {
        for(j=0;j<NUM;j++)
        {
            output[i][j]=short round(input[i][j]*quantable[i][j]);
        }
    }
    cout<<"反量化后的数据为："<<endl;
    PRINT(output);
    cout<<endl;
    memset(input,0,NUM*NUM*sizeof(short));
    memcpy(input,output,NUM*NUM*sizeof(short));
}

void PRINT(short input[NUM][NUM])
{
    short p,q,i,j;
    for(p=0; p<NUM; p++)
    {
        for(q=0; q<NUM; q++)
            cout<<input[p][q]<<'\t';
        cout<<endl;
    }
}

int main()
{
    short p,q,i,j;
    short input[NUM][NUM] =
    {
        {98, 156, 96, 99, 156, 161, 161, 166},
        {94, 95, 95, 96, 98, 160, 161, 167},
        {95, 94, 91, 94, 157, 163, 169, 166},
        {141, 92, 143, 94, 143, 143, 140, 87},
        {127, 124, 123, 74, 72, 73, 72, 111},
        {90, 61, 106, 93, 58, 54, 77, 49},
        {106, 72, 74, 73, 74, 74, 111, 70},
        {77, 127, 85, 89, 87, 154, 162, 166}
    };
    cout<<"原始数据为:"<<endl;
    PRINT(input);
    cout<<endl;
    cout<<endl;
    for(p=0; p<NUM; p++)
    {
        for(q=0; q<NUM; q++)
            input[p][q]-=128;
    }
    DCT(input);
    QUAN(input);
    NIQUAN(input);
    IDCT(input);
    system("pause");
    return 0;
}


