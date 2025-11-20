class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                if(i - mp[1] <= k) {
                    return false;
                }
            }
            if(nums[i] == 1) {
                mp[1] = i;
            }
        }

        return true;
    }
};