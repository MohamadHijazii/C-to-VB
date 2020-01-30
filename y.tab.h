/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    type = 258,
    id = 259,
    int_val = 260,
    float_val = 261,
    double_val = 262,
    char_val = 263,
    int_type = 264,
    float_type = 265,
    double_type = 266,
    char_type = 267,
    semicolon = 268,
    cama = 269,
    op = 270,
    cp = 271,
    ob = 272,
    cb = 273,
    equal = 274,
    plus = 275,
    minus = 276,
    mult = 277,
    divs = 278,
    and = 279,
    or = 280,
    done = 281
  };
#endif
/* Tokens.  */
#define type 258
#define id 259
#define int_val 260
#define float_val 261
#define double_val 262
#define char_val 263
#define int_type 264
#define float_type 265
#define double_type 266
#define char_type 267
#define semicolon 268
#define cama 269
#define op 270
#define cp 271
#define ob 272
#define cb 273
#define equal 274
#define plus 275
#define minus 276
#define mult 277
#define divs 278
#define and 279
#define or 280
#define done 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:1921  */

    char _type;
    char variable[32];
    int int_value;
    float float_value;
    char char_value;
    double double_value;
    char str[256];

#line 120 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
