#include <cmath>
#include "ad.h"
using namespace std;

Real Sgn(Real a,Real b){
  return (b<0)?(Real)-abs(a):(Real)abs(a);
}
