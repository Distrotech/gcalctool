
/*  $Header$
 *
 *  Copyright (C) 2004-2008 Sami Pietila
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *           
 *  This program is distributed in the hope that it will be useful, but 
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 *  General Public License for more details.
 *           
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 */

#include "mp-equation.h"
#include "calctool.h"
#include "mp-equation-parser.h"
#include "mp-equation-lexer.h"

extern int _mp_equation_parse(yyscan_t yyscanner);

int 
mp_equation_parse_(const char *expression, MPNumber *result, int need_result)
{
    int ret = 0;
    MPEquationParserState state;
    yyscan_t yyscanner;
    YY_BUFFER_STATE buffer;

    if (!(expression && result) || strlen(expression) == 0)
        return(-EINVAL);

    memset(&state, 0, sizeof(MPEquationParserState));
    state.base = basevals[v->base];
    state.wordlen = v->wordlen;
    state.angle_units = v->ttype;
    mp_set_from_mp(display_get_answer(&v->display), &state.ans);
    v->math_error = 0;
        
    _mp_equation_lex_init_extra(&state, &yyscanner);
    buffer = _mp_equation__scan_string(expression, yyscanner);

    ret = _mp_equation_parse(yyscanner);

    _mp_equation__delete_buffer(buffer, yyscanner);
    _mp_equation_lex_destroy(yyscanner);

    ret = (state.error) ? state.error : ret;
    if (ret)
        return ret;

    if ((need_result != 0) != (state.have_result != 0))
        return -EINVAL;

    if (v->math_error)
        return v->math_error;

    mp_set_from_mp(&state.ret, result);
    return 0;
}


int 
mp_equation_parse(const char *expression, MPNumber *result)
{
    return(mp_equation_parse_(expression, result, 1));
}


int 
mp_equation_udf_parse(const char *expression)
{
    MPNumber t;
    return mp_equation_parse_(expression, &t, 0);
}

int _mp_equation_error(void *yylloc, MPEquationParserState *state, char *text)
{
    return 0;
}