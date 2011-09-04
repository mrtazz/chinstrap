/**
 * chinstrap_types.h - type definitions used in various stages
 */

#ifndef __CHINSTRAP_TYPES_H__
#define __CHINSTRAP_TYPES_H__

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
  OPEN_TAG = 0,
  CLOSE_TAG,
  STRING,
  SECTION_START,
  SECTION_END,
  COMMENT,
  INV_SECTION_START,
  LAMBDA_START,
  DOT
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
  NUMBER = 0,
  STRING,
  BOOL,
  ARRAY,
  MAP
};
/**
 * the chinstrap_value (context) is a data representation inspired by JSON, it
 * can be filled with data and used to render templates.
 */
typedef struct chinstrap_value_t chinstrap_value;
typedef struct chinstrap_value_t
{
  const int type;
  union
  {
    const char* value;
    const double value;
    const int value;
    const chinstrap_value*[];
  };
} chinstrap_value;


#endif //__CHINSTRAP_TYPES_H__
