#include<iostream>

using namespace std;

int arr[]={1,8,6,7,4,3,2,5};
int len=sizeof(arr) / sizeof(arr[0]);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int p,int r)  //p is the starting index of the array and r the ending index
{
    int x=arr[r];  //taking pivot as the last index ele.
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(arr[j]<=x) //sorting all the ele at index smaller than the pivot(basically all el except last index one).
        {
            i+=1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]); //giving pivot its correct pos.
    return i+1;  //return pos of pivot in partially sorted arr.
}

void QuickSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);  //q is the coorect pos the pivot will take in the final sorted array. It basically gets divided into two
                                   //parts:ele smaller than pivot having pos before pivot pos and ele greater than the pivot following the pivot pos.
        QuickSort(arr,p,q-1); //recursivley sort array till pivot pos
        QuickSort(arr,q+1,r); //recursively sort array after pivot pos
    }
    
}

int main()
{
    cout<<"Given array:"<<endl;
    for(int i=0;i<len;i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"Array sorted using Quick sort:"<<endl;
    QuickSort(arr,0,len-1);
    for(int i=0;i<len;i++)
    {
        cout << arr[i] << " ";
    }

}