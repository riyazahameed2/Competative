#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insertFront(int value){
    struct node *ptr;
    int item = value;
    ptr = (struct node *) malloc (sizeof(struct node *));
    if(ptr == NULL){
        cout<<"\n OVERFLOW";
    }
    else{
        ptr -> data = item;
        ptr -> next = head;
        head = ptr;
        cout<<"\nNode inserted!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    }

}
void insertLast(int value){
    struct node *ptr,*temp;
    int item = value;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        cout<<"\nOVERFLOW";
    }
    else{
        ptr->data = item;
        if(head == NULL){
            ptr -> next = NULL;
            head = ptr;
            cout<<"\nNode inserted!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }
        else{
            temp = head;
            while (temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = NULL;
            cout<<"\nNode inserted!!!!!!!!!!!!!!!!!!";

        }
    }
}

void deleteFront(){
    struct node *ptr;
    if(head == NULL){
        cout<<"\nList is empty\n";
    }
    else{
        ptr = head;
        head = ptr -> next;
        free(ptr);
        cout<<"\nNode deleted from the beginning ........................\n";
    }
}
void deleteLast(){
    struct node *ptr,*ptr1;
    if(head == NULL){
        cout<<"\nlist is empty";
    }
    else if(head -> next == NULL){
        head = NULL;
        free(head);
        cout<<"\n Node of the list deleted ...............\n";
    }

    else{
        ptr = head;
        while(ptr -> next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1 -> next = NULL;
        free(ptr);
        cout<<"\nDeleted Node from the last .....................\n";
    }
}
void display(){
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        cout<< "\n Nothing to print !!!!!!!!!!!!!!!!!!!!!!!!";
    }
    else
    {
        cout<<"\n Displaying values . . . . .\n";
        while (ptr != NULL)
        {
            cout<<"\n" << ptr -> data;
            ptr = ptr -> next;
        }
    }
}

int main ()  {
    insertFront (1);
    insertLast (0);
    insertLast (8);
    insertLast (9);
    display();
    deleteFront();
    display();
    deleteLast();
    display();


    return 0;
}
