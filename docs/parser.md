# The mustache parser

## Overview
The mustache parser is the only part in chinstrap which has a stateful
knowledge of the template. All stages below work on basis of a single character
or token. The parser takes one token at a time from the lexer and builts a
parse tree from it.

## API
The parser module provides a simple API for parsing a template:

    mustache_tree_node* parse(char* thetemplate);

This call internally initializes a `lexer_context` with the template string and
starts asking it for tokens. From the emitted tokens a parse tree is built
representing the template. The return value is a pointer to the root node of
the parse tree.

This can then be used to transform the data further. The default way is mostly
the rendering of the template via the `render()` function.

## Under the hood
### The parse tree
The parse tree is the central representation of the template as a syntax
structure. After the template is available in tree form, many different
operations can be executed on the tree in order to gain information about the
template or transform the tree.

### A parse tree node
A parse tree node is an object with 6 properties:

- A type property describing the type of mustache node
- A content property which describes the actual content of that node
- A link to the parent node
- A link to the next neighbour node on the left
- A link to the next neighbour node on the right
- A list of links to all child nodes

This way it is rather easy to navigate through the tree and get the next node
in the tree parsing process.

