
/*  $Header$
 *
 *  Copyright (c) 1987-2005 Sun Microsystems, Inc. All Rights Reserved.
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

#ifndef CALCTOOL_H
#define CALCTOOL_H

#include "config.h"

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>

#define MP_SIZE      150     /* Size of the multiple precision values. */

#define FCLOSE       (void) fclose     /* To make lint happy. */
#define FPRINTF      (void) fprintf
#define FPUTS        (void) fputs
#define GETHOSTNAME  (void) gethostname
#define MEMCPY       (void) memcpy
#define MEMSET       (void) memset
#define MKSTEMP      (void) mkstemp
#define REWIND       (void) rewind
#define SPRINTF      (void) sprintf
#define SSCANF       (void) sscanf
#define STRCAT       (void) strcat
#define STRCPY       (void) strcpy
#define STRNCAT      (void) strncat
#define UNLINK       (void) unlink

/* Menu bar menu types. */

enum mb_type { M_ABOUT, M_ASCII, M_BASIC, M_ADV, M_CONTENTS, M_COPY,  M_FIN,
	       M_PASTE, M_QUIT,  M_REGS,  M_SCI, M_EXP, M_TSEP, M_ZEROES };

enum base_type { BIN, OCT, DEC, HEX };      /* Base definitions. */

/* Main calctool window types. */
enum fcp_type  { FCP_KEY, FCP_REG, FCP_MODE };

enum item_type { BASEITEM, TTYPEITEM, NUMITEM,
                 HYPITEM,  INVITEM,   OPITEM,  MODEITEM };

/* Popup menu types. */
enum menu_type { M_ACC,  M_CON,  M_EXCH, M_FUN,  M_LSHF,
                 M_RCL,  M_RSHF, M_STO,  M_NONE
};

/* Calculator modes. */
enum mode_type { BASIC, ADVANCED, FINANCIAL, SCIENTIFIC };

enum num_type { ENG, FIX, SCI };            /* Number display mode. */

/* Resources. */
enum res_type { R_ACCURACY, R_BASE, R_DISPLAY, R_MODE, R_REGS, R_TRIG,
                R_ZEROES,   R_TSEP, R_SYNTAX
};

enum trig_type { DEG, GRAD, RAD };          /* Trigonometric types. */

enum trig_func { SIN=1, COS=2, TAN=4 };

/* Abbreviations for the gcalctool keyboard and menu equivalents. */

#define KEY_DIV   a_buttons[3]              /* / */
#define KEY_LPAR  a_buttons[4]              /* ( */
#define KEY_BSP   a_buttons[5]              /* Control-h */

#define KEY_MUL   a_buttons[11]             /* * */
#define KEY_RPAR  a_buttons[12]             /* ) */

#define KEY_CHS   a_buttons[13]             /* C */
#define KEY_INT   a_buttons[14]             /* i */
#define KEY_STO   a_buttons[15]             /* S */

#define KEY_SUB   a_buttons[19]             /* - */
#define KEY_PER   a_buttons[20]             /* % */
#define KEY_SQRT  a_buttons[21]             /* s */
#define KEY_FRAC  a_buttons[22]             /* : */
#define KEY_RCL   a_buttons[23]             /* R */

#define KEY_EQ    a_buttons[26]             /* = */
#define KEY_ADD   a_buttons[27]             /* + */
#define KEY_REC   a_buttons[28]             /* r */
#define KEY_SQR   a_buttons[29]             /* @ */
#define KEY_ABS   a_buttons[30]             /* u */
#define KEY_EXCH  a_buttons[31]             /* X */

#define KEY_CTRM  f_buttons[0]              /* m */
#define KEY_DDB   f_buttons[1]              /* D */
#define KEY_FV    f_buttons[2]              /* v */
#define KEY_PMT   f_buttons[3]              /* P */
#define KEY_PV    f_buttons[4]              /* p */
#define KEY_RATE  f_buttons[5]              /* T */
#define KEY_SLN   f_buttons[6]              /* l */
#define KEY_SYD   f_buttons[7]              /* Y */
#define KEY_TERM  f_buttons[8]              /* T */

