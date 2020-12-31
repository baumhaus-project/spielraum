#include "cista/mmap.h"

#include "step/entity_map.h"
#include "step/parse_step.h"

#include "IFC2X3/IfcProduct.h"
#include "IFC2X3/register_all_types.h"

int main(int argc, char** argv) {
  auto input_file = cista::mmap{argv[1], cista::mmap::protection::READ};
  auto const ifc_input = utl::cstr{
      reinterpret_cast<char const*>(input_file.data()), input_file.size()};

  auto parser = step::entry_parser{};
  IFC2X3::register_all_types(parser);
  auto model = step::entity_map{parser, ifc_input};
  model.get_entity<IFC2X3::IfcProduct>(step::id_t{0});
}