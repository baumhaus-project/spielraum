#pragma once
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/webview.h"
#include "wx/wx.h"
#endif

namespace spielraum::ui {

struct web_viewer_frame : public wxFrame {
  web_viewer_frame();
  web_viewer_frame(web_viewer_frame const&) = delete;
  web_viewer_frame(web_viewer_frame&&) = delete;
  web_viewer_frame& operator=(web_viewer_frame const&) = delete;
  web_viewer_frame& operator=(web_viewer_frame&&) = delete;
  ~web_viewer_frame() = default;

  wxPanel* main_panel_;
  wxWebView* browser_;
};

}  // namespace spielraum::ui