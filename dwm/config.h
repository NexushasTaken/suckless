/* See LICENSE file for copyright and license details. */
/* Colors */
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
#ifdef SYSTRAY
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0; 	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
#endif
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char defaultFont[]     = "Hack Nerd Font:size=10";
static const char *fonts[]          = { defaultFont };
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { FG,      BG,            BG_DARK },
	[SchemeSel]  = { FG_DARK, BG_HIGHLIGHT,  BG_DARK  },
};

/* tagging */
static const char *tags[] = {
  "\uf303", /* Archlinux */
  "\uf120", /* Terminal */
};

#ifdef RAINBOW_TAG
static const char *tagcolors[] = { "#00ffff", "#ffffff" };
static const char tagsel[] = BG_HIGHLIGHT;
static const char tagnorm[] = BG;
#endif

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class  instance  title  tags-mask  isfloating  monitor */
	{ NULL,   NULL,     NULL,  1,         1,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\ueb78",   NULL    },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  /* Switch tag */ \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  /* See all in windows tag KEY to current tag */\
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  /* Move current focused window to tag KEY */\
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  /* Toggle visibity of focused window on other tag KEY */\
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
  "dmenu_run",
  "-m", dmenumon,
  "-fn", defaultFont,
  "-nb", BG,
  "-nf", FG,
  "-sb", BG_HIGHLIGHT,
  "-sf", FG_DARK,
  NULL
};

// Screenshot
static const char *shotcmd[] = { "scrot", "-q", "100", NULL };
static const char *shotareacmd[] = { "scrot", "-q", "100", "-s", NULL };
static const char *termcmd[]     = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ Mod1Mask|ShiftMask,           XK_t,      spawn,          {.v = termcmd } },
	{ 0,                            XK_Print,  spawn,          {.v = shotcmd } },
	{ ShiftMask,                    XK_Print,  spawn,          {.v = shotareacmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  // Kill focused window
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
  // Set layout to floating
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[0]} },
  // Set layout to Monocle
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
  // See all Windows including the other tags window to current tag
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  // Set the current Window to all tags
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
  { MODKEY,                       XK_h,      shiftview,      {.i = -1}},
  { MODKEY,                       XK_l,      shiftview,      {.i =  1}},
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

  // Monitor keybinds
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	#ifdef SYSTRAY
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	#endif
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
