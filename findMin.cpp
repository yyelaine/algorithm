class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int l = 0;  
        int r = num.size()-1;  
        if(num[l]<num[r])  
            return num[l];  
        while(l<r)  
        {  
            int mid = (l+r)/2;  
            if(num[mid]>num[r])  
                l = mid+1;  
            else  
                r = mid;  
        }  
        return num[l];  
    }
};