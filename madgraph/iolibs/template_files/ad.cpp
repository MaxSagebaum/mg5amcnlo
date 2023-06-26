#include "ad.h"

std::vector<std::pair<std::string, int>> inputs;
std::vector<std::pair<std::string, int>> outputs;

namespace ad {
  void addInput(std::string const& name, Real& value) {
    Real::getTape().registerInput(value);

    inputs.push_back(std::make_pair(name, value.getIdentifier()));
  }

  void addOutput(std::string const& name, Real& value) {
    Real::getTape().registerOutput(value);

    outputs.push_back(std::make_pair(name, value.getIdentifier()));
  }

  void computeAndWriteGrad() {
		Tape& tape = Real::getTape();

    for(auto& cur : outputs) {
			tape.gradient(cur.second) = 1.0;
		}

    tape.evaluate();

    for(auto& cur : inputs) {
      std::cout << cur.first << ": " << tape.gradient(cur.second) << std::endl;
    }
    tape.printStatistics();
  }
}
