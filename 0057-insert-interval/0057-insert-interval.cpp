class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //intution three case possible non-overlap || overlap || non-overlap

        int n=intervals.size();
        vector<vector<int>> result;
        if(n==0) return {newInterval};

        for(int i=0; i<n; i++){
            while(i<n && intervals[i][1]<newInterval[0]){
                result.push_back(intervals[i]);
                i++;
            }

            //overlapping found lets maintain the new interval till overlapping.
            //overlapping tabtak rahegi jabtak ith start<=newIntervalend milta rahega.
            while(i<n && intervals[i][0]<=newInterval[1]){
                newInterval[0]=min(intervals[i][0], newInterval[0]);
                newInterval[1]=max(intervals[i][1], newInterval[1]);
                i++;
            }
            result.push_back({newInterval[0],newInterval[1]});

            while(i<n){
                result.push_back(intervals[i]);
                i++;
            }
        }

        return result;
    }
};