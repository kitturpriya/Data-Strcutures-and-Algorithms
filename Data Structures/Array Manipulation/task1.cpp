#include<iostream>
using namespace std;
//TASK 2
//i)
int main()
{
    int arr[]={1,2,3,4,5};
    int n= (sizeof(arr)/sizeof(arr[0]));
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];   
    }
    cout<<"Sum of all elements:"<<sum<<endl;
    float avg=0;
    avg=(sum/n);
    cout<<"Average of all elements:"<<avg<<endl;
//ii)
   int max=0;
   int min=5;
   for(int i=0;i<n;i++)
   {   
       
       if (arr[i]>max)
       {
           max=arr[i];
       }
    
   }
   for(int i=0;i<n;i++)
   {  
       
       if (arr[i]<min)
       {
           min=arr[i];
       }
       
   }
   cout<<"Max of all elements:"<<max<<endl;
   cout<<"Min of all elements:"<<min<<endl;
  
}
