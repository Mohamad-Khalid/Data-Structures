#include <iostream>
using namespace std;

// class stack implementation (Linked Stack)
// Principle : Last in First out (LEFO)

template<class t> 
class stack{

	// node contain value and a pointer of node type
	struct node
	{
		int value;
		node *next;
	};

	node*stackTop; // pointer to the top element

	int stackSize; // number of elements of the stack


public:

	// Initialize the values of stackTop and stackSize
	stack(){ 
		stackTop = NULL;
		stackSize = 0;
	}

	// boolean function that returns true if the stack is empty
	// and false if it contains elements
	bool empty(){
		return stackSize == 0;
	}

	// push elements to the stack
	void push(t v){
		node *newElement = new node;
		newElement -> value = v;
		newElement -> next = stackTop;
		stackTop = newElement;
		stackSize++;
	}

	// delete the top element 
	void pop(){
		if(empty()){
			cout<<"Empty stack\n";
		}
		else{
			node *temp = stackTop;
			stackTop = stackTop -> next;
			temp = NULL;
			delete temp;
			stackSize -- ;
		}
	}

	// function that returns the size of thre stack
	int size(){
		return stackSize;
	}

	//returns the value of the top element
	int top(){
		if(empty()){
			cout<<"Empty stack\n";
		}
		else{
			return stackTop -> value;
		}
	}

	// print all elements in the stack
	void display(){
		node *current = stackTop;
		while(current!=NULL){
			cout<<current -> value<<" ";
			current = current ->next;
		}
	}

};

// function to test the stack
void testStack(stack<int>s){
	// push,pop,size,empty,display
	int choice = 1;
	while(choice){
		printf("\nEnter your choice\n");
		printf("1- push\n2- pop\n3- get the size\n4- check if empty\n5- print the stack\n0- to exit\n");
		scanf("%d",&choice); // suppose the user will input a number


		if(choice == 1){
			int value;
			printf("Enter the value\n");
			scanf("%d",&value);
			s.push(value);
		}

		else if(choice == 2){
			s.pop();
		}		

		else if(choice == 3){
			printf("size is : %d\n",s.size() );
		}	

		else if(choice == 4){
			if(s.empty())
				printf("Empty Stack\n");
			else
				printf("Not empty stack\n");
		}	
		else if(choice == 5){
			s.display();
			puts("");
		}
		else if(choice == 0){
			break;
		}	
		else{
			printf("Enter a valid choice :)\n");
		}	
	}
}


int main(){

	stack <int> st;
	testStack(st);
	
	return 0;
}
