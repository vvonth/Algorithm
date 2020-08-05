#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(void){
    vector<char>v;
    string text;
    string sub;
    cin>>sub>>text;
    deque<char>left;
    deque<char>right;
    int start=0;
    int last=text.length()-1;
    while(start<=last){
        while(start<=last){
            left.push_back(text[start++]);
            if(left.size()>=sub.size()){
                bool check=false;
                for(int i=0;i<sub.size();i++){
                    check=true;
                    if(left[left.size()-sub.size()+i]!=sub[i]){//abcd
                        check=false;
                        break;
                    }
                }
                if(check){
                    for(int i=0;i<sub.size();i++){
                        left.pop_back();
                    }
                    break;
                }
            }
        }
        while(start<=last){
            right.push_front(text[last--]);
            if(right.size()>=sub.size()){
                bool check=false;
                for(int i=0;i<sub.size();i++){
                    check=true;
                    if(right[i]!=sub[i]){
                        check=false;
                        break;
                    }
                }
                if(check){
                    for(int i=0;i<sub.size();i++){
                        right.pop_front();
                    }
                    break;
                }
            }
        }
    }
    while (!left.empty()) {
        v.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        v.push_back(right.front());
        right.pop_front();
    }
    for (int i = 0; i < v.size(); i++) {
        //문자가 일치한다.
        bool check = true;
        if(i>=sub.size()){
            for(int j=0;j<sub.size();j++){
                if(v[i-sub.size()+j]!=sub[j]){
                    check=false;
                    break;
                }
            }
            if(check){
                for(int j=0;j<sub.size();j++){
                    cout<<v[i-sub.size()+j];
                }
            }
        }
        
    }
    
//    string result="";
//    while(!left.empty()){
//        result+=left.front();
//        left.pop_front();
//    }
//    while(!right.empty()){
//        result+=right.front();
//        right.pop_front();
//    }
//    while(result.find(sub)<result.size()){
//        result.erase(result.find(sub),sub.size());
//    }
//    if(!result.empty()){
//        cout<<result;
//    }
    
}
