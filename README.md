Symmetric-Matrix
--------------------------------------------------------------------------------------------------------------
This repository deals with the problem of reducing  space complexity of Symmetric Matrix using Eigen
(a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms).
Both the Upper and Lower Triangular matrices of a Symmetric Matrix are identical. Therefore a huge amount of
memory can be saved if only one of the upper and lower triangular matrix is stored(upper Triangular matrix 
in this case).

Suppose there is Symmetric Square Matrix of size 10^19 by 10^19. And let's assume that it stores double values
in it. As a single double value is of 8 bytes, total amount of memory used if we store all the elements of this matrix is 8x10^38 bytes which is =~ 6.4 × 10^27 Tb and on and on .................
So, It can be seen that around 3.2 × 10^27 Tb of memory will be saved if we  save the space by just storing the upper or lower triangular part of a Symmetric Matrix and could perform all the basic Matrix arithmetic easily.


How it is being implemented?
----------------------------------------------------------------------------------------------------------------
A standalone C++ class for a symetric matrix(SymMat in this case) has been created. It is simmilar to 
the Eigen::Matrix class of Eigen library.
The class consists of the following function:
1. A constructor to make a SymMat from an Eigen::Matrix
2. Accessors for S(i,j): S(j,i) should of course return the same as S(i,j). where S is a Symmetric matrix.
3. Functions for matrix addition:

   (i)  SymMat +/- SymMat
   (ii) SymMat +/- Eigen::Matrix
4. Functions for matrix multiplication:

   (i)  SymMat∗SymMat
   (ii) SymMat∗Eigen::Matrix


**IT HAS BEEN ASSUMED THAT THE USER PROVIDES A EIGEN::MATRIX FROM WHICH A SYMMETRIC MATRIX HAS TO BE EXTACTED AND STORED.**
This repository consists of the following files:
-----------------------------------------------------------------------------------------------------------------
1. A C++ header file Symmetric.h
   The Header file consits of a SymMat class whose members have been described in the comments in the file itself.

   


