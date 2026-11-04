class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
       long long int y = 0;
        int z=x;
        
        while (x >0) {
            int l = x % 10;
            
         
            y = y * 10 + l;
            x /= 10;
        }
        if(y==z){
            return true;
        } 
        else
        return false;
    }
    

};