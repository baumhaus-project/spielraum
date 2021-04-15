#include "ifc_utl/queries.h"

#include "IFC2X3/IfcExtrudedAreaSolid.h"
#include "IFC2X3/IfcProductRepresentation.h"
#include "IFC2X3/IfcRectangleHollowProfileDef.h"
#include "IFC2X3/IfcRepresentation.h"
#include "IFC2X3/IfcRepresentationItem.h"
#include "IFC2X3/IfcWallStandardCase.h"

#include <iostream>

int main(int argc, char** argv) {
  auto model = ifc_utl::read_file(argv[1]);

  auto const guid = "2O2Fr$t4X7Zf8NOew3FNld";
  auto const& wall =
      ifc_utl::get_entity_by_guid<IFC2X3::IfcWallStandardCase>(model, guid);

  if (wall.Name_.has_value()) {
    std::cout << wall.Name_.value() << std::endl;
  }

  if (wall.Representation_.has_value()) {
    for (auto repr : wall.Representation_.value()->Representations_) {
      std::cout << repr->RepresentationType_.value() << std::endl;
      for (auto item : repr->Items_) {
        std::cout << item->id_ << std::endl;
        std::cout << item->NAME << std::endl;
        auto casted = static_cast<IFC2X3::IfcExtrudedAreaSolid*>(item);
        std::cout << casted->Depth_ << std::endl;
        std::cout << casted->SweptArea_->ProfileName_.value() << std::endl;
        std::cout << casted->SweptArea_->NAME;
      }
    }
  }
}