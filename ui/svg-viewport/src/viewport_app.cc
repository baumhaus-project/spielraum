#include "svg-viewport/ui/viewport_app.h"

#include "wx/wx.h"
#include "wx/wxprec.h"

#include "svg-viewport/ui/main_frame.h"

IMPLEMENT_APP(viewport_app)

bool viewport_app::OnInit() {
  setlocale(LC_ALL, "en_US.UTF-8");
  setlocale(LC_NUMERIC, "en_US.UTF-8");
  setlocale(LC_TIME, "en_US.UTF-8");

  auto const frame = new viewport::ui::main_frame();
  frame->Show();
  return true;
}