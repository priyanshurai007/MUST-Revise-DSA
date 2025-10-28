class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();

        /*intution :  
            We need to satisfy both left and right neighbor constraints.
            That’s like having two rules running in opposite directions:
            Left → Right: each higher-rated child than the left neighbor gets +1 more candy.
            Right → Left: each higher-rated child than the right neighbor gets +1 more candy.
            So you must take the max of both for the final candy distribution to each child
        */

        //brute force.

        // vector<int> left(n);
        // vector<int> right(n);
        // left[0]=1;
        // right[n-1]=1;

        // //first distribute the left way along.
        
        // for(int i=1; i<n; i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]=left[i-1]+1;
        //     }else{
        //         left[i]=1;
        //     }
        // }

        // //second distribut the right way along.

        // for(int i=n-2; i>=0; i--){
        //     if(ratings[i]>ratings[i+1]){
        //         right[i]=right[i+1]+1;
        //     }else{
        //         right[i]=1;
        //     }
        // }

        // //take the max of both as you have to satisfy both the left and right way. as we already distributed the in minimum way so there will be no problem.

        // int sum=0;
        // for(int i=0; i<n; i++){
        //     sum+=max(left[i],right[i]);
        // }

        // return sum;

        /*
           Intution: for optimal way is slope based.
        */

        int sum=1; //as i am moving from the second i=1 element
        int i=1;

        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }

            int peak=1;

            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }

            int down=1;

            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }

            if(down>peak){
                sum+=down-peak;
            }
        }

        return sum;
    }
};