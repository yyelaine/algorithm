class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int ans = -1000000;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum > ans)
            {
                ans = sum;
            }
            if(sum < 0)
            {
                sum = 0;   //子串和为负数，丢掉
            }
        }
        return ans;
    }
};
