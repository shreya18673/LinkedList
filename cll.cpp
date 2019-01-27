#include<iostream>
using namespace std;

//class node
class node{
	public:
	//data input
	int data;
	//next
	node*next;
	//constructor
	node(){
		next=NULL;
	}
};

//class linked list
class linkedlist{
	public:
	//this class contains the head and the nodes linked to each other
	//head-stores the address of a node hence datatype will be Node
	node *head;
	//tail-stores the address of a node hence datatype will be Node
	node *tail;
	//constructor to make head point to null by default
	linkedlist(){
		head=NULL;
		tail=NULL;
	}
	
	//insert
	void insert(int value){
		//create new node an point a pointer to it
		node*temp=new node;
		//input the data
		temp->data=value;
		//If 1st node is added
		if(head==NULL){
			head=temp;
			tail=temp;
			head->next=head;
		}
		else{
			tail->next=temp;
			tail=temp;
			tail->next=head;
		}
	}
			
	//insertAt
	void insertAt(int value,int position){
		//creat a new node and point a pointer to it
		node*temp=new node;
		//input the data
		temp->data=value;
		//get to the position where node has to be inserted
		if(position==1){
			cout<<"******"<<endl;
			temp->next=head;
			head=temp;
			tail->next=head;
		}
		else if(position==countItems()+1){
			tail->next=temp;
			tail=temp;
			tail->next=head;
		}
		else{
			node*current=head;
			for(int i=1;i<position-1;i++){
				current=current->next;
			}
			temp->next=current->next;
			current->next=temp;
		}
		
	}
	
	
		
	//delete
	void deletee(){
		node*temp=tail;
		node*current=head;
		while((current->next)->next!=head){
			current=current->next;
		}

		current->next=head;
		tail=current;
		delete temp;
	}
	
	//deleteAt
	void deleteAt(int position){
		
		//reach the position
		if(position==1){
			node*dumb=head;
			head=head->next;
			tail->next=head;
			delete dumb;
		}
		else if(position==countItems()){
			node*temp=tail;
			node*current=head;
			while((current->next)->next!=head){
				current=current->next;
			}

			current->next=head;
			tail=current;
			delete temp;
		}
		else{
			node*temp;
			node*current=head;
			for(int i=1;i<position-1;i++){
				current=current->next;
			}
			temp=current->next;
			current->next=(current->next)->next;
			delete temp;
		}
		
	}
	
			
	//countItems
	int countItems(){
		node*current=head;
		int i=1;
		while(current->next!=head){
			current=current->next;
			i++;
		}
		/*for(int i=1;current->next!=NULL;i++){
			current=current->next;
		}
		int z=i;*/
		return i;
	}
	//display
	void display(){
		//declare a pointer to store the value of head
		node *current=head;
		/*for(Node *current=head;current !=NULL;current->next){
			cout<<current->data<<"=>"<<endl;
		}*/
		while(current->next != head){
            cout << current->data << "=>";
            current = current->next;
        }
        cout<<current->data<<endl;
		
	}
};



int main(){
	int p,v,d;
	linkedlist l1;
	
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insertAt(10,6);
	
	l1.deletee();
	l1.deleteAt(1);
	cout<<l1.countItems()<<endl;
	l1.display();

return 0;
}
