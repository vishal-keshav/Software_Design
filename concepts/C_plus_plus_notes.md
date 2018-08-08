### Class, constructors and destructors:
RAII: **Resource allocation is initialization** paradigm is followed for memory cleanup
of variables that goes out of scope. Typically, the variables declared in main program
resides in stack, and upon program exit(going out of scope), the de-allocation are taken
care by program itself. However, variables that are allocated dynamically (resides in heap)
have to be manually deleted. delete or delete[] ptr does clean up the memory, or in other
words the vaiable goes out of scope with memory clean-up. These ensure no memory leaks.

* For structures and classes, destructors prodive a mean to do so for all the resources
holded by the class (dynamically allocated) to deallocate them, when the class variable
goes out of scope. If the class is a variable, upon program exit, they go out of scope
caling destructors for further cleanup. If they classes itself are allocated as pointer,
then delete will make the variabels go out of scope and hence calling the destructors
for deallocation of dynamically allocated memory holded by the class.

Copy constructor can be forbidded by following way:
```
Class_name(const Class_name&) = delete
```

### friend keyword:
A friend keyword before a Class name or a function inside a class gives that Class or
function the ability to access protected and private variables and functions. This
relationaship is not transitive and not inherited.

### virtual keyword:
A virtual keyword for a member function in a base class denotes that derived class
**can** override the function, and if it does so, then at the runtime, depending on the
pointer pointing to one memory location (base or derived object), particular function
will be executed. Such virtualization is possible only with pointers.
virtual keyword does not mean its an interface, both base and derived can implement that.

### **this** pointer:
An object of a declared Class is mere an address to the structure, where class varibables
resides. When a function on object is called, obj.fun(arg), in reality, a function with
object address along with arguments are called fun(&obj, arg). This is true for all the
class functions including constructor(s) and destructor. In the class function, the object's
address is interpreted by a const pointer called "this". So, this is a hidden parameter
of an object, and can be explicitely used. For example, this->class_variable is same as
using obj.class_variable. The main use of explicitely accessing this pointer in a class
is done for chanining expressions. Typically, instead of returing void, * this is returned.
The returned value is merely an object value, upon which more class funtions can be called.
```
obj.fun1(arg1).fun2(arg).fun3(arg3)
```

### inline functions:
The keyword inline before the function name forces compilers to compile the function defenition
code everywhere where it has been called. For smaller functions which are being called multiple
times, inline is desirable since during runtime, intructions are not needed to be loaded and
restored back when a funtions call happens, and because of increased locality of reference
(instruction cache), execution time improvements can be seen.

### Template and typename:
If function is to use multiple data types, a placeholder concept comes in handy. Template
defines that there are going to be generic data type on which function has to work and
typename is used to declare and name all those generic data type.
```
template <typename T1, typename T2, typename T3>
T3 func(T1 arg1, T2, arg2){}
```

* A good practice is to declare input and return argument by reference, since Template can
be used for a class (having operators overloaded)
```
T3& func(T1& arg1, T2& arg2){}
```
For a templated class, if class functions defenition are seperated from class declaration,
then while defining class functions, class template is used like below:
```
template <typename T>
void Class_name<T>::func() {}
```
It has to be noted that while compiling the this, linker problems can be caused as compiler
probably does not know the function defenition of one of the other type when defenition is
compiled. So it is recommended that templated class defenition be put in class declaration.
Specializing(for which a genric placeholer not work) a class template requires below method:
```
template<>
class Class_name<specialized_type>{}
```

### Default arguments:
Just like in python, arguments can be supplied, if not supplied, the default value will be used
```
void func(int a, int b=1, int c=4){}
```
b and c are default arguments. Once a default argument is declared, all subsequent arguments
has to have default values.

### Passing arguments by reference(symbolic and pointer):
Symbolic reference passes the local variable reference without any copy.
Pointer passes the memory address.
Symbolic reference example:
```
void fun(int &a){}
void main(){int a = 10, fun(a)}
```
Symbolic reference is enforced by function defenition, from main,
the variable is passed as value.
Pointer reference example:
```
void fun(int * a){}
void main(){int a = 10, fun(&a)}
```
Pointer reference is enforced by **both** main and fun

