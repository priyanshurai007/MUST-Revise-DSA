class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            char charS=s[i];
            char charT=t[i];
            mp[charS]++;
            mp[charT]--;
        }

        for(auto it:mp){
            if(it.second!=0) return false;
        }
        return true;
    }
};