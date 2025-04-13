#pragma once
#include <iostream>
#include <chrono>

#define USE_TIMER 1

#if USE_TIMER
#define MEASURE_FUNCTION() ScopedTimer timer{__func__}
#else
#define MEASURE_FUNCTION()
#endif

class ScopedTimer {

public:
  using ClockType = std::chrono::steady_clock;

  ScopedTimer(const char* ifunction) :
    function_{ifunction}, start_{ClockType::now()} {
  }

  ScopedTimer(const ScopedTimer&) = delete;
  ScopedTimer(ScopedTimer&&) = delete;
  auto operator=(const ScopedTimer&) -> ScopedTimer& = delete;
  auto operator=(ScopedTimer&&) -> ScopedTimer& = delete;

  ~ScopedTimer() {
    const auto stop = ClockType::now();
    const auto duration = (stop - start_);
    const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::cout << ms << " ms " << function_ <<  '\n';
  }

private:
  const char* function_ = {};
  const ClockType::time_point start_ = {};
};
