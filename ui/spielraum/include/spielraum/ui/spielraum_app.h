#pragma once
#include "wx/wx.h"

struct spielraum_app : public wxApp {
  virtual bool OnInit();
};

DECLARE_APP(spielraum_app)