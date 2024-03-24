#include<iostream>
#include<string.h>
using namespace std;
char prefix[30];
// char reversecopy[30];
int stack[30];
int top=-1;
int a,b,length;
float result;
void push(int j){
    top++;
    stack[top]=prefix[j]-48;  //prefix[j] gives ascii value of character so need to subtract 48 to get the actual number
}
void pop(){
    a=stack[top];
    top--;
    b=stack[top];
}
int main(){
    cout<<"Enter prefix expression: "<<endl;
    cin>>prefix;
    //reversing the prefix expression
    strrev(prefix);
    cout<<prefix;
    length=strlen(prefix);
    for(int i=0; i<length;i++){
        if(prefix[i]>=48 && prefix[i]<=57){
            push(i);
        }
        else{
            pop();
            switch(prefix[i]){
                 case '+':
                result=a+b;
                break;
             case '-':
                result=a-b;
                break;
             case '*':
                result=a*b;
                break;
             case '/':
                result=a/b;
                break;
            }
            stack[top]=result;
        }
    }
    cout<<"The result is: "<<stack[top];
    return 0;
}