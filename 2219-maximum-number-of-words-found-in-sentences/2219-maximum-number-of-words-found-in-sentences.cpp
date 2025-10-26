class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int maxi=0;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<sentences[i].size(); j++){
                while(j<sentences[i].size() && sentences[i][j]!=' '){
                    j++;
                }
                cnt++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};