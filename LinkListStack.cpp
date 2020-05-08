#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
   int data;
   struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    display();



}
void push(int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(top == NULL)
      newNode -> next = NULL;
   else
      newNode -> next = top;
   top = newNode;
    cout<<"\nInserted!!!!!!!!!!!!\n";
}
void pop(){
   if(top == NULL)
      cout<<"\nStack is Empty!!!!!!!!\n";
   else{
      struct Node *temp = top;
      cout<<"\nElement popped: "<< temp->data<< "\n" ;
      top = temp->next;
      free(temp);

   }
}
void display(){
   if(top == NULL)
      cout<<"\nStack is Empty!!!!!!!!!!!!!!\n";
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
            cout<<temp->data<< "--->";
            temp = temp -> next;
      }
      cout<<temp->data<<"--->NULL\n";
   }
}
