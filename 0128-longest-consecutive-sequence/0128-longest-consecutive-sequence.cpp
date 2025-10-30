class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen=0;

        for(auto num:st){
            if(st.count(num-1)) continue;
            int cur=0;
            while(st.count(num)){
                cur++;
                maxLen=max(cur,maxLen);
                num=num+1;
            }
        }
        return maxLen;
    }
};