#define KEY_LSFT  s_buttons[0]              /* < */
#define KEY_RSFT  s_buttons[1]              /* > */
#define KEY_16    s_buttons[2]              /* [ */
#define KEY_32    s_buttons[3]              /* ] */
#define KEY_ACC   s_buttons[7]              /* A */

#define KEY_CON   s_buttons[8]              /* # */
#define KEY_FUN   s_buttons[9]              /* F */
#define KEY_ETOX  s_buttons[11]             /* { */
#define KEY_TTOX  s_buttons[12]             /* } */
#define KEY_YTOX  s_buttons[13]             /* y */
#define KEY_FACT  s_buttons[14]             /* ! */
#define KEY_RAND  s_buttons[15]             /* ? */

#define KEY_COS   s_buttons[19]             /* J */
#define KEY_SIN   s_buttons[20]             /* K */
#define KEY_TAN   s_buttons[21]             /* L */
#define KEY_LN    s_buttons[22]             /* N */
#define KEY_LOG   s_buttons[23]             /* G */

#define KEY_OR    s_buttons[27]             /* | */
#define KEY_AND   s_buttons[28]             /* & */
#define KEY_NOT   s_buttons[29]             /* ~ */
#define KEY_XOR   s_buttons[30]             /* ^ */
#define KEY_XNOR  s_buttons[31]             /* n */

#define BCOLS          4      /* No of columns of Basic Mode buttons. */
#define BROWS          5      /* No of rows of Basic Mode buttons. */

#define ACOLS          8      /* No of columns of Advanced Mode buttons. */
#define AROWS          4      /* No of rows of Advanced Mode buttons. */

#define FCOLS          8      /* No of columns of Financial Mode buttons. */
#define FROWS          2      /* No of rows of Financial Mode buttons. */

#define SCOLS          8      /* No of columns of Scientific Mode buttons. */
#define SROWS          4      /* No of rows of Scientific Mode buttons. */

#define EQUAL(a, b)    (strlen(a)==strlen(b)) & !strcmp(a, b) 

#define INC            { argc--; argv++; }
#define IS_KEY(v, n)   (v == n)

#ifndef LINT_CAST
#ifdef  lint
#define LINT_CAST(arg)  (arg ? 0 : 0)
#else
#define LINT_CAST(arg)  (arg)
#endif /*lint*/
#endif /*LINT_CAST*/

#define MAX_DIGITS     40         /* Maximum displayable number of digits. */
#define MAX_LOCALIZED  (MAX_DIGITS * (1 + MB_LEN_MAX) + MB_LEN_MAX)

/* Maximum number of various graphics pieces. */
#define MAXITEMS       8          /* Maximum number of panel items. */
#define MAXMENUS       9          /* Maximum number of popup menus. */

#ifndef MAXLINE
#define MAXLINE        256        /* Length of character strings. */
#endif /*MAXLINE*/

#define MAXACC         30    /* Max. number of digits after numeric point. */
#define MAXBASES       4          /* Maximum number of numeric bases. */
#define MAXCONFUN      10         /* Maximum number of constants/functions. */
#define MAXDISPMODES   3          /* Maximum number of display modes. */
#define MAXEXTRAS      8          /* Maximum number of keysym alternates. */
#define MAXMODES       4          /* Maximum number of calculator modes. */
#define MAXREGS        10         /* Maximum number of memory registers. */
#define MAXSTACK       256        /* Parenthese stack size. */
#define MAXTRIGMODES   3          /* Maximum number of trig. modes. */
#define MAXVKEYS       1          /* Number of valid keys after an error. */
#define MAXSYNTAX      2          /* Number of syntaxes in calculator */

#define MCOLS          8          /* Number of columns of "special" keys. */
#define MROWS          2          /* Number of rows of "special" keys. */
#define MODEKEYS       MCOLS * MROWS

#ifndef MIN
#define MIN(x,y)       ((x) < (y) ? (x) : (y))
#endif /*MIN*/

