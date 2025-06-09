#include<iostream>

using namespace std;
class node{
    public:
        int val;
        node* next;
        node(int val){
            this->val= val;
            this->next= nullptr;
        }
};
class linkedlist{
    public:
        node* head;
        node*tail;
        int size;
        linkedlist(){
            head= nullptr;
            tail=nullptr;
            size=0;
        }

       void insertatend(int val){
         node* temp = new node(val);
         if(size==0) head= tail = temp;
         else{
            tail->next=temp;
            tail=temp;
         }

            size++;
       }
       void insertatbegin(int val){
          node* temp = new node(val);
          if(size==0) head= tail= temp;
          else{
              temp->next=head;
              head=temp;
          }

          size++;
       }
       
       void display(){
              node* temp = head;
              while(temp != nullptr){
                    cout<<temp->val<<" ";
                    temp=temp->next;
              }

              cout<<endl;
       }
       void size1(){
           cout<<"Size of linked list is: "<<size<<endl;
       }
       void insertatpos(int pos, int val){
              if(pos<0 || pos>size) return;
              if(pos==0){
                  insertatbegin(val);
                  return;
                
              }
              if(pos==size){
                 insertatend(val);
                 return;
              }
              else{
                    node* temp= new node(val);
                    node* current= head;
                    for(int i=0;i<pos-1;i++){
                        current= current->next;
                    }
                    temp->next=current->next;
                    current->next=temp;

                    size++;
              }
       }

      int getvalue(int index)
    {
        node* temp = head;
        if (index < 0 || index >= size)
            return -1;
        for (int i = 0; i <= index; i++)
        {
            if (i == index){
                return temp->val;
            }
                
            temp = temp->next;
        }
    }
    void deleteatpos(int pos)
    {
        if (pos < 0 || pos >= size)
            return;
        if (pos == 0)
        {
            head = head->next;
            size--;
            if (size == 0)
                tail = nullptr;
        }
        if (pos == size - 1)
        {
            node *temp = head;
            for (int i = 0; i < size - 2; i++)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            tail = temp;
            size--;
        }
        else
        {
            node *temp = head;
            for (int i = 0; i <= pos - 1; i++)
            {

                if (i == pos - 1)
                {
                    temp->next = temp->next->next;
                    size--;
                }
                temp = temp->next;
            }
        }
    }

};
// a demonstration of the linked list operations
int main(){
    
    linkedlist l1;

    l1.insertatend(10);
    l1.insertatend(20);
    l1.insertatend(30);
    l1.insertatbegin(5);
    l1.insertatpos(2, 15);
    l1.display();
    l1.size1();
    cout<<l1.getvalue(2);
    cout<<endl;
    l1.deleteatpos(2);
    l1.display();
    l1.size1();

}
