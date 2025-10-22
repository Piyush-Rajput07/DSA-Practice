class Solution {
public:
    bool canAssign(int i, vector<int>& jobs, vector<int>& workers, int maxAllowedTime) {
        if(i == jobs.size()) return true;
        
        for(int w=0; w<workers.size(); w++) {
            if(workers[w]+jobs[i] <= maxAllowedTime) {
                workers[w] += jobs[i];

                if(canAssign(i+1, jobs, workers, maxAllowedTime)) 
                    return true;
                
                workers[w] -= jobs[i];

                if(workers[w] == 0) break;
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int sum = 0, ans = 0;
        for(int val : jobs) {
            sum += val;
        }

        int st = *max_element(jobs.begin(), jobs.end());
        int end = sum;

        while(st <= end) {
            int mid = st + (end-st)/2;
            vector<int> workers(k, 0);

            if(canAssign(0, jobs, workers, mid)) {
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