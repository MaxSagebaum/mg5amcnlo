#include <iostream>
#include <iomanip> 
#include <ad.h>

#include "CPPProcess.h"
#include "rambo.h"

int main(int argc, char** argv){

  ad::Tape& tape = Real::getTape();
  tape.setActive();

  // Create a process object
  CPPProcess process;

  // Read param_card and set parameters
  process.initProc("../../Cards/param_card.dat");

  Real energy = 1500;
  Real weight;

  // Get phase space point
  vector<Real*> p = get_momenta(process.ninitial, energy,
				 process.getMasses(), weight);

  // Set momenta for this event
  process.setMomenta(p);

  // Evaluate matrix element
  process.sigmaKin();

  const Real* matrix_elements = process.getMatrixElements();

  cout << "Momenta:" << endl;
  for(int i=0;i < process.nexternal; i++)
    cout << setw(4) << i+1 
	 << setiosflags(ios::scientific) << setw(14) << p[i][0]
	 << setiosflags(ios::scientific) << setw(14) << p[i][1]
	 << setiosflags(ios::scientific) << setw(14) << p[i][2]
	 << setiosflags(ios::scientific) << setw(14) << p[i][3] << endl;
  cout << " -----------------------------------------------------------------------------" << endl;


  // Display matrix elements
  for(int i=0; i<process.nprocesses;i++) {
    Real o = matrix_elements[i];
		ad::addOutput("matrixElement[" + std::to_string(i) + "]", o);
    cout << " Matrix element = " 
//	 << setiosflags(ios::fixed) << setprecision(17)
	 << matrix_elements[i]
	 << " GeV^" << -(2*process.nexternal-8) << endl;
  }

  cout << " -----------------------------------------------------------------------------" << endl;

  tape.setPassive();

  ad::computeAndWriteGrad();
}
