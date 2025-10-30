class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        int n=asteroids.size();
        stack<int> st;
        
        for(int i=0; i<n; i++){
            bool alive=true;
            while(alive && asteroids[i]<0 && !st.empty() && st.top()>0){
                if(st.top()==abs(asteroids[i])){
                    alive=false;
                    st.pop();
                }else if(st.top()<abs(asteroids[i])) st.pop();
                else{
                    alive=false;
                }
            }
            if(alive) st.push(asteroids[i]);
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};