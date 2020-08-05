#include <iostream>
using namespace std;
int X,Y;
int price[3];
long m;
void brute_force(int numX,int numY,long sum){
    while(true){
    if(m>sum){
        m=sum;
    }
    if(numX==0){
        if(price[1]>2*price[2]){
            m=m-price[1]*numY+2*price[2]*numY;
        }
        return;
    }else if(numY==0){
        if(price[0]>2*price[2]){
            m=m-price[0]*numY+2*price[2]*numY;
        }
        return;
    }
        numX--;
        numY--;
        sum=sum-price[0]-price[1]+2*price[2];
   // brute_force(numX-1, numY-1,);
    }
}
int main(void){
    for(int i=0;i<3;i++){
        cin>>price[i];
    }
    cin>>X;
    cin>>Y;
    m=price[0]*X+price[1]*Y;
    if(2*price[2]<price[0]&&2*price[2]<price[1]){
        m=2*price[2]*max(X,Y);
    }else{
        brute_force(X,Y,m);
    }
    
    cout<<m<<'\n';
    return 0;
}