#define B_NOBUTTONS      BROWS * BCOLS  /* Number of Basic Mode buttons. */
#define A_NOBUTTONS      AROWS * ACOLS  /* Number of Advanced Mode buttons. */
#define F_NOBUTTONS      FROWS * FCOLS  /* Number of Financial Mode buttons. */
#define S_NOBUTTONS      SROWS * SCOLS  /* Number of Scientific Mode buttons. */

#ifndef CFNAME
#define CFNAME         ".gcalctoolcf"
#endif /*CFNAME*/

#ifndef RCNAME
#define RCNAME         ".gcalctoolrc"
#endif /*RCNAME*/

#ifndef TRUE                    /* Boolean definitions. */
#define TRUE           1
#endif /*TRUE*/

#ifndef FALSE
#define FALSE          0
#endif /*FALSE*/


typedef unsigned long  BOOLEAN;

enum button_flags {
    none         = 0,          /* No flags */
    binop        = 1,          /* Is binary operation ie. A op B */ 
    unop         = 2,          /* Is unary operation ie. op A. */
    enter        = 4,          /* Expression is entered */
    number       = 8,          /* Number button */
    immediate    = 16,         /* Button does immediate function */

    parenthesis  = 64,         /* Parenthesis */
    func         = 128,        /* Function */
    bsp          = 256,        /* Backspace */
    clear        = 512,        /* Clear display */
    neg          = 1024,       /* Negate display */
    inv          = 2048,       /* Reciprocial */
    con          = 4096,       /* Constant */
    regrcl       = 8192,       /* Recall register */
    expnum       = 16384,      /* Exponential number */
    postfixop    = 32768,      /* Unary postfix operation */
    prefixop     = 65536       /* Unary prefix operation */
};

struct exprm_state {       /* Expression mode state */
    int calc_complete : 1;
    int numeric_ans : 1;    /* Show answer numerically 
                             * (alternative is symbolically) 
                             */
    int ans[MP_SIZE];        /* Previously calculated answer */
    int ansbak[MP_SIZE];     /* Pre ans */
    char *expbak;
};

enum shiftd {
    left = 0,
    right 
};

enum syntax {
    npa = 0,                 /* Non-precedence arithmetic */
    exprs,                   /* Expression with arithmetic precedence */
};

struct button {
    char *str;               /* Button display string. */
    char *hstr;              /* Button help string. */
    char *astr;              /* AccessibleName string (if tooltip not useful) */
    guint mods[MAXEXTRAS];   /* Keyboard modifiers (Shift, Ctrl, ...). */
    guint value[MAXEXTRAS];  /* Button keyboard equivalents. */
    char func_char;          /* Unique function string character. */
    enum menu_type mtype;    /* Type of popup menu (if any). */
    void (*func)();          /* Function to obey on button press. */
    char *symname;           /* Expression function name */
    enum button_flags flags; /* Misc flags */
};

struct menu {
    char *title;             /* Menu title. */
    int  total;              /* Number of menu entries. */
    int  index;              /* Index into menu string array. */
    int  defval;             /* Default menu item position (from 1). */
};

struct calcVars {                      /* Calctool variables and options. */
    struct exprm_state e;               /* Expression mode state */
  
    struct button *pending_but;        /* Button info. for pending op. */
    struct button *current;            /* Current button/character pressed. */
  
    char *appname;                     /* Application name for resources. */
    char con_names[MAXREGS][MAXLINE];  /* Selectable constant names. */
    char display[MAXLINE];             /* Current calculator display. */
    char *exp_posn;                    /* Position of the exponent sign. */
    char fnum[MAX_DIGITS];             /* Scratchpad for fixed numbers. */
    char fun_names[MAXREGS][MAXLINE];  /* Function names from .gcalctoolcf. */
    char fun_vals[MAXREGS][MAXLINE];   /* Function defs from .gcalctoolcf. */
    char *home;                        /* Pathname for users home directory. */
    char *iconlabel;                   /* The calctool icon label. */
    char op_item_text[5];              /* Operand item panel string. */
    char opstr[5];                     /* Operand string during pending op. */
    char *progname;                    /* Name of this program. */
    char pstr[5];                      /* Current button text string. */
    const char *radix;                 /* Locale specific radix string. */
    char *shelf;                       /* PUT selection shelf contents. */
    char snum[MAX_DIGITS];             /* Scratchpad for scientific numbers. */
    const char *tsep;                /* Locale specific thousands seperator. */
    char *titleline;                   /* Value of titleline (if present). */
    char *tool_label;                  /* Title line for calculator window. */

