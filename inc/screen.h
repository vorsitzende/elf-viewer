/* SCREEN.H - Screen Printing Functions and Declarations.
 * Claudia Jughashvili, 2019
 */

#ifndef _SCREEN_H_
#define _SCREEN_H_

struct FRAME {
  unsigned int x, y, width, height;
  const char* title;
};

#ifdef __cplusplus
extern "C" {
#endif

  const struct FRAME* draw_frame (const struct FRAME*);
  const char** print_list (unsigned int, unsigned int, unsigned int,
    const char**);
  unsigned int post_log (const char*);

#ifdef __cplusplus
};
#endif

#endif /* _SCREEN_H_ */
