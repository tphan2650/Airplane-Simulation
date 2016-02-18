# Airplane-Simulation

####CPSC 131 Project 1: object-oriented programming
Spring 2016
Tim Finer, CSU Fullerton
tifiner@fullerton.edu

##Introduction
In this project you will write an object-oriented C++ module involving several interrelated classes. The
module implements a simulation of the boarding process of an airplane, in which a set of passengers
attempt to stow their carryon bags and take their assigned seats in an orderly fashion. This subject matter
is hopefully interesting, but is not the primary focus of the project. Rather, the focus of the project is on
using essential OOP features appropriately: classes, pointers, encapsulation and modularity.

###The Code
A ZIP archive file, *project-1.zip*, is available in TITANium. It contains the following files:
  1. `project-1-template.cpp` is a C++ file that declares the `Bag`, `Passenger` and 
     `Airplane` classes, as well as a related enum type. The private area of most classes are marked
     with TODO comments, indicating that you’ll need to add code there. Please rename this class to
     `project-1_lastname_firstname.cpp`.
  2. `project-1-scenarios.txt` contains some scenarios and their expected output.

As presented `project-1-template.cpp` should compile cleanly and run without error.

The classes and their specification are given in `project-1-template.cpp;` pay particular attention
to the comments preceding the non-trivial member functions. There are several interrelated classes, so this
module is moderately complex. However, all the classes follow the generally-accepted OOP practices and
C++ conventions that have been covered in class.

Once you have finished the airline module, the two program should compile cleanly, link, run, and print
meaningful messages to standard output. If there are any assertion errors, it means that something is not
implemented correctly.

This code was developed with the *clang++* compiler on the OS X operating system via command line
(e.g. **clang++** --**std=c++14** **project-1-solution.cpp -o airplane**). However it is portable C++, and should
work properly on Windows and Linux. The code is known to run on http://ideone.com as well.
