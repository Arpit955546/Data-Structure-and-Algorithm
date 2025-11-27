#include<iostream>
using namespace std;
void rotate(string &s,int &k){
    int n=s.size();//calculating the size of string
    
    for(int j=0;j<k;j++){//k times rotaion
        char c=s[n-1];
   for(int i=n-1; i>0; i--){ // shift right
        s[i] = s[i-1];//shift right by 1
    }
    s[0]=c;
}
    cout<< s;//print the string
} 
int main(){
    string n;
    int m;
    cout<<"number of rotation"<<endl;
    cin>>m;

    cout<<"enter a string"<<endl;
    cin>>n;
   rotate(n,m);//calling the function
}