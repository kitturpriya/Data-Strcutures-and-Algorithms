//TASK 2
#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int top=-1;
int stack[]={};

void push(int x)
{
    top+=1;
    stack[top]=x;
   for(int i=0;i<top+1;i++)
   {
       cout<<stack[i]<<" ";
   }
   cout<<endl;
    
}
int pop()
{
    if(top==-1)
   {
        cout<<"Stack is empty."<<endl;
   }
   
  return stack[top];
   
}

int main()
{   

    string postfix="2 3 ^"; 
    cout<<"Postfix expression to be evluated:"<<postfix<<endl;
    int z = postfix.length();
    
    for(int i=0 ;i<z;i++)
    {
        
        if(isdigit(postfix[i])==true)
       {
          for(int j=i+1;j<z;j++)
        {
           if( postfix[j]==' ')
           {
               string res= postfix.substr(i,j);
               int y=stoi(res);
               push(y);
               i=j;
           }
           
        }  
          

       }
        else if(postfix[i]=='/' )
        {
           int a=pop();
           top-=1;
           int b=pop();
           top-=1;
           int total= b/a;
           push(total);
           
        }
        else if(postfix[i]=='*' )
        {
           int a=pop();
           top-=1;
           int b=pop();
           top-=1;
           int total= b*a;
           push(total);
           
        }
        else if(postfix[i]=='+')
        {
           int a=pop();
           top-=1;
           int b=pop();
           top-=1;
           int total= b+a;
           push(total);
           
        }
        else if(postfix[i]=='-' )
        {
           int a=pop();
           top-=1;
           int b=pop();
           top-=1;
           int total= b-a;
           push(total);
           
        }
        else if(postfix[i]=='^' )
        {
           int a=pop();
           top-=1;
           int b=pop();
           top-=1;
           int total= pow(b,a);
           push(total);
           
        }
       
        
    }
    
  
}
    
