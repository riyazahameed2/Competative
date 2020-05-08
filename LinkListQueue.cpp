#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void enQueue(int);
void deQueue();
void display();

int main(){
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    display();
    deQueue();
    display();

}
void enQueue(int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   cout<<"\nInserted!!!!!!!!\n";
}
void deQueue(){
   if(front == NULL)
      cout<<"\nQueue is Empty!!!\n";
   else{
      struct Node *temp = front;
      front = front -> next;
      cout<<"\nDeleted element: "<< temp->data<<"\n";
      free(temp);
   }
}
void display(){
   if(front == NULL)
      cout<<"\nQueue is Empty!!!!!!!!!!!\n";
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 cout<<temp->data<< "--->";
	 temp = temp -> next;
      }
      cout<<temp->data<<"--->NULL\n";
   }
}
