//-----------------------------------------------------------------------------
//    Zach Wilcox
//    A02080016
//
//    Continuous Time Systems and Signals
//    Programming Assignment 2
//
//    main.cpp
//-----------------------------------------------------------------------------

//float *conv(float *A, float *B, int lenA, int lenB, int *lenC);


#include "conv.h"
#include <stdio.h>
#include <iostream>
#include <fstream>


int main(){

  std::ofstream outfile("answers");

  float f1[] = {0,1,2,3,2,1};
  int len1 = 6;
  /*
  float f2[] = {-2,-2,-2,-2,-2,-2,-2};
  int len2 = 7;
  float f3[] = {1,-1,1,-1};
  int len3 = 4;
  float f4[] = {0,0,0,-3,-3};
  int len4 = 5;
*/
  float *Y;
  int lenY;

  Y = conv(f1, f1, len1, len1, &lenY);
  std::cout << "Y: ";
  for(int i = 0; i < lenY; i++){
    outfile << i << " " << Y[i] << std::endl;
    std::cout << Y[i] << "  ";
  }
  std::cout << std::endl;

/*
  Y = conv(f1, f2, len1, len2, &lenY);
  std::cout << "Y: ";
  for(int i = 0; i < lenY; i++){
    std::cout << Y[i] << "  ";
  }
  std::cout << std::endl;


  Y = conv(f1, f3, len1, len3, &lenY);
  std::cout << "Y: ";
  for(int i = 0; i < lenY; i++){
    std::cout << Y[i] << "  ";
  }
  std::cout << std::endl;


  Y = conv(f2, f3, len2, len3, &lenY);
  std::cout << "Y: ";
  for(int i = 0; i < lenY; i++){
    std::cout << Y[i] << "  ";
  }
  std::cout << std::endl;


  Y = conv(f1, f4, len1, len4, &lenY);
  std::cout << "Y: ";
  for(int i = 0; i < lenY; i++){
    std::cout << Y[i] << "  ";
  }
  std::cout << std::endl;
*/
  return 0;
}
