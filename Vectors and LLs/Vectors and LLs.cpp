//Yasmina Mahdy 900221083

#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

void insertAfter(vector<int>& v, int firstValue, int secondValue, int& size)
{
	for (int i = 0;i < size;i++)
	{
		if (v[i] == firstValue)
		{
			v.insert(v.begin() + i + 1, secondValue);
			size++;
		}
	}

	//note to self: try to figure this out later

	/*auto it = v.begin();
	for (int i = 0;i < size;i++)
	{
		//not working properly
		it=find(v.begin()+i, v.end(), firstValue);
		if (it != v.end()) {
			v.insert(it + 1, secondValue);
			size++;
		}
	}*/

}

int main()
{
	int n, x, firstVal, secondVal; vector<int>v;

	//initializing the vecttor, n, firstVal and secondVal by user
	cout << "Please enter the number of integers you'd like to enter: ";cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "integer " << i + 1 << ": ";
		cin >> x;
		v.push_back(x);
	}

	cout << "Please enter the first value: "; cin >> firstVal;
	cout << "Please enter the second value: "; cin >> secondVal;

	//call function for insertAfter
	insertAfter(v, firstVal, secondVal, n);

	//call function for vector to linked list construcor

	cout << "\nVector to Linked List";
	LinkedList<int> VL(v);
	VL.print();

	cout << "\n\nNew Linked List:";

	//call function for adding, removing, printing and showing sum
	LinkedList<int> ll;
	for (int i = 0;i < 5;i++) {
		
		ll.addNode(i+1);

	}
	ll.removeNode();
	ll.print();
	cout << "\nSum is " << ll.sum()<<endl;

	return 0;
}

