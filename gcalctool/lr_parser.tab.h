/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_LR_LR_PARSER_TAB_H_INCLUDED
# define YY_LR_LR_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int lrdebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NEG = 258,
     tABS = 259,
     tACOS = 260,
     tACOSH = 261,
     tAND = 262,
     tANS = 263,
     tASIN = 264,
     tASINH = 265,
     tATAN = 266,
     tATANH = 267,
     tCBRT = 268,
     tCHS = 269,
     tCOS = 270,
     tCOSH = 271,
     tDDB = 272,
     tEXP = 273,
     tFRAC = 274,
     tFV = 275,
     tINT = 276,
     tLN = 277,
     tLOG10 = 278,
     tNOT = 279,
     tOR = 280,
     tPI = 281,
     tPMT = 282,
     tPV = 283,
     tRAND = 284,
     tRATE = 285,
     tSIN = 286,
     tSINH = 287,
     tSLN = 288,
     tSQRT = 289,
     tSYD = 290,
     tTAN = 291,
     tTANH = 292,
     tTERM = 293,
     tU16 = 294,
     tU32 = 295,
     tXNOR = 296,
     tXOR = 297,
     tRCL = 298,
     tSTO = 299,
     tCLR = 300,
     tINUMBER = 301,
     tDNUMBER = 302,
     POS = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 39 "lr_parser.y"

  int int_t[MP_SIZE];


/* Line 2058 of yacc.c  */
#line 110 "lr_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE lrlval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int lrparse (void *YYPARSE_PARAM);
#else
int lrparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int lrparse (void);
#else
int lrparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_LR_LR_PARSER_TAB_H_INCLUDED  */
