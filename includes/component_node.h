
/*
 * An interface to a generic node to the tree.
 * This is header for the component_node class.
 * The pattern followed for node inheritance is Composite.
 * Recursively built objects. 
 * 
 *       component --------------> composite (possibly consisting of leaves)
 *           |					(operation is delegated to component that compose it)
 *           |
 *			 |-----------> leaf (actually defines the operation done on it).
 *
 * Unary, binary, ops nodes are composite components
 * leaf nodes are leaf components
 */

class component_node{
	public:
		/*Pure virtual function (de-constructor)
		A pure virtual function has to be overridden by the derived class*/
		virtual ~component_node()=0;
		/* const argument reference in a function means inside the the function,
		it will not be modified, but only used.
		When const is put after a member function, that would mean the member
		function is not allowed to alter the state of *this* object of which
		the member function is a part of. *this* is an implicit pointer to the 
		object in current scope.*/
		virtual int item() const;
		virtual component_node* left() const; //For leaf component, this is null
		virtual component_node* right() const; //For leaf component, this is null
	private:
		int item_;
		component_node *left_;
		component_node *right_;
};