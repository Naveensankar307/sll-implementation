#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node *Node;

Node head = NULL;
Node nn,temp,cur;
Node getNode();
Node readdetails(Node nn);
Node insertatbeg(Node nn);
Node insertatend(Node nn);
Node deleteatbeg(Node head);
Node deleteatend(Node head);
void display(Node nn);

main(){
    int ch;
    while(1){
        cout<<"enter 1 for insert at begining"<<"\n";
        cout<<"enter 2 for insert at end"<<"\n";
        cout<<"enter 3 for delete at begining"<<"\n";
        cout<<"enter 4 for delete at end"<<"\n";
        cout<<"enter 5 for display"<<"\n";
        cout<<"enter 6 to exit"<<"\n";
        cin>>ch;
        switch (ch)
        {
        case 1: head = insertatbeg(nn);
            break;
        case 2:head = insertatend(nn);
            break;
        case 3:head = deleteatbeg(head);
            break;
        case 4:head = deleteatend(head);
            break;
        case 5:
            display(nn);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid entry";
            break;
        }

    }

}

Node getNode(){
    nn = (Node)malloc(sizeof(Node));
    if(nn == NULL){
        cout<<"memory not allocated ";
    }
    else
        return nn;
}
Node readdetails(Node nn){
    cout<<"enter the data : ";
    cin>>nn->data;
    nn->next = NULL;
    return nn;
}
Node insertatbeg(Node nn){
    nn = getNode();
    nn = readdetails(nn);
    if(head == NULL){
        head = nn;
    }
    else{
        nn->next = head;
        head = nn;
    }
    return head;
}
Node insertatend(Node nn){
    nn = getNode();
    nn = readdetails(nn);
    if(head == NULL){
        head = nn;
    }
    else{
        cur = head;
        while(cur->next!= NULL){
            cur = cur->next;
        }
       cur->next = nn;
       return head; 
    }
}

Node deleteatbeg(Node head){
    if(head == NULL){
        cout<<"list is empty";
    }
    else if(head->next == NULL){
        cout<<"deleted head->data";
        free(head);
    }
    else{
        temp = head;
        cur=head->next;
        while(cur->next!=NULL){
            temp=temp->next;
            cur = cur->next;
        }
        cout<<"delete cur->data";
        free(cur);
        temp->next = NULL;
        return head;
    }
}
Node deleteatend(Node head){
    if(head == NULL){
        cout<<"list is empty";
    }
    else if(head->next == NULL){
        cout<<"deleted head->data";
        free(head);
    }
    else{
        temp = head;
        head = temp->next;
        cout<<"deleted head->data";
        free(temp);
        return head;
    }
}

void display(Node nn){
    if(head == NULL){
        cout<<"list is empty";
    }
    else{
        temp = head;
        while(temp->next != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
}
