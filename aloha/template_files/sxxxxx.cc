#include <complex>
#include <cmath>
#include "aloha_aux_functions.h"
#include "ad.h"
using namespace std;
void sxxxxx(Real p[4],int nss, complex<Real> sc[3]){
  sc[2] = complex<Real>(1.00,0.00);
  sc[0] = complex<Real>(p[0]*nss,p[3]*nss);
  sc[1] = complex<Real>(p[1]*nss,p[2]*nss);
  return;
}
