class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int oddCount = 0, result = 0;
        mp[0] = 1; //we have seen 0 oddCount once 

        for(int i=0; i<nums.size(); i++) {
            oddCount += (nums[i]%2);

            if(mp.find(oddCount - k) != mp.end()) {
                result += mp[oddCount - k];
            }
            mp[oddCount]++;
        }
        return result;
    }
};