#include<iostream>
using namespace std;
int defanging(string &s){
    int n=s.size();
    int index=0;
    string ans;
    while(index<n){
        if(s[index]=='.'){
            ans+="[.]";
        }
        else{
            ans+=s[index];
        }
        index++;
    }
 cout<<ans;
 return 0;
}
int main(){
    string n;
    cout<<"enter an IP address"<<endl;
    cin>>n;
    defanging(n);
}