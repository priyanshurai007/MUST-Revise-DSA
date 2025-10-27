class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int farthest=0;
        int left=0;
        int right=0;
        int minJump=0;

        while(right<n){
            //find the range of the next window
            for(int i=left; i<=right; i++){
                farthest=max(farthest, i+nums[i]);
            }
            //need minJump+1 to go that window.
            minJump++;
            //next window contain the last index no need to iterate further simply return minJump;
            if(farthest>=n-1) return minJump;
            //maintain the next window.
            left=right+1;
            right=farthest;
        }

        return -1;
    }
};