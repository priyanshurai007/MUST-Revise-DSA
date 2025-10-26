class Solution {
public:
    bool checkValidString(string s) {
        //brute force -> recursion+dp approach.
        int low=0; //minimum no. of open paranthesis.
        int high=0; //maximum no. of open paranthesis.

        for(auto c: s){
            if(c=='('){
                low++;
                high++;
            }else if(c=='*'){ //take range of possibily by assumin empty,(,)
                low--;
                high++;
            }else{
                low--;
                high--;
            }
            low=max(low,0);
            if(high<0) return false;
        }

        return low==0;
    }
};