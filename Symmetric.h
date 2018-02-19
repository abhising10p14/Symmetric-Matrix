#ifndef SYMMAT_H
#define SYMMAT_H

#include<vector>
#include<typeinfo>
#include <eigen3/Eigen/Dense>
					
//#include <Eigen/Dense>

/*********************************************************
	If error while compiling, comment the line :
	#include <eigen3/Eigen/Dense>  

	and	remove the comment from:
	#include <Eigen/Dense> 
 **********************************************************/

#define  ll long long int 

template<typename _Scalar>  
class SymMat
{
public:
	Eigen::MatrixXd Eigen_Matrix;					//The Eigen Matrix to be converted into Symetric Matrix
	ll _Rows;										//_Rows = num of rows
	ll _Cols;										//_Cols = num of columns 
	std::vector < _Scalar > symmatrix;				//To store the upper Diagonal only ->reduces  the storage
													// Storing the Upper Diagonal row wise in the vector :

/************************************************************
				Constructor 
*************************************************************/

	SymMat();
	SymMat(Eigen::MatrixXd M,ll _Dimension);
	_Scalar  operator()(ll i,ll j);
    void Print_Matrix();

/***************************************************************************************
	Operator overloading for accesing the SymMat by just object name , i.e cout<<obj;
****************************************************************************************/
    
	/*friend ostream & operator <<( ostream& os, const SymMat & m){
		m.Print_Matrix();
		return os ;*/
	

};

#endif // SYMMAT_H
