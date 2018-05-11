
/*
 * An interface for all kinds of expression tree
 * A tree is expected to provide iterating functionality
 * It has to made of component_nodes
 *
 * Adapter pattern implements manages the different apis of
 * operation implementer, by showing client a consistent api
 * that does not change.
 * Bridge patter however, does not have such problem, all the
 * implementer of apis have consistent api that a client expects.
 *
 * expression_tree interfaces an operation to client, where operation
 * is actually implemented by root component_node.
 * 
 * Abstraction (expression_tree) ----------------> Implementer
 *												(component_node)
 *														|
 *														|
 *											------------|-------
 *											|				   |
 *							    concrete_implementer  concrete_implementer
 *							   (composite_unary_node) (composite binary node)	
 */

class expression_tree{
	public:
		expression_tree(component_node *root);
		// Function overloading over constructor
		expression_tree(const expression_tree &e);
		~expression_tree();
		//Copy constructor
		void operator=(const expression_tree &e);
		bool is_null() const
		const int item() const
		
	private:
		int item_;
		/*
		 * Shared pointer is similar to a normal pointer, difference
		 * is that it is responsible for deleting the pointer when
		 * object goes out of scope
		 */
		std::shared_ptr <component_node> root_;
};