Lesson 1: Getting Up and Running


Intro
-----

The goal of this lesson is to get you up and running with some basic tools that
will allow us to collaborate on writing code. You will:

1. Learn some basics of the terminal.
2. Install Git so that you can access our code repository.
3. Install MacPorts, a tool for installing other open-source software.
4. Install CMake, a tool which helps us compile code on a variety of platforms.
5. Download code from our repository.
6. Compile and run a program from the terminal.


The Terminal
------------

The terminal (or command line) is a vital tool for most programmers. When you
first start using the terminal, you will feel like you've gone back to the
stone-age. But the terminal is *very* powerful (in my opinion, much more than a
fancy user interface). In fact, I do much of my work directly from the terminal.
You can open a terminal on Mac by searching for "terminal" in spotlight. When
you've opened a terminal it will just look like a black box with a prompt
waiting for you to enter something. Here are some commands you will need to know
in order to get basic stuff done. Give these a try:

pwd

This stands for "print working directory." This tells you where you are located
in the file-system.


ls

This command lists the contents (files and directories) of your current
directory.


cd <path>

This stands for "change directory." It let's you specify a path for changing
your directory. For example, "cd /Users/jyoder/blah" will change my current
working directory to "/Users/jyoder/blah," that is, a directory "blah" under my
home directory "/Users/jyoder". If my current working directory is
"/Users/jyoder" and I run "cd blah", then my current working directory will
again be "/Users/jyoder/blah". You can move up one directory with "cd .." (two
dots).


mkdir

This will make a directory. For example, if my working directory is
"/Users/jyoder" and I run "mkdir blah", then a new directory "blah" will be
created under "/Users/jyoder". Try creating a directory and then cd into it. Now
try cd'ing out of it using "cd .."


rm <path>

This will remove the file at path. For example, if my working directory is
"/Users/jyoder" and I run "rm funky.txt", then I will delete the file
"funky.txt" in my home directory. Use this command with caution -- you cannot
get the file back after you do this (it doesn't go into the "trash"). Remember,
with great power comes great responsibility.


rm -r <path>

This command is even scarier than the one above. If <path> is a directory, it
will delete the entire directory and its contents. Use with much caution. Try
removing the directory "blah" that you created above.


mv <source-path> <destination-path>

This will move the file or directory at <source-path> to the specified
<destination-path>. Try creating a directory and then renaming it using "mv
somedir anotherdir".


man <command>

If you have questions about what a command does or how to use it, you can
consult the system "manual". Try typing "man rm" for information on the remove
command. Just hit 'q' to exit the manual.


Git
---

I'd like to collaborate with you on code using a tool called Git. Git is a
version control program used to (among many other things) manage changes to a
shared codebase. Knowing some version control tool will be very useful to you in
the future should you continue to write software. There is a lot of good
information on what Git is and how it is used here:

    http://git-scm.com/documentation

You don't need to go and read the whole manual now, I just want to give you a
resource that you can turn to if you need more information.

Our shared codebase is located online at www.github.com. You will use Git on
your local computer to download source code and upload changes back to GitHub
(you are reading this on GitHub as we speak).


Installing Git
--------------

Install Git on your computer. You can find the installer here:

    http://git-scm.com/download/mac

Once installed, you should be able to execute the "git" command from the
terminal (give it a try and make sure it doesn't generate an error message). Now
run the following commands to configure git:

    git config --global user.name "<your-name>"
    git config --global user.email "<your-email>"
    git config --global credential.helper 'cache --timeout=7200'

I got this info from the following page on GitHub. You can look here for more
info on what the above commands mean:

    https://help.github.com/articles/set-up-git


Installing MacPorts
--------------------

MacPorts is a tool which will allow you to easily locate, download, and install
a host of open source development tools. You can find information on how to
download and install it here:

    http://www.macports.org


Installing CMake
----------------

CMake is a tool that will make it easier for us to compile the software that we
share using git. The tools I use for development are a bit different than your
because I am working on Linux and you are working on Mac. CMake automatically
generates project files suitable for either platform without us having to
maintain two separate projects. You can install it using MacPorts from the
terminal like this:

    sudo ports install cmake

Just so you know, the 'sudo' command executes the following command (ports) as
the system super-user (or administrator). Special privileges are required to
install software on your computer. The command will ask you to enter your
password.


Downloading Source Code
-----------------------

It's time to download our source code. Run this command from the terminal:

    git clone https://github.com/jyoder/programming-basics.git

That's it! You should now have a clone of the online code repository (repo). You
can browse this from the Mac Finder or from the terminal. The contents of the
project on your computer should mirror what you see on GitHub.


Compiling a Program
-------------------

In the terminal, change directory to the following path in our project:

    cd programming-basics/lessons/001

If you run "ls", you will find the following contents:

    CMakeLists.txt
    README.txt
    source

"README.txt" is the file you are reading right now. "source" is a directory that
contains a single C++ file, upcase.cpp, which is the code you sent me in your
email. We are going to compile this into a program which you can run from the
terminal. CMakelists.txt contains instructions for generating a project for
building your program.

First, we create a directory where all of the automatically generated files
related to our build will go and then change directory to it. Let's call this
directory, "build":

    mkdir build
    cd build

Now we use the cmake tool to generate the appropriate project file for our
platform. In my case, the platform is Linux, in your case it's Mac. This will
generate an Xcode project file in your build directory that you can then use
inside Xcode to build your program:

    cmake -G Xcode ..

The "dot-dot" tells cmake that the instructions for how to generate the project
file (CMakeLists.txt) are located one directory up. Once you've done this, you
should have an Xcode project file in your build directory. You can load this up
in Xcode and build your program.

If all went well, there should now be a new directory called "output". This
contains your compiled program (called "upcase"). You can run the program from
your current directory like this:

    output/upcase

Give it a try! If you successfully got through all of this, then take a look at
the contents of upcase.cpp. This is your original source code, but I've added
comments with suggestions on how it can be improved. Your next lesson will be up
update the code and submit it back to the online repository. Let me know and
I'll send you the next lesson.

