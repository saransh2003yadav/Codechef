#include<iostream>
using namespace std;
struct circular
{
    int num;
    circular *next;
    circular *prev;
};
circular *head=NULL;
circular *rear;
circular *temp;
circular *okay;
int count=1;
void add_new_node()
{
    cout<<"Enter the value"<<endl;
    circular *new_node=new circular;
    cin>>new_node->num;
    if(head==NULL)
    {
        head=new_node;
        temp=head;
        temp->prev=NULL;
        temp->next=NULL;
        rear=temp;
    }
    else
    {
        temp->next=new_node;
        new_node->prev=temp;
        temp=new_node;
        okay=head;
        temp->next=okay;
        okay->prev=temp;
        rear=temp;
    }
}
void insert_node(int count)
{
    unsigned int position;
    int b=count+1;
    cout<<"Enter the position you want to enter"<<endl;
    cin>>position;
    if(position>b)
    {
        cout<<"Please enter valid position"<<endl;
        count--;
        return;
    }
    cout<<"Enter the value"<<endl;
    circular *temp3= new circular;
    cin>>temp3->num;
    int d=b/2;
    if(position==1)
    {
        okay->prev=temp3;
        temp3->next=okay;
        temp3->prev=temp;
        temp->next=temp3;
        okay=temp3;
        head=okay;
    }
    else if(position==b)
    {
        okay->prev=temp3;
        temp3->next=okay;
        temp3->prev=temp;
        temp->next=temp3;
        temp=temp3;
        rear=temp;
    }
    else if(position<=d)
    {
        circular *temp2=okay;
        for(int i=1;i<(position-1);i++)
       {
         temp2=temp2->next;
       }
       circular *temp4=temp2->next;
       temp2->next=temp3;
       temp3->prev=temp2;
       temp3->next=temp4;
       temp4->prev=temp3;
    }
    else
    {
        position=count+2-position;
        circular *temp4=temp;
        circular *temp2=temp;
        for(int i=1;i<(position-1);i++)
        {
            temp2=temp2->prev;
        }
        temp4=temp2->prev;
        temp4->next=temp3;
        temp3->prev=temp4;
        temp3->next=temp2;
        temp2->prev=temp3;
    }
}
void display(int count)
{
    circular *temp2=head;
    if(temp2==NULL)
    {
        cout<<"There is no data to be displayed"<<endl;
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            cout<<temp2->num<<endl;
            temp2=temp2->next;
        }
    }
}
void delete_node(int count)
{
    int position;
    cout<<"Enter the position of the node you want to delete"<<endl;
    cin>>position;
    circular *temp2;
    int b=(count+1)/2;
    if(position>count || head==NULL)
    {
        cout<<"Invalid entry"<<endl;
        return;

    }
    else if(position==1)
    {
        temp2=okay;
        okay=okay->next;
        delete temp2;
        okay->prev=temp;
        temp->next=okay;
        head=okay;
    }
    else if(position==count)
    {
        temp2=temp;
        temp=temp->prev;
        delete temp2;
        rear=temp;
        temp->next=head;
        okay->prev=temp;
    }
    else if(position<=b)
    {
        temp2=head;
        for(int i=1;i<(position-1);i++)
         {
         temp2=temp2->next;
         }
        circular *temp3=temp2->next;
        circular *temp4=temp3->next;
        temp2->next=temp4;
        temp4->prev=temp2;
        delete temp3;
    }
    else
    {
        position=count-position;
        temp2=temp;
        for(int i=1;i<position;i++)
        {
            temp2=temp2->prev;
        }
        circular *temp3=temp2->prev;
        circular *temp4=temp3->prev;
        temp2->prev=temp4;
        temp4->next=temp2;
        delete temp3;
    }
}
int main()
{
    add_new_node();
    int a=0;
    while(a!=5)
 {
    cout<<"Enter 1 if you want to add new element"<<endl;
    cout<<"Enter 2 if you want to delete any element"<<endl;
    cout<<"Enter 3 if you want to enter element at any position"<<endl;
    cout<<"Enter 4 if you want to display all the elements"<<endl;
    cout<<"Enter 5 if you want to quit"<<endl;
//  cout<<"Enter 6 if you want to reverse the list"<<endl;
    cin>>a;
    switch (a)
    {
        case 1:
               add_new_node();
               count++;
               break;
        case 2:
               delete_node(count);
               count--;
               break;
        case 3:
               insert_node(count);
               count++;
               break;
        case 4:
               display(count);
               //cout<<"Reached here";
               break;
        case 5:
               break;
  /*      case 6:
               reverse_list();
               break;  */
        default:
               cout<<"Invalid entry"<<endl;
    }
 }
 cout<<"The total no. of nodes are "<<count<<endl;
}
