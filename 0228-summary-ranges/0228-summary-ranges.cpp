class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<string> result;
        while(i<n){
            int s=nums[i];
            while(i+1<n && nums[i]+1==nums[i+1]){
                i++;
            }
            int e=nums[i];
            if(s==e){
                result.push_back(to_string(s));
            }else{
                result.push_back(to_string(s)+"->"+to_string(e));
            }
            i++;
        }
        return result;
    }
};