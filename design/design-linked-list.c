#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node*next;
}Node;


typedef struct {
    Node *head;
    
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj ->head = NULL;
    return obj;
    
    
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    Node *temp = obj->head;
    int count = 0;

    while(temp!=NULL){
        if(count == index){
            return temp->val;
        }
        count++;
        temp = temp->next;
    }
    return -1;
    
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if(obj->head == NULL){
        obj->head = newNode;
        return;
    }
    Node* temp = obj->head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index==0){
        myLinkedListAddAtHead(obj,val);
        return;
    }
    Node* temp = obj->head;
    int count = 0;
    while(temp!=NULL && count < index-1){
        temp = temp->next;
        count++;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(obj->head == NULL){
        return;
    }
    if(index == 0){
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        return;
    }
    Node* temp = obj->head;
    int count =0;
    while(temp!=NULL && count < index-1){
        temp = temp->next;
        count++;
    }
    if(temp == NULL || temp->next == NULL){
        return;
    }
    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *temp = obj->head;
    while(temp!=NULL){
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/