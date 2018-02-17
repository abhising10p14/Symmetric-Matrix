/*****************************
	Assumption:   The input given by the user is a Eigen Matrix
******************************/

#include<iostream>
#include<vector>
#include <eigen3/Eigen/Dense>
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
	MatrixXd Eigen_Matrix;				//The Eigen Matrix to be converted into Symetric Matrix
	ll _Rows;							//_Rows = num of rows
	ll _Cols;							//_Cols = num of columns 
	vector < _Scalar > symmatrix;		//To store the upper Diagonal only ->reduces  the storage
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
			cout<<"Exception: "<<endl<<"You cannot enter "<<num<<" as a dimension.";
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
	}// Constructor ends here 

/*********************************************************************
  Implementing the Matrix indexing i.e S(i,j) = S[i][j] i.e Accessor
**********************************************************************/

	int operator()(ll i,ll j)
    {
        if (i <= j)
      	return symmatrix[(i * _Rows - (i - 1) * i / 2 + j - i)];
  		 else
      	return symmatrix[(j * _Rows - (j - 1) * j / 2 + i - j)];
    }

	void Print_Matrix();


};



template<typename _Scalar> 
void SymMat<_Scalar>::Print_Matrix()
{

  ll i,j,k;
  cout<<endl<<"The Upper Triangular part of the Given Matrix looks like:"<<endl;
  //for(i=0;i<symmatrix.size();i++)cout<<symmatrix[i]<<" "; cout<<endl;
  cout<<"\nThe given Symmetric Matrix looks like:\n"; 
  ll temp = 0,r_temp = _Rows;    
  for(i=0;i<_Rows;i++)
  {
  	for (j=0;j<_Cols;j++)
  	{  
  	  
  		if (i <= j)
      	cout<<symmatrix[(i * _Rows - (i - 1) * i / 2 + j - i)]<<" ";
  		 else
      	cout<<symmatrix[(j * _Rows - (j - 1) * j / 2 + i - j)]<<" ";

  	}
  	cout<<endl;
  }cout<<endl;
}

int main()
{
  MatrixXd m(4,4);
  m(0,0) = 1;
  m(0,1) = 2;
  m(0,2) = 3;
  m(0,3) = 4;
  m(1,0) = 5;
  m(1,1) = 6;
  m(1,2) = 7;
  m(1,3) = 8;
  m(2,0) = 9;
  m(2,1) = 10;
  m(2,2) = 11;
  m(2,3) = 12;
  m(3,0) = 13;
  m(3,1) = 14;
  m(3,2) = 15;
  m(3,3) = 16;
  SymMat<int> s(m,4);
  s.Print_Matrix();
  //cout<<s(1,2)<<endl;				//To access the s(i,j) simillr to the accessor of Eigen::Matrix 
  cout << m << std::endl;
  //cout<m.triangularView<Eigen::Upper>()<<endl;
  
}

/*1 2 3 4 
6 7 8 9 
1 2 3 4 
6 7 8 9 */
