class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int sum = 0;
        mp[0] = -1; //for edge case, like arr 1 2 3

        for(int i=0; i<n; i++) {
            sum += nums[i];

            int rem = sum%k;

            //checking if it's present in the map
            if(mp.find(rem) != mp.end()) {
                
                if(i - mp[rem] >= 2) {
                    return true;
                }

            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};