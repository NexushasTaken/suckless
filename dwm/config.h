/* See LICENSE file for copyright and license details. */
#define BG_DARK "#16161e"
#define BG "#1a1b26"
#define BG_HIGHLIGHT "#292E42"
#define TERMINAL_BLACK "#414868"
#define FG "#C0CAF5"
#define FG_DARK "#A9B1D6"
#define FG_GUTTER "#3B4261"
#define DARK3 "#545C7E"
#define COMMENT "#565F89"
#define DARK5 "#737AA2"
#define BLUE0 "#3D59A1"
#define BLUE "#7AA2F7"
#define CYAN "#7DCFFF"
#define BLUE1 "#2AC3DE"
#define BLUE2 "#0DB9D7"
#define BLUE5 "#89DDFF"
#define BLUE6 "#B4F9F8"
#define BLUE7 "#394B70"
#define MAGENTA "#BB9AF7"
#define MAGENTA2 "#FF007C"
#define PURPLE "#9D7CD8"
#define ORANGE "#FF9E64"
#define YELLOW "#E0AF68"
#define GREEN "#9ECE6A"
#define GREEN1 "#73DACA"
#define GREEN2 "#41A6B5"
#define TEAL "#1ABC9C"
#define RED "#F7768E"
#define RED1 "#DB4B4B"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const int showbar   = 1;        /* 0 means no bar */
static const int topbar    = 1;        /* 0 means bottom bar */
static const char *fonts[] = { "Hack Nerd Font:size=11" };

static const char *colors[][3]      = {
	/*               fg       bg             border   */
	[SchemeNorm] = { FG,      BG,            BG_DARK },
	[SchemeSel]  = { FG_DARK, BG_HIGHLIGHT,  BG_DARK  },
};

// tagging                    Arch      Terminal  Chrome    Music     Game      Cog
//                            1         2         3         4         5         6         
static const char *tags[] = {"\uf303", "\uf120", "\uf268", "\uf001", "\uf11b", "\uf085"/*, "7", "8", "9" */};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance    title         tags mask          isfloating   monitor */
	{ "osu!",               NULL,       NULL,         1 << 4,            1,           -1 },
	{ "Google-chrome",      NULL,       NULL,         1 << 2,            1,           -1 },
	{ "Rhythmbox",          NULL,       NULL,         1 << 2,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\uebc8",      tile },    /* first entry is default */
	{ "\ueb78",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = {
  "dmenu_run",
  "-fn", "Hack Nerd Font:size=11",
  "-nb", BG,
  "-nf", FG,
  "-sb", BG_HIGHLIGHT,
  "-sf", FG_DARK,
  NULL
};
static const char *termcmd[]     = { "alacritty", NULL };
static const char *rofi_run[]    = { "rofi", "-show", "run", NULL };
static const char *rofi_window[] = { "rofi", "-show", "window", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ Mod1Mask|ShiftMask,           XK_t,      spawn,          {.v = termcmd } },
	{ Mod1Mask|ShiftMask,           XK_q,      spawn,          {.v = rofi_run } },
	{ Mod1Mask|ShiftMask,           XK_w,      spawn,          {.v = rofi_window } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.01} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.01} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	//TAGKEYS(                        XK_7,                      6)
	//TAGKEYS(                        XK_8,                      7)
	//TAGKEYS(                        XK_9,                      8)
  { MODKEY,                       XK_h,      shiftview,      {.i = -1}},
  { MODKEY,                       XK_l,      shiftview,      {.i =  1}},
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