    int MPcon_vals[MAXREGS][MP_SIZE];  /* Selectable constants. */
    int MPdebug;                       /* If set, debug info. to stderr. */
    int MPerrors;                      /* If set, output errors to stderr. */
    int MPdisp_val[MP_SIZE];           /* Value of the current display. */
    int MPexpr_val[MP_SIZE];           /* Value of the current expression. */
    int MPlast_input[MP_SIZE];         /* Previous number input by user. */
    int MPmvals[MAXREGS][MP_SIZE];     /* Memory register values. */
    int *MPnumstack[MAXSTACK];         /* Numeric stack for parens. */
    int MPresult[MP_SIZE];             /* Current calculator total value. */
    int MPimresult[MP_SIZE];           /* Current intermediate result. */
    int MPtresults[3][MP_SIZE];        /* Current trigonometric results. */

    enum base_type base;            /* Current base: BIN, OCT, DEC or HEX. */
    enum fcp_type curwin;           /* Window current event occured in. */
    enum mode_type modetype;        /* Current calculator mode. */
    enum num_type dtype;            /* Number display mode. */
    enum trig_type ttype;           /* Trig. type (deg, grad or rad). */

    enum syntax syntax;             /* Calculation syntax mode */

    char *expression;  /* Expression entered by user */
  
    int accuracy;      /* Number of digits precision (Max 9). */
    int beep;          /* Indicates whether there is a beep sound on error. */
    int cur_ch;        /* Current character if keyboard event. */
    int cur_op;        /* Current arithmetic operation. */
    int doing_mi;      /* Set if adjusting the "show zeroes" menu item. */
    int down;          /* Indicates is a mouse button is down. */
    int error;         /* Indicates some kind of display error. */
    int hyperbolic;    /* If set, trig functions will be hyperbolic. */
    int iconic;        /* Set if window is currently iconic. */
    int inverse;       /* If set, trig and log functions will be inversed. */
    int ismenu;        /* Set when do_pending called via a popup menu. */
    int key_exp;       /* Set if entering exponent number. */
    int ndisplay;      /* Height of the numerical display. */
    int new_input;     /* New number input since last op. */
    int noparens;      /* Count of left brackets still to be matched. */
    int numsptr;       /* Pointer into the parenthese numeric stack. */
    int old_cal_value;      /* Previous calculation operator. */
    int opsptr;        /* Pointer into the parentheses operand stack. */
    int opstack[MAXSTACK];  /* Stack containing parentheses input. */
    int pending;            /* Set for command depending on multiple presses. */
    int pending_op;    /* Arithmetic operation for pending command. */
    int pointed;       /* Whether a decimal point has been given. */
    int rstate;        /* Indicates if memory register frame is displayed. */
    int show_paren;    /* Set if we wish to show DISPLAYITEM during parens. */
    int show_tsep;     /* Set if the thousands seperator should be shown. */
    int show_zeroes;   /* Set if trailing zeroes should be shown. */
    int started;       /* Set just before window is displayed. */
    int toclear;       /* Indicates if display should be cleared. */
};

typedef struct calcVars *Vars;


/* MP definitions. */

#define C_abs(x)    ((x) >= 0 ? (x) : -(x))
#define dabs(x)     (double) C_abs(x)
#define min(a, b)   ((a) <= (b) ? (a) : (b))
#define max(a, b)   ((a) >= (b) ? (a) : (b))
#define dmax(a, b)  (double) max(a, b)
#define dmin(a, b)  (double) min(a, b)

