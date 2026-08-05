class Solution {
public:
double solve(double x,long long a){
    if(a==0){
        return 1; 
    }
    double half=solve(x,a/2);
    if(a%2==0){
        return half*half;
    }
    else{
        return half*half*x;
    }
}
    double myPow(double x, int n) {
       long long a=n;
       if(a<0){
        x=1/x;
        a=-a;
       }
       return solve(x,a); 
    }
};