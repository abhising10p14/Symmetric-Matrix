#include"Symmetric.cpp"
#include <iostream>


int main()
{
  MatrixXd m(4,4);
// Can be stored in this formt also:
  m << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
  cout<<"m :"<<endl<<m<<endl<<endl;
/* simillar to m = 1  2  3  4
                   5  6  7  8
                   9  10 11 12
                   13 14 15 16 */


  MatrixXd m2(4,4);
/*m2(0,0) = 1;
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
  m2(3,3) = 16;*/
// Another Eigen::Matrix
  m2 << -1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16;
  cout<<"m2: "<<endl<<m2<<endl<<endl;
  SymMat<double> s(m,4);
  SymMat<double> s2(m2,4);
  cout<<"s matrix is: "<<endl;
  s.Print_Matrix();
  //s2.Print_Matrix();
  cout<<"s(1,2): "<<s(1,2)<<endl;											   //To access the s(i,j) simillar to the accessor of Eigen::Matrix 

  SymMat<double> s3  = s + s2;									         //Addition of Two SymMat
  //s3.Print_Matrix();
  MatrixXd m3(4,4);
  m3  = s + m;													                 //Addition of SymMat and Eigen::Matrix
  //cout<<"s is:"<<endl<<s<<endl<<endl;         				//NEEDS TO BE FIXED
  cout<<"s+m = m3 is : "<<endl<<m3<<endl<<endl;
  //cout<<typeid(m(0,0)).name();
  //cout<<typeid(s3.symmatrix[0]).name();

  SymMat<double> s4  = s3 - s2;									        //Difference of Two SymMat
  //s3.Print_Matrix();

  s3.Print_Matrix();
  MatrixXd m4(4,4);
  m4  = s - m;			                 										//Difference of SymMat and Eigen::Matrix
  cout<<"s matrix is: "<<endl;
  s.Print_Matrix();
  cout<<"m is:"<<endl<<m<<endl<<endl;
  cout<<"s-m = m4 is : "<<endl<<m4<<endl<<endl;


  /********************************************************
  Testng for the Multipliction
  *********************************************************/


  MatrixXd m5 = s3*m;											              //SymMat * Eigen::Matrix
  cout<<"m5 = s3*m :"<<"\n"<<m5<<endl<<endl;				

   MatrixXd m6 = s3*s;											            //SymMat * Eigen::Matrix
   cout<<"m6 = s3*s :"<<"\n"<<m6<<endl<<endl;				


  
}


