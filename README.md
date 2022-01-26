## About

This is an example repository of rmkit.h being used in a cpp project (a port of
`input_demo` from rmkit's main repository). `second.h` and `second.cpp` are
used to demonstrate that rmkit.h can be imported from multiple files.

This works because rmkit.h is a single file header that keeps the
implementation gated behind `RMKIT_IMPLEMENTATION` define.

Notice a few things in the Makefile:

* rmkit.h is included in multiple files
* rmkit.h is compiled into rmkit.o using `-DRMKIT_IMPLEMENTATION`
* rmkit.o is linked against the other .o files to make the final executable

**NOTE:** You should probably use a copy of rmkit.h from the main rmkit
repository, instead of using the one included here.

## Contact

If you have questions or need help compiling a project, please open an issue on
this repository or the main rmkit repository
