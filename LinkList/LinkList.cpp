#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class linklist {
    node *head,*curr;
    public:

    linklist(){
        head = NULL;
        curr = NULL;
    }

    void insert_at_end (int data){
        node *newnode = new node();
        newnode-> data = data;
        newnode ->next =NULL;
        
    if (head ==NULL)
    {
        head = newnode;
    }
    else {
        curr = head;
        while (curr->next !=NULL)
        {
            curr = curr -> next;
        }
        curr ->next = newnode;
    }
        
    }

    void insert_at_start(int data) 
    {
        node *newnode = new node();
        newnode -> data = data;
        newnode-> next = head;
        head = newnode;

    }

    void insert_at_position(int position, int data) // Insert at specific position
    {
        node *newnode = new node();
        newnode-> data = data;
        int pos = 0;
        curr = head;

        if (position < 0 )return; 

        if (position == 0)
        {
            newnode ->next = head;
            head = newnode;
            return;
        }
        while (curr != NULL && pos != position -1 )
        {
            curr = curr -> next;
            pos ++;
           
        }

        if (curr == NULL) {
            cout << "Position out of bounds!" << endl;    
            delete newnode;
            return;
        }
        newnode ->next = curr ->next ;
        curr -> next = newnode;
    }

    void delete_at_end ()
    {
        if (head == NULL)
        {
            cout<<"List is empty;";
            return;
        }

        if (head ->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }   
             curr = head;
        while (curr ->next ->next !=NULL)
        {
            curr = curr -> next;
        }
        node *temp;
        temp = curr -> next;
        curr -> next = NULL;
        delete temp;
    }

    void delete_at_start (){
        node *temp;
        temp = head;
        head = head-> next;
        delete temp;
    }

    void delete_at_position(int position){
        if (position < 0 ) 
        {   cout<<"Position out of bounds!"<<endl;
            return;}

        if (head == NULL)
        {
            cout<<"List is empty"<<endl;
        }

        int pos = 0;
        node *temp;
        curr = head;
        if (position == 0)
        {
            temp = head;
            head = head-> next;
            delete temp;
            return;
        }
        while (curr != NULL && pos != position -1)
        {
            curr = curr -> next;
            pos ++;
        }

        if (curr == NULL )
        {
            cout<<"Position out of bounds "<<endl;
            return;
        }

        temp = curr -> next;
        curr ->next = curr ->next ->next;
        delete temp;
    }

    void display(){
        curr = head ;
        while (curr)
        {
            cout<<curr->data <<"->";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{

    linklist obj;
    obj.insert_at_end(6);
    obj.insert_at_end(7);
    obj.insert_at_end(8);
    obj.display();
    obj.insert_at_start(3);
    obj.insert_at_start(2);
    obj.insert_at_start(1);
    obj.display();
    obj.insert_at_position(3,4);
    obj.display();
    // obj.delete_at_end();
    // obj.display();
    // obj.delete_at_start();
    // obj.display();
    // obj.delete_at_position(4);
    // obj.display();


 

}
