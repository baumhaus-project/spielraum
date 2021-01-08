#include "cista/mmap.h"

#include "IFC2X3/IfcProduct.h"
#include "IFC2X3/parser.h"

std::string ifc_str(std::string const& guid) {
  return "#96945 = IFCFLOWCONTROLLER('" + guid +
         R"(', #2, 'linDbNetComponent', $, $, #96946, #96951, 'Tag:-281736096');
#96951 = IFCPRODUCTDEFINITIONSHAPE($, $, (#96944));
#96944 = IFCSHAPEREPRESENTATION(#20, 'Body', 'MappedRepresentation', (#96933));
#96933 = IFCMAPPEDITEM(#96927,#96934);
#96935 = IFCDIRECTION((0.000002,1.000000,-0.000000));
#96936 = IFCDIRECTION((1.000000,-0.000002,0.000000));
#96937 = IFCDIRECTION((0.000000,-0.000000,-1.000000));
#96938 = IFCCARTESIANPOINT((-55853.364335,57958.087044,46051.925317));
#96934 = IFCCARTESIANTRANSFORMATIONOPERATOR3D(#96935,#96936,#96938,1.000000,#96937);
#96927 = IFCREPRESENTATIONMAP(#96929,#96928);
#96930 = IFCCARTESIANPOINT((0.000000,0.000000,0.000000));
#96931 = IFCDIRECTION((0.000000,0.000000,1.000000));
#96932 = IFCDIRECTION((1.000000,0.000000,0.000000));
#96929 = IFCAXIS2PLACEMENT3D(#96930, #96931, #96932);
#96928 = IFCSHAPEREPRESENTATION(#20, 'Body', 'MappedRepresentation', (#92397,#94162,#96919));
#96919 = IFCMAPPEDITEM(#96913,#96920);
#96913 = IFCREPRESENTATIONMAP(#96915,#96914);
#96914 = IFCSHAPEREPRESENTATION(#20, 'Body', 'Brep', (#94559));
#94559 = IFCFACETEDBREP(#94560);
#94560 = IFCCLOSEDSHELL((#94561));
#94561 = IFCFACE((#94562));
#94562 = IFCFACEOUTERBOUND(#94563, .T.);
#94563 = IFCPOLYLOOP((#94165, #94166, #94167));
#94165 = IFCCARTESIANPOINT((8.793929,21.230422,105.000056));
#94166 = IFCCARTESIANPOINT((5.005869,26.779034,104.999912));
#94167 = IFCCARTESIANPOINT((-0.000000,22.979643,105.000056));
)";
}

#include "step/id_t.h"
#include "utl/parser/cstr.h"

template <typename T>
T const& get_product_by_guid(step::model& model,
                                     std::string const& guid) {
  for (unsigned i = 0; i < model.id_to_entity_.size(); ++i) {
    if (model.id_to_entity_.at(i) != nullptr) {
      try {
        auto const& prod = model.get_entity<T>(step::id_t{i});
        if (prod.GlobalId_ == guid) {
          return prod;
        }
      } catch (const std::exception& e) {
      }
    }
  }
  utl::verify(false, "no entity with GUID {} found", guid);
  throw;
}

void test() {
  auto const guid = "0Gkk91VZX968DF0GjbXoN4";
  auto const ifc_input = ifc_str(guid);

  auto model =
  IFC2X3::parse(ifc_input);

  auto const& prod = get_product_by_guid<IFC2X3::IfcProduct>(model, guid);
  std::cout << prod.GlobalId_ << std::endl;
}

int main(int argc, char** argv) {
  //  auto input_file = cista::mmap{argv[1], cista::mmap::protection::READ};
  //  auto const ifc_input = utl::cstr{
  //      reinterpret_cast<char const*>(input_file.data()), input_file.size()};
  //
  //  auto parser = step::entry_parser{};
  //  IFC2X3::register_all_types(parser);
  //  auto model = step::entity_map{parser, ifc_input};
  //  model.get_entity<IFC2X3::IfcProduct>(step::id_t{0});

  test();
}