### Smart pointer and move semantics and copy semantics:
Smart pointers are designed to handle auto resource re-claim when pointers go out of scope.
unique_ptr are used if requirment is to exclusively handle the resource. copy will throw an
error during compile, but move semantics can be used to transfer the ownership.
*unique_ptr* can manage the destruction of array as well, like *std::array*, *std::vector*
**std::make_unique<Class_name>(args)** is a recommneded way to create unique_ptr.
make_unique is a templated function to create such pointer and is safe for handelling resource.
```
unique_ptr<Class_name> p1 = new Class_name()
unique_ptr<Class_name> p2 = std::move(p1)
```
p2.get() is the memory address of Class_name object.
shared_ptr are used when a resource is to be shared by multiple owners(done through ref count).
copy semantics works on shared_ptr and compiler does not complain.
**std::make_shared<Class_name>(args)** is recommended for shared_ptr creation. Yet, for array
like resource, shared_ptr does not handle. A unique_ptr can be converted to shared_ptr, but
vice versa is not possible.
```
shared_ptr<Class_name> p1 = new Class_name()
shared_ptr<Class_name> p2(p1); //or p2 = p1
p1.get()
p1.use_count()
p1.reset()
```
weak_ptr does is same as shared_ptr but does not hold ref count. They are used to break the
**cyclic dependencies**.

### Exception handelling:
A caller can either handle the exception in catch block or throw it back to its caller in catch block.
In try block, it the caller will be able to handle the case properly, if not, then catch block.
```
void fun(int a){
    //Create an error, and throw back to caller (main)
    throw -1;
}
void main(){
    try{
        fun(100); //Creates and throws an exception
    }
    catch(int exception){
        cout << "Exception caught" << endl;
    }
}
```

### const and constexpr:
const before any variable ensure it remains unchanged, and if it unchanged, during compile,
error is thrown. constexpr is resolved at compilation time also but values are fixed at compile.

### namespace and using directives:
A namespace is used for resolvinf name collision between variables of same name or function of
same name. If no namespace is specifiedm it is assumed to be global name space.
**::var_name** takes to global namespace and resolves for var_name, where as namespace_name::var_name
resolves for var_name in namespace_name. In order to not use directive multiple times, using
keyword is used
```
using std::cout -> now on in this scope, cout will be resolved from std namespace
using namespace std -> now on in this scope, everything will be first resolved from std namespace
```

### Casting data types:
static_cast is used to convert one fundamental data type to another, and typecheck is done at
compile time. These can convert 4 bytes to 1 byte (int to char).
```
data_type1 var1;
data_type2 var2 = static_cast<data_type2>(var1)
```
[TO-DO] dynamic_cast
[TO-DO] reinterpret_cast

### auto keyword:
Automatic type deduction of a variable from initializer. These cannot be used as parameter
declaration in function defenition.

### Variadic templates (**std::forward** covered):
This method is used to pass variable number of arguments in a function, where type check are
done at compile time. It requires a base case and generic case. The variable number of arguments
are called template_pack. A simple example:
```
template<typename T> //Specialized
T sum(T a){return a}
template<typename T, typename... Args>
T sum(T a, Args... args){return a+sum(args...)}
```
[TO-DO] These can also be extended to classses.
[LINK1](https://eli.thegreenplace.net/2014/variadic-templates-in-c/)
[LINK2](http://bajamircea.github.io/coding/cpp/2016/04/07/move-forward.html)

### Bind function and placeholders:
std::bind(function) creates a binded function with some functional characteristics modified.
With positional placeholders, the binded function may not be required to provide all arguments
and that too in any order. using namespace std::placeholder let use **_1**, **_2**, **_3** ... as
placeholder for the creation of new binded or modified function.
```
int sum(int a, int b, int c){return a + b + c}
auto binded_fn = std::bind(sum, **_2**, 100, **_1**)
binded_fn(10, 50) = sum(50, 100, 10)
```

### Lambda functions:
```
f = [capture clause] (parameters) -> return-type  
{   
   definition of method   
}
```

### std::function:
This class wraps any callable into an object that can moved and copied. Supported callable
types are function, a function pointer, a pointer to member, or any kind of function object.
The bind on a function using placeholder creates a std::function.
```
include<functional>
void sum(int a, int b){return a+b}
std::function<void(int, int)> f_1 = sum;
std::function<void()> f_2 = []() { print_num(50, 100); };
f_1(50, 100); f_2();
```

### Override keyword:
This keyword is being put at function defenition of derived class, to help developer
to have a check if the function signature matches to that of base class and the function
is virtual (meaning base function was intended to be overwritten and decided on runtime).

### final specifier:
A final specifier in a virtual function of base class means that derived class cannot
re-write the implementation of that function. Also, if class is final, no inheritence is
allowed.

### explicit, default and delete keyword for class member function:
default keyword instructs compiler to autogenerate the body of function.
delete keyword restricts compiler to autogenerate the body of function.
These are required since modern compiler generate constructor, copy constructor,
destructor etc body automatically.

[TO-DO] Shallow and deep copy:
[LINK3](http://www.learncpp.com/cpp-tutorial/915-shallow-vs-deep-copying/)
