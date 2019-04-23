/* termios type and macro definitions.  Linux version.
2	   Copyright (C) 1993-2017 Free Software Foundation, Inc.
3	   This file is part of the GNU C Library.
4
5	   The GNU C Library is free software; you can redistribute it and/or
6	   modify it under the terms of the GNU Lesser General Public
7	   License as published by the Free Software Foundation; either
8	   version 2.1 of the License, or (at your option) any later version.
9
10	   The GNU C Library is distributed in the hope that it will be useful,
11	   but WITHOUT ANY WARRANTY; without even the implied warranty of
12	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
13	   Lesser General Public License for more details.
14
15	   You should have received a copy of the GNU Lesser General Public
16	   License along with the GNU C Library; if not, see
17	   <http://www.gnu.org/licenses/>.  */
18
19	#ifndef _TERMIOS_H
20	# error "Never include <bits/termios.h> directly; use <termios.h> instead."
21	#endif
22
23	typedef unsigned char        cc_t;
24	typedef unsigned int        speed_t;
25	typedef unsigned int        tcflag_t;
26
27	#define NCCS 32
28	struct termios
29	  {
30	    tcflag_t c_iflag;                /* input mode flags */
31	    tcflag_t c_oflag;                /* output mode flags */
32	    tcflag_t c_cflag;                /* control mode flags */
33	    tcflag_t c_lflag;                /* local mode flags */
34	    cc_t c_line;                        /* line discipline */
35	    cc_t c_cc[NCCS];                /* control characters */
36	    speed_t c_ispeed;                /* input speed */
37	    speed_t c_ospeed;                /* output speed */
38	#define _HAVE_STRUCT_TERMIOS_C_ISPEED 1
39	#define _HAVE_STRUCT_TERMIOS_C_OSPEED 1
40	  };
41
42	/* c_cc characters */
43	#define VINTR 0
44	#define VQUIT 1
45	#define VERASE 2
46	#define VKILL 3
47	#define VEOF 4
48	#define VTIME 5
49	#define VMIN 6
50	#define VSWTC 7
51	#define VSTART 8
52	#define VSTOP 9
53	#define VSUSP 10
54	#define VEOL 11
55	#define VREPRINT 12
56	#define VDISCARD 13
57	#define VWERASE 14
58	#define VLNEXT 15
59	#define VEOL2 16
60
61	/* c_iflag bits */
62	#define IGNBRK        0000001
63	#define BRKINT        0000002
64	#define IGNPAR        0000004
65	#define PARMRK        0000010
66	#define INPCK        0000020
67	#define ISTRIP        0000040
68	#define INLCR        0000100
69	#define IGNCR        0000200
70	#define ICRNL        0000400
71	#define IUCLC        0001000
72	#define IXON        0002000
73	#define IXANY        0004000
74	#define IXOFF        0010000
75	#define IMAXBEL        0020000
76	#define IUTF8        0040000
77
78	/* c_oflag bits */
79	#define OPOST        0000001
80	#define OLCUC        0000002
81	#define ONLCR        0000004
82	#define OCRNL        0000010
83	#define ONOCR        0000020
84	#define ONLRET        0000040
85	#define OFILL        0000100
86	#define OFDEL        0000200
87	#if defined __USE_MISC || defined __USE_XOPEN
88	# define NLDLY        0000400
89	# define   NL0        0000000
90	# define   NL1        0000400
91	# define CRDLY        0003000
92	# define   CR0        0000000
93	# define   CR1        0001000
94	# define   CR2        0002000
95	# define   CR3        0003000
96	# define TABDLY        0014000
97	# define   TAB0        0000000
98	# define   TAB1        0004000
99	# define   TAB2        0010000
100	# define   TAB3        0014000
101	# define BSDLY        0020000
102	# define   BS0        0000000
103	# define   BS1        0020000
104	# define FFDLY        0100000
105	# define   FF0        0000000
106	# define   FF1        0100000
107	#endif
108
109	#define VTDLY        0040000
110	#define   VT0        0000000
111	#define   VT1        0040000
112
113	#ifdef __USE_MISC
114	# define XTABS        0014000
115	#endif
116
117	/* c_cflag bit meaning */
118	#ifdef __USE_MISC
119	# define CBAUD        0010017
120	#endif
121	#define  B0        0000000                /* hang up */
122	#define  B50        0000001
123	#define  B75        0000002
124	#define  B110        0000003
125	#define  B134        0000004
126	#define  B150        0000005
127	#define  B200        0000006
128	#define  B300        0000007
129	#define  B600        0000010
130	#define  B1200        0000011
131	#define  B1800        0000012
132	#define  B2400        0000013
133	#define  B4800        0000014
134	#define  B9600        0000015
135	#define  B19200        0000016
136	#define  B38400        0000017
137	#ifdef __USE_MISC
138	# define EXTA B19200
139	# define EXTB B38400
140	#endif
141	#define CSIZE        0000060
142	#define   CS5        0000000
143	#define   CS6        0000020
144	#define   CS7        0000040
145	#define   CS8        0000060
146	#define CSTOPB        0000100
147	#define CREAD        0000200
148	#define PARENB        0000400
149	#define PARODD        0001000
150	#define HUPCL        0002000
151	#define CLOCAL        0004000
152	#ifdef __USE_MISC
153	# define CBAUDEX 0010000
154	#endif
155	#define  B57600   0010001
156	#define  B115200  0010002
157	#define  B230400  0010003
158	#define  B460800  0010004
159	#define  B500000  0010005
160	#define  B576000  0010006
161	#define  B921600  0010007
162	#define  B1000000 0010010
163	#define  B1152000 0010011
164	#define  B1500000 0010012
165	#define  B2000000 0010013
166	#define  B2500000 0010014
167	#define  B3000000 0010015
168	#define  B3500000 0010016
169	#define  B4000000 0010017
170	#define __MAX_BAUD B4000000
171	#ifdef __USE_MISC
172	# define CIBAUD          002003600000                /* input baud rate (not used) */
173	# define CMSPAR   010000000000                /* mark or space (stick) parity */
174	# define CRTSCTS  020000000000                /* flow control */
175	#endif
176
177	/* c_lflag bits */
178	#define ISIG        0000001
179	#define ICANON        0000002
180	#if defined __USE_MISC || (defined __USE_XOPEN && !defined __USE_XOPEN2K)
181	# define XCASE        0000004
182	#endif
183	#define ECHO        0000010
184	#define ECHOE        0000020
185	#define ECHOK        0000040
186	#define ECHONL        0000100
187	#define NOFLSH        0000200
188	#define TOSTOP        0000400
189	#ifdef __USE_MISC
190	# define ECHOCTL 0001000
191	# define ECHOPRT 0002000
192	# define ECHOKE         0004000
193	# define FLUSHO         0010000
194	# define PENDIN         0040000
195	#endif
196	#define IEXTEN        0100000
197	#ifdef __USE_MISC
198	# define EXTPROC 0200000
199	#endif
200
201	/* tcflow() and TCXONC use these */
202	#define        TCOOFF                0
203	#define        TCOON                1
204	#define        TCIOFF                2
205	#define        TCION                3
206
207	/* tcflush() and TCFLSH use these */
208	#define        TCIFLUSH        0
209	#define        TCOFLUSH        1
210	#define        TCIOFLUSH        2
211
212	/* tcsetattr uses these */
213	#define        TCSANOW                0
214	#define        TCSADRAIN        1
215	#define        TCSAFLUSH        2
216
217
218	#define _IOT_termios /* Hurd ioctl type field.  */ \
219	  _IOT (_IOTS (cflag_t), 4, _IOTS (cc_t), NCCS, _IOTS (speed_t), 2)
