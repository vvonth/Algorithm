#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<string> v;
    string s;
    for(scanf("%d",&n);n>0;n--)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),[](string u, string v){
        //return make_pair(u.size(), u)<make_pair(v.size(), v);
        if(u.size()==v.size())
            return u<v;
        else
           return u.size()<v.size();
    });
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto x : v)
        cout<<x<<'\n';
}
