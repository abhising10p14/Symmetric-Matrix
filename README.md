Symmetric-Matrix
--------------------------------------------------------------------------------------------------------------
This repository deals with the problem of reducing  space complexity of Symmetric Matrix using Eigen
(a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms).
Both the Upper and Lower Triangular matrices of a Symmetric Matrix are identical. Therefore a huge amount of
memory can be saved if only one of the upper and lower triangular matrix is stored(upper Triangular matrix 
in this case).

Suppose there is Symmetric Square Matrix of size 10^19 by 10^19. And let's assume that it stores double values
in it. As a single double value is of 8 bytes, total amount of memory used if we store all the elements of this matrix is 8*10^38 bytes which is =~ 8*8.00000000000000043e+32 Mb =~ 7.99999999999999931e+29 Gb =~ 8.00000000000000038e+26 Tb and on and on .................
So, It can be seen how much memory can be saved if we just save the space by just storing the upper or lower triangular in case of a Symmetric Matrix and could perform all the basic Matrix arithmetic easily.


How it is being implemented?
--------------------------------------------------------------------------------------------------------------
A standalone C++ class for a symetric matrix(SymMat in this case) has been created. It is simmilar to 
the Eigen::Matrix class of Eigen library.
The class consists of the following function:
1. A constructor to make a SymMat from an Eigen::Matrix
2. Accessors for S(i,j): S(j,i) should of course return the same as S(i,j). where S is a Symmetric matrix.
3. Functions for matrix addition:
   SymMat +/- SymMat
   SymMat +/- Eigen::Matrix
4. Functions for matrix multiplication:
   SymMat∗SymMat
   SymMat∗Eigen::Matrix

This repository consists of the following files:
--------------------------------------------------------------------------------------------------------------
1. Symmetric.cpp
   The ...