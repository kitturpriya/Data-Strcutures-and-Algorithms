//iii)
#include<iostream>
using namespace std; 

//INSERTION
void insert(int arr[],int n)
{
  int arr1[n+1];
  int x;
  int value;
  cout<<"\n Enter index:";
  cin>>x;
  cout<<"\n Enter value to be inserted:";
  cin>>value;
  for(int i=0;i<x;i++)
  {
    arr1[i]=arr[i];
  }
  arr1[x]=value;
  for(int i=x+1; i<n+1;i++)
  {
    arr1[i]=arr[i-1];
  }
  cout<<"Array after insertion:";
  for(int i=0;i<n+1;i++)
  {
    cout<<arr1[i]<<" ";
  }
  

}
//DELETION
void deletion(int arr[],int n)
{
  int arr1[n-1];
  int x;
  cout<<"\n Enter index:";
  cin>>x;
  for(int i=0;i<x;i++)
  {
    arr1[i]=arr[i];
  }
  for(int i=x+1; i<n;i++)
  {
    arr1[i-1]=arr[i];
  }
  cout<<"Array after deletion:";
  for(int i=0;i<n-1;i++)
  {
    cout<<arr1[i]<<" ";
  }

}

int main()
{
  int arr[]={1,2,3,4,5};
  int n;
  n=(sizeof(arr)/sizeof(arr[0]));
  cout<<"Initial array:"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
  insert(arr,n);
  cout<<endl;

  deletion(arr,n);
}