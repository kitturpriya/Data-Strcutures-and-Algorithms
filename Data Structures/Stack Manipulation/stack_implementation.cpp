#include<iostream>

using namespace std;

//TASK 1
int n=10;
int top=-1;
int stack[10]={};
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
bool isFull()
{
    
    if(top==n-1)
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
    
    if(isFull())
    {
      cout<<"Stack is full"<<endl;
    }
    else
    {
      top+=1;
      stack[top]=x;
    }
   for(int i;i<top+1;i++)
   {
       cout<<stack[i]<<" ";
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
   for(int i;i<top+1;i++)
   {
       cout<<stack[i]<<" ";
   }
   cout<<endl;
}
void peek()
{
   if(isEmpty())
   {
       cout<<"Stack is empty"<<endl;
   }
   else
   {
      cout<<"Element at the top:"<<stack[top]<<endl;
   }
}
int main()
{ 
    int num,x;
    while(true)
    {
     cout<<"Enter number for operation to be performed:";
     cin>>num;
    if(num==1)
    {
        cout<<"Enter number to be pushed:";
        cin>>x;
        push(x);
    }
    else if(num==2)
    {   
        cout<<"Stack after popping:";
        pop();
    }
    else if(num==3)
    {
        peek();
    }
    else
    {
         cout<<"Incorrect input."<<endl;
         break;
    } 
    }
 

    

    
}

