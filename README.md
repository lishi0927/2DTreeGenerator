!! WORK IN PROGRESS !!
----------------------

Basic application of the space colonization algorithm for tree generation (in 2D).

## Note

Current version is able to:

* Generate a simple (elipsis) crown shape and fill it with numerous random attraction points
* Generate a first tree node (trunk) randomly at the bottom of the window
* Resolve the tree with a simple render (made of lines)


## Setup

In order to build and run 2DTreeGenerator, be sure to have all the following installed:

* Compiler stuff : __g++__ / __gcc__
* SDL stuff : __libSDL__ and __libSDL_image__
* OpenGL stuff : __libGL__ and __libGLU__
* Premake : __premake4__

To build 2DTreeGenerator you first have to generate the Makefile (or any other project configuration, see [Premake4 documentation](http://industriousone.com/what-premake) for more informations.) : 

    $ premake4 gmake

The build thanks to :

    $ make

And run :

    $ ./2DTreeGenerator

## Screenshots

![1st screen](https://github.com/lvictorino/2DTreeGenerator/blob/master/screenshots/2DTree_1.png?raw=true)

![2nd screen](https://github.com/lvictorino/2DTreeGenerator/blob/master/screenshots/2DTree_2.png?raw=true)

![3rd screen](https://github.com/lvictorino/2DTreeGenerator/blob/master/screenshots/2DTree_3.png?raw=true)
