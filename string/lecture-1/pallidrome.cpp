#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
   string orignal=s;
    int start=0;
    int end=s.size()-1;
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
    string s1=s;
    if(s1==orignal){
        cout<<1;
    }
    else{
        cout<<0;
    }
  
    return 0;


}