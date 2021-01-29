#include "spielraum/ui/web_viewer_frame.h"

#include "wx/webview.h"
#include "wx/wfstream.h"
#include "wx/wx.h"

#include "pugixml.hpp"

#if !wxUSE_WEBVIEW_WEBKIT && !wxUSE_WEBVIEW_WEBKIT2 && !wxUSE_WEBVIEW_IE && \
    !wxUSE_WEBVIEW_EDGE
#error "A wxWebView backend is required"
#endif

namespace spielraum::ui {

web_viewer_frame::web_viewer_frame()
    : wxFrame(nullptr, -1, "Web Viewer", wxDefaultPosition, wxSize{1080, 720}) {
  SetMinSize(GetSize());
  Centre();

  auto sizer = new wxBoxSizer{wxVERTICAL};
  main_panel_ = new wxPanel{this};

  // Create the webview
  auto const url = "file:///home/zero/code/svg/web.html";
  browser_ = wxWebView::New(main_panel_, -1, url);
  browser_->SetName("WebViewer");

  sizer->Add(browser_, 1, wxEXPAND | wxALL, 15);
  main_panel_->SetSizerAndFit(sizer);
}

}  // namespace spielraum::ui