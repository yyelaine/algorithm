class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int ret = 0;  
        int r = heights.size()-1;  
        int l = 0;  
        while (l < r)  
        {  
            ret = max(ret,min(heights[l],heights[r])*(r-l));  
            if(heights[l]<heights[r])  
                l++;  
            else   
                r--;  
        }  
        return ret;  
    }
};