/*
 * Copyright (C) 2020 fleroviux
 *
 * Licensed under GPLv3 or any later version.
 * Refer to the included LICENSE file.
 */

#pragma once

#include <memory>
#include <string>

#include "core/cpu.hpp"

namespace GameBoyAdvance {
  
class Emulator {
public:
  enum class StatusCode {
    BiosNotFound,
    GameNotFound,
    BiosWrongSize,
    GameWrongSize,
    Ok
  };
  
  Emulator(std::shared_ptr<Config> config);

  void Reset();
  auto LoadGame(std::string const& path) -> StatusCode;
  void Frame();
  
private:
  static auto DetectSaveType(std::uint8_t* rom, size_t size) -> Config::SaveType;
  
  auto LoadBIOS() -> StatusCode; 
  
  CPU cpu;
  bool bios_loaded = false;
  bool save_detect = false;
  std::shared_ptr<Config> config;
};

}