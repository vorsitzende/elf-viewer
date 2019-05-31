# ELF-Viewer
Program to view ELF files and piece apart their headers and relevant components.

Claudia Jughashvili, 2019

## Dependencies
- `CURSES` - For screen manipulation.  PDCURSES 4.0.2 worked on Windows.  NCURSES worked on Linux x86_64.

## Usage Notes
- Program expects a command-line argument in the form of a path to an ELF file.  It will prompt for one if none is detected.
- Resizing the console while the program is running will produce unfavorable behavior, and possibly crash.  Working on fixing that.
