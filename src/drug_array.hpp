/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_drug_array_hpp 
#define VT_drug_array_hpp

#include "drug.hpp"
#include <optional>

class drug_array {
private:
  std::vector<drug> drugs_;

public:
  drug_array() noexcept 
  {}
  
  void add_drug(const drug& d)
  {
    drugs_.push_back(d);
  }
  
  size_t size() const noexcept
  {
    return drugs_.size();
  }
  
  std::optional<drug> get_drug(size_t position) const
  {
    if (position < drugs_.size())
      return std::make_optional(drugs_.at(position));
    
    return std::optional<drug>();
  }
  
  std::vector<std::string> get_drugs() const
  {
    std::vector<std::string> res;
    
    for (const std::string& name: drugs_) {
      res.push_back(name);
    }
    
    return res;
  }
  
public: // overloaded operators
  
  void operator+=(const drug& d)
  {
    add_drug(d);
  }
  
  std::optional<drug> operator[](size_t pos) const
  {
    return get_drug(pos);
  }
  
  friend std::ostream& operator<<(std::ostream& out, drug_array& d_arr)
  {
    static char id{'a'};
    
    for (const auto& d: d_arr.get_drugs()) {
      out << id++ << ") " << d << "\n";
    }
    return out;
  }
};

#endif