//Include lib.
#include<iostream>
using namespace std;

//declare class for making a node
class Node{
	public:
	//data
	int data;
//pointer that will store the address of next node
	Node *next;
//pointer that will point to the previous node
	Node *prev;
//constructor which by default makes the pointer point to null
	Node(){
		next=NULL;
		prev=NULL;
	}
};

//declare class.....................................
class linkedlist{
	public:
	//this class contains the head and the nodes linked to each other
	//head-stores the address of a node hence datatype will be Node
	Node *head;
	//tail-stores the address of a node hence datatype will be Node
	Node *tail;
	//constructor to make head point to null by default
	linkedlist(){
		head=NULL;
		tail=NULL;
	}
	//insert
	void insert(int value){

		//make new node
		//declare a pointer that points to the created node
		Node*temp=new Node;

		//input data
		temp->data=value;

		//inseret the new node
		//for inserting the first node
		if(head==NULL){
			head=temp;
			tail=temp;
		}

		//forinserting any other node
		else{
			tail->next=temp;
			temp->prev=tail;
		}
			
		//updating the position of tail
		tail=temp;
	}

	//insertAt
	void insertAt(int value, int position){
		//create a new node and a pointer which points to that node
		Node*temp=new Node;
		//input the data
		temp->data=value;
		
		//reach the position to insert node
		if(position==1){
			//insert at 1st position
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
		else if(position==1+countitems()){
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
		
		else{
			Node*current=head;
			for(int i=1;i<position-1;i++){
				current=current->next;
			}
		
		//point temp's next to the next node
			temp->next=current->next;
			
		//point temp's prev to previous node
			current->next=temp;
			temp->prev=current;
			(temp->next)->prev=temp;
		}
	}
		
	//delete
		void deletee(){
			Node*current=tail;
			(tail->prev)->next=NULL;
			tail->prev=tail;
			delete current;
				
		}
		
	//deleteAt
	void deleteAt(int position){
		//reach the position of deletion
		if(position==1){
			Node*temp=head;
			head=head->next;
			delete temp;
		}
		else if(position==countitems()){
			Node*temp=tail;
			(tail->prev)->next=NULL;
			tail->prev=tail;
			delete temp;
		}
		else{
			Node*current=head;
			for(int i=1;i<position;i++){
				current=current->next;
			}
			//link the prev of next node to the previous node
			(current->next)->prev=current->prev;
			//link the next of previous node to next node
			(current->prev)->next=current->next;
			//delete the isolated node
			delete current;
		}
		
		
	}
	//countitems
	int countitems(){
		Node*current=head;
		int i=1;
		while(current->next!=NULL){
			i++;
			current=current->next;
		}
		return i;
	}
	//display data
	void display(){
		Node*current=head;
			while(current!=NULL){
				cout<<current->data<<"->";
				current=current->next;
			}
	}
};
		


int main(){
	int n,v,p;
//declare an object
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
		cout<<"Linked List: ";
	l1.display();
	cout<<endl;
	l1.deletee();
		cout<<"Linked List after deleting the last element: ";
	l1.display();
	cout<<endl;
		cout<<"Enter the position at which you want to delete node: "<<endl;
		cin>>n;
	l1.deleteAt(n);
		cout<<"Linked List after deleting the "<<n<<"th element: ";
	l1.display();
	cout<<endl;
	cout<<"Enter th eposition at which you want to insert a node: "<<endl;
		cin>>p;
			if(n>l1.countitems()+1){
				cout<<"Linked list does not have that many elements.";
			}
			else{
				cout<<"Enter the value you want to store in the inserted node."<<endl;
				cin>>v;
				l1.insertAt(v,p);
			}
		cout<<"Linked List after inserting a node at "<<n<<"th position of value "<<v<<" : ";
		l1.display();
		cout<<endl;
	




return 0;
}
