class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int zeroCount = 0, maxLen = 0;
        int l = 0, r = 0;

        while(r < n) {
            if(nums[r] != 1) 
                zeroCount++;

            while(l < n && zeroCount > 1) {
                if(nums[l] == 0)    zeroCount--;
                l++;
            }

            maxLen = max(maxLen, r-l);
            r++;
        }
        return maxLen;
    }
};