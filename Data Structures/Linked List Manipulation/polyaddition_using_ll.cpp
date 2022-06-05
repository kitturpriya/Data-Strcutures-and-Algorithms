#include<iostream>
#include<string>

using namespace std;

class polynomial
{
  public:
  int coef;
  int power;
  polynomial* next;
  void display();
  void display1();
  void addpoly();
};
polynomial* start=new polynomial();
void polynomial::display()
{
    int n;
    cout<<"Enter no of terms:";
    cin>>n;
    string poly="";
    polynomial*temp;
    for(int i=0;i<n;i++)
    {


        if(i==0) 
        {
            int a,b;
            cout<<"Enter coeff for term "<<i+1<<":";
            cin>>a;
            start->coef=a;
            cout<<"Enter power for term "<<i+1<<":";
            cin>>b;
            start->power=b;
            string c=to_string(a);
            string d=to_string(b);
            poly.append(c);
            poly.append("x^");
            poly.append(d);
            poly.append("+");
        }
    
    
        else
        {
            polynomial* count=new polynomial();
            if(i==1)
            {
                start->next=count;
            }
            else
            {
                temp->next=count;  //links previous node with the new node formed in the current loop.  
            }
            
            int a,b;
            cout<<"Enter coeff for term "<<i+1<<":";
            cin>>a;
            count->coef=a;
            cout<<"Enter power for term "<<i+1<<":";
            cin>>b;
            count->power=b;
            temp=count;
            string c=to_string(a);
            string d=to_string(b);
            poly.append(c);
            poly.append("x^");
            poly.append(d);
            if(i!=n-1)
            {
                poly.append("+");
            }
            else
            {
                temp->next=NULL;
            }
        
        
        }
        
    }
    cout<<"Polynomial 1:"<<poly<<endl;
   
}
polynomial* start1=new polynomial();
void polynomial::display1()
{
    int n;
    cout<<"Enter no of terms:";
    cin>>n;
    string poly="";
    polynomial*temp;
    for(int i=0;i<n;i++)
    {


        if(i==0) 
        {
            int a,b;
            cout<<"Enter coeff for term "<<i+1<<":";
            cin>>a;
            start1->coef=a;
            cout<<"Enter power for term "<<i+1<<":";
            cin>>b;
            start1->power=b;
            string c=to_string(a);
            string d=to_string(b);
            poly.append(c);
            poly.append("x^");
            poly.append(d);
            poly.append("+");
        }
    
    
        else
        {
            polynomial* count=new polynomial();
            if(i==1)
            {
                start1->next=count;
            }
            else
            {
                temp->next=count;  //links previous node with the new node formed in the current loop.  
            }
            
            int a,b;
            cout<<"Enter coeff for term "<<i+1<<":";
            cin>>a;
            count->coef=a;
            cout<<"Enter power for term "<<i+1<<":";
            cin>>b;
            count->power=b;
            temp=count;
            string c=to_string(a);
            string d=to_string(b);
            poly.append(c);
            poly.append("x^");
            poly.append(d);
            if(i!=n-1)
            {
                poly.append("+");
            }
            else
            {
                temp->next=NULL;
            }
        
        
        }
        
    }
    cout<<"Polynomial 2:"<<poly<<endl;
    
}
void polynomial::addpoly()
{
   cout<<"Addition of both:";
   polynomial *temp1= new polynomial();
   polynomial *temp= new polynomial();
   temp1=start1;
   temp=start;
   while(temp!=NULL)
   {
       while(temp1!=NULL)
       {
           if((temp->power)==(temp1->power))
           {
               temp->coef+=temp1->coef; 
           }
           temp1=temp1->next;
    
       }
       
       cout<<temp->coef<<"x^"<<temp->power<<"+";
       
       temp1=start1;
       temp=temp->next;
   }
   temp=start;
   while(temp1!=NULL)
   {
       int count=0;
       while(temp!=NULL)
       {
           if((temp->power)==(temp1->power))
           {
               count++;
           }
           temp=temp->next;
       }

       if(count==0)
       {
           cout<<temp1->coef<<"x^"<<temp1->power;
       }
       temp1=temp1->next;
       if(temp1!=NULL && count==0)
       {
           cout<<"+";
       }
       temp=start;
       
   }

}
int main()
{
    polynomial obj;
    obj.display();
    obj.display1();
    


    obj.addpoly();
    


}