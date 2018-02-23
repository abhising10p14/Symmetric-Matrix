/*****************************
	Assumption:   The input given by the user is a Eigen Matrix
******************************/
#include"Symmetric.h"
#include<iostream>
using namespace std;
using namespace Eigen;


/************************************************************
				Constructor definition
*************************************************************/

template<typename _Scalar> 
SymMat<_Scalar>::SymMat()
{

		_Rows =_Cols = 0;
}

template<typename _Scalar> template<typename type,int r,int c>
SymMat<_Scalar>::SymMat(Eigen::Matrix<type,r,c>M)
	{
		long long int _Dimension  = M.rows();		//gets the dimension of the Eigen::Matrix ,rows == cols
		_Rows = _Dimension;
		_Cols = _Dimension;
		

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
		}//Exception Handling ends here 

		for(ll i=0;i<_Rows;i++)
		{
			for(ll j =i;j<_Cols;j++)
			{
				//cout<<M(i,j)<<" ";
				symmatrix.push_back(M(i,j));								// Store in Row Major Order
			}//cout<<endl;
		}
	}// Constructor ends here 


/*********************************************************************
  Implementing the Matrix indexing i.e S(i,j) = S[i][j] i.e Accessor
  using operatpr () overloading 
**********************************************************************/
template<typename _Scalar> 
_Scalar  SymMat<_Scalar>::operator()(ll i,ll j)
{
    if (i <= j)
    return symmatrix[(i * _Rows - (i - 1) * i / 2 + j - i)];
  	else
    return symmatrix[(j * _Rows - (j - 1) * j / 2 + i - j)];
}

/*Using this output stream overloading for printing the matrix*/ 
template<typename _Scalar>
inline std::ostream &operator <<( std::ostream &out,  const SymMat<_Scalar> & m){
		 
		 for(ll i=0;i<m._Rows;i++)
		  {
		  	for (ll j=0;j<m._Cols;j++)
		  	{  
		  	  
		  		if (i <= j)
		      	 out << m.symmatrix[(i * m._Rows - (i - 1) * i / 2 + j - i)] << " ";
		  		 else
		      	 out <<  m.symmatrix[(j * m._Rows - (j - 1) * j / 2 + i - j)] << " ";

		  	}
		  	cout<<endl;
		  }cout<<endl;
		 //out << m.Print_Matrix< _Scalar >() ;
		 return out;
	}





/***************************************************************************************
	Uisng Operator/Function Overloading for Addition :
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
		
	}
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
		
		
	}
	return result;
}


/*************************************************
Subtraction of Two Matrix
*************************************************/

//1. Difference btw SymMat and SymMat
template<typename _Scalar>
SymMat<_Scalar> operator -(SymMat<_Scalar> const &ob1,SymMat<_Scalar> const &ob2)
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
		result.symmatrix[i] = (ob1.symmatrix[i] - ob1.symmatrix[i]);
		
	}
	return result;
}// This function ends here 


// Subtraction of SymMat + Eigen::Matrix
template<typename _Scalar>
MatrixXd operator -(SymMat<_Scalar> const &ob1,Eigen::MatrixXd &m)
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

			result(i,j) = temp - m(i,j);
		}
		
		
	}
	return result;
}// This function ends here 



/***************************************************************************
	Product btw two Matrix
****************************************************************************/

//1. Product btw SymMat and SymMat
template<typename _Scalar>
MatrixXd operator *(SymMat<_Scalar> const &ob1,SymMat<_Scalar> const &ob2)
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
	MatrixXd result(length,length);
    for (ll i = 0; i < length; i++)
    {
        for (ll j = 0; j < length; j++)
        {
            result(i,j) = 0;
            for (ll k = 0; k < length; k++)
            {
            	_Scalar temp1,temp2  ;
				if (i <= k)
		      	temp1 = ob1.symmatrix[(i * length - (i - 1) * i / 2 + j - i)];
		  		if(i>k)
		      	temp1 = ob1.symmatrix[(j * length - (j - 1) * j / 2 + i - j)];

		      	if (k <= j)
		      	temp2 = ob1.symmatrix[(i * length - (i - 1) * i / 2 + j - i)];
		  		if(k>j)
		      	temp2 = ob1.symmatrix[(j * length - (j - 1) * j / 2 + i - j)];

                result(i,j) += temp1*temp2;
            }
        }
    }
    return result;
} // This function ends here 

//2. Product btw SymMat and Eigen::Matrix
template<typename _Scalar>
MatrixXd operator *(SymMat<_Scalar> const &ob1,Eigen::MatrixXd &m)
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
	for (ll i = 0; i < length; i++)
    {
        for (ll j = 0; j < length; j++)
        {
            result(i,j) = 0;
            for (ll k = 0; k < length; k++)
            {
            	_Scalar temp  ;
				if (i <= k)
		      	temp = ob1.symmatrix[(i * length - (i - 1) * i / 2 + j - i)];
		  		if(i>k)
		      	temp = ob1.symmatrix[(j * length - (j - 1) * j / 2 + i - j)];

                result(i,j) += temp*m(k,j);
            }
        }
    }
	return result;
}// This function ends here 

