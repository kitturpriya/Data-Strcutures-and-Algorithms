//TASK 3
#include<iostream>
#include<string>

using namespace std;


int top=-1;
int stack[]={};
bool isEmpty()
{

    if(top==-1)
    {
        return true;
    }
    else
    {
       return false;
    }
}
void push(int x)
{
    

      top+=1;
      stack[top]=x;
   for(int i=0;i<top+1;i++)
   {
       cout<<char(stack[i])<<" ";
   }
   cout<<endl;
    
}
void pop()
{
   if(isEmpty())
   {
       cout<<"Stack is empty"<<endl;
   }
   else
   {
      stack[top--];
   }
   for(int i=0;i<top+1;i++)
   {
       cout<<char(stack[i])<<" ";
   }
   cout<<endl;
}
int main()
{
  string exp="a{b(c)[d]e{f}}";
  cout<<"Expression to be checked for balanced braces:"<<exp<<endl;
  int len= exp.length();
  for(int i=0;i<len;i++)
  {
      if(exp[i]=='(' || exp[i]== '[' ||exp[i]== '{')
      {
          push(exp[i]);
      }
      else if(exp[i]==')' ||exp[i]== '}' ||exp[i]== ']')
      {
          pop();
      }
      else
      {
          continue;
      }
  }
  if(isEmpty())
  {
      cout<<"Expression has balanced braces."<<endl;
  }
  else
  {
     cout<<"Expression does not have balanced braces."<<endl;
  }
}