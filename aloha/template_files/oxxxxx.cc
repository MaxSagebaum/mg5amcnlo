#include <complex>
#include <cmath>
#include "aloha_aux_functions.h"
#include "ad.h"
using namespace std;
void oxxxxx(Real p[4],Real fmass,int nhel,int nsf, complex<Real> fo[6]){
  complex<Real> chi[2];
  Real sf[2],sfomeg[2],omega[2],pp,pp3,sqp0p3,sqm[2];
  int nh,ip,im;
  fo[0] = complex<Real>(p[0]*nsf,p[3]*nsf);
  fo[1] = complex<Real>(p[1]*nsf,p[2]*nsf);
  nh = nhel*nsf;
  if (fmass != 0.000){
    pp = min(p[0],sqrt((p[1]*p[1])+(p[2]*p[2])+(p[3]*p[3])));
    if (pp == 0.000){
      sqm[0] = sqrt(std::abs(fmass));
      sqm[1] = Sgn(sqm[0],fmass); 
      ip = -((1-nh)/2) * nhel ;
      im = (1+nh)/2 * nhel;
      fo[2] = im *sqm[std::abs(ip)];
      fo[3] = ip*nsf*sqm[std::abs(ip)];
      fo[4] = im*nsf*sqm[std::abs(im)];
      fo[5] = ip*sqm[std::abs(im)];
    }
    else{
//      pp = min(p[0],sqrt((p[1]*p[1])+(p[2]*p[2])+(p[3]*p[3])));
      sf[0] = Real(1+nsf+(1-nsf)*nh)*0.5;
      sf[1] = Real(1+nsf-(1-nsf)*nh)*0.5;
      omega[0] = sqrt(p[0]+pp);
      omega[1] = fmass/omega[0];
      ip = (1+nh)/2 ;
      im = (1-nh)/2 ;
      sfomeg[0] = sf[0]*omega[ip];
      sfomeg[1] = sf[1]*omega[im];
      pp3 = max(pp+p[3],0.00);
      chi[0] = complex<Real>(sqrt(pp3*0.5/pp),0.00);
      if (pp3 == 0.00){ 
	chi[1] = complex<Real>(-nh,0.00);
      }
      else{
	chi[1] = complex<Real>(nh*p[1],-p[2])/sqrt(2.0*pp*pp3);
      }
      fo[2] = sfomeg[1]*chi[im];
      fo[3] = sfomeg[1]*chi[ip];
      fo[4] = sfomeg[0]*chi[im];
      fo[5] = sfomeg[0]*chi[ip];
    }
  }
  else{
    if((p[1] == 0.00) and (p[2] ==0.00) and (p[3] < 0.00)){
      sqp0p3 = 0.00;
    }
    else{
      sqp0p3 = sqrt(max(p[0]+p[3],0.00))*nsf;
    }
    chi[0] = complex<Real>(sqp0p3,0.00);
    if(sqp0p3 == 0.000){ 
      chi[1] = complex<Real>(-nhel,0.00)*sqrt(2.0*p[0]);
    }
    else{
      chi[1] = complex<Real>(nh*p[1],-p[2])/sqp0p3;
    }
    if(nh==1){
      fo[2] = chi[0];
      fo[3] = chi[1];
      fo[4] = complex<Real>(0.00,0.00);
      fo[5] = complex<Real>(0.00,0.00);
    }
    else{      
      fo[2] = complex<Real>(0.00,0.00);
      fo[3] = complex<Real>(0.00,0.00);
      fo[4] = chi[1];
      fo[5] = chi[0];
    }
  }
  return;
}
