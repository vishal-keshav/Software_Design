/*
 * Class definition of component_node
*/

#include "component_node.h"

//Base member initialization in constructor
component_node::component_node(const int &item, component_node *left, component_node *right) : item_(item), left_(left), right_(right) {}

component_node::~component_node(){
	delete left_;
	delete right_;
}

int component_node::item(void) const {
	return item_;
}

component_node *component_node::left(void) const {
	return left_;
}

component_node *component_node::right(void) const {
	return right_;
}