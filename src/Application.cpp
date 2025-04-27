#include "Application.h"

namespace RudeRacoon {
  void RudeRacoon::Application::Start()
  {
    if(mRunning) return;
    mRunning = true;
  
    Init();
  
    while(mRunning) {
      Update();
    }
    Destroy();
  }
}

