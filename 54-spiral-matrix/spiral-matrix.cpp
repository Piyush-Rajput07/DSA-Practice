class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;

        int sRow = 0, sCol = 0, eRow = m - 1, eCol = n - 1;
        while((sRow <= eRow) && (sCol <= eCol)) { 
            //top
            for(int j=sCol; j<=eCol; j++) {
                ans.push_back(matrix[sRow][j]);
            }
            //right
            for(int i=sRow+1; i<=eRow; i++) {
                ans.push_back(matrix[i][eCol]);
            }
            //bottom
            for(int j=eCol-1; j>=sCol; j--) {
                if(sRow == eRow) {
                    break;
                }
                ans.push_back(matrix[eRow][j]);
            }
            //left
            for(int i=eRow-1; i>=sRow+1; i--) {
                if(sCol == eCol) {
                    break;
                }
                ans.push_back(matrix[i][sCol]);
            }
            //update condns.
            sRow++; eCol--; eRow--; sCol++;
        }
        return ans;
    }
};