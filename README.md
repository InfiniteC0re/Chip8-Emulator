# Chip8-Emulator
Simple Chip-8 emulator written in C++ that uses OpenGL to render the virtual screen.

CHIP-8 is an interpreted programming language, developed by Joseph Weisbecker. It was initially used on the COSMAC VIP and Telmac 1800 8-bit microcomputers in the mid-1970s. CHIP-8 programs are run on a CHIP-8 virtual machine. It was made to allow video games to be more easily programmed for these computers. The simplicity of CHIP-8, and its long history and popularity, has ensured that CHIP-8 emulators and programs are still being made to this day.

## Building
I haven't tested the emulator on any platforms but Windows so I can't gurantee the rendering part it will work on Linux or Mac

To build the emulator on Windows simply compile it in Visual Studio and make sure you have `opengl32.lib` on your system

## Usage
`./CHIP8-Emulator.exe ROM_FILE`

### Keyboard layout:
| Chip 8 -> |   |   |   |   | Emulator -> |   |   |   |   |
|-----------|---|---|---|---|-------------|---|---|---|---|
|           | 1 | 2 | 3 | C |             | 1 | 2 | 3 | 4 |
|           | 4 | 5 | 6 | D |             | Q | W | E | R |
|           | 7 | 8 | 9 | E |             | A | S | D | F |
|           | A | 0 | B | F |             | Z | X | C | V |

## Changing settings
At the moment there's no way to change settings of the emulator without recompiling it

To change the CPU Hz modify the CPU_HZ define in `src/devices/CPU.h`

To change the scale of the virtual display pixels modify the WINDOW_SCALE define in `src/main.cpp`

## Useful links
[Chip-8 Specification](http://www.cs.columbia.edu/~sedwards/classes/2016/4840-spring/designs/Chip8.pdf)
•
[Wikipedia](https://en.wikipedia.org/wiki/CHIP-8)
