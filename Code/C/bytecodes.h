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
   arguments.   FIXME: describe the return values.*/
#define CALL 0x03

/* This bytecode is similar to CALL, but the primary value of the call
   is pushed onto the stack.  If the call returns no values, then NIL
   is pushed instead. */
#define CAll_RECEIVE_ONE 0x04
