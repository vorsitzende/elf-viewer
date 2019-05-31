
#include <screen.h>
#include <elf.h>
#include <curses.h>

static inline void init_screen (void) {
  initscr ();
  cbreak ();
  noecho ();
  keypad (stdscr, TRUE);
  nodelay (stdscr, FALSE);
  curs_set (0);
  refresh ();
};

int main (int argc, const char** argv) {
  init_screen ();

  static char buffer[50];
  const char* elf_header = (const char*)load_elf_file (argv[0]);
  struct FRAME left_frame = { 0, 0, 31, LINES - 7, "HEADER DATA" };
  struct FRAME right_frame = { 31, 0, COLS - 31, LINES - 7, "INFORMATION" };

  draw_frame (&left_frame);
  draw_frame (&right_frame);
  post_log ("SCREEN INITIALIZED SUCCESSFULLY.");
  snprintf (buffer, 50, "%d ARGUMENT(S):", argc);
  post_log (buffer);
  for (int i = 0; i < argc; i++) {
    snprintf (buffer, 50, "ARG %d: %s", i + 1, argv[i]);
    post_log (buffer);
  };

  for (unsigned int i = 0; i < 3; i++) {
    snprintf (buffer, 30, "%02X.%02X.%02X.%02X.%02X.%02X.%02X.%02X.%02X.%02X",
      elf_header[0+(i*10)], elf_header[1+(i*10)], elf_header[2+(i*10)],
      elf_header[3+(i*10)], elf_header[4+(i*10)], elf_header[5+(i*10)],
      elf_header[6+(i*10)], elf_header[7+(i*10)], elf_header[8+(i*10)],
      elf_header[9+(i*10)]);
    mvaddstr (i + 1, 1, buffer);
  };

  const struct ELF32_HEADER* header = (const struct ELF32_HEADER*)elf_header;
  snprintf (buffer, COLS - 28, "MACHINE CODE %04X : %s", header->e_machine,
    machine_string (header->e_machine));
  mvaddstr (1, 32, buffer);
  refresh ();

  getch ();

  endwin ();
  return 0;
};
