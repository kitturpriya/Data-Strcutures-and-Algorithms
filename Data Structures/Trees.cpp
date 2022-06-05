//TASK3
#include<iostream>

using namespace std;

class Tree
{
    public:
    Tree* left_child;
    Tree* right_child;
    int val;
};

class BST  //In a binary search tree,right child has greater val ele and left one has the smaller one.
{
    public:
    Tree* root;
    BST()
    {
        root=NULL;   //Initially root will be null.
    }

    void insert(int data)
    {
        Tree* x=new Tree();
        Tree* parent;
        x->left_child=NULL;
        x->right_child=NULL;
        x->val=data;

        if(root==NULL)  //basically inserting the starting node.
        {
            root=x;
        }
        else   //else check the correct position to insert the node.
        {
            Tree* current;
            current=root;
            while(current!=NULL)
            {
                parent=current; //to find the parent of the node which needs to be inserted.
                //if the val to be inserted is greaterthan the node we traversing,keep checking on its right side or do otherwise.
                if(data>(current->val))
                {
                    current=current->right_child;  
                }
                else
                {
                    current=current->left_child;
                }
            }
            if(data>(parent->val))
            {
                parent->right_child=x;
            }
            else
            {
                parent->left_child=x;
            }
        }
    }
    void printBST(Tree* node)
    {
        if(node!=NULL)
        {
            printBST(node->left_child);
            cout<<" "<<node->val<<" ";
            printBST(node->right_child);
        }
    }
    void display()
    {
        printBST(root);
    }
};

int main()
{
   BST obj;
   obj.insert(1);
   obj.insert(2);
   obj.insert(3);
   obj.insert(4);
   obj.insert(5);

   cout<<"Binary Tree:"<<endl;
   obj.display();
}

