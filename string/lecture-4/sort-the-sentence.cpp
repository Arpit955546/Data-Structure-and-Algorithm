#include<iostream>
#include<vector>
using namespace std;
void reorder(string s){
vector <string> ans(10);
    string temp;
    int count=0;
    int index=0;
    while(index<s.size()){
        if(s[index]==' '){
            int pos=temp[temp.size()-1]-'0';
            temp.pop_back();
            ans[pos]=temp;
            temp.clear();
            count++;
        }
        else{
            temp=temp+s[index];
        }
        index++;
    }
       int pos=temp[temp.size()-1]-'0';
            temp.pop_back();
            ans[pos]=temp;
            temp.clear();
            count++;
    for(int i=1;i<=count;i++){
        temp=temp+ans[i];
        temp=temp+' ';
    } 
    temp.pop_back();
    cout<<temp;
}
int main(){
    string s;
    cout<<"enter a string ";
    getline(cin,s);
    reorder(s);
    return 0;
}