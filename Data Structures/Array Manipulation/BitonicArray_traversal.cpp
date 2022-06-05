#include<iostream>

using namespace std;

int BitonicArr[] = {4, 9, 10, 20, 17, 16, 15, 5, 1} ; //arr with increasing seq followed by a decreasing seq.
int len=sizeof(BitonicArr) / sizeof(BitonicArr[0]); 
int peak(int arr[], int len1, char mode)
{  
    if (mode == 'r') {

        if (len1 > 0) {

            for (int i=0; i<len; i++) {    //swapped the elements of the right side(decreasing seq) to become an increasing seq.
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[len-i-1];
                arr[len-i-1] = temp;
            }
            int m; //index of middle ele.
            if(len1%2!=0)
            {
                m=(len1-1)/2;
            }
            else {
                m=(len1/2)-1;
            }
            int greatest=m;                  //keep track of the greatest ele index as search proceeds.
            int i=m-1;                       //start search from left of mid ele.
            int j=m+1;  
            while(i>=-1 && j<len1)
            {
                if(arr[i]>arr[m])
                {
                    greatest=i; 
                    m=i;
                    i--;                     //keep searching for the greatest ele in the left side
                }        
                else if(arr[j]>arr[m])
                {
                    greatest=j; 
                    m=j;
                    j++;                     //keep searching for the greatest ele in the right side
                }
                else
                {
                    greatest = m;
                    i = -1;
                    j = len1+1;
                }
     
            }
            //greatest ele index in the array.
            return greatest;              
        }
        else {
            return -1;
        }
    }
    else {

        if (len1 > 0){

            int m; //index of middle ele.
            if(len1%2!=0)
            {
                m=(len1-1)/2;
            }
            else{
                m=(len1/2)-1;
            }
            int greatest=m;                  //keep track of the greatest ele index as search proceeds.
            int i=m-1;                       //start search from left of mid ele.
            int j=m+1;  
            while(i>=-1 && j<len1)
            {
                if(arr[i]>arr[m])
                {
                    greatest=i; 
                    m=i;
                    i--;                     //keep searching for the greatest ele in the left side
                }        
                else if(arr[j]>arr[m])
                {
                    greatest=j; 
                    m=j;
                    j++;                     //keep searching for the greatest ele in the right side
                }
                else
                {   
                    greatest = m;
                    break;
                }
     
            }
            //greatest ele index in the array.
            return greatest; 

        } else {
            return -1;
        } 
   }              
   
}

void Partition(int arr[],int s, int len_l, int len_r)
{
   
    if(BitonicArr[peak(arr, len_l, 'l')] == s || BitonicArr[len - 2 - peak(arr, len_r, 'r')] == s) {

        cout<<"\nFound."; //if the element was found in the left/ right part

    } else if (len_l >= 0 || len_r >= 0) {

        Partition(arr, s, len_l-1, len_r-1);  //if not, continue the process.

    } else {

        cout<<"\nNot Found."; 

    }
}

int main()
{
   cout<<"Given Bitonic array:"<<endl;
    for(int i=0;i<len;i++)
    {
        cout << BitonicArr[i] << " ";
    }
   cout<<endl;
   int ele;
   cout<<"Enter element to be searched: ";
   cin>>ele;
   int split = peak(BitonicArr, len, 'l');
   if (BitonicArr[split] == ele) {
       cout<<"\nFound.";
   } else {
        int len_l = split;
        int len_r = len - split - 2;
        Partition(BitonicArr, ele, len_l, len_r);
   }

}
