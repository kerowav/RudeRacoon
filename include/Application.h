#pragma once

namespace RudeRacoon
{
  class Application {
  public:
    Application() = default;
    virtual ~Application() = default;
  
    void Start();

    inline void Stop() {
      mRunning = false;
    }

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Destroy() = 0;
  private:
    bool mRunning = false;

  };

  // Application* GetApplication();
} // namespace RudeRacoon
