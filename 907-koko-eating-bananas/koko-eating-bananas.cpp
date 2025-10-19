class Solution {
public:
    bool isPossibleSpeed(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for(int val : piles) {
            hours += (val + k - 1)/k; //ceil value -> ceil(val/k)
        }
        return (hours <= h) ? true : false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, end = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(isPossibleSpeed(piles, h, mid)) { //try to find lower speed than this
                ans = mid;
                end = mid - 1;
            }
            else { //needs more speed
                st = mid + 1;
            }
        }
        return ans;
    } 
};