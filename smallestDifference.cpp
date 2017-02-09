class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int ret = INT_MAX;  
        sort(B.begin(),B.end());  
        for(int i=0;i<A.size();i++)  
        {  
            int diff = lower_bound(B.begin(),B.end(),A[i])-B.begin();  
            ret = min(ret,abs(A[i]-B[diff]));  
            if(diff>0)  
                ret = min(ret,abs(A[i]-B[diff-1]));  
            if(diff+1<B.size())  
                ret = min(ret,abs(A[i]-B[diff+1]));  
        }  
        return ret;  
    }
};
