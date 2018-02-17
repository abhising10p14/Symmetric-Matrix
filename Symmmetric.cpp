/*****************************
	Assumption:   The input given by the user is a Eigen Matrix
******************************/

#include<iostream>
#include<vector>
#include<typeinfo>
#include <eigen3/Eigen/Dense>
#define  ll long long int 					//Matrx Size could be  very large 
//#include <Eigen/Dense>

/*********************************************************
	If error while compiling, comment the line :
	#include <eigen3/Eigen/Dense>  

	and	remove the comment from:
	#include <Eigen/Dense> 
 **********************************************************/





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

	SymMat()
	{

		_Rows =_Cols = 0;
	}

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
			cout<<"Exception: "<<endl<<"You cannot enter "<<num<<" as a dimension."<<endl;
			exit(0);
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

	_Scalar  operator()(ll i,ll j)
    {
        if (i <= j)
      	return symmatrix[(i * _Rows - (i - 1) * i / 2 + j - i)];
  		 else
      	return symmatrix[(j * _Rows - (j - 1) * j / 2 + i - j)];
    }


    void Print_Matrix();

/***************************************************************************************
	Operator overloading for accesing the SymMat by just object name , i.e cout<<obj;
****************************************************************************************/
    
	friend ostream & operator <<( ostream& os, const SymMat & m){
		m.Print_Matrix();
		return os ;
	}


	


};


template<typename _Scalar> 
void SymMat<_Scalar>::Print_Matrix()
{

  cout<<"\nThe given Symmetric Matrix looks like:\n"; 
    
  for(ll i=0;i<_Rows;i++)
  {
  	for (ll j=0;j<_Cols;j++)
  	{  
  	  
  		if (i <= j)
      	cout<<symmatrix[(i * _Rows - (i - 1) * i / 2 + j - i)]<<" ";
  		 else
      	cout<<symmatrix[(j * _Rows - (j - 1) * j / 2 + i - j)]<<" ";

  	}
  	cout<<endl;
  }cout<<endl;

}	//Print_Matrix Function ends here 






/***************************************************************************************
	Uisng Function Overloading for Addition :
	SymMat + SymMat
	SymMat + Eigen::Matrix

****************************************************************************************/
// Addition of SymMat + SymMat
template<typename _Scalar>
SymMat<_Scalar> operator +(SymMat<_Scalar> const &ob1,SymMat<_Scalar> const &ob2)
{
	//Throw Exception if size of both the SymMat are not same 
	try {
				if(ob1._Rows!=ob2._Rows) 
				{
					throw ob1._Rows;
				}

		}
		catch(ll num) 
		{
			cout<<"Exception: "<<endl<<"The given SymMats for addition don't have same dimension"<<endl;
			exit(0);
			
		}
	ll length = ob1._Rows;
	SymMat<_Scalar> result = ob1;
	for(ll i =0;i<length*(length+1)/2;i++)
	{
		result.symmatrix[i] = (ob1.symmatrix[i] + ob1.symmatrix[i]);
		//cout<<result.symmatrix[i]<<" ";
	}//cout<<endl;
	return result;
}

// Addition of SymMat + Eigen::Matrix
template<typename _Scalar>
MatrixXd operator +(SymMat<_Scalar> const &ob1,Eigen::MatrixXd &m)
{

	//Throw Exception if size of SymMat and Eigen::Matrix are not same 
	try {
				if(ob1._Rows!=m.rows() || ob1._Rows!=m.cols() || m.cols()!=m.rows()) 
				{
					throw ob1._Rows;
				}

		}
		catch(ll num) 
		{
			cout<<"Exception: "<<endl<<"The given SymMat and Eigen:: Matrix for addition don't have same dimension"<<endl;
			exit(0);
			
		}

	//Throw Exception if size of anyone of  the SymMat or Eigen::Matrix is zero
	try {
				if(ob1._Rows==0 || m.rows()==0 || m.cols()==0) 
				{
					throw ob1._Rows;
				}

		}
		catch(ll num) 
		{
			cout<<"Exception: "<<endl<<"Zero sized Matrix found for Addition"<<endl;
			exit(0);
			
		}

	//Throw Exception if data type of both the SymMat are not same 
	try {
				if(typeid(m(0,0)).name() != typeid(ob1.symmatrix[0]).name()) 
				{
					throw ob1._Rows;
				}

		}
		catch(ll num) 
		{
			cout<<"Exception: "<<endl<<"Two Matrix of different data types"<<endl;
			exit(0);
			
		}

	ll length = ob1._Rows;
	MatrixXd result = m;
	for(ll i =0;i<length;i++)
	{
		for(ll j=0;j<length;j++)
		{
			_Scalar temp  ;
			if (i <= j)
	      	temp = ob1.symmatrix[(i * length - (i - 1) * i / 2 + j - i)];
	  		if(i>j)
	      	temp = ob1.symmatrix[(j * length - (j - 1) * j / 2 + i - j)];

			result(i,j) = temp + m(i,j);
		}
		
		
	}//cout<<endl;
	return result;
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

  MatrixXd m2(4,4);
  m2(0,0) = 1;
  m2(0,1) = 2;
  m2(0,2) = 3;
  m2(0,3) = 4;
  m2(1,0) = 5;
  m2(1,1) = 6;
  m2(1,2) = 7;
  m2(1,3) = 8;
  m2(2,0) = 9;
  m2(2,1) = 10;
  m2(2,2) = 11;
  m2(2,3) = 12;
  m2(3,0) = 13;
  m2(3,1) = 14;
  m2(3,2) = 15;
  m2(3,3) = 16;
  SymMat<double> s(m,4);
  SymMat<double> s2(m2,4);
  s.Print_Matrix();
  //s2.Print_Matrix();
  //cout<<s(1,2)<<endl;				//To access the s(i,j) simillar to the accessor of Eigen::Matrix 

  SymMat<double> s3  = s + s2;		//Addition of Two SymMat
  //s3.Print_Matrix();
  MatrixXd m3(4,4);
  m3  = s + m;
  //cout<<"s is:"<<endl<<s<<endl<<endl;
  cout<<"m is:"<<endl<<m<<endl;
  cout<<"s+m = m3 is : "<<endl<<m3<<endl;
  //cout<<typeid(m(0,0)).name();
  //cout<<typeid(s3.symmatrix[0]).name();
  
}


