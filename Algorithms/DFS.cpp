#include<iostream>

using namespace std;



int top=-1;
int stack[10]={};
int nodes[10];
int edges[10][10];
int n,e;

void push(int x)
{  
    top+=1;
    stack[top]=x;
    
    
}
int pop()
{
   return stack[top--];  
}
void DFS(int s) //specifyig source
{
   push(s);
   cout<<"DFS Traversal:";
   int u;
   bool visited[10];
   while(top!=-1)
   {
     
     u=pop();
     visited[u]=true;   //marking node visited  
     for(int i=0;i<n;i++)
     {
       if(edges[u][i]==1 && edges[i][u]==1)
       {
         
           if(visited[i]==false)
           {
             visited[i]=true;
             push(i);
           }
         
         
       }
     }
     cout<<u<<" ";
   }
}
int main()
{
  
  int n1,n2;
  cout<<"Enter no. of nodes:";
  cin>>n;
  cout<<"Nodes:";
  for(int i=0;i<n;i++)
  {
    cin>>nodes[i];
    cout<<" ";
  }
  cout<<endl;
  cout<<"Enter no. of edges:";
  cin>>e;
  cout<<"Edges:"<<endl;
  for(int i=0;i<e;i++)
  {
    cin>>n1>>n2;
    edges[n1][n2] = 1;
    edges[n2][n1] = 1;
  
  }
  DFS(0);
  
}