#include <iostream>
#include <string.h>
using namespace std;

int main()
{
        int nums[4]={1,2,3,4};
        int len=sizeof(nums);
        cout<<len<<endl;
        int num1[len];
        //int num2[len];
        //int num3[len+2];
        //if(len<=1)
            //return nums;
        for(int i=0;i<len;i++)
        {
            if(nums[i]%2==1)//ÎªÆæÊý
            {
                for(int j=0;j<len;j++)
                {
                    num1[j]=nums[i];
                }
            }
        }
        int temp=sizeof(num1);
        for(int i=0;i<len;i++)
        {
            if(nums[i]%2!=1)
            {
                for(int n=temp;n<len;n++)
                {
                    num1[n]=nums[i];
                }
            }
        }
        //return num1;


        //memcpy(num3,num1,sizeof(num1));
        //memcpy(num3+sizeof(num1),num2,sizeof(num2));
        for(int i=0;i<len;i++)
            cout<<num1[i]<<endl;

}
