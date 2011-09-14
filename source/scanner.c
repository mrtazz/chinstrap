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
  len = (length < 0) ? strlen(thetemplate) : length;
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
  ++s->current_col;
  const char c = s->thetemplate[s->pos];
  scanner_token ret = {s->current_row,
                       s->current_col,
                       c
                      };
  ++s->pos;

  return ret;
}

