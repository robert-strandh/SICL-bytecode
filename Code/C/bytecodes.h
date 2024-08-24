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

