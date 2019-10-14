#include<iostream>
using namespace std;
// node stucture
struct Node
{
    int data;
    Node* left;
    Node* right;
};

void insertion(Node** head, int data)
{
	Node* newnode = new Node();
	if(newnode==NULL)
	{
		cout<<"NODE NOT CREATED";
		getchar();
		getchar();
	}
	Node* last = *head;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	if(*head==NULL)
	{
		*head=newnode;
		return;
	}

	while(1)
	{
		if(data > last->data)
		{
			if(last->right != NULL)
			{
				last=last->right;
				continue;
			}
			else
			{
				last->right = newnode;
				break;
			}
		}
		else
		{
			if(last->left != NULL)
			{
				last=last->left;
				continue;
			}
			else
			{
				last->left = newnode;
				break;
			}
		}
	}
}

void printtree(Node* head)
{
    if(head==NULL)
    {
        cout<<"empty tree"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    cout<<temp->data<<endl;
}

// main function
int main()
{
	int choice,choice2,data;
	Node* head=NULL;
	while(1)
	{
		// choice for tree
		cout<<"1. enter elements"<<endl;
		cout<<"2. print left side elements"<<endl;
		cout<<"3. exit"<<endl;
		cin>>choice;

		// enter elements
		if(choice==1)
		{
			cout<<"enter data: ";
			cin>>data;
			insertion(&head, data);
		}

		else if(choice==2)
		{
			printtree(head);
			cout<<endl;
		}

		else if(choice==3)
		{
			break;
		}
	}
}

