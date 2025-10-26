class Solution {
public:
vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> result;
    int i = 0;

    while (i < n) {
        int start = nums[i];
        // move until the numbers stop being consecutive
        while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
            i++;
        }
        int end = nums[i];

        // create range string
        if (start == end)
            result.push_back(to_string(start));
        else
            result.push_back(to_string(start) + "->" + to_string(end));

        i++; // move to the next new range
    }

    return result;
}
};