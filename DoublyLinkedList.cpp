#include<iostream>
#include<stdlib.h>
using namespace std;
struct node  {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

void insert_front(int value)  {
   struct node *ptr;
   int item = value;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)  {
       cout<<"\nOVERFLOW.............";
   }
   else {
        if(head == NULL)  {
           ptr -> next = NULL;
           ptr -> prev = NULL;
           ptr -> data = item;
           head = ptr;
        }
        else {
           ptr -> data = item;
           ptr -> prev = NULL;
           ptr -> next = head;
           head -> prev = ptr;
           head = ptr;
   }
   cout<<"\nNode Inserted Front...................\n";
}

}
void insert_last(int value)  {
   struct node *ptr,*temp;
   int item = value;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)  {
       cout<<"\nOVERFLOW..................";
   }
   else {
        ptr -> data = item;
       if(head == NULL) {
           ptr -> next = NULL;
           ptr -> prev = NULL;
           head = ptr;
       }
       else {
          temp = head;
          while(temp -> next != NULL) {
              temp = temp -> next;
          }
          temp -> next = ptr;
          ptr -> prev=temp;
          ptr -> next = NULL;
          }

       }
     cout<<"\n Node Inserted Last...............\n";
    }
void delete_front()  {
    struct node *ptr;
    if(head == NULL) {
        cout<<"\n UNDERFLOW..............";
    }
    else if(head->next == NULL) {
        head = NULL;
        free(head);
        cout<<"\n Node Deleted Front...............\n";
    }
    else {
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
        cout<<"\n Node Deleted Front...........\n";
    }

}
void delete_last() {
    struct node *ptr;
    if(head == NULL)  {
        cout<<"\n UNDERFLOW.................";
    }
    else if(head->next == NULL) {
        head = NULL;
        free(head);
        cout<<"\n Node Deleted Last..............\n";
    }
    else {
        ptr = head;
        if(ptr->next != NULL) {
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
        cout<<"\n Node Deleted Last.............\n";
    }
}



void display(){
    struct node *ptr;
    cout<<"\n Displaying Node..............\n";
    ptr = head;
    while(ptr != NULL) {
        cout<<"\n"<<ptr->data;
        ptr=ptr->next;
    }
}


int main ()  {
    insert_front(3);
    insert_front(2);
    insert_front(1);
    display();
    insert_last(4);
    insert_last(5);
    display();
    delete_last();
    display();
}

