#include<iostream>

using namespace std;

int n,e;
int nodes[10];
int edges[10][10];
int weight[10][10];  //stores the weights of all edges(here weight is the length of the pipe)
int MST[10];  //stores the min weight neighbour node for each node.
int MST_weight[10];  //stores the min weight incident on each node.

int Prims(int num)
{
    for(int i=0;i<n;i++)   //initially all weights and min edges are stored as 0.
    {
      MST_weight[i]=0;    
      MST[i]=0;
    }
  
    for(int i=0;i<n;i++)
    {
    
            int u=nodes[i]; //taking a node one by one(here source node is node 1)
            int min=100000;
            int min_edge=0;
            for(int j=u;j<n;j++)  //starting from j=u will not check visited nodes.
            {
                if(edges[u][j+1]==1 && u!=j+1)  //traverse all the unvisited neighbours of the node u 
                {
                   if(weight[u][j+1]<min)
                   {
                       min=weight[u][j+1];  //to get the min weight of edge incident on node u.
                       min_edge=j+1;
                   }
                }
            }
            MST_weight[u-1]=min;
            MST[u-1]=min_edge;
           
        
    }

    cout<<"Mininum Spanning Tree using Prims Algorithm:";
    for(int i=0;i<n;i++)
    {
      if(MST[i]!=0)
      {
        cout<<nodes[i]<<","<<MST[i]<<" ";
      }
        
    }

    //Calculating the total min cost of pipes
    int total_cost=0;
    for(int i=0;i<n;i++)
    {
      int cost;
      if(MST[i]!=0)
      {
        cost=(num)*(MST_weight[i]);
        total_cost+=cost;
      }
        
    }

    return total_cost;



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
  

  int edge_weight=0;
  for(int i=0;i<n;i++)
  {
    int n3=i+1;
    for(int j=i;j<n;j++)
    {
      int n4=j+1;
      if(edges[n3][n4]==1 && edges[n4][n3]==1)
      {
          cout<<"Weight for edge ("<<n3<<","<<n4<<") :";
          cin>>edge_weight;
          weight[n3][n4]=edge_weight;
          weight[n4][n3]=edge_weight;
      }
      
    }
    
     
  }
  int cost;
  cout<<"Enter cost per pipe(in Rs.): ";
  cin>>cost;

  //Implementing Prim's Algo
  int res= Prims(cost);
  cout<<endl;
  cout<<"Total cost(in Rs.): "<<res<<endl;
}