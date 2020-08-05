#include <iostream>
#include <vector>
using namespace std;
long long arr[100];

int N;
bool result;
bool chk[100];

bool compare(pair<pair<int,int>,long long> &a, pair<pair<int,int>,long long>&b){
    if(a.first.first==b.first.first){
        return a.first.second<b.first.second;
    }
    return a.first.first>b.first.first;
}
int main(void){
    cin>>N;
    vector<pair<pair<int,int>,long long>> v(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        long long value=arr[i];
        while(arr[i]>0){
            if(arr[i]%3==0){
                arr[i]/=3;
                v[i].first.first++;
                //cout<<"arr[i]: "<<arr[i]<<' '<<"3나누기: "<<v[i].first.first<<'\n';
            }else{
                arr[i]/=2;
                v[i].first.second++;
            }
        }
        v[i].second=value;
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<N;i++){
        cout<<v[i].second<<' ';
    }
    cout<<'\n';
    return 0;
}

