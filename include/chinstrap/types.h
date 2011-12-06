/**
 * chinstrap_types.h - type definitions used in various stages
 */

#ifndef __CHINSTRAP_TYPES_H__
#define __CHINSTRAP_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

// scanner types
/**
 * a scanner token determines a character and its location in the template
 * given by row and column
 */
typedef struct scanner_token_t
{
  // row of the character
  const int row;
  // column of the character
  const int col;
  // the actual character
  const char cargo;
} scanner_token;

// lexer types
/**
 * different types of mustache tokens stored in an enum for easy lookup
 */
enum mustache_tokens
{
  MUSTACHE_OPEN_TAG = 0,
  MUSTACHE_CLOSE_TAG,
  MUSTACHE_STRING,
  MUSTACHE_SECTION_START,
  MUSTACHE_SECTION_END,
  MUSTACHE_COMMENT,
  MUSTACHE_INV_SECTION_START,
  MUSTACHE_LAMBDA_START,
  MUSTACHE_DOT
};

/**
 * the lexer token struct defines an int type token and if necessary the
 * content to be passed to the parser.
 */
typedef struct lexer_token_t
{
  // type of mustache lexer token
  int type;
  // content mostly used for mustache strings
  const char* content;
} lexer_token;

// parser types
// TODO: define parse tree here

// render types
/**
 * The possible different types for values passed as context
 */
enum chinstrap_values
{
  CHINSTRAP_NUMBER = 0,
  CHINSTRAP_STRING,
  CHINSTRAP_BOOL,
  CHINSTRAP_ARRAY,
  CHINSTRAP_MAP
};
/**
 * the chinstrap_value (context) is a data representation inspired by JSON, it
 * can be filled with data and used to render templates.
 */
typedef struct chinstrap_value_t chinstrap_value;
struct chinstrap_value_t
{
  // mustache value type
  const int type;
  // key field used for map values
  const char* key;
  union
  {
    const char* string;
    const double number;
    const int boolean;
    chinstrap_value* array;
    // TODO: we need a dict/map type here also
  } value;
};

#ifdef __cplusplus
}
#endif

#endif //__CHINSTRAP_TYPES_H__
