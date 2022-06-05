///TASK 2
#include<iostream>

using namespace std;

int ele[]={4,1,3,2,16,9,10,14,8,7};
int len=sizeof(ele)/sizeof(ele[0]);


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Implementing and performing operations a Max Heap.
void max_heapify(int arr[],int i,int n)  //maintains the max-heap property
{
   int l=(2*i);    //left child index
   int r=(2*i)+1;  //right child index
   int largest;
   //same thing can be applied for min-heap using the proper comparision operators.
   if(l<=n && arr[l-1]>arr[i-1])  
   {
       largest=l;
   }
   else
   {
       largest=i;
   }
   if(r<=n && arr[r-1]>arr[largest-1])
   {
       largest=r;
   }
   if(largest!=i)
   {
       swap(&arr[i-1],&arr[largest-1]);
       max_heapify(arr,largest,n);
   }
}

void build_max_heap()  //building a heap
{
    for(int i=(len/2);i>=1;i--)  //since the elements from (len/2)+1 till len will be leaf nodes.
    {
        max_heapify(ele,i,len);
    }
}

void heap_sort()
{
    build_max_heap();
    for(int i=len;i>=2;i--)  
    { 
        swap(&ele[0],&ele[i-1]);
        max_heapify(ele,1,i-1);
    }
}

int main()
{
 
    cout<<"Given array of elements:"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<ele[i]<<" ";
    }
    cout<<endl;

    build_max_heap();
    cout<<"After implementing Max Heap:"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<ele[i]<<" ";
    }
    cout<<endl;

    heap_sort();
    cout<<"After Implementing Heap Sort:"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<ele[i]<<" ";
    }
    cout<<endl;

}