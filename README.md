# CCinit
<img width="320" height="100" alt="image" src="https://i.ibb.co/WW5V92kJ/ccinit.png" />
<b> ⚠️ This is stil a largely experimental thing. </b> 

I also recommend you to use to save frequently, by using Git, so that your work might not be lost.
Note that libraries need to be converted to this format, so that they can work at all.
Also linters as of right now aren't compatible with this special library format.
The `library` directory contains an extension made in such a way. 
A tool that can, in a way, making so that the entire code of a package is put within the file `main.c`, so it becomes one file. 
The `library` directory is not really supposed to be really be used as one cohesive library, but is instead as a mere test of the program.
## Introduction
This only works on GNU/Linux as of now or it could be used on Windows with a compatibility layer.
To install CCinit, use this, except you might want to replace the `~` directory with something else.

```bash
cd ~
git clone git@github.com:codemanticism/CCinit.git
cp ~/CCinit/ccinit.py ~/.local/bin/ccinit
```
## How to use
Two examples
`ccinit`: Create a `main.c` file.
`ccinit main.c`: Reads the `main.c` file and actually does all that heavy lifting for you and everything after `\n/*main*/` remains the same.

### Special formatting
<b>Important: Don't use the `#include "LIBRARY"` structure wherein LIBRARY refers to the file which has already been specified thru the the system of initial annotations I made for this program.</b>
It creates a `compile.sh` file, if there's not one and no arguments are specified, which is supposed to compile it with `gcc`.
If there's no `main.c` in the root of the directory, it will create a `main.c` file and no further arguments are provided in the context. If there is one argument, then it will download all the dependencies listed like so, at the start of the file:
```c
/*https://raw.githubusercontent.com/codemanticism/CCinit/refs/heads/main/libraries/number.c /types.c /calc.c /random.c*/
//It is not recommended to use include unless it is a  
...
```
After all it will put all that into a `main.c` file, that might be gigantic, but which is really supposed to be easily used thru features like CTRL + F and terminal text editor.
It has to be styled like this: `/*example*/`, not like that: `//example`. It has to be the very first line of the file, so the file has to start with `/*`.
If the element of the array that is generated after ` ` is treated as the seperator, starts with an `/` like the one in the example, it already fills all the stuff in, so that, for example, `/[insert_other_project]/refs/heads/main/main.c` if used in the correct context can make it so that it already fills in the rest, meaning the `https://raw.githubusercontent.com/codemanticism` part, in this case.
There is an example folder with the full implementation of a library, but only parts of the library can be used if one wants it.
## Limits
It was made to be used for `.c` only. I wanted to make using C more "Pythonic".
