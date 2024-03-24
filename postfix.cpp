/*
Algorithm for evaluating postfix expression: 
1. Scan the expression from left to right. 562*42/1-1*-4*+
2. If the scanned element is operand push it to the stack.
3. If the scanned element is operator then:
    a. Pop out top two elements of the stack assigning A as top element and B is the next to top element.
    b. Evaluate  B(operator)A.
    c. Place the result of step b to the stack
    d. Repeat steps from 1 to 3 until end of the expression.
*/
#include<iostream>
#include<string.h>
using namespace std;
char postfix[30];
int stack[25];
int top=-1;
int a,b,length,result;
void push(int j){
        top++;
        stack[top]=postfix[j]-48;
   
}
void pop(){
        a=stack[top];
        top--;
        b=stack[top];
}
int main(){
    cout<<"Enter postfix expression:"<<endl;
    cin>>postfix;
    length=strlen(postfix);
    for(int i=0;i<length;i++){
        if(postfix[i]>=48 && postfix[i]<=57){
         push(i);
        }
        else {
            pop();
            switch (postfix[i])
            {
            case '+':
                result=b+a;
                break;
             case '-':
                result=b-a;
                break;
             case '*':
                result=b*a;
                break;
             case '/':
                result=b/a;
                break;
            }
         stack[top]=result;
        }
    }
            cout<<"The answer is: "<<stack[top]<<endl;
            
    
    return 0;
}