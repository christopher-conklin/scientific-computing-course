#Alternative Coding Environment for Mac Users

As many of you have noticed, the Mac version of CodeBlocks is very out of date, crashes a lot, etc. There are a number of alternative IDEs (XCode, Eclipse, etc.) and text editors (MacVim, TextEdit, etc.) that you can use, but some of them cost money, some are more complex than our needs require, and some will not interface well with the CodeBlocks project files the rest of your group is using.

I have been working on an alternative that is a combination of a simple but productive editor and a bit of homemade code that I wrote to make the build process match that of CodeBlocks. Below I will show you how to set everything up so that you can write your code and still collaborate with others using CodeBlocks.

(Note to Windows users, this should work for you too if you don't like CodeBlocks, but I haven't tested it on Windows so you may have to adjust a few settings to get things right)

##Step 1: Download Atom[^editor]

[^editor]: If you have a preferred editor you want to use, you can skip steps 1 and 2 and just follow the instructions in step 3.

[Atom](atom.io) is a text editor that is made by the same people that made GitHub. It is not an IDE, meaning it does not have all of the same build features as CodeBlocks, but we will get around that with some extra packages and some custom code.

There are a few really nice features of Atom that aren't found in CodeBlocks. One is the connection to GitHub. Because Atom is made by GitHub, it is really easy to access your GitHub files straight from Atom. Another is [teletype](https://teletype.atom.io), which allows multiple coders to edit the same file in real time. A third is the ability to add [packages](https://atom.io/packages/) developed by the Atom community that give you extra custom features.

##Step 2: Add "gcc-make-run" package[^gcc]

[^gcc]: This package allows you to run your code directly from Atom. Another option is to open up a Terminal window, navigate to the folder with your code, and type `gcc MYCODE.c -o MYCODE`, replacing `MYCODE` with the name of your file. This will create an executable called `MYCODE`, which you can then run by typing `./MYCODE` into terminal.

When you open Atom, click on "Install a Package" in the Welcome Guide, and then click "Open Installer." (Or you can press `command`+`,` and select "Install"). Search for "gcc-make-run." When you find this package, click "Install." 

This package allows you to compile and run code directly from Atom. Test it out by opening a C file. You can run the code either by right clicking on the file and selecting "Compile Run" or by pressing `F6` (On my laptop `F6` does key brightness by default, so I had to press `fn`+`F6` to get it to work). Just like CodeBlocks, a window will appear with your running code, and any error or warning messages will also pop up.

##Step 3: Add my custom makefile
Thus far you can edit and run single files in Atom in the same way you can in CodeBlocks. The last piece handles building projects in the same way.

The primary way C/C++ developers build big projects is with something called a *makefile*. The details of creating a makefile are beyond the scope of this course, but basically it checks to see which files have been updated, compiles and links those files, and then creates an executable.

I wrote a makefile that will compile and link all .c files located in your project folder, and create an executable that has the same name as your project folder. Download my makefile [XXXhereXXX](XXX). It is important that the file does have any extension to the name, and is just called "Makefile".

Put the makefile in the same folder as your project. The makefile will only work if the folder contains *exactly* the .c files you need for your project, no more or less (there can be other files, just not any other .c files). Also unless you wrote your `#include` statements in a weird way, you need your .h files in this folder too.

In the next step I will discuss using the makefile[^make].

[^make]: An option you always have to run the makefile is to open a Terminal window, navigate to the directory with the makefile, and type `make`. This will run the makefile and produce the executable. To clear the .o files and the executable, type `make clean`.

##Step 4: Working with projects

When you select "File $\rightarrow$ Open" in Atom, you can select individual files, or you can open a project by selecting the project folder and clicking "Open." This will open a new window with the contents of your project folder ont the left side of the screen. Clicking on those files will open them up in Atom. You will also notice nice features like autocompletion and variable/function recognition.

To build your project, right-click on the Makefile on the left side of the window and click "Make Run," the first option (or open the makefile and run it with `F6` like you would any other file). The makefile will compile any new files that need compiling, put the object files in the "obj" folder, and link them together to make an executable file in the "bin" folder, just like how CodeBlocks does. It will also run the executable automatically, so it is like pressing "Build and Run" in codeblocks.

My makefile assumes you are in Debug mode, and will create its files accordingly. If you want to switch to Release mode, change line 2 of the makefile from `TAR := Debug` to `TAR := Release`.

##Step 6: Going back to CodeBlocks
If you have a CodeBlocks project with all the source and header files in the project folder, all you need to do is add my makefile to that folder and then it will do the rest. If you (or your groupmates) have been working outside of CodeBlocks and want to run things in CodeBlocks, you have to do one more thing.

My makefile automatically links all .c files in your project folder, but CodeBlocks does not. You will have to add the files to the project once you are in CodeBlocks. I think the easiest way to do this is to select "Project $\rightarrow$ Add files recursively" and then select your project folder. CodeBlocks will then pull up all the files in your folder and ask if you want to add them. Once the files are added to your project, you can build and run in CodeBlocks and get the same results as using Atom and Makefile.



