#include "cista/mmap.h"

#include "IFC2X3/parser.h"

namespace ifc_utl {

step::model read_file(char* file_path) {
  auto input_file = cista::mmap{file_path, cista::mmap::protection::READ};
  auto const ifc_input = utl::cstr{
      reinterpret_cast<char const*>(input_file.data()), input_file.size()};

  return IFC2X3::parse(ifc_input);
}

}  // namespace ifc_utl
