//-----------------------------------------------------------------------------
//    Zach Wilcox
//    A02080016
//
//    Continuous Time Systems and Signals
//    Programming Assignment 2
//
//    conv.cpp
//
//    source code for convolution function
//-----------------------------------------------------------------------------

#include "conv.h"

// function to convolve two functions
// A=F1 (array) B=F2 (array) lenx =points in array x
float *conv(float *A, float *B, int lenA, int lenB, int *lenY){
  int nconv;
  int i, j, i1;
  float temp;
  float *Y;

  // output len is lengths added -1 since index starts at 0
  nconv = lenA + lenB - 1;

  // allocate output function
  Y = (float*) calloc(nconv, sizeof(float));

  //convolve according to equation 2
  for (i = 0; i < nconv; i++){
    i1 = i;
    temp = 0;
    for (j = 0; j < lenB; j++){
      if (i1 >= 0 && i1 < lenA){
        temp += (A[i1] * B[j]);
      }
      i1 -= 1;
      Y[i] = temp;
    }
  }

  // write out array length
  (*lenY) = nconv;
  return(Y);
}
