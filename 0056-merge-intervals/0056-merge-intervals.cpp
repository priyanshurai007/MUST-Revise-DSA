class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());

        int s=intervals[0][0];
        int e=intervals[0][1];
        for(int i=1; i<n; i++){
            int curstart=intervals[i][0];
            int curend=intervals[i][1];

            if(curstart<=e){
                e=max(curend,e);
            }else{
                result.push_back({s,e});
                s=curstart;
                e=curend;
            }
        }
        result.push_back({s,e});
        return result;
    }
};