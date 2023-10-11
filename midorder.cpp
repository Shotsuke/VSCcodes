#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int in_stack(char c){
    switch(c){
        case '-':        
        case '+' :return 3;
        case '*' :
        case '/' :return 5;
        case '^' :return 7;
        case '~' :return 8;
        case '(' :return 1;
        case ')' :return 10;
    }
    return 0;
}
int out_stack(char c){
    switch(c){
        case '-':        
        case '+' :return 2;
        case '*' :
        case '/' :return 4;
        case '^' :return 6;
        case '~' :return 9;
        case '(' :return 10;
        case ')' :return 1;
    }
    return 0;
}

int main(){
    string s;
    cin>>s;
    char stack[10000]={0};
    char exp[10000]={0};
    int index=-1;
    int e_index=-1;
///-----------------------------------------init-----------------------------------------------///    
    for(int i=0;s[i]!='\0';i++){
        if('0'<=s[i] && s[i]<='9') exp[++e_index]=s[i];
        else{
            while( index!=-1 && (out_stack(s[i]) <  in_stack(stack[index])) ){
                exp[++e_index]=stack[index];
                index--;
            }
            if(index==-1) stack[++index]=s[i];
            else if( out_stack(s[i]) >  in_stack(stack[index]) ) stack[++index]=s[i];
            else if( out_stack(s[i]) == in_stack(stack[index])) index--;
        }
    }
    for(;index>=0;index--) exp[++e_index]=stack[index];
    ///for(int i=0;exp[i]!='\0';i++)   printf("%c",exp[i]);///
    
///------------------------------------translation-------------------------------------------///
    int res[10000]={0};
    index=-1;
    for(int i=0;exp[i]!='\0';i++){
        if('0'<=exp[i] && exp[i]<='9') res[++index]=exp[i]-'0';
        else if(exp[i]=='~'){
            res[index]=0-res[index];
        }
        else{
            int right=res[index--];
            int left=res[index--];
            switch (exp[i])
            {
            case '+':
                res[++index]=right+left;
                break;
            case '-':
                res[++index]=left-right;
                break;
            case '*':
                res[++index]=left*right;
                break;
            case '/':
                res[++index]=left/right;
                break;
            case '^':
                res[++index]=pow(left,right);
                break;
            default:
                break;
            }
        }
    }
    printf("%d",res[0]);
    return 0;
}