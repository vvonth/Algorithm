#include<iostream>
#include<set>
using namespace std;

int main(){
    int N;
    int k;
    cin>>N;
    set<int>s;
    for(int i=0;i<N;i++)
    {
        cin>>k;
        s.insert(k);
    }
    for(auto k : s)
    {
        cout<<k<<' ';
    }
    cout<<'\n';
}
