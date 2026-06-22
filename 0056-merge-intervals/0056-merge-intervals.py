class Solution(object):
    def merge(self, intervals):

        intervals.sort()

        result=[]
        s=intervals[0][0]
        e=intervals[0][1]

        for i in range(1, len(intervals)):
            curstart=intervals[i][0]
            curend=intervals[i][1]

            if curstart<=e:
                e=max(curend,e)
            else:
                result.append([s,e])
                s=curstart
                e=curend
        
        result.append([s,e])
        
        return result

        