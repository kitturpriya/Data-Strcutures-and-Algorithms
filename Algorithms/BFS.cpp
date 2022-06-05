#include<iostream>

using namespace std;

int top=-1;
int queue[10]={};
int n,e;
int nodes[10];
int edges[10][10];


void enqueue(int x)
{
  top+=1;
  queue[top]=x;
 
    
 
}
int dequeue()
{
   
  int ele=queue[0];
  for(int i=0;i<top;i++)
  {
    queue[i]=queue[i+1];
  }  
  top--;                                                       
  return ele;
   
}
void BFS(int s) //specifying source
{
   enqueue(s);
   cout<<"BFS Traversal:";
   int u;
   bool visited[10];
   while(top!=-1)
   {
     
     u=dequeue();
     visited[u]=true;   //marking node visited          
     for(int i=0;i<n;i++)
     {
       if(edges[u][i]==1 && edges[i][u]==1)
       {
         
           if(visited[i]==false)  //unvisited
           {
             visited[i]=true;
             enqueue(i);

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
  cout<<endl;
  BFS(0);
  
}