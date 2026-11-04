class Solution {
public:
    int addDigits(int num) {
        long long sum=0;
        if(num<10){
            return num;
        }
       while(num>=10){
        sum=0;
        while(num>0){
            int r=num%10;
            sum+=r;
            num=num/10;
        }
        num=sum;

       } 
       return sum;
    }
};