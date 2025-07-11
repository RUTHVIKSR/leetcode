class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        
        int maxi = nums[0];
        int mini = nums[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        if(mini == maxi)
            return 0;

        int b = n-1;
        if(b == 1)
            return maxi - mini;
        int bsize = ((maxi - mini)/b) + 1;
        vector<int> bmin(b, INT_MAX);
        vector<int> bmax(b, INT_MIN);
        vector<bool> bused(b, false);

        for(int x : nums){
            int idx = (x - mini)/bsize;
            bmin[idx] = min(bmin[idx], x);
            bmax[idx] = max(bmax[idx], x);
            bused[idx] = true;
        }
        
        int prevMax = mini;
        int ans = 0;
        for(int i=0;i<b;i++){
            if(bused[i] == false)
                continue;

            int gap = bmin[i] - prevMax;
            ans = max(ans, gap);
            prevMax = bmax[i];
        }
        ans = max(ans, maxi - prevMax);
    
        return ans;
    }
};