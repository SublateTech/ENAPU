
/*
    KBD.HPP
    Created 1995 by Dejvid Zaninovic
*/

#ifndef KBD_HPP
#define KBD_HPP

#define K_SPACE         32          // normal keys
#define K_ESC           27
#define K_TAB           9
#define K_BKSP          8
#define K_ENTER         13
#define K_SEMICOLON     59
#define K_SQUOTE        39
#define K_DQUOTE        34
#define K_F1            (59 + 256)  // extended keys
#define K_F2            (60 + 256)
#define K_F3            (61 + 256)
#define K_F4            (62 + 256)
#define K_F5            (63 + 256)
#define K_F6            (64 + 256)
#define K_F7            (65 + 256)
#define K_F8            (66 + 256)
#define K_F9            (67 + 256)
#define K_F10           (68 + 256)
#define K_F11           (133 + 256)
#define K_F12           (134 + 256)
#define K_SH_F1         (84 + 256)
#define K_SH_F2         (85 + 256)
#define K_SH_F3         (86 + 256)
#define K_SH_F4         (87 + 256)
#define K_SH_F5         (88 + 256)
#define K_SH_F6         (89 + 256)
#define K_SH_F7         (90 + 256)
#define K_SH_F8         (91 + 256)
#define K_SH_F9         (92 + 256)
#define K_SH_F10        (93 + 256)
#define K_SH_F11        (135 + 256)
#define K_SH_F12        (136 + 256)
#define K_CTRL_F1       (94 + 256)
#define K_CTRL_F2       (95 + 256)
#define K_CTRL_F3       (96 + 256)
#define K_CTRL_F4       (97 + 256)
#define K_CTRL_F5       (98 + 256)
#define K_CTRL_F6       (99 + 256)
#define K_CTRL_F7       (100 + 256)
#define K_CTRL_F8       (101 + 256)
#define K_CTRL_F9       (102 + 256)
#define K_CTRL_F10      (103 + 256)
#define K_CTRL_F11      (137 + 256)
#define K_CTRL_F12      (138 + 256)
#define K_ALT_F1        (104 + 256)
#define K_ALT_F2        (105 + 256)
#define K_ALT_F3        (106 + 256)
#define K_ALT_F4        (107 + 256)
#define K_ALT_F5        (108 + 256)
#define K_ALT_F6        (109 + 256)
#define K_ALT_F7        (110 + 256)
#define K_ALT_F8        (111 + 256)
#define K_ALT_F9        (112 + 256)
#define K_ALT_F10       (113 + 256)
#define K_ALT_F11       (139 + 256)
#define K_ALT_F12       (140 + 256)
#define K_ALT_A         (30 + 256)
#define K_ALT_B         (48 + 256)
#define K_ALT_C         (46 + 256)
#define K_ALT_D         (32 + 256)
#define K_ALT_E         (18 + 256)
#define K_ALT_F         (33 + 256)
#define K_ALT_G         (34 + 256)
#define K_ALT_H         (35 + 256)
#define K_ALT_I         (23 + 256)
#define K_ALT_J         (36 + 256)
#define K_ALT_K         (37 + 256)
#define K_ALT_L         (38 + 256)
#define K_ALT_M         (50 + 256)
#define K_ALT_N         (49 + 256)
#define K_ALT_O         (24 + 256)
#define K_ALT_P         (25 + 256)
#define K_ALT_Q         (16 + 256)
#define K_ALT_R         (19 + 256)
#define K_ALT_S         (31 + 256)
#define K_ALT_T         (20 + 256)
#define K_ALT_U         (22 + 256)
#define K_ALT_V         (47 + 256)
#define K_ALT_W         (17 + 256)
#define K_ALT_X         (45 + 256)
#define K_ALT_Y         (21 + 256)
#define K_ALT_Z         (44 + 256)
#define K_ALT_0         (129 + 256)
#define K_ALT_1         (120 + 256)
#define K_ALT_2         (121 + 256)
#define K_ALT_3         (122 + 256)
#define K_ALT_4         (123 + 256)
#define K_ALT_5         (124 + 256)
#define K_ALT_6         (125 + 256)
#define K_ALT_7         (126 + 256)
#define K_ALT_8         (127 + 256)
#define K_ALT_9         (128 + 256)
#define K_ALT_MINUS     (130 + 256)
#define K_ALT_EQUAL     (131 + 256)
#define K_SH_TAB        (15 + 256)
#define K_INS           (82 + 256)
#define K_DEL           (83 + 256)
#define K_PRTSC         (114 + 256)
#define K_END           (79 + 256)
#define K_HOME          (71 + 256)
#define K_PGDN          (81 + 256)
#define K_PGUP          (73 + 256)
#define K_DOWN          (80 + 256)
#define K_LEFT          (75 + 256)
#define K_RIGHT         (77 + 256)
#define K_UP            (72 + 256)
#define K_ALT_BKSP      (14 + 256)
#define K_ALT_ENTER     (28 + 256)
#define K_ALT_ESC       (1 + 256)
#define K_ALT_TAB       (165 + 256)
#define K_CTRL_TAB      (148 + 256)
#define K_CTRL_END      (117 + 256)
#define K_CTRL_HOME     (119 + 256)
#define K_CTRL_UP       (146 + 256)
#define K_CTRL_LEFT     (116 + 256)
#define K_CTRL_RIGTH    (115 + 256)
#define K_SH_UP         (145 + 256)
#define K_ALT_UP        (152 + 256)
#define K_ALT_DOWN      (160 + 256)
#define K_ALT_LEFT      (155 + 256)
#define K_ALT_RIGTH     (157 + 256)
#define K_ALT_DELETE    (163 + 256)
#define K_ALT_END       (159 + 256)
#define K_ALT_HOME      (151 + 256)
#define K_ALT_INSERT    (162 + 256)
#define K_ALT_PGUP      (153 + 256)
#define K_ALT_PGDN      (161 + 256)
#define K_ALT_RBRACKET  (26 + 256)
#define K_ALT_LBRACKET  (27 + 256)
#define K_ALT_SEMICOLON (39 + 256)
#define K_ALT_SQUOTE    (40 + 256)
#define K_ALT_BQUOTE    (41 + 256)
#define K_ALT_BSLASH    (43 + 256)
#define K_ALT_COMMA     (51 + 256)
#define K_ALT_PERIOD    (52 + 256)
#define K_ALT_SLASH     (53 + 256)
#define K_ALT_KSLASH    (164 + 256)
#define K_ALT_KSTAR     (55 + 256)
#define K_ALT_KMINUS    (78 + 256)
#define K_ALT_KENTER    (166 + 256)
#define K_CTRL_KSLASH   (149 + 256)
#define K_CTRL_KSTAR    (150 + 256)
#define K_CTRL_KMINUS   (142 + 256)
#define K_CTRL_KPLUS    (144 + 256)

struct sk_stat {				// keyboard status word at 0:417
	unsigned lctrl:1;
	unsigned lalt:1;
	unsigned sysreq:1;
	unsigned pause:1;
	unsigned slock:1;
	unsigned nlock:1;
	unsigned clock:1;
	unsigned insert:1;
	unsigned rshift:1;
	unsigned lshift:1;
	unsigned ctrl:1;
	unsigned alt:1;
};

void kbflush();        					// flush keyboard buffer
int getchf (char list[]);				// get char in list
int getpassf (char buf[], int len);		// get password in buff
int getkey();							// get key
int ungetkey (int key);					// unget key
void kbset (int rate, int delay);

//extern sk_stat far *kbstat;

#endif

