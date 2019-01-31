/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_controller_hpp 
#define VT_controller_hpp

#include "drug_array.hpp"
#include <fstream>

class controller {
private:
  drug_array drug_arr_;
  
  const std::string kFilepath_;
  std::ifstream file_;

public:
  controller(const std::string& path, const std::string& filename)
    : kFilepath_{path + '/' + filename}
  {
    init_array();
  }
  
  void init_array()
  {
// TODO Make this shit work. 
    file_.open(kFilepath_, std::ios::in);
    
    std::string name;
    std::istream& pos{std::getline(file_, name, ' ')};
    
    for ( ; pos; ) {
      std::vector<double> doses;
      double temp;
      
      while (pos >> temp)
        doses.push_back(temp);
        
      drug_arr_ += drug(name, doses);
    }
  }
  
  drug_array get_drug_array() const noexcept
  {
    return drug_arr_;
  }
};

#endif