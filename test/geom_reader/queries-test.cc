#include "doctest/doctest.h"

#include "IFC2X3/parser.h"

#include "ifc_utl/queries.h"

using namespace ifc_utl;

std::string ifc_product(std::string const& guid) {
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

#include "IFC2X3/IfcProduct.h"

TEST_CASE("get entity by guid") {
  auto const guid = "0Gkk91VZX968DF0GjbXoN4";
  auto const input = ifc_product(guid);
  auto model = IFC2X3::parse(input);

  auto const& prod = get_entity_by_guid<IFC2X3::IfcProduct>(model, guid);

  REQUIRE(&prod != nullptr);
  CHECK(prod.GlobalId_ == guid);
  CHECK(prod.Name_.value() == "linDbNetComponent");
  CHECK(prod.line_idx_ == 0);
  CHECK(prod.Representation_.value() != nullptr);
  CHECK(prod.ObjectPlacement_.value() == nullptr);
  CHECK(prod.OwnerHistory_ == nullptr);
  CHECK(prod.Description_.value_or("") == "");
  CHECK(prod.ObjectType_.value_or("") == "");
};

TEST_CASE("read model from file") { CHECK(false); }
