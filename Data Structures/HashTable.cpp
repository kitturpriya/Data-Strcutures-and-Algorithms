//TASK 1 http://cpp.sh/2476p
#include <iostream>
#include<list>

using namespace std;

class HashTable
{
   int partition; //no of places you want
   list<int>*hashtable;//container 
   public:
    HashTable(int a)   //constructor
    {
      partition=a;
      hashtable=new list<int>[partition];
    }
    int hashFunction(int a)//the hash-modulo func
    {
        return (a%partition);

    }
    void insert_element(int key)//function used to insert elements to the hashtable
    {
        //to get the hash index of key
        int indexkey=hashFunction(key);
        hashtable[indexkey].push_back(key);
    }
    void delete_element(int key)//function used to delete elements from the hashtable
    {
        int indexkey=hashFunction(key);
        list<int>::iterator i=hashtable[indexkey].begin();
        for(;i!=hashtable[indexkey].end();i++)
        {
            if(*i==key)
                break;

        }
        if(i!=hashtable[indexkey].end())
        {

            hashtable[indexkey].erase(i);
        }



    }
    void display_table()//used to display hashtable values
    {

        for(int i=0;i<partition;i++)
        {
            cout<<i;
            list<int>::iterator j=hashtable[i].begin();
        for(;j!=hashtable[i].end();j++)
            {
                cout<<"---->"<<*j;


            }
            cout<<endl;

        }
    }
    void search_element(int key)//used to search element
    {
        int a=0;//will be 1 if element exist otherwise 0
        int indexkey=hashFunction(key);
                list<int>::iterator i=hashtable[indexkey].begin();
        for(;i!=hashtable[indexkey].end();i++)
        {
            if(*i==key)
            {
                a=1;
                break;
            }


        }
        if(a==1)
            {
                cout<<"The element you wanted to search is present in the hashtable."<<endl;
            }
            else
            {
                cout<<"Element not present"<<endl;
            }

     }
     ~HashTable()//destructor
     {
         delete[]hashtable;

     }


};

int main()
{
    int bucketn,element;
    int num;
    bool test=true;
    cout<<"Enter the no of partitions:";
    cin>>bucketn;
    HashTable obj(bucketn);
    while(test==true)
    {
    cout<<"1.Insert element to the hashtable\n2.Search element from the hashtable\n3.Delete element from the hashtable\n4.Display elements of the hashtable\n5.Exit"<<endl;
    cout<<"Enter your choice:";
    cin>>num;
    switch(num)
    {
        case 1:cout<<"Enter the element to be inserted:";
        cin>>element;
        obj.insert_element(element);
        break;
        case 2:cout<<"Enter the element to be searched:";
        cin>>element;
        obj.search_element(element);
        break;
        case 3:cout<<"Enter the element to be deleted:";
        cin>>element;
        obj.delete_element(element);
        obj.display_table();
        break;
        case 4:obj.display_table();
        break;
        case 5:test=false;
        break;
        default:cout<<"Invalid Input."<<endl;
    }
    }
}
