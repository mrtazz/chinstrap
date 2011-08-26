# chinstrap - mustache C library

## Overview
chinstrap is a C library which provides [mustache](http://mustache.github.com)
template processing. It is intended to be easily usable as a library which can
be bound from other languages. It takes a more academic approach to compiling
mustache templates and provides such things as a scanner, lexer and parser.

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
- [Check](http://sourceforge.net/projects/check/) for unit tests

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
