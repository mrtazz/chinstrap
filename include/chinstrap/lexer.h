/**
 *  lexer.h - header file for the chinstrap lexer module
 */
#ifndef __CHINSTRAP_LEXER_H__
#define __CHINSTRAP_LEXER_H__

// includes
#include "chinstrap/types.h"

#ifdef __cplusplus
extern "C" {
#endif

// typedefs
/**
 * different types of mustache tokens stored in an enum for easy lookup
 */
typedef enum
{
  /* {{ */
  MUSTACHE_OPEN_TAG = 0,
  /* }} */
  MUSTACHE_CLOSE_TAG,
  /* "foobar" */
  MUSTACHE_STRING,
  /* # */
  MUSTACHE_SECTION_START,
  /* / */
  MUSTACHE_SECTION_END,
  /* ^ */
  MUSTACHE_INV_SECTION_START,
  /* / */
  MUSTACHE_INV_SECTION_END = MUSTACHE_SECTION_END,
  /* ! */
  MUSTACHE_COMMENT,
  /* "{{ foo }} is awesome", where <foo> is 'renderable' */
  MUSTACHE_LAMBDA_START,
  /* STRING.element */
  MUSTACHE_DOT
} mustache_tokens;

/**
 * the lexer token struct defines an int type token and if necessary the
 * content to be passed to the parser.
 */
typedef struct lexer_token_t
{
  // type of mustache lexer token
  mustache_tokens type;
  // content mostly used for mustache strings
  const char* content;
} lexer_token;

// API functions

#ifdef __cplusplus
}
#endif

#endif

