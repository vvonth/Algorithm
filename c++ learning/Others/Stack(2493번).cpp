//
//  Stack(2493번).cpp
//  c++ learning
//
//  Created by 원태희 on 13/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <cstdio>
#include<cstdlib>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node*root;

struct node ** search(struct node **toLook,int num);
void insertTree(struct node **toInsert,int num);
void deleteTree(struct node **toDelete);
void freeAll(struct node*toFree);

int main()
{
   int menuSelect;
    int num;
    struct node **where;
    while(1){
        puts("1.insert");
        puts("2.delete");
        puts("3.search");
        puts("4.end program");
        scanf("%d",&menuSelect);
        switch(menuSelect){
            case 1:
                puts("insert num");
                scanf("%d",&num);
                if(*(where=search(&root,num))){
                    puts("The number is already in the tree");
                    break;
                }
                insertTree(where,num);
                break;
            case 2:
                puts("delete num");
                scanf("%d",&num);
                if(*(where=search(&root,num))){
                    deleteTree(where);
                }
                else{
                    puts("there is no such num");
                }
                break;
            case 3:
                puts("search num");
                scanf("%d",&num);
                if(*(search(&root,num))){
                    puts("the number exists");
                }
                else{
                    puts("there is no such number");
                }
                break;
            case 4:
                freeAll(root);
                return 0;
        }
    }
}
struct node ** search(struct node **toLook,int num){
    if(*toLook==0||(*toLook)->data==num)
        return toLook;
    if((*toLook)->data>num)
        return &(*toLook)->left;
    return &(*toLook)->right;
}
void insertTree(struct node **toInsert,int num){
    struct node*where;
    where=*toInsert=(struct node*)malloc(sizeof(struct node));
    where->left=where->right=0;
    where->data=num;
}
void deleteTree(struct node **toDelete){
    struct node *left,*right,**to;
    if(*toDelete==0)
        return;
    left=(*toDelete)->left;
    right=(*toDelete)->right;
    if(left!=0&&right!=0){
        for(to=&right->left;*to;to=&(*to)->left);
        *to=left;
        free(*toDelete);
        *toDelete=right;
        return;
    }
    free(*toDelete);
    if(left==0){
        *toDelete=right;
    }
    else{
        *toDelete=left;
    }
}
    
void freeAll(struct node*toFree){
    if(toFree==0)
        return;
    freeAll(toFree->left);
    freeAll(toFree->right);
    free(toFree);
}

