class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int sRow = 0, eRow = m - 1, sCol = 0, eCol = n - 1;
        vector<int> ans;

        while(sRow <= eRow && sCol <= eCol) {
            //Top
            for(int i=sCol; i<= eCol; i++) {
                ans.push_back(mat[sRow][i]);
            }
            //Right
            for(int i=sRow+1; i<= eRow; i++) {
                ans.push_back(mat[i][eCol]);
            }
            //Bottom
            for(int i=eCol-1; i>=sCol; i--) {
                if(sRow == eRow) {
                    break;
                }
                ans.push_back(mat[eRow][i]);
            }
            //Left
            for(int i=eRow-1; i>=sRow+1; i--) {
                if(sCol == eCol) {
                    break;
                }
                ans.push_back(mat[i][sCol]);
            }
            //Update condns.
            sRow++; eRow--; sCol++; eCol--;
        }
        return ans;
    }
};