class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int first = nums[i];
            int sec = tar - first;

            if(m.find(sec) != m.end()) { //m.find() takes constant time
                ans.push_back(i);
                ans.push_back(m[sec]);
                return ans;
            }
            m[first] = i; //storing val in unord. map
        }
        return ans;
    }
};