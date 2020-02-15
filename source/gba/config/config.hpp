/*
 * Copyright (C) 2020 fleroviux
 *
 * Licensed under GPLv3 or any later version.
 * Refer to the included LICENSE file.
 */

#pragma once

#include <cstdint>
#include <memory>

#include "device/audio_device.hpp"
#include "device/input_device.hpp"
#include "device/video_device.hpp"

namespace GameBoyAdvance {

struct Config {
  std::string bios_path = "bios.bin";
  
  bool skip_bios = false;
  
  enum class SaveType {
    Detect,
    SRAM,
    FLASH_64,
    FLASH_128,
    EEPROM_4,
    EEPROM_64
  } save_type = SaveType::Detect;
  
  struct Video {
  } video;
  
  struct Audio {
    enum class Interpolation {
      Cosine,
      Cubic,
      Sinc_32,
      Sinc_64,
      Sinc_128,
      Sinc_256
    } interpolation = Interpolation::Cosine;
  } audio;
  
  std::shared_ptr<AudioDevice> audio_dev = std::make_shared<NullAudioDevice>();
  std::shared_ptr<InputDevice> input_dev = std::make_shared<NullInputDevice>();
  std::shared_ptr<VideoDevice> video_dev = std::make_shared<NullVideoDevice>();
};

}
