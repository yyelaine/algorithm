class Solution {  
public:  
    /** 
     * @param prices: Given an integer array 
     * @return: Maximum profit 
     */  
    int maxProfit(vector<int> &prices) {  
        // write your code here  
        int n = prices.size();  
        if (n <= 1) return 0;  
        vector<int> trans;  
        for (int i = 1; i <= n; i++)  
            trans.push_back(prices[i] - prices[i-1]);  
        int imax = 0, res = 0;  
        for(int i = 0; i < n-1; i++){  
            imax += trans[i];  
            if (imax > res) res = imax;  
            else if(imax < 0) imax = 0;  
        }  
        return res;  
    }  
};  