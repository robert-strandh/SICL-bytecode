/* This bytecode takes one argument which is the index of a local
   variable to push onto the stack. */
#define PUSH_LOCAL 0x00

/* This bytecode takes one argument which is the index of a literal to
   push onto the stack. */
#define PUSH_LITERAL 0x01

/* This bytecode takes one argument which is the index of a closure
   value to push onto the stack. */
#define PUSH_CLOSURE_VALUE 0x02

/* This bytecode takes one arguments which is the number of arguments
   to pass to the called function.  The top of the stack contains
   those arguments with the rightmost argument pushed last.  The
   function to call is located on the stack immediately below the
   arguments.  The values are stored in the values vector of the
   virtual machine */
#define CALL 0x03

/* This bytecode is similar to CALL, but the primary value of the call
   is pushed onto the stack.  If the call returns no values, then NIL
   is pushed instead. */
#define CAll_RECEIVE_ONE 0x04

/* This bytecode is similar to CALL, but it takes two arguments.  The
   first argument is as with CALL.  The second argument is the number
   of return values that should be pushed onto the stack, with missing
   values replaced with NIL. */
#define CAll_RECEIVE_FIXED 0x05

/* This bytecode pops a fixed number of values from the stack and
   assigns those values to local variables.  It takes two arguments.
   The first argument is the number of values to be popped and
   assigned.  The second argument is the lowest index of the local
   variable to be assigned to.  The value on top of the stack is
   assigned to the local with the highest index. */
#define ASSIGN_LOCALS 0x06

/* This bytecode pops a single value from the stack and assigns it to
   the local variable with the index supplied as the argument of this
   bytecode. */
#define ASSIGN_ONE_LOCAL 0x07

/* This bytecode creates a new cell and sets its contents to a value
   popped from the stack.  The new cell is then pushed to the
   stack. */
#define MAKE_CELL 0x08

/* This bytecode pops a value off the stack, and that value is known
   to be a cell.  It then pushes the contents of the cell onto the
   stack. */
#define CELL_REFERENCE 0x09

/* This bytecode pops a value off the stack, and that value is known
   to be a cell.  It then pops another value off the stack and copies
   that value into the cell. */
#define CELL_SET 0x0a

/* This bytecode takes one argument which is an index into the vector
   of literals.  That literal is a function template with a closure
   size N.  This bytecode pops N values from the stack and creates a
   new closure consisting of the template and the popped values as its
   closure vector, such that the first value popped is the last
   element in the closure vector.  The resulting closure is pushed
   onto the stack.  */
#define MAKE_CLOSURE 0x0b

/* This bytecode takes one argument which is an index into the vector
   of literals.  That literal is a function template with a closure
   size N.  This bytecode creates a new closure with an uninitialized
   closure vector of size N.  The resulting closure is pushed onto the
   stack.  */
#define MAKE_UNINITIALIZED_CLOSURE 0x0c

/* This bytecode takes one argument which is the index of a local
   variable.  That variable contains an uninitialized closure produced
   by MAKE_UNINITIALIZED_CLOSURE with a template that has a closure
   size N.  This bytecode pops N values off of the stack and mutates
   the uninitialized closure so that its closure vector contains those
   popped values.  The first value popped becomes the last element of
   the closure vector. */
#define INITIALIZE_CLOSURE 0x0d

/* This bytecode ends the execution of the current function. */
#define RETURN 0x0e

/* This bytecode takes one argument which is the number of required
   parameters, say N.  It sets the first N local variables to the
   first N arguments passed to this function. */
#define BIND_REQUIRED_PARAMETERS 0x0f

/* This bytecode takes two arguments, say N and M, where N is the
   number of required parameters and M is the number of optional
   parameters.  This bytecode sets the M local variables starting at N
   to the M arguments starting at N.  If there are fewer than M
   remaining arguments, then the corresponding local variables are set
   to a special "unsupplied" value that has no particular meaning
   except to the bytecode JUMP_IF_UNSUPPLIED. */
#define BIND_OPTIONAL_PARAMETERS 0x10
