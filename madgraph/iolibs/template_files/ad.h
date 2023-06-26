#pragma once

#include <string>
#include <vector>
#include <tuple>

#include <codi.hpp>

using Real = codi::RealReverse;

namespace ad {

  using Tape = typename Real::Tape;
  void addInput(std::string const& name, Real& value);
  void addOutput(std::string const& name, Real& value);
  void computeAndWriteGrad();

  inline double value(Real const& v) {
    return v.getValue();
  }
  inline double value(double const& v) {
    return v;
  }
}
