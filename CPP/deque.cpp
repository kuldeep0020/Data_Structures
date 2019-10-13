
//-------------------------------------------------------------------------
//-------compile using "g++ -std=c++11 -o deque deque.cpp"---------
//-------------------------------------------------------------------------



/*  -----------------------------SAMPLE INPUT---------------------------------------
>>create 7 
Deque Created

>>push_back 45

>>push_back 98

>>view
7   45   98   

>>pop_back
98
>>view
7   45   

>>push_back 123

>>view
7   45   123   

>>pop_front 
7
>>view
45   123   

>>push_front 128

>>view
128   45   123   

>>tttt
Invalid Command 
>>sftgstgfset
Invalid Command 
>>setsetsetset
Invalid Command 
>>quit
*/



#include <iostream>
#include <string>

using namespace std;


typedef struct n{
public:
    int val;
    struct n * prev;
    struct n* next;//check togrther


}node;


class deque{
    public:
    node *top;
    node *root;

    void create(int dat){
        top=(node*)malloc(sizeof(node));
        root=(node*)malloc(sizeof(node));

        
        top->next=NULL;
        root->prev=NULL;
        top->val=dat;
        root=top;
        cout<<"Deque Created\n";

    }

    void pushFront(int dat){
     
        node *ele=(node*)malloc(sizeof(node));
        ele->val=dat;
        root->next=ele;
        ele->prev=root;
        ele->next=NULL;
        root=ele;


    }

    void pushBack(int dat){
        node *ele=(node*)malloc(sizeof(node));
        ele->val=dat;
        ele->next=top;
        ele->prev=NULL;
        top->prev=ele;
        top=ele;

    }

    int popBack(){
        int res=top->val;
        top=top->next;
        top->prev=NULL;
        return res;
    }

    int popFront(){
        int res=root->val;
        root=root->prev;
        root->next=NULL;
        return res;
    }

    void view(){
        node *temp=(node*)malloc(sizeof(node));
        temp=root;
        while(temp!=NULL){
            cout<<temp->val<<"   ";
            temp=temp->prev;
        }
        cout<<endl;

    }

}; 



int main(){
    deque deq;
  cout<<" supported commands  --   create n | push_back n | push_front n | pop_back | pop_front | view | quit "<<endl;
    cout<<"-------------see code for sample input -----------"<<endl;
    

    while(true){
        cout<<"\n>>";
        string input,command;
        int val;
        getline(cin,input);

        
        if (input=="pop_back"){
            cout<<deq.popBack();


        }
        else if (input=="pop_front"){
            cout<<deq.popFront();
        }

        else if(input=="view"){
            deq.view();
        }

        else if(input=="quit"){
            break;
        }

        else if("create"==(input.substr(0,input.find_first_of(' ')))) {
            val=stoi(input.substr(1+input.find_first_of(' ')));
            deq.create(val);

        }

        

        else if("push_back"==(input.substr(0,input.find_first_of(' ')))){
            val=stoi(input.substr(1+input.find_first_of(' ')));// getting the input from command
            deq.pushBack(val);
        }
        else if("push_front"==(input.substr(0,input.find_first_of(' ')))){
            val=stoi(input.substr(1+input.find_first_of(' ')));// getting the input from command
            deq.pushFront(val);
        } 

        
        else cout<<"Invalid Command ";

    }


}
