/**
 * scanner.c - implementation of the chinstrap scanner module
 */

#include "chinstrap/scanner.h"

/**
 * init the scanner with a mustache template
 *
 * :param template const char*: mustache template to scan
 * :return &scanner: scanner context for the template
 */
scanner scanner_init(const char* thetemplate, int length)
{
  scanner s = {0,0,"",0,0};
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
  scanner_token ret = {s->current_row,
                       s->current_col,
                       s->thetemplate[s->pos]
                      };

  return ret;
}

/**
 * get the previous char from the last issued from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_previous_char(scanner* s)
{
  scanner_token ret = {s->current_row - 1,
                       s->current_col - 1 ,
                       s->thetemplate[(s->pos-1)]
                      };

  return ret;
}
/**
 * get the next char from the last issued from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_next_char(scanner* s)
{
  scanner_token ret = {s->current_row + 1,
                       s->current_col + 1 ,
                       s->thetemplate[(s->pos+1)]
                      };

  return ret;
}
