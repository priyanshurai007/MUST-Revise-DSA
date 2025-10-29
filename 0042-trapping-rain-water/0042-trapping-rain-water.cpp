class Solution {
public:
    int trap(vector<int>& height) {

        //brute force.

        int n=height.size();

        // vector<int> leftMax(n);
        // vector<int> rightMax(n);

        // leftMax[0]=height[0];
        
        // for(int i=1; i<n; i++){
        //     leftMax[i]=max(height[i],leftMax[i-1]);
        // }

        // rightMax[n-1]=height[n-1];

        // for(int i=n-2; i>=0; i--){
        //     rightMax[i]=max(height[i],rightMax[i+1]);
        // }

        // int total=0;
        // for(int i=0; i<n; i++){
        //     if(height[i]<=leftMax[i] && height[i]<=rightMax[i]){
        //         total+=min(leftMax[i],rightMax[i])-height[i];
        //     }
        // }

        // return total;

        //optimal approach.

        int leftMax=0, rightMax=0;
        int l=0,r=n-1;
        int total=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(leftMax>=height[l]){
                    total+=leftMax-height[l];
                }else{
                    leftMax=height[l];
                }
                l++;
            }else{
                if(rightMax>=height[r]){
                    total+=rightMax-height[r];
                }else{
                    rightMax=height[r];
                }
                r--;
            }
        }

        return total;
    }
};