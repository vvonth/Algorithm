#include <iostream>
using namespace std;
int color[3];
int tmp[3];

int main(void){
    int n;
    cin>>n;
    int R,G,B;
    cin>>R>>G>>B;
    color[0]=R;
    color[1]=G;
    color[2]=B;
    for(int i=1;i<n;i++){
        tmp[0]=color[0];
        tmp[1]=color[1];
        tmp[2]=color[2];
        cin>>R>>G>>B;
        color[0]=min(tmp[1],tmp[2])+R;
        color[1]=min(tmp[0],tmp[2])+G;
        color[2]=min(tmp[0],tmp[1])+B;
    }
    cout<<min(color[0], min(color[1], color[2]))<<'\n';
    return 0;
}
