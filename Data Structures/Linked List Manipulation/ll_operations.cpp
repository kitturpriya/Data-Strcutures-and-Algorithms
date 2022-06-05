#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;   //next in each node is a pointer that stores address of the next node.
    void insertbeg(int val);
    void insertend(int val);
    int midpos(node* n);
    void insertmid(int val,node** current );
    void del(int pos,node** current ) ;
    void display(node*n);

};
node*  head = new node();
node* second = new node();
node* third = new node();
node* first;
node* last;
//(a)
void node::insertbeg(int val)  //insert new node at the beginning.
{
        first=new node();
        first->next=head;
        first->data=val;
}
void node::insertend(int val)  //insert new node at the end.
{
        last=new node();
        third->next=last;
        last->data=val;
        last->next=NULL;  //last is the end lost of the linked list.
}
int node::midpos(node* n)
{
    int pos=0;
    int sum=0;
    
    while(n != NULL)
    {
        sum+=1;
        n=n->next;
    }
    if(sum%2==0)
    {
        pos=(sum+2)/2;
    }
    else
    {
        cout<<"There is no exact middle position."<<endl;
        pos=(sum+1)/2;
    }
    return pos;
}
void node::insertmid(int val,node** current ) //insert new node in the middle.
{
    //This code can insert a new node at any specified position if pos is passed into the func.
    int pos=midpos(first);
    while(pos--)
    {
        if(pos==0)
        {
            node* midnode= new node();
            midnode->next=*current;    //inserting the new node at pos by shifting the earlier node at that pos ahead.
            midnode->data=val;
            *current=midnode;  //linking the previous node with newly inserted one.
        }
        else
        {
            current= &(*current)->next;
        }
    }

}
//(b)
void node::display(node* n)   //display the linked list.
{
        while (n != NULL) 
        {
            cout <<"Data: "<< n->data <<" Next-Node: "<< n->next<<"\t";
            n=n->next;
        }
}
//(c)
void node::del(int pos,node** current ) //delete node at any specified position.
{
    node* current2 = new node();
    while(pos--) 
    {
        if(pos == 0) 
        {
        //This part skips the node to be deleted and continues the loop from the next node.
        current2 = *current;
        *current = current2->next;  //updated the current to the next of the node to be deleted.
        
        } 
        else
        {
            current= &(*current)->next;
        }
    }


}
int main()
{
    head->data = 4; // assigns data to the first node.
    head->next = second; // Links first node with the second node.
    second->data=9;
    second->next=third;
    third->data=1;
    third->next=NULL;  //singly linked list with 3 nodes initially.

    node obj;
    cout<<"Initial Linked List: \n";
    obj.display(head);
    cout<<endl;
    obj.insertbeg(5);
    cout<<"Linked List after insertion of a node at the beginning: \n";
    obj.display(first);
    cout<<endl;
    obj.insertmid(3,&first);
    cout<<"Linked List after insertion of a node in the middle: \n";
    obj.display(first);
    cout<<endl;
    obj.insertend(10);
    cout<<"Linked List after insertion of a node at the end: \n";
    obj.display(first);
    cout<<endl;

    int pos;
    cout<<"Enter position of node to be deleted: ";
    cin>>pos;
    obj.del(pos,&first);
    cout<<"Linked List after deletion of a node at position "<<pos<<"\n";
    obj.display(first);
    cout<<endl;
    

}