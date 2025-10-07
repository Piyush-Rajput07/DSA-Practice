class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++) {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end());
        int st = 0, end = n - 1;

        while((st <= end) && (st != end)) {
            if(vec[st].first + vec[end].first == target) {
                res.push_back(vec[st].second);
                res.push_back(vec[end].second);
                return res;
            }
            else if(vec[st].first + vec[end].first < target) {
                st++;
            }
            else {
                end--;
            }
        }
        return res;
    }
};