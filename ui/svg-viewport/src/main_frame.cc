#include "svg-viewport/ui/main_frame.h"

#include "wx/wx.h"

namespace viewport::ui{
  main_frame::main_frame()
    : wxFrame(nullptr, -1, "Svg Viewport", wxDefaultPosition,
             wxSize(WIDTH, HEIGHT)) {
    SetMinSize(GetSize());
    Centre();
  }

  main_frame::~main_frame() noexcept {}
} //namespace viewport::ui