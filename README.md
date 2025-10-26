# piano-leds

## Setup

[Install PlatformIO](https://docs.platformio.org/en/latest/core/installation/methods/installer-script.html) and build the project:
```bash
pio run
```

Flash to board (follow instructions on udev rules if necessary):
```bash
pio run --target upload
```

## References

- [platformio - init project](https://docs.platformio.org/en/latest/core/userguide/project/cmd_init.html)
  ```bash
  pio project init -b nanoatmega328
  pio lib install fastled/FastLED@3.10.2
  ```
- [FastLED](https://github.com/FastLED/FastLED?tab=readme-ov-file#-documentation--support)
