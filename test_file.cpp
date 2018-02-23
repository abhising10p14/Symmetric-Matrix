#include"Symmetric.cpp"
#include <iostream>


int main()
{
  MatrixXd m(4,4);
// Can be stored in this formt also:
  m << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
  cout<<"m :"<<endl<<m<<endl<<endl;
/* simillar to m =
                   1  2  3  4
                   5  6  7  8
                   9  10 11 12
                   13 14 15 16 
*/



  Matrix<float,4,4>mi_7;                            //You can also pass a float type Eigen::Matrix
  mi_7 << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
  cout<<"mi_7 :"<<endl<<mi_7<<endl<<endl;
  SymMat<float> sandy(mi_7); 
  cout<<"Sandy:\n"<<sandy;  


  MatrixXd m2(4,4);
  m2 << -1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16;
  cout<<"m2:\n"<<m2<<endl<<endl;
  SymMat<double> s(m);                                  //The data type of both the SymMat must be same
  SymMat<double> s2(m2);
  cout<<"s SymMat matrix is: \n"<<s;                     //prints the SymMat matrix 
  


  /********************************************************
  Testng for the Addition
  *********************************************************/
  

  cout<<"s(1,2): "<<s(1,2)<<endl<<endl;                        //To access the s(i,j) simillar to the accessor of Eigen::Matrix 
  SymMat<double> s3  = s + s2;                           //Addition of Two SymMat
  
  MatrixXd m3(4,4);
  m3  = s + m;                                           //Addition of SymMat and Eigen::Matrix
  cout<<"s is:"<<endl<<s<<endl<<endl;                    
  cout<<"s+m = m3 is : "<<endl<<m3<<endl<<endl;

  //cout<<typeid(m(0,0)).name();
  //cout<<typeid(s3.symmatrix[0]).name();


/********************************************************
  Testng for the Difference
  *********************************************************/

  SymMat<double> s4  = s3 - s2;                          //Difference of Two SymMat
  
  cout<<"The s3 SymMat matrix is:\n"<<s3<<endl;
  MatrixXd m4(4,4);
  m4  = s - m;                                           //Difference of SymMat and Eigen::Matrix
  cout<<"s SymMat matrix is: \n"<<s;
  cout<<"m is:"<<endl<<m<<endl<<endl;
  cout<<"s-m = m4 is : "<<endl<<m4<<endl<<endl;


  /********************************************************
  Testng for the Multipliction
  *********************************************************/


  MatrixXd m5 = s3*m;                                    //SymMat * Eigen::Matrix
  cout<<"m5 = s3*m :"<<"\n"<<m5<<endl<<endl;        

   MatrixXd m6 = s3*s;                                   //SymMat * Eigen::Matrix
   cout<<"m6 = s3*s :"<<"\n"<<m6<<endl<<endl;       


  
}