struct button *button_for_fc(char);
struct button *button_for_value(int);
struct button *copy_button_info(struct button *);

void syntaxdep_show_display();
char *button_str(int);
char *convert(char *);
char *gc_strdup(char *str);
const char *get_radix();
char *get_resource(enum res_type);
const char *get_tsep();
char *make_number(int *, int, BOOLEAN, BOOLEAN);
char *set_bool(int);

unsigned short *get_but_data();

int button_mods(int);
int button_value(int);
int char_val(char);
int do_rcl_reg(int reg, int value[MP_SIZE]);
int do_sto_reg(int reg, int value[MP_SIZE]);
int do_tfunc(int s[MP_SIZE], int t[MP_SIZE], enum trig_func tfunc);
int get_menu_entry(enum menu_type, int);
int main(int, char **);

void beep();
void build_word_map();
void clear_display(int);
void display_prop_sheet();
void do_base(enum base_type);
void do_business();
void do_calc();
void do_lr_calc();
void do_expression();
void do_calctool(int, char **);
void do_clear();
void do_clear_entry();
void do_delete();
void do_numtype(enum num_type);
void do_expno();
void do_immed();
void do_memory();
void do_mode();
void do_none();
void do_number();
void do_paren();
void do_pending();
void do_point();
void do_portion();
void do_trig();
void do_trigtype(enum trig_type);
void doerr(char *);
void exp_del();
void get_constant(int);
void get_function(int);
void get_options(int, char **);
void grey_buttons(enum base_type);
void handle_menu_selection(struct button *, int);
void initialise();
void init_args();
void init_frame_sizes();
void init_vars();
void init_Xvars(int *, char **);
void key_init();
void localize_number(char *, const char *);
void load_resources();
void make_frames();
void make_menus();
void make_reg(int, char *);
void make_registers();
void mperr();
void MPstr_to_num(char *, enum base_type, int *);
void paren_disp(char);
void process_item(struct button *);
void process_str(char *);
void push_num(int *);
void push_op(int);
void put_resource(enum res_type, char *);
void read_cfdefs();
void read_resources();
void read_str(char **, char *);
void refresh_display();
void save_pending_values(struct button *);
void save_resources();
void set_accuracy_menu_item(int);
void set_accuracy_tooltip(int);
void set_display(char *, int);
void write_display(char *);
void set_error_state(int);
void set_hyp_item(int);
void set_ins_key();
void set_inv_item(int);
void set_mode(enum mode_type);
void set_title(enum fcp_type, char *);
void show_display(int *);
void show_error(char *);
void srand48();
void start_tool();
void str_replace(char **, char *, char *);
void switch_hands(int);
void update_statusbar(gchar *, const gchar *);
void usage(char *);
void win_display(enum fcp_type, int);

/* Global Brent MP routines in mp.c. */
int mpeq(int *, int *);
int mpge(int *, int *);
int mpgt(int *, int *);
int mple(int *, int *);
int mplt(int *, int *);

void mpabs(int *, int *);
void mpadd(int *, int *, int *);
void mpaddi(int *, int *, int *);
void mpasin(int *, int *);
void mpatan(int *, int *);
void mpcdm(double *, int *);
void mpcim(int *, int *);
void mpcmd(int *, double *);
void mpcmf(int *, int *);
void mpcmi(int *, int *);
void mpcmim(int *, int *);
void mpcos(int *, int *);
void mpcosh(int *, int *);
void mpdiv(int *, int *, int *);
void mpdivi(int *, int *, int *);
void mpexp(int *, int *);
void mpln(int *, int *);
void mpmul(int *, int *, int *);
void mpmuli(int *, int *, int *);
void mpneg(int *, int *);
void mppi(int *);
void mppwr(int *, int *, int *);
void mppwr2(int *, int *, int *);
void mpset(int *, int *, int *);
void mpsin(int *, int *);
void mpsinh(int *, int *);
void mpsqrt(int *, int *);
void mpstr(int *, int *);
void mpsub(int *, int *, int *);
void mptanh(int *, int *);

#endif /*CALCTOOL_H*/
