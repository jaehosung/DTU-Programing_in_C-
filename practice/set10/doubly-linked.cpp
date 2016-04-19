#include "doubly-linked.h"
List::List(void){
    first = NULL;
};
//Destructor
List::~List(void){
    Node * temp = first;
    if(temp!=NULL){
        while(temp == NULL){
            Node * next = temp ->next;
            delete temp;
            temp = next;
        }
    }
}; 
// This should insert n in the list
void List::insert(int n){
    Node *temp = new Node;
    temp->val = n;
    temp->prev = NULL;
    temp->next = NULL;

    if(first == NULL){
        first = temp;
    }else{
        Node *itr = first;

        while(itr->next != NULL){
            itr = itr->next;
        };

        temp->prev = itr;
        itr->next = temp;
    }
};
// This should reverse the list
void List::reverse(void){
    if(first!=NULL){
        Node *temp = first;
        while(temp!=NULL){
            Node *swapTemp = temp->next;
            temp->next = temp->prev;
            temp->prev = swapTemp;
            first = temp;
            temp = temp->prev;
        }
    }
};
// This shoiuld print the list
void List::print(void){
    Node *temp = first;
    if(first != NULL){
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

