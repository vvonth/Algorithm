//
//  vector(2920번).cpp
//  c++ learning
//
//  Created by 원태희 on 08/11/2018.
//  Copyright © 2018 원태희. All rights reserved.
//

#include<vector>
#include<cstdio>
using namespace std;
int ascend(vector<int>&);//선언!!!!
int descend(vector<int>&);
int main()
{   int n;
    vector<int> v;
    v.reserve(8);//크기 지정
    for(int i=0;i<8;i++)
    {scanf("%d", &n);
        v.push_back(n);
    }
    if(ascend(v))
    {
        printf("ascending");
    }
    else if(descend(v))
    {
        printf("descending");
    }
    else
        printf("mixed");
    printf("%d",ascend(v));
    printf("%d",descend(v));
}
int ascend(vector<int>& v)//매개변수 넘길때!
{
    for(int i=0;i<8;i++)
    {
        if(v.at(i)!=i+1)
            return 0;
        
    }
    return 1;
}
int descend(vector<int>& v)
{
    int j=0;
    for(int i=8;i>0;i--)
    { if(v.at(j)!=i)
        return 0;
        j++;
    }
    return 1;
}

