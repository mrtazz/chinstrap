/**
 *  scanner.h - header file for the chinstrap scanner module
 */
#ifndef __CHINSTRAP_SCANNER_H__
#define __CHINSTRAP_SCANNER_H__

// includes
#include "chinstrap_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// typedefs

typedef struct
{
  // the current row of the context
  int current_row;
  // the current column of the context
  int current_col;
  // mustache template as const char*
  const char* template;
  // length of the template string
  const int template_length;
  // current position in the string
  int pos;

} scanner;

// module variables
static int counter = 0;

// API functions

/**
 * init the scanner with a mustache template
 *
 * :param template const char*: mustache template to scan
 * :return &scanner: scanner context for the template
 */
&scanner scanner_init(const char* template);

/**
 * get (the next) char from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_char(*scanner);
/**
 * get the previous char from the last issued from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_previous_char(*scanner);
/**
 * get the next char from the last issued from the template
 *
 * :return scanner_token: struct {row, col, cargo}
 */
scanner_token get_next_char(*scanner);

#ifdef __cplusplus
}
#endif

#endif
