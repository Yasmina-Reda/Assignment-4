#pragma once
#include <vector>
using namespace std;

template <class T>
struct node {
	T value;
	int occurrence=1;
	node<T>* next=NULL;
};

//note to self, if same template you cannot bypass <T> in node?
template <class T>
class LinkedList {
private:
	node<T> *first=NULL;


public:
	//default constructor
	LinkedList() {};

	//constructor that creates a linked list starting with a node
	LinkedList(T info)
	{
		first = new node<T>();
		first->value = info;
	}

	~LinkedList()
	{
		//deletes dynamically allocated nodes

			node<T>* temp = first, * next = temp;
			while (temp != NULL)
			{
				next = temp->next;

				//note to self: cannot delete unless dynamically allocated
				delete temp;
				temp = next;
			}
	}

	//adds a new node to the beginning of a linked list
	void addNode(T info)
	{

		if (first == NULL) {
			first = new node<T>();
			first->value = info;
		}
		else {
			node<T>* N = new node<T>();
			N->value = info;
			N->next = first;
			first = N;

			//to insert at the end of the list
			
			//node<T> *temp = first;
			//while (temp->next != NULL)
			//{
			//	temp = temp->next;
			//}

			//temp->next = N;
		}
	}


	//removes and returns a pointer to the node at the beginning of a linked list
	node<T>* removeNode()
	{
		//returns a NULL pointer
		if (first == NULL) {
			cout << "Error. Nothing to remove";
			return first;
		}
		
		else {

			//to a remove a node dynamically allocated in VL
				node<T>* last = first;
				//saves the data of the node to send back before deallocating
				node<T> sendBack = *last;
				first = first->next;
				delete last;
				return &sendBack;

			//to remove from end of node
			
			//node<T> *last, *temp = first;
			//while ((temp->next)->next != NULL)
			//{
			//	temp=temp->next;
			//}
			//last = temp->next;
			//temp->next = NULL;
			//node<T> sendBack = *last;
			// delete last;
			//return &sendBack;
		}
	}


	//creates and returns a linked list based on the vectors elements
	LinkedList (vector<int> v)

	{
		for (int i = 0;i < v.size();i++)
		{
			bool exist = false; node<T>* temp = first, *element=temp; 

			//could only think of a nested loop to do it 
			//but makes time complexity n^2
			while (temp != NULL && !exist)
			{
				if (v[i] == temp->value) exist = true;
				//to store the correct element
				element = temp;
				temp = temp->next;
			}

			//if it does not exist will add a new node
			if (!exist) addNode(v[i]);
			//if it exists will increment its occurence
			else element->occurrence++;

		}
	}

	//prints elements of the linked list
	void print()
	{
		node<T>* temp = first;
		while (temp!= NULL)
		{
			cout <<"\nElement: "<< temp->value << " Occurence: "<<temp->occurrence;
			temp=temp->next;
		}
		cout << endl;
	}

	//assume that the question wants to return the sum
	//of the elements in the "linked list" and not the sum of those
	//that were in the vector, in which case the value
	//of each node would've been multiplied by its occurence
	int sum()
	{
		int SUM=0;
		node<T>* temp = first;
		while (temp!= NULL)
		{
			SUM += temp->value;
			temp=temp->next;
		}
		return SUM;
	}



};
