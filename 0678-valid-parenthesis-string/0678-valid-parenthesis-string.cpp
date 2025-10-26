class Solution {
public:
    bool checkValidString(string s) {
        int low=0;
        int high=0;
        for(auto c:s){
            if(c=='('){
                low++;
                high++;
            }else if(c=='*'){
                low--;
                low=max(low,0);
                high++;
            }else{
                high--;
                low--;
                low=max(low,0);
                if(high<0) return false;
            }
        }
        return low==0;
    }
};