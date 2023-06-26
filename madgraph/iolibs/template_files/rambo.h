#include <vector>

using namespace std;

class Random
{
  public:
    Real ranmar();
    void rmarin(int ij, int kl);
    
  private:
    Real ranu[98];
    Real ranc, rancd, rancm;
    int iranmr, jranmr;
};


Real rn(int idummy);

vector<Real*> get_momenta(int ninitial, Real energy,
				    vector<Real> masses, Real& wgt);

vector<Real*> rambo(Real et, vector<Real>& xm, Real& wt);
