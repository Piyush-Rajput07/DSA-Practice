class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, set<vector<int>> &s) {
        if(i == nums.size()) {
            //store subsets in set
            s.insert(ans);
            return;
        }
        //include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, s);

        ans.pop_back();
        //exclude
        getAllSubsets(nums, ans, i+1, s);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        set<vector<int>> s;

        getAllSubsets(nums, ans, 0, s);
        vector<vector<int>> allSubsets(s.begin(), s.end());

        return allSubsets;
    }
};