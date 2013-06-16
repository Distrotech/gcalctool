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

#ifndef YY_CE_CE_PARSER_TAB_H_INCLUDED
# define YY_CE_CE_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int cedebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tABS = 258,
     tACOS = 259,
     tACOSH = 260,
     tAND = 261,
     tANS = 262,
     tASIN = 263,
     tASINH = 264,
     tATAN = 265,
     tATANH = 266,
     tCBRT = 267,
     tCHS = 268,
     tCLR = 269,
     tCOS = 270,
     tCOSH = 271,
     tCTRM = 272,
     tDDB = 273,
     tEXP = 274,
     tFRAC = 275,
     tFV = 276,
     tINT = 277,
     tLN = 278,
     tLOG10 = 279,
     tNOT = 280,
     tOR = 281,
     tPI = 282,
     tPMT = 283,
     tPV = 284,
     tRAND = 285,
     tRATE = 286,
     tRCL = 287,
     tSIN = 288,
     tSINH = 289,
     tSLN = 290,
     tSQRT = 291,
     tSTO = 292,
     tSYD = 293,
     tTAN = 294,
     tTANH = 295,
     tTERM = 296,
     tU16 = 297,
     tU32 = 298,
     tXNOR = 299,
     tXOR = 300,
     tINUMBER = 301,
     tDNUMBER = 302,
     tREG = 303,
     NEG = 304,
     POS = 305,
     HIGH = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 38 "ce_parser.y"

  int int_t[MP_SIZE];
  int integer;


/* Line 2058 of yacc.c  */
#line 114 "ce_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE celval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int ceparse (void *YYPARSE_PARAM);
#else
int ceparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int ceparse (void);
#else
int ceparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_CE_CE_PARSER_TAB_H_INCLUDED  */
