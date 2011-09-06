# chinstrap - mustache C library

## Overview
chinstrap is a C library which provides [mustache](http://mustache.github.com)
template processing. It is intended to be easily usable as a library which can
be bound from other languages. It takes a more academic approach to compiling
mustache templates and provides such things as a scanner, lexer and parser.

Chinstrap uses 4 stages for successfully rendering mustache templates. The
scanner runs through the template and emits single characters to work with. In
the next stage the lexer creates meaningful (in the mustache context) tokens of
the retrieved characters. These token are then given to the parser, which knows
the [state machine]() to render mustache templates and creates a parse tree
based on it. The parse tree is then passed to the renderer along with the
context to create the rendered template.

## API

    #include<chinstrap.h>

    int result = chinstrap_render(char const* template, chinstrap context);

## Installation
- Clone the repository:

    git clone https://github.com/mrtazz/chinstrap.git

- Make sure everything works

    make tests

- Install it as a library

    make all install

## Dependencies
- [yajl](https://github.com/lloyd/yajl) for unit testing

## Meta
- [Bugs](http://github.com/chinstrap/issues)
- [Features](https://pivotaltracker.com/000000)

## Contribute
If you want to contribute:

- Fork the project.
- Make your feature addition or bug fix based on develop.
- Add tests for it. This is important so I don’t break it in a future version unintentionally.
- Commit, do not mess with version
- Send me a pull request. Bonus points for topic branches.

## Related
- If you want a more data model agnostic parser checkout [crustache]()
