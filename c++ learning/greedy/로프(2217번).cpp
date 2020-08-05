//
//  로프(2217번).cpp
//  c++ learning
//
//  Created by 원태희 on 2019/11/24.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
int compare(const void* first, const void* second){
    if(*(int*)first>*(int*)second){
        return 1;
    }else if(*(int*)first<*(int*)second){
        return -1;
    }else{
        return 0;
    }
}
int main(void){
    int N;
    
    scanf("%d",&N);
    int *arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    
    qsort(arr,N,sizeof(int),compare);
    
    int max=arr[N-1];
    for(int i=0;i<N;i++){
        if(max<arr[i]*(N-i))
            max=arr[i]*(N-i);
    }
    printf("%d\n",max);
    return 0;
}
