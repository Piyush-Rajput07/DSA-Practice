class Solution {
public:
    bool isPossible(vector<int>& position, int m, int maxAllowedDist) {
        int balls = 1, pos = position[0];
        for(int i=0; i<position.size(); i++) {
            if(position[i] - pos >= maxAllowedDist) {
                balls++;
                pos = position[i];
            }
        }
        return (balls >= m) ? true : false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int st = 1, end = *max_element(position.begin(), position.end()) - *min_element(position.begin(), position.end());
        int ans = end;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(isPossible(position, m, mid)) { //right
                ans = mid;
                st = mid + 1;
            }
            else { //left
                end = mid - 1;
            }
        }
        return ans;
    }
};