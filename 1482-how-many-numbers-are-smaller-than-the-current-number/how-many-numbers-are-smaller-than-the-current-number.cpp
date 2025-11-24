class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> first;
        for(int i=0; i<n; i++) {
            if(!first.count(temp[i])) {
                first[temp[i]] = i;
            }
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = first[nums[i]];
        }

        return ans;
    }
};