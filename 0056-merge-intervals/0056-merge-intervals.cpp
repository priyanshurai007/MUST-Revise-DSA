class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        int s=intervals[0][0];
        int e=intervals[0][1];

        for(int i=1; i<n; i++){
            int curstart=intervals[i][0];
            int curend=intervals[i][1];

            if(curstart<=e){
                e=max(e,curend);
            }else{
                res.push_back({s,e});
                s=curstart;
                e=curend;
            }
        }
        res.push_back({s,e});
        return res;
    }
};