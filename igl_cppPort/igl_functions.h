#pragma once
//#include <Eigen/Core>
#include <eigen3/Eigen/Core>

#if defined(RH_DLL_EXPORTS)

/* Compiling XIGLLIB as a Windows DLL - export classes, functions, and globals
 */
#define RH_CPP_CLASS __declspec(dllexport)
#define RH_CPP_FUNCTION __declspec(dllexport)
#define RH_CPP_DATA __declspec(dllexport)

#define RH_C_FUNCTION extern "C" __declspec(dllexport)

#else

/* Using XIGLLIB as a Windows DLL - import classes, functions, and globals */
#define RH_CPP_CLASS __declspec(dllimport)
#define RH_CPP_FUNCTION __declspec(dllimport)
#define RH_CPP_DATA __declspec(dllimport)

#define RH_C_FUNCTION extern "C" __declspec(dllimport)

#endif

void convertArrayToEigenXd(float* inputArray, int sz,
                           Eigen::MatrixXd& outputEigen);
void convertArrayToEigenXi(int* inputArray, int sz,
                           Eigen::MatrixXi& outputEigen);

extern "C" __declspec(dllimport) double Add(double a, double b);

RH_C_FUNCTION
void igl_adjacency_list(int* F, int nF, int* adjLst, int& sz);
