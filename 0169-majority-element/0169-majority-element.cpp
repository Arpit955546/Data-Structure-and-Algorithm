class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int condidate=nums[0];
       int count=1;
       for(int i=1;i<nums.size();i++){
        if(count==0){
        condidate=nums[i];
      }
      if(nums[i]==condidate){
         count++;
      } 
      else{
        count--;
      }
      
       }
      return condidate;
    }
};