#include <iostream>

using namespace std;

int main()
{
        int nums[7]={1,1,1,1,2,2,2};
        if(!nums.empty())
        return NULL;
        int len=sizeof(nums);
        int number[10];
        int index=0;
        int temp=0;
        for(int i=0;i<10;i++)
        {
            number[i]=0;
        }
        for (int i=0;i<len;i++)
        {
            index=nums[i];
            number[i]++;
        }
        for(int j=0;j<10;j++)
        {
            if(number[j]>0.5*len)
            {
                return j;
            }
        }
}
