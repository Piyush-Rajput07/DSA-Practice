class Solution {
public:
    bool isPossibleSpeed(vector<int>& dist, double hour, int s) {
        int n = dist.size();
        double time = 0;
        for(int i=0; i<n; i++) {
            if(i != n-1) {
                time += ceil((double)dist[i]/s);
            }
            else {
                time += (double)dist[i]/s;
            }
        }
        return (time <= hour) ? true : false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int st = 1, end = 1e7;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(isPossibleSpeed(dist, hour, mid)) { //try to find lower speed
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }
};