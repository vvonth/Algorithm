#include <stdio.h>
typedef struct tri{
    struct tri *child[10];
    char data;
    int isEnd;
}trie;

trie tr[1200];
int p_cnt=1;
int recur(trie* try,char *s){
    int collision=1;
    if(try->isEnd==1)
        return 1;
    if(try->child[*s-'0']==NULL){
        try->child[*s-'0']=&tr[p_cnt++];
        try->child[*s-'0']->data=*s-'0';
        collision=0;
    }
    if(*(s+1)=='\0'){
        try->isEnd=1;
        return collision;
    }
    return collision*recur(try->child[*s-'0'],s+1);
}

int main(void){
    int t;
    int flag=0;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        for(int i=0;i<1200;i++){
        }
        flag=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char s[11];
            scanf(" %s",s);
            if(recur(&tr[0],s)==1)
                flag=1;
        }
        if(flag)
            printf("NO\n");
        else{
            printf("YES\n");
        }
    }
    return 0;
}

