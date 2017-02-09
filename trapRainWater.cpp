class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
         int ret = 0;  
        if(heights.size()==0)  
            return ret;  
        int lmax = 0, rmax = 0;  
        int l = 0, r = heights.size()-1;  
        while(l<r)  
        {  
            lmax = max(lmax,heights[l]);  
            rmax = max(rmax,heights[r]);  
            if(lmax<rmax)  
                ret += lmax-heights[l],l++;  
            else  
                ret += rmax-heights[r],r--;  
        }  
        return ret;  
    }
};