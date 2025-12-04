class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int farthest=0;
        int left=0;
        int right=0;
        int minJump=0;

        for(int i=0; i<n; i++){
            for(int k=left; k<=right; k++){
                farthest=max(farthest,k+nums[k]);
            }

            minJump++;

            if(farthest>=n-1) return minJump;

            left=right++;
            right=farthest;
        }
        return minJump;
    }
};