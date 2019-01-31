/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include <iostream>
#include "controller.hpp"

int main(int argc, char **argv) 
{
  controller c(std::getenv("PWD"), "test.txt");
 
  drug_array d = c.get_drug_array();
  
  bool is_ok{false};
  size_t id{0};
  while (!is_ok) {
    std::cout << d << d.size();
    std::cin >> id;
    
    is_ok = static_cast<bool>(d[id]);
  }
  drug d_ptr = d[id].value();
  std::cout << d_ptr;
  
  
}