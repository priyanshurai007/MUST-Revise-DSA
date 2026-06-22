class Solution {
    public int[][] merge(int[][] intervals) {

        List<int[]> result=new ArrayList<>();
        Arrays.sort(intervals,(a,b)->Integer.compare(a[0],b[0]));

        int s=intervals[0][0];
        int e=intervals[0][1];

        for(int i=1; i<intervals.length; i++){
            int curstart=intervals[i][0];
            int curend=intervals[i][1];

            if(curstart<=e){
                e=Math.max(e,curend);
            }else{
                result.add(new int[] {s,e});
                s=curstart;
                e=curend;
            }
        }
        result.add(new int[]{s,e});

        return result.toArray(new int[result.size()][]);
    }
}