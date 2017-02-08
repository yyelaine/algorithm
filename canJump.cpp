class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int maxN = 0; //记录能走的最大步数  
            int i = 0;    //记录当前走到第几个元素    
            while(i<=maxN)  //能走的最大步数都不能到达当前元素 循环终止    
            {    
                maxN = max(maxN,i+A[i]);   //随时更新能走的最大步数  
                ++i;                      //每次往前走一步  
                if(maxN>=A.size()-1)    
                    return true;    
            }    
            return false; 
    }
};
