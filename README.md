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


**It has been assumed that the user provides anEigen::Matrix from which a symmetric has to be extracted and stored.**

This repository consists of the following files:
-----------------------------------------------------------------------------------------------------------------
1. A C++ header file Symmetric.h
   The Header file consist of a SymMat class whose members have been described in the comments in the file itself.
   The SymMat class consist of the following memebers :
   1. **```Eigen::MatrixXd Eigen_Matrix```**			 The Eigen Matrix which is to be converted into Symetric 	
   														 Matrix 
   2. **```_Rows```**								     The Number of Rows
   3. **```_Cols```**									 The Number of Columns which is same as number of rows
   4. **```std::vector  Scalar symmatrix```**			 To store the upper Diagonal only. It reduces  the storage
   5. **```SymMat()```**							     Default Constructor
   6. **```SymMat(Eigen::MatrixXd M)```**  				 Parameterized Constructors
   7. **```_Scalar  operator()(ll i,ll j)```**			 The S(i,j) operator
   8. **```operator <<(ostream &out, const SymMat<Y> & m)```**  '<<' Operator overloading for output of the matrix 
   																   Same as the cout<< m ;(where m is a Eigen::Matrix)

2. A C++ source file Symmetric.cpp
	The source file consists of the implementation of all the member function of the class SymMat as well as the operator overloading declared in the class.

3. A test_file.cpp 
	This contains all the required test cases which checks the utility of all the inbuilt functions where both the SymMat and the Eigen::Matrix have been used.



How to use this class and compile it?
--------------------------------------------------------------------------------------------------------------------

To use this class you just have to include this following in your main program.
   
   #include"Symmetric.cpp"

   To create an object of the SymMat class 
   SymMat<_Scalar> s2(m);
   
   Here, _Scalar can be any datatype supported in the C++
   	     m is the Eigen::matrix which is  provided by the user and from which Symmetric  matrix has to be extracted.
   	 e.g 
   	 	Eigen::MatrixXd m(4,4); 
   	 	SymMat<double> s(m);


 
**If fatal error:Eigen/Dense: No such file or directory
	occurs  while compiling, then comment the line:
	#include <eigen3/Eigen/Dense>  
	and	remove the comment from:
	#include <Eigen/Dense> from the file Symmetric.h**

**Currently It is being assumed that the input Eigen::Matrix is of type ```double```, if Eigen::Matrix is of any other data type, Corresponding changes should be made to the header as well as the source file**





	

