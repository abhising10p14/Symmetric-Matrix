/*****************************
	Assumption:   The input given by the user is a Eigen Matrix
******************************/

#include<iostream>
#include<vector>
#include <eigen3/Eigen/Dense>
#include <iomanip>
#define  ll long long int 					//Matrx Size could be  very large 
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
template<typename _Scalar>  
class SymMat
{
public:
	MatrixXd Eigen_Matrix;			//The Eigen Matrix to be converted into Symetric Matrix
	ll _Rows;						//_Rows = num of rows
	ll _Cols;						//_Cols = num of columns 
	vector < _Scalar > symmatrix;	//To store the upper Diagonal only ->reduces  the storage
									// Storing the Upper Diagonal row wise in the vector :

/************************************************************
				Constructor 
*************************************************************/
	SymMat(MatrixXd M,ll _Dimension)
	{
		_Rows = _Dimension;
		_Cols = _Dimension;
		Eigen_Matrix = M;

/***********************************************************
	 Throwing an Exception if dimension 
	 provided by the user is less than zero
***********************************************************/
		try {
				if(_Dimension < 0) 
				{
					throw _Dimension;
				}

			}
		catch(ll num) 
		{
			cout<<"You cannot enter "<<num<<" as a dimension.";
		}
/**********************************************************/
		for(ll i=0;i<_Rows;i++)
		{
			for(ll j =i;j<_Cols;j++)
			{
				//cout<<M(i,j)<<" ";
				symmatrix.push_back(M(i,j));			// Store in Row Major Order
			}//cout<<endl;
		}
	}

	void Print_Matrix();


};



template<typename _Scalar> 
void SymMat<_Scalar>::Print_Matrix()
{
  //clock_t start;
  //double duration;
  //start=clock();
  ll i,j,k;
  cout<<"\nThe given Symmetric Matrix looks like:\n";     
  for(i=0;i<_Rows;i++)
  {
  	for (j=0;j<_Cols;j++)
  	{  
  	   if( i>=j )
  	   {
		 k=(i*(i+1))/2;
  		 k=k+j;
  		 cout<<setw(2)<<symmatrix[k]<<" ";
       }
       else
       {
		 k=(j*(j+1))/2;
  		 k=k+i;
  		 cout<<setw(2)<<symmatrix[k]<<" ";
       }

  	}
  	cout<<"\n";
  }
}

int main()
{
  MatrixXd m(3,3);
  m(0,0) = 1;
  m(0,1) = 2;
  m(0,2) = 3;
  m(1,0) = 4;
  m(1,1) = 5;
  m(1,2) = 6;
  m(2,0) = 7;
  m(2,1) = 8;
  m(2,2) = 9;
  
  SymMat<int> s(m,3);
  s.Print_Matrix();
  std::cout << m << std::endl;
}

/*1 2 3 4 
6 7 8 9 
1 2 3 4 
6 7 8 9 */
