/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_drug_hpp 
#define VT_drug_hpp

#include <iostream>
#include <vector>
#include <cmath>

class drug {
private:
  std::vector<double> doses_;
  std::string name_;

public:
  drug(std::string name, std::vector<double> doses) 
    : doses_{std::move(doses)}
    , name_{std::move(name)}
  {}
  
  std::string get_name() const noexcept
  {
    return name_;
  }
  
  std::vector<double> get_doses() const noexcept
  {
    return doses_;
  }
  
  double get_dose(size_t position) const
  {
    if (position < doses_.size())
      return doses_.at(position);
    
    return NAN;
  }
  
  void add_dose(double dose)
  {
    doses_.push_back(dose);
  }
  
public: // overloaded operators  
  
  void operator+=(double dose)
  {
    add_dose(dose);
  }
  
  double operator[](size_t position) const
  {
    return get_dose(position);
  }
  
  operator std::vector<double>() const noexcept
  {
    return get_doses();
  }
  
  operator std::string() const noexcept
  {
    return get_name();
  }
  
  friend std::ostream& operator<<(std::ostream& out, drug& d)
  {
    static char id{'a'};
    
    for (const auto& dose: d.get_doses()) {
      out << id++ << ") " << dose << "\n";
    }
    return out;
  }
};

#endif