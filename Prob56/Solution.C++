// Link To Problem:-
// https://leetcode.com/problems/merge-intervals/submissions/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        int k = 0;
        output.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
            if (output[k][1] >= intervals[i][0])
                output[k][1] = max(output[k][1], intervals[i][1]);
            else
            {
                output.push_back(intervals[i]);
                k++;
            }

        return output;
    }
};