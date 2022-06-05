#include<iostream>
#include<string>
//#include <bits/stdc++.h>

using namespace std;

int top=-1;
int top1=-1;

char stack[100];
char postfix[100];


void push(char x)
{
      top+=1;
      stack[top]=x;  
      //cout<<stack[top];
    cout<<"stack:";
    for(int i=0;i<top+1;i++)
   {
       cout<<stack[i]<<" ";
   }
   cout<<endl;  
}
void push1 (char x)
{
      top1 +=1;
      postfix[top1]=x;
      //cout<<x;
      //cout<<postfix[top1];
      cout<<"postfix:";
      for(int i=0;i<top1+1;i++)
   {
       cout<<postfix[i]<<" ";
   }
   cout<<endl;   
}
char pop()
{
    top--;
    return stack[(top+1)];
    cout<<"stack:";
    for(int i=0;i<top+1;i++)
   {
       cout<<stack[i]<<" ";
   }
   cout<<endl;  
    
   
}


int main()
{   
    string infix="(K+[M*N])";   
    int len=infix.length();
    
    cout<<"Infix expression: "<<infix<<endl;
    for(int i=0;i <len;i++)
    {
         if(infix[i]=='(' || infix[i]== '[' || infix[i]== '{')
         {
            push(infix[i]);
         }
        else if(infix[i]==')' ||infix[i]== '}' ||infix[i]== ']')  
       {  
          int g=0;
          for(int j=top;j>=0;j--)
          {
            if(g==0)
            {
               if(stack[j]=='(' || stack[j]== '[' || stack[j]== '{')  
              {   
                g=1;
                //cout<<"in loop1";
                char arr[len]={};
                int p=0;
                for(int k=top;k>j-1;k--)
                {
                
                        char a=pop();
                        arr[p]=a;
                        cout<<arr[p];
                        p++;
                        //top--;
                
                }
      
                for(int l=0;l<p-1;l++)
                {
                    push1(arr[l]);
                }
            
            
              }
            }
            
        
          }
       }
        else if(infix[i]=='^')
       {
         if(stack[top]=='^')
         {
            char a= pop();
            push1(a);
            push(infix[i]);
         }
         else
         {
           push(infix[i]); 
         }
                                                   
       }
        else if(infix[i]=='/')     //-   -
       {
         if(stack[top]=='^' || stack[top]=='*'|| stack[top]=='/')
         {
            char a= pop();
            push1(a);
            push(infix[i]);
            for(int j=top;j>=0;j--)
           {
               if(stack[top]=='^' || stack[top]=='*'|| stack[top]=='/')
               {
                  char a= pop();
                  push1(a);
                  push(infix[i]);
               }
               else
               {
                  break;
               }
           }
         }
         else
         {
           push(infix[i]);
         }
         
        
       }
        else if(infix[i]=='*')
       {
         if(stack[top]=='^' ||stack[top]=='/'|| stack[top]=='*')
         {
          char a= pop();
          push1(a);
          push(infix[i]);
          for(int j=top;j>=0;j--)
           {
               if(stack[top]=='^' || stack[top]=='/'|| stack[top]=='*')
               {
                  char a= pop();
                  push1(a);
                  push(infix[i]);
               }
               else
               {
                  break;
               }
           }
         }
         else
         {
           push(infix[i]);
         }
        
       }
       else if(infix[i]=='+')
       {
         if(stack[top]=='*' || stack[top]=='/'|| stack[top]=='^'|| stack[top]=='-'|| stack[top]=='+')
         {
          char a= pop();
          push1(a);
          //push(infix[i]);
          for(int j=top;j>=0;j--)
           {
               if(stack[top]=='^' || stack[top]=='*'||stack[top]=='/' ||stack[top]=='-'|| stack[top]=='+')
               {
                  char a= pop();
                  push1(a);
                  push(infix[i]);
               }
               else
               {
                  break;
               }
           }
         }
         else
         {
           push(infix[i]);
         }
        
        }
       else if(infix[i]=='-')
       {
         if(stack[top]=='*' || stack[top]=='/'|| stack[top]=='^'|| stack[top]=='+'|| stack[top]=='-')
         {
          char a= pop();
          push1(a);
          push(infix[i]);
           for(int j=top;j>=0;j--)
           {
               if(stack[top]=='^' || stack[top]=='*'||stack[top]=='/' ||stack[top]=='+'|| stack[top]=='-')
               {
                  char a= pop();
                  push1(a);
                  push(infix[i]);
               }
               else
               {
                  break;
               }
           }
          
         }
         else
         {
           push(infix[i]);
         }
        
       }
       else if(int(infix[i])<=90 && int(infix[i])>=65)
       {
          push1(infix[i]);
       }

    }

    for(int z=top;z>=0;z--)
    {
        char y=pop();
        cout<<y;
        //top--;
        push1(y);
    }
    cout<<"Stack: ";
    for(int n=0;n<top+1;n++)
    {
        cout<<stack[n]<<" ";
    }
    cout<<endl;
    cout<<"Postfix expression: ";
    for(int m=0;m<top1+1;m++)
    {
        cout<<postfix[m]<<" ";
    }
    
   
}
    

 

    

    


