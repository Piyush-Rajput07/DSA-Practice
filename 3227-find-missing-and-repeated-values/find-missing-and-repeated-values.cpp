class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        set<int> values;
        int currSum = 0;
        vector<int> ans;

        int dupVal;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                currSum += grid[i][j];

                if(values.find(grid[i][j]) != values.end()) {
                    ans.push_back(grid[i][j]);
                    dupVal = grid[i][j];
                }
                else {
                    values.insert(grid[i][j]);
                }
            }
        }
        int expSum = n*n*((n*n)+1)/2;
        int missingNo = expSum - (currSum - dupVal); 
        ans.push_back(missingNo);

        return ans;
    }
};