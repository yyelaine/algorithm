#include <iostream>
#include <string>

using namespace std;

int main()
{   string A="AABCD";
    string B="ACD";
    int Acharact[26];
    int Bcharact[26];
    for(int i=0;i<26;i++)
    {
        Acharact[i]=0;
        Bcharact[i]=0;
    }
    int Alenth=A.length();
    int Blenth=B.length();
    int index=0;
    for(int i=0;i<Alenth;i++)
    {
        index=A[i]-65;
        Acharact[index]++;
    }
    for(int i=0;i<Blenth;i++)
    {
        index=B[i]-65;
        Bcharact[index]++;
    }
    for(int j=0;j<26;j++)
    {
        if(Bcharact[j]>Acharact[j])
            return false;
        if(j==25)
            return true;
    }
}
