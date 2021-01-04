#pragma once
#include "wx/wx.h"

struct viewport_app : public wxApp {
  virtual bool OnInit();
};

DECLARE_APP(viewport_app)