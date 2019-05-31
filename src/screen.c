/* SCREEN.C - Definitions of Screen Printing Functions.
 * Claudia Jughashvili, 2019
 */

#include <screen.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>

const struct FRAME* draw_frame (const struct FRAME* frame) {
  /* Draw Border */
  mvhline (frame->y, frame->x, ACS_HLINE, frame->width - 1);
  mvhline (frame->y + frame->height - 1, frame->x, ACS_HLINE,
           frame->width - 1);
  mvvline (frame->y, frame->x, ACS_VLINE, frame->height - 1);
  mvvline (frame->y, frame->x + frame->width - 1, ACS_VLINE,
           frame->height - 1);
  mvaddch (frame->y, frame->x, ACS_ULCORNER);
  mvaddch (frame->y + frame->height - 1, frame->x, ACS_LLCORNER);
  mvaddch (frame->y, frame->x + frame->width - 1, ACS_URCORNER);
  mvaddch (frame->y + frame->height - 1, frame->x + frame->width - 1,
    ACS_LRCORNER);

  /* Draw Title */
  if (frame->title)
    mvaddstr (frame->y, frame->x + ((frame->width / 2) -
      (strlen (frame->title) / 2)), frame->title);

  refresh ();
  return frame;
};

const char** print_list (unsigned int x, unsigned int y, unsigned int count, 
  const char** list)
{
  for (unsigned int i = 0; i < count; i++)
    mvaddstr (y + i, x, list[i]);
  refresh ();
  return list;
};

unsigned int post_log (const char* str) {
  static struct FRAME* log_frame;
  static char* log_list[5];
  static unsigned int log_count;

  if (!log_frame) {
    log_frame = (struct FRAME*)malloc (sizeof (struct FRAME));
    log_frame->x = 0;
    log_frame->y = LINES - 7;
    log_frame->width = COLS;
    log_frame->height = 7;
    log_frame->title = "LOG";
  };

  if (!str)
    return log_count;

  if (log_list[0])
    free (log_list[0]);

  for (unsigned int i = 1; i < 5; i++)
    log_list[i-1] = log_list[i];

  log_list[4] = (char*)calloc (strlen (str) + 10, sizeof (char));
  snprintf (log_list[4], strlen (str) + 10, "[%d] %s", log_count, str);

  for (unsigned int i = 0; i < 5; i++) {
    mvhline (LINES - 6 + i, 0, ' ', COLS);
    mvaddstr (LINES - 6 + i, 1, log_list[i]);
  };

  draw_frame (log_frame);
  return ++log_count;
};
