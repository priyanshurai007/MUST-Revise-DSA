class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;
        for(int i=0; i<n; i++){
            
            if(i>farthest) return false; //you can't able to reach i and it must be early — this is essential to detect “stuck” zones like [3,2,1,0,4].
            farthest=max(farthest,i+nums[i]); //do not move this statement to upwards from above statements.
            if(farthest>=n-1) return true;

        }

        return false;
    }
};