class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        for(int i=0; i<n-1; i++) {
            int ele = *max_element(arr.begin()+i+1, arr.end());

            arr[i] = ele;
        }
        arr[n-1] = -1;

        return arr;
    }
};