class Solution(object):
    def twoSum(self, nums, target):
        mp={}

        for i in range(len(nums)):
            if target-nums[i] in mp:
                return [mp[target-nums[i]],i]
            
            mp[nums[i]]=i
        
        return []