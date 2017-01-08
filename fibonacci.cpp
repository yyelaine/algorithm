#include <iostream>

using namespace std;


int fibonacci(int n) {
        // write your code here
        int Array[n];
        //int sum=0;
        for(int j=0;j<n;j++)
        {
                if(j==0)
                Array[0]=0;
                if(j==1)
                Array[1]=1;
                if(j>=2)
                    {
                    Array[j]=Array[j-1]+Array[j-2];
                    cout<<Array[j]<<endl;
                    }
        }
        return Array[n-1];
    }

int main()
{
    int result = fibonacci(5);
    cout<<result<<endl;
}
