# CCinit
⚠️ This is stil a largely experimental thing.  
A tool that serves so that the dependences can be more easily managed, in an easy way.
The `library` directory is not really supposed to be really be used as one cohesive library, but is instead as a mere test of the program.
## Introduction
This only works on GNU/Linux as of now.
<img width="320" height="100" alt="image" src="https://i.ibb.co/WW5V92kJ/ccinit.png" />
To install CCinit, use this, except you might want to replace the `~` directory with something else.

```bash
cd ~
git clone git@github.com:codemanticism/CCinit.git
cp ~/CCinit/ccinit.py ~/.local/bin/ccinit
```
## How to use
If there's no `main.c` in the root of the directory, it will create a `main.c` file and no further arguments are provided in the context. If there is one argument, then it will download all the dependencies listed like so, at the start of the file:
```bash
/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/number.c /types.c /calc.c /random.c*/
...
```
It was a to be styled like this: `/*example*/`, not like that: `//example` and has to be the very first line of the file, so the file has to start with `/*`.
If the element starts with an `/`, it already fills all the stuff in, so that, for example, `/[insert_other_project]/refs/heads/main/main.c` if used in the correct context can make it so that it already fills in the rest, meaning the `https://raw.githubusercontent.com/codemanticism` part, in this case.
There is an example folder with the full implementation of a library, but only parts of the library can be used if one wants it.
## Limits
It could be theorically used with `.js`, `.cpp` and `.java`, for example, although it was theorically built to be used with `.c`. However it would not be compatible with `.py`.
