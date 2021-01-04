#pragma once
#include "wx/wx.h"

#define WIDTH 1080
#define HEIGHT 720

namespace viewport::ui{
  struct main_frame : public wxFrame{
    main_frame();
    main_frame(main_frame const&) = delete;
    main_frame(main_frame&&) = delete;
    main_frame& operator=(main_frame const&) = delete;
    main_frame& operator=(main_frame&&) = delete;
    ~main_frame() override;
  };
} //namespace viewport::ui