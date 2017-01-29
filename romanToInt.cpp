class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        if(s.size()==0)  
            return 0;  
        map<char,int>  cnt;  
        map<char,bool> check;  
        check['I']=true;  
        check['X']=true;  
        check['C']=true;  
        int  sum=0;  
        int  size=s.size();  
        cnt['I']=1;;  
        cnt['X']=10;  
        cnt['C']=100;  
        cnt['M']=1000;  
        cnt['V']=5;  
        cnt['L']=50;  
        cnt['D']=500;  
          
        for(int i=0;i<size;){  
            if(i+1<size&&check[s[i]]&&cnt[s[i]]<cnt[s[i+1]]){  
                sum+=cnt[s[i+1]]-cnt[s[i]];  
                i+=2;  
            }else{  
                sum+=cnt[s[i]];  
                ++i;  
            }      
        }  
        return sum;    
    }
};