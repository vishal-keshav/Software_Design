#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

class myvector
{
public:
	int item[3];
	myvector(){
		item[0] = 100;
		item[1] = 200;
		item[2] = 300;
		iterator(0, this);
	}

	class iterator
	{
	private:
		int _index;
		myvector *mv;
	public:
		iterator(int index, myvector* mv) :_index(index), mv(mv){
		}
		iterator(int index) :_index(index){

		}
		bool operator != (const iterator& eit){
			return this->_index != eit._index;
		}

		int operator* (){
			return this->mv->item[_index];
		}
		void operator++()
		{
			_index++;
		}
		void operator++(int dummy)
		{
			_index++;
		}

	};

	iterator begin(){
		return iterator(0);
	}

	iterator end(){
		return iterator(3);
	}
};

class mylist
{
private:
	class Node
	{
	public:
		int data;
		Node *next = nullptr;

	};
	Node *head;
public:
	mylist(){
		head = new Node();
		head->data = 100;
		head->next = new Node();
		head->next->data = 200;
		head->next->next = new Node();
		head->next->next->data = 300;

	}

	class iterator
	{
	private:
		Node* _ptr;
	public:
		iterator(Node *ptr) :_ptr(ptr){
		}

		bool operator != (const iterator& eit){
			return this->_ptr != eit._ptr;
		}
		int operator* (){
			return this->_ptr->data;
		}
		void operator++ (){
			this->_ptr = this->_ptr->next;
		}
		void operator++ (int dummy){
			this->_ptr = this->_ptr->next;
		}

	};

	iterator begin(){
		return iterator(head);
	}

	iterator end(){
		return iterator(nullptr);
	}
};

int main()
{
	myvector mv;

	for (int d : mv){
		cout << d << " ";
	}
	mylist ml;

	for (int d : ml){
		cout << d << " ";
	}

	vector<int> numbers = {1,2,3,4,5};
	for (int number : numbers){
		cout << number << " ";
	}

	for (vector<int>::iterator bit = numbers.begin(); bit != numbers.end(); bit++){
		int number = *bit;
		cout << number << " ";
	}
	return 0;
}
