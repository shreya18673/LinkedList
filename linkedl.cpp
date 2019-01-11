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
//constructor which by default makes the pointer point to null
	Node(){
		next=NULL;
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
	}
//insert
	void insert(int value){
		//create a new node in heap
		//declare a pointer in stack which will store address of the created node
		Node *temp=new Node;
		//fill in the data
		temp->data=value;
		//if 1st node is added
		if(head==NULL){
			
		//1st node should have head as its pointer
			head=temp;
		}
		else{
		//for any other node
			
			tail->next=temp;
		}
		//updating the position of tail		
			tail=temp;
	}
//insertAt
	void insertAt(int position, int value)
	{
		if(position !=1){
			//reach the place of insertion
			Node *current=head;
			for(int i=1;i<position-1;i++){
				current=current->next;
			}
			/*int i =1;
		    while(i < position-1)
			{
		        i++;
		        current = current->next;
		    }*/
			//create a node
			Node *temp=new Node;
			//fill in the data
			temp->data=value;
			//point to the next node
			temp->next=current->next;
			current->next=temp;
			
		}
		else{
			//insert at 1st position
			Node *temp=new Node;
			temp->data=value;
			temp->next=head;
			head=temp;

			
		}
		
	}
		
		
			
//delete
	void deelete(){
		//declare pointer that points to the address store in tail
		Node *temp=tail;

		//declare a pointer that points to the address stored in head
		Node *current=head;

		//make current point to the previous node of the node which has to be deleted
		while(current->next!=tail){
			current=current->next;
		}

		//let the tail point to the previous node of the node which has to be deleted
		tail=current;

		//break the link b/w the last two nodes
		tail->next=NULL;

		//delete the node permanently	
		delete temp;
	
	}
//deleteAt
	void deleteAt(int position){
		if(position !=1){
			//point current at the 1st node
			Node *current=head;
			//reach the position
			int i=1;
			while(i<position){
				i++;
				current=current->next;
			}
			//point ptr to position node's next node
			Node *ptr=current->next;
			//temp points to the position node
			Node*temp=current;
		
			//reach the previous node
			Node *present=head;
			int j=1;
			while(j<position-1){
				j++;
				present=present->next;
			}
		
			//make a link b/w the previous node and the node after the position node
			present->next=ptr;
		
			//break the link b/w position node and the next node
			temp->next=NULL;

			//delete temp
			delete temp;
		}
		else{
			//point temp to 1st node
			Node*temp=head;
			//assign head to 2nd node
			head=temp->next;
			//delete the 1st node
			delete temp;
		}
			
		
	}
		
//countItems
	int countItems(){
		Node*current=head;
		int i=1;
		while(current->next!=NULL){
			i++;
			current=current->next;
		}
		//cout<<"No. of items in linked list are "<<i<<endl;
		return i;
	}	

//display
	void display(){
		//declare a pointer to store the value of head
		Node *current=head;
		/*for(Node *current=head;current !=NULL;current->next){
			cout<<current->data<<"=>"<<endl;
		}*/
		while(current != NULL){
            cout << current->data << "=>";
            current = current->next;
        }
		cout<<endl;
	}
};
	




int main(){
	int z,n,v;
	//object
	linkedlist l1;
		//insering nodes 
		l1.insert(1);
		l1.insert(2);
		l1.insert(3);
		l1.insert(4);
		l1.insert(5);
		//displaying the original linked list
		cout<<" * The linked list is ";
		l1.display();
		cout<<endl;

		//deleting the last node of the linked list
		l1.deelete();
		cout<<" * After deleting the last node ";
		l1.display();
		cout<<endl;

		//deleting the node at 2nd position
		l1.deleteAt(2);
		cout<<" * After deleting node at 2nd position ";
		l1.display();
		cout<<endl;

		//count items
		z=l1.countItems();
		cout<<" * No. of items are "<<z<<endl;

		//asking the user for position to insert the node and its value
		cout<<"Enter the position at which you want to insert node."<<endl;
		cin>>n;
		cout<<"Enter the value you want to store at the inserted node."<<endl;
		cin>>v;
	
		//if the entered position is not +nt in the linked list
		if(n>z){
			cout<<" * Linked List does not have that many elements"<<endl;
		}
		//if the entered position is present in the linked list
		else{
		l1.insertAt(n,v);
		cout<<" * After insering node with data value = "<<n<<" at "<<v<<" position ";
		l1.display();
		cout<<endl;
		}*/
return 0;
}

