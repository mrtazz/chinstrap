/**
 * scanner.c - implementation of the chinstrap scanner module
 */

#include "scanner.h"

/**
 * init the scanner with a mustache template
 *
 * :param template const char*: mustache template to scan
 * :return &scanner: scanner context for the template
 */
&scanner scanner_init(const char* template)
{
  scanner s = {0, 0, template, }

}

/**
 * get (the next) char from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_char(*scanner)
{
  // init the return value
  scanner_token ret = {current_row,
                       current_col,
                       scanner->template[scanner->pos]
                      };

  return ret;
}

/**
 * get the previous char from the last issued from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_previous_char(*scanner)
{
  scanner_token ret = {current_row - 1,
                       current_col - 1 ,
                       scanner->template[scanner->(pos-1)]
                      };

  return ret;
}
/**
 * get the next char from the last issued from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_next_char(*scanner)
{
  scanner_token ret = {current_row + 1,
                       current_col + 1 ,
                       scanner->template[scanner->(pos+1)]
                      };

  return ret;
}
