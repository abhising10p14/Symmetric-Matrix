#ifndef SYMMAT_H
#define SYMMAT_H

#include<vector>
#include<typeinfo>
#include <eigen3/Eigen/Dense>
#include <iostream>
#define  ll long long int 				
//#include <Eigen/Dense>

/*********************************************************
	If error while compiling, comment the line :
	#include <eigen3/Eigen/Dense>  

	and	remove the comment from:
	#include <Eigen/Dense> 
 **********************************************************/


template<typename _Scalar>  
class SymMat
{
public:

	ll _Rows;									//_Rows = num of rows
	ll _Cols;									//_Cols = num of columns 
	std::vector < _Scalar > symmatrix;			//To store the upper Diagonal only ->reduces  the storage

                                                // Storing the Upper Diagonal row wise in the vector :

/************************************************************
				Constructor 
*************************************************************/

	SymMat();
	template<typename type,int r,int c>			//You can use any type of Eigen::Matrix
	SymMat(Eigen::Matrix<type,r,c>M);
	_Scalar  operator()(ll i,ll j);

/***************************************************************************************
	Operator overloading for accesing the SymMat by just object name , i.e cout<<obj;
****************************************************************************************/
    template<class Y>
	friend std::ostream & operator <<( std::ostream& out, const SymMat<Y> & m);

};

#endif // SYMMAT_H
