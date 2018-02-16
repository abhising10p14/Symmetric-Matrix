/*****************************
	Assumption:   The input given by the user is a Eigen Matrix
******************************/

#include<iostream>
#include<vector>
#include <eigen3/Eigen/Dense> 
//#include <Eigen/Dense>

/*********************************************************
	If error while compiling, comment the line :
	#include <eigen3/Eigen/Dense>  

	and	remove the comment from:
	#include <Eigen/Dense> 
 **********************************************************/


// Raise the error if the input size is <=0
//First Take a square Matrix as input , now you have to store 
//the uppper diaogonal of this matrix into
// Sym 


using namespace std;
using namespace Eigen;


//Using a simillar class as that of Matrix class of Eigen:
//..............................................................................................
// template<typename _Scalar, int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols>
//..............................................................................................
template<typename _Scalar,int _Rows, int _Cols>  
class SymMat
{
public:
	MatrixXd Eigen_Matrix;			//The Eigen Matrix to be converted into Symetric Matrix
									//_Rows = num of rows
									//_Cols = num of columns 
	vector < _Scalar > symmatrix;	//To store the upper Diagonal only ->reduces  the storage
									// Storing the Upper Diagonal rowwise in the vector :

	SymMat(MatrixXd M,int _Dimension,_Scalar)
	{
		_Rows = _Dimension;
		_Cols = _Dimension;
		Eigen_Matrix = M;
	}


};
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  MatrixXd c = m;
  std::cout << c << std::endl;
}