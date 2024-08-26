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

/* This bytecode takes one argument, say N, representing the sum of
   the number of required parameters and the number of optional
   parameters.  This bytecode creates a list of all the arguments
   starting at argument N, and assign it to the local variable with
   index N.  */
#define LISTIFY_REMAINING_ARGUMENTS 0x11

/* This bytecode is used to parse keyword arguments.  It takes four
   arguments.  The first argument, say N, represents the sum of the
   number of required parameters and the number of optional
   parameters.  The second argument, say KEY-COUNT-INFO, can be
   thought of as a single high bit and the remaining bits.  The high
   bit is set when &ALLOW-OTHER-KEYS is present in the lambda list,
   and cleared otherwise.  The remaining bits (7 in the normal case,
   15 in the long version of the bytecode), say KEY-COUNT, represent a
   count of the number of keywords explicitly mentioned in the lambda
   list.  The third argument, say KEYS is an index into the vector of
   literals where KEY-COUNT keywords are located.  The fourth argument
   to this bytecode, say BASE, is the index of the first local
   variable to be assigned a keyword argument.  The index of the local
   variable relative to BASE corresponds to the index of the keyword
   into the vector of literals relative to KEY.  If the number of
   remaining arguments is odd, then an error must be signaled.  If
   there is a keyword argument with a keyword that is not in the list
   of keywords in the vector of literals, then if the high bit of
   KEY-COUNT-INFO is cleared, then signal a program error. */
#define PARSE_KEYWORD_ARGUMENTS 0x13

/* Read the next byte as a label.  Unconditionally branch using that
   label.  The label is a little-endian signed integer and it is
   relative to the current program counter. */
#define JUMP_8 0x14

/* Read the next two bytes as a label.  Unconditionally branch using
   that label.  The label is a little-endian signed integer and it is
   relative to the current program counter. */
#define JUMP_16 0x15

/* Read the next three bytes as a label.  Unconditionally branch using
   that label.  The label is a little-endian signed integer and it is
   relative to the current program counter. */
#define JUMP_24 0x16

/* Read the next byte as a label.  Pop a value from the stack.  If the
   value is not NIL, branch using the label.  The label is a
   little-endian signed integer and it is relative to the current
   program counter. */
#define JUMP_IF_8 0x17

/* Read the next two bytes as a label.  Pop a value from the stack.
   If the value is not NIL, branch using the label.  The label is a
   little-endian signed integer and it is relative to the current
   program counter. */
#define JUMP_IF_16 0x18

/* Read the next three bytes as a label.  Pop a value from the stack.
   If the value is not NIL, branch using the label.  The label is a
   little-endian signed integer and it is relative to the current
   program counter. */
#define JUMP_IF_24 0x19
