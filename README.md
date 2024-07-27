This repository will eventually contain a bytecode-only version of the
SICL Common Lisp implementation.  We are using the bytecodes from the
Maclina Common Lisp library, initially designed for the Clasp Common
Lisp implementation.

We are making a bytecode-only version for several reasons:

- It is easier to debug a system based on bytecodes than a system
  based on native machine code.

- Many issues in the SICL system can be found and fixed before we make
  a system with native code generation.

- We can design a real debugger in a system using bytecodes without
  slowing down the code too much, since it is already not that fast.
  Experience with a real debugger can then be used in a system with
  native code generation.

- Perhaps the most crucial part of SICL is the bootstrapping
  procedure.  This procedure makes it possible to use external
  libraries that implement part of the Common Lisp standard, yet use
  the full language for the implementation.  A bytecode-only version
  of SICL will confirm the validity of the bootstrapping procedure.

- We hope to generate interest for SICL relatively early with a
  bytecode-only version.  A version that generates native code will
  take much longer to create.

- Some libraries that are required for a version of SICL that
  generates native code are not yet usable, and we have no estimated
  time for them to be usable.

To simplify the transition from a bytecode version of SICL to a
version that generates native code, the bytecode version uses the
object representation designed for the version with native code
generation.