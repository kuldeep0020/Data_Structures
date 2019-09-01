#include<bits/stdc++.h>
using namespace std;
//node, simplest element of linked list contains data and next pointer
class Node{
  public:
  int data;
  Node *next;
};

//linked class that will bind nodes together to create linked list
class linked{
  public:
  Node *Head,*ch;
  linked(){
    Head=NULL;  //initializing head with null when linked class is created
  }
  //add data in the begining of linked list
  void push(int da){
    Node* new_node=new Node();  //new node created
    new_node->data=da;  //data initialized by da which is passed as argument
    new_node->next=Head;  //points node which is pointed by head
    Head=new_node;  //changing head pointer to point new node
  }
  //function to display all the elements
  void display(){
    Node *tem=Head; //initialized tem with head
    while(tem!=NULL){ //loop till end
      cout<<tem->data<<" ";
      tem=tem->next;  //changing tem to point tem`s next
    }
    cout<<endl; 
  }
  //recursive function to check palindrome
  int pa_check(Node *tem,int con){
    if(tem==NULL) //if reached depth then return 1
      return 1;
    con=pa_check(tem->next,con);  //calls next element by calling pa_check with next`s address
    if(con==0)  //if con==0 means that palindrome check found elements that not match so no need to continue after that
      return 0;
    if(tem->data!=ch->data){  //if data doesnt match than return 0 which make con 0
      con=0;
    }
    ch=ch->next;  //ch pointer at every execution changes its place by one element
    return con; //it returns 1 if all ok till now 0 if not
  }
  void palindrome(){
    Node *tem=Head; //initialized tem with head
    ch=Head;
    int con=pa_check(tem,1);  //calls pa_check function with head as argument and if get 1 then it is palindrome
    if(con)
      cout<<"Palindrome"<<endl;
    else 
      cout<<"NOT Palindrome"<<endl;
  }
};
int main(){
  linked list;  //created linked list
  list.push(1);
  list.push(1);
  list.push(2);
  list.push(6);
  list.push(6);
  list.push(6);
  list.push(2);
  list.push(1);
  list.push(1);
  list.display(); //to call display
  list.palindrome();  //to check if it was palindrome
  return 0;
}