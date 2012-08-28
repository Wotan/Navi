#ifndef _TEMPLATEMACRO_H_
# define _TEMPLATEMACRO_H_

#undef NAVI_COMMA
#define NAVI_COMMA ,

# define NAVI_TPL_FUN_CALL0
# define NAVI_TPL_FUN_CALL1 a1
# define NAVI_TPL_FUN_CALL2 a1, a2
# define NAVI_TPL_FUN_CALL3 a1, a2, a3
# define NAVI_TPL_FUN_CALL4 a1, a2, a3, a4
# define NAVI_TPL_FUN_CALL5 a1, a2, a3, a4, a5
# define NAVI_TPL_FUN_CALL(n) NAVI_TPL_FUN_CALL##n

# define NAVI_TPL_DEF0
# define NAVI_TPL_DEF1 class A1
# define NAVI_TPL_DEF2 class A1, class A2
# define NAVI_TPL_DEF3 class A1, class A2, class A3
# define NAVI_TPL_DEF4 class A1, class A2, class A3, class A4
# define NAVI_TPL_DEF5 class A1, class A2, class A3, class A4, class A5
# define NAVI_TPL_DEF(n) NAVI_TPL_DEF##n

# define NAVI_TPL_FUN_DEF0
# define NAVI_TPL_FUN_DEF1 A1 a1
# define NAVI_TPL_FUN_DEF2 A1 a1, A2 a2
# define NAVI_TPL_FUN_DEF3 A1 a1, A2 a2, A3 a3
# define NAVI_TPL_FUN_DEF4 A1 a1, A2 a2, A3 a3, A4 a4
# define NAVI_TPL_FUN_DEF5 A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
# define NAVI_TPL_FUN_DEF(n) NAVI_TPL_FUN_DEF##n

# define NAVI_TPL_TYPE_DEF0
# define NAVI_TPL_TYPE_DEF1 A1
# define NAVI_TPL_TYPE_DEF2 A1, A2
# define NAVI_TPL_TYPE_DEF3 A1, A2, A3
# define NAVI_TPL_TYPE_DEF4 A1, A2, A3, A4
# define NAVI_TPL_TYPE_DEF5 A1, A2, A3, A4, A5
# define NAVI_TPL_TYPE_DEF(n)  NAVI_TPL_TYPE_DEF##n

#endif /* !_TEMPLATEMACRO_H_ */
