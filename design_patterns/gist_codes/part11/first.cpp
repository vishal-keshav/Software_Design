using namespace std;


// Implement Stack data structure in C language

// Version - 1 - Single Instance design in C
/*int items[10];
int top = 0;

void push(int item)
{
	items[top] = item;
	top++;
}

int pop()
{
	top--;
	return items[top];
}*/

// Version - 2 - Multi Instance design in C

/*struct Stack
{
	int items[10];
	int top = 0;
};

void push(Stack *s, int item)
{
s->items[s->top] = item;
s->top++;
}

int pop(Stack *s)
{
s->top--;
return s->items[s->top];
}*/

// Version - 3 - Multi Instance design in C++

class Stack
{
public:
	int items[10];
	int top = 0;
	// gauranteed initialization
	Stack()
	{

	}
	// gauranteed de-initialization
	~Stack()
	{

	}

	//operator overaloding, which is not in C

	void push(int item) // void push(Stack *this, int item)
	{
		items[top] = item; // this->items[this->top] = item;
		top++; // this->top++;
	}

	int pop()
	{
		top--;
		return items[top];
	}
};

template<class T>
class LinkedList
{
public:
	void add()
	{
		//abdhdfff;
	}
};

int main()
{
	// Multi-instance design will require address
	/*Stack s1, s2, s3;

	push(&s1, 100);
	push(&s1, 200);
	push(&s1, 300);*/
	Stack s1, s2, s3;

	s1.push(100); //push(&s1, 100);
	s1.push(200); //push(&s1, 100);
	s1.push(300); //push(&s1, 100);

	//LinkedList<int> l1;
	//l1.add(5); // If this is uncommented, then only compilation error will happen.
	return 0;
}
