# chinstrap - mustache C library

## Overview
chinstrap is a C library which provides [mustache](http://mustache.github.com)
template processing. It is intended to be easily usable as a library which can
be bound from other languages. It takes a more academic approach to compiling
mustache templates and provides such things as a scanner, lexer and parser.

## API

    #include<chinstrap.h>

    int result = chinstrap_render(char const* template, chinstrap context);


## Meta
- [Bugs](http://github.com/chinstrap/issues)
- [Features](https://pivotaltracker.com/000000)

