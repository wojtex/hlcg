/*
 * Describing nodes
 */

#pragma once

#include "node.hpp"

#include <vector>

#include "../utility/signals.hpp"

namespace hlcg {
  
  // Selector selects other nodes
  class Selector
  {
  public:
    virtual std::vector<Node *> & get_selected() = 0;
  };
  
  // Add name to the node
  class Named
  {
  public:
    virtual std::wstring & get_name() = 0;
  };
  
  // Container contains other declarations
  // Eg. modules, namespaces, classes (static members) [also: interfaces]
  class Container
  {
  public:
    virtual std::vector<Node *> & get_members() = 0;
    
    // Invoked when a lookup of a member from this container is performed.
    // Use this to load some members to the container before.
    // Usefull in code compilation.
    Signal<void(Container *)> on_select_member;
  };
  
  // Can return a specialization
  class Template
  {
  public:
    // TODO
  };
}