#include <iostream>

using namespace std;

int main()
{
        string str="abc___";
        if(str.length()<=0)
        return true;
        int charact[128];
        for(int i=0;i<128;i++)
        {
            charact[i]=0;
        }
        int lenth=str.length();
        int index=0;
        for(int i=0;i<lenth;i++)
        {
            index=str[i];
            charact[index]++;
        }
        for(int j=0;j<128;j++)
        {
            if(charact[j]>1)
            {

                cout<<"chongfu"<<endl;
                return false;
                break;
            }
        }
        return true;
}
