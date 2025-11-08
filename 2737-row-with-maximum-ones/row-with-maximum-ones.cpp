class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int maxCount = INT_MIN;
        int maxRowIdx = -1;

        for(int i=0; i<rows; i++) {
            int count = 0;
            for(int j=0; j<cols; j++) {
                if(mat[i][j] == 1)  count++;

                if(count > maxCount) {
                    maxCount = count;
                    maxRowIdx = i;
                }
            }
        }
        return {maxRowIdx, maxCount};
    }
};