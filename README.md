build the rust and copy .dll over to output dir of C++ project

C++ project has a .h file

then, create .def file in there

```bash
EXPORTS
printPhrase
```

in developer prompt make .lib file

```bash
lib /def:mylib.def /out:mylib.lib /machine:x64
```

then run
