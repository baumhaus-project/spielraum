#include <iostream>

#include "cista/mmap.h"

#include "IFC2X3/parser.h"

namespace ifc_utl {

step::model read_file(char* file_path);

template <typename T>
T const& get_entity_by_guid(step::model& m, std::string const& guid) {
  for (auto const& ptr : m.entity_mem_) {
    auto const casted = dynamic_cast<T*>(ptr.get());
    if (casted != nullptr && casted->GlobalId_ == guid) {
      return *casted;
    }
  }
  throw std::runtime_error{"not found"};
}

}  // namespace ifc_utl
