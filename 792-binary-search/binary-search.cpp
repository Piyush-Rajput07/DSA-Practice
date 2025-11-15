class Solution {
public:
    int binSearch(vector<int>& arr, int tar, int st, int end) {
        if(st > end) {
            return -1;
        }
        int mid = st + (end - st)/2;

        if(arr[mid] == tar) {
            return mid;
        }
        else if(arr[mid] < tar) {
            return binSearch(arr, tar, mid + 1, end);
        }
        else {
            return binSearch(arr, tar, st, mid - 1);
        }
    }

    int search(vector<int>& arr, int tar) {
        int st = 0, end = arr.size() - 1;
        
        return binSearch(arr, tar, st, end);
    }
};