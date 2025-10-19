class Solution {
public:
    bool isPossibleCapacity(vector<int>& weights, int days,int maxAllowedCapacity) {
        int day = 1, weight = 0;
        for(int val : weights) {
            if(weight + val <= maxAllowedCapacity) {
                weight += val;
            }
            else {
                day++;
                weight = val;
            }
        }
        return (day <= days) ? true : false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        int st = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(isPossibleCapacity(weights, days, mid)) { //find less possible weight
                ans = mid;
                end = mid - 1;
            }
            else { //need more weight capacity
                st = mid + 1;
            }   
        }
        return ans;
    }
};