#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    int m=0;
    
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    do{
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=abs(v.at(i-1)-v.at(i));
        }
        m=max(m,sum);
    }while(next_permutation(v.begin(), v.end()));
    printf("%d",m);
}
