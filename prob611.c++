// https://leetcode.com/problems/valid-triangle-number/description/

// Time Complexity:-O(N^2).
// Space Comlexity:-O(log(n)).
    
// Approach:-
//     In this what we are going to do is that we will initially sort the given array and for each pair of nums[i],
// nums[j] we will found the right most index k such that nums[i] + nums[j] > nums[k] because if this holds true and 
// we whave sorted array so nums[k] is always greater than nums[i] and nums[j] so adding anything to nums[k] would not 
// affect the result. Now here we ware going to optimise the solution by not usinf another loop for finding the k here 
// we are just finding k on the basis of the previous reult because for every increasig pair k will be after to that 
// one which was found earlier so what we will try is to found it from the previous reult ue to which the time 
// complexity changes to O(N^2) from O(N^3).

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        int N=nums.size();
        for(int i=0;i<N-2;i++) {
            int k=i+2;
            for(int j=i+1;j<N-1 && nums[i]!=0;j++) {
                while(k<N && nums[i]+nums[j] > nums[k])
                    k++;
                
                count+=k-j-1;
            }
        }
        
        return count;
    }
};