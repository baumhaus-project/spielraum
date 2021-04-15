#include "spielraum/ui/spielraum_app.h"

#include <string>

#include "wx/wx.h"

#include "spielraum/ui/web_viewer_frame.h"

IMPLEMENT_APP(spielraum_app)  // NOLINT

bool spielraum_app::OnInit() {
  setlocale(LC_ALL, "en_US.UTF-8");
  setlocale(LC_NUMERIC, "en_US.UTF-8");
  setlocale(LC_TIME, "en_US.UTF-8");

  auto const frame = new spielraum::ui::web_viewer_frame();
  frame->Show();

  return true;
}
