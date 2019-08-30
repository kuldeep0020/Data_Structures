#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
};
class linked{
  public:
  Node *Head,*ch;
  linked(){
    Head=NULL;
  }
  void push(int da){
    Node* new_node=new Node();
    new_node->data=da;
    new_node->next=Head;
    Head=new_node;
  }
  void display(){
    Node *tem=Head;
    while(tem!=NULL){
      cout<<tem->data<<" ";
      tem=tem->next;
    }
    cout<<endl;
  }
  int pa_check(Node *tem,int con){
    if(tem==NULL)
      return 1;
    con=pa_check(tem->next,con);
    if(con==0)
      return 0;
    if(tem->data!=ch->data){
      con=0;
    }
    ch=ch->next;
    return con;
  }
  void palindrome(){
    Node *tem=Head;
    ch=Head;
    int con=pa_check(tem,1);
    if(con)
      cout<<"Palindrome"<<endl;
    else 
      cout<<"NOT Palindrome"<<endl;
  }
};
int main(){
  linked list;
  list.push(1);
  list.push(1);
  list.push(2);
  list.push(6);
  list.push(6);
  list.push(6);
  list.push(2);
  list.push(1);
  list.push(1);
  list.display();
  list.palindrome();
  return 0;
}