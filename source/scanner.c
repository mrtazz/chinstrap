/**
 * scanner.c - implementation of the chinstrap scanner module
 */

#include <string.h>
#include "chinstrap/scanner.h"

/**
 * init the scanner with a mustache template
 *
 * :param template const char*: mustache template to scan
 * :return &scanner: scanner context for the template
 */
scanner scanner_init(const char* thetemplate, int length)
{
  int len;
  len = (length < 0) ? (int)strlen(thetemplate) : length;
  scanner s = {0, 0, thetemplate, len, 0};
  return s;
}

/**
 * get (the next) char from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_char(scanner* s)
{
  // init the return value
  char c;
  c = s->thetemplate[s->pos];
  // check if there is a new row
  if (c == '\n')
  {
    // increase row number
    ++(s->current_row);
    // reset column number
    s->current_col = 0;
    ++(s->pos);
    c = s->thetemplate[s->pos];
  } /* if */

  /* Verify that we stop when the string is terminated */
  if (c != '\0')
  {
    ++s->current_col;
    ++s->pos;
  } /* if */

  scanner_token ret = { s->current_row, s->current_col, c };

  return ret;
}

