#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int > v;
    v.push_back(50);
    v.push_back(500);
    v.push_back(5000);
    v.push_back(50000);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    int y=v.capacity();
    cout<<y;




}