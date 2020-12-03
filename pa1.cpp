#include <stdio.h>
#include <fstream>
#include <iostream>




void vecadd(float *a, float *b, float *c){
  for (int i = 0; i < 3; i++){
    c[i] = a[i] + b[i];
  }
}

void matadd(double a[][3], double b [][3], double c[][3])
{
    int i, j;
        for (i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                c[i][j] = a[i][j] + b[i][j];
}



// multiply matrix
void mattimes(float t, float a[][3], float m[][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            m[i][j] = t*a[i][j];
}

void matsub(double a[][3], double b [][3], double c[][3])
{
    int i, j;
        for (i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                c[i][j] = a[i][j] - b[i][j];
}

void matvecmult(float m[][3], float *v, float *prod)
{
    float sum;
    int i, j;
    for(i = 0; j < 3; j++){
        sum = 0;
        for (j = 0; j < 3; j++){
            sum += m[i][j] * v[j];
        }
    prod[i] = sum;
    }
}

void vecsub(double *v1, double *v2, double *v3){
    int i;
    for(i = 0; i < 3; i++){
        v3[i] = v1[i] - v2[i];
    }
}









//-----------first order diff eq-----------------------------------------------
// @param a is a in (D-a), y0 is initial condition
void Order1DiffEq(float a, float y0){

  // open file to write to
  std::ofstream outfile;
  outfile.open("Order1DEQ");

  //(D - a) * Y0(t) = 0
  float deltat = .1; // resolution     *arbitrary, based on desired accuracy
  int iterations = 100; // 10 / deltat   *arbitrary, based on desired range
  float y = y0;    // Y0(0)    (3 in our specific example)
  //float a = -2.5; //  The a in (D-a)

  // loop calculating the values at each 'deltat' interval for 'iterations' loops
  if (outfile.is_open()) {
    for (int i = 0; i < iterations; i++){
        outfile << (i * deltat) << "  " << y << std::endl;
        y = (1 + (a * deltat)) * y;
    }
    outfile.close();
  }
  else {
    std::cout << "Couldn't open file" << std::endl;
    exit(0);
  }
}
//--------End first order diff eq----------------------------------------------




//---------Third order diff eq-------------------------------------------------
// first 3 params are constants, next 3 are initial conditions
void Order3DiffEQ(float a2, float a1, float a0, float y0, float yy0, float yyy0){

  // open file to write to
  std::ofstream outfile;
  outfile.open("Order1DEQ");

  float deltat = .1; // resolution     *arbitrary, based on desired accuracy
  int iterations = 100; // 10 / deltat   *arbitrary, based on desired range
  float temp0[3];//, temp1[3][3];
  float x[3] = {y0,yy0,yyy0};
  float A[3][3] = {{0,  1,  0},
                   {0,  0,  1},
                  {(-1)*a0,(-1)*a1,(-1)*a2}};
//  float I[3][3] = {{1,0,0},
//                  {0,1,0},
//                  {0,0,1}};


  if (outfile.is_open()) {
   for (int i = 0; i < iterations; i++){
       outfile << (i * deltat) << "  " << x[0] << std::endl;
       //std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;
       matvecmult(A,x,temp0);
       std::cout << temp0[0] << " " << temp0[1] << " " << temp0[2] << std::endl;
       temp0[0] = temp0[0] * deltat;
       temp0[1] = temp0[1] * deltat;
       temp0[2] = temp0[2] * deltat;


       x[0] = x[0] + temp0[0];
       x[1] = x[1] + temp0[1];
       x[2] = x[2] + temp0[2];
    }
    outfile.close();
  }
  else {
   std::cout << "Couldn't open file" << std::endl;
   exit(0);
  }
}






int main(){

//  Order1DiffEq(-2.5, 3);
  Order3DiffEQ(.6,25.1125,2.5063,1.5,2,-1);
/*
    //--------------- question 1 ------------------------------------------

    float deltat = .1; // resolution
    int iterations = 100; // 10 / deltat
    double x[3] = {1.5, 2, -1};
//    double xtemp[3][3];
    double i[3][3] = {
        1,0,0,
        0,1,0,
        0,0,1
    };
    double A[3][3] = {
    0,1,0,
    0,0,1,
    .779, .779, .368
    };
    double t[3][3], t1[3], t2[3];
//    double xout = 1.5;


    int j;
if (outfile.is_open()) {
    for (j = 0; j < iterations; j++){
       outfile << (j * deltat) << "  " << x[0] << " " << x[1] << " " << x[2] << std::endl;
       mattimes(deltat, A, t);
                                //void matvecmult(double m[][2], double *v, double *prod)
//       matvecmult(i, x, t1);
      t1[0] = x[0];
      t1[1] = x[1];
      t1[2] = x[2];

      t2[0] = ((x[0]*t[0][0]) + (x[0]*t[0][1]) + (x[0]*t[0][2]));
      t2[1] = ((x[1]*t[1][0]) + (x[1]*t[1][1]) + (x[1]*t[1][2]));
      t2[2] = ((x[2]*t[2][0]) + (x[2]*t[2][1]) + (x[2]*t[2][2]));
                                //void matsub(double a[][3], double b [][3], double c[][3])
       vecsub(t1, t2, x);
    }
    outfile.close();
}

*/

    //--------------- question 2 ------------------------------------------

    //--------------- question 2 ------------------------------------------
    return 0;
}
