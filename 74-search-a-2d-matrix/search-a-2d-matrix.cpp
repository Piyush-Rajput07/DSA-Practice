class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();

        int st = 0, end = n - 1;
        while(st <= end) {
            int mid = st + (end - st)/2;

            if(target == matrix[row][mid]) {
                return true;
            } else if(target < matrix[row][mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        //BS on rows
        int startRow = 0, endRow = m - 1;
        while(startRow <= endRow) {
            int midRow = startRow + (endRow - startRow)/2;

            if((target >= matrix[midRow][0]) && (target <= matrix[midRow][n-1])) {
                //BS on midRow
                return searchInRow(matrix, target, midRow);

            } else if(target < matrix[midRow][0]) {
                //top => left
                endRow = midRow - 1;
            } else {
                //bottom => right
                startRow = midRow + 1;
            }
        }
        return false;
    }
};