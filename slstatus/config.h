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

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
#define SEP { separator, "^b" BG "^^c" FG "^ \ue0b3 ", NULL},
#define RESET "^c" FG "^"
static const struct arg args[] = {
	/* function     format         argument */
  // Name
  { separator,    "^b" BG_HIGHLIGHT "^ ^b" BG_HIGHLIGHT "^^c" BG "^\ue0b2", NULL},           
  { separator,    "^b" BG "^^c#ffffff^ Nexus",                              NULL},           
  SEP
  { disk_used,    "^c#808080^\uf0a0 " RESET "%s/",                          "/"},            
  { disk_total,   "%s GB",                                                  "/"},            
  SEP
  // CPU percent
  { cpu_perc,     "^c#808080^\ufb19 " RESET "%3s%%",                        NULL},           
  // CPU MHz
  { cpu_freq,     " %s MHz",                                                NULL},           
  SEP
  { ram_used,     "^c#ffffff^RAM " RESET "%s/",                             NULL},           
  { ram_total,    "%s GB",                                                  NULL},           
  SEP
  { netspeed_rx,  "%5s ^c#00ff00^\uf103 ",                                  "eno1"},         
  { netspeed_tx,  RESET "%5s ^c#9D7CD8^\uf102",                             "eno1"},         
  SEP
  // Date
	{ datetime,     "^c#ffffff^\uf073 " RESET "%s",                           "%a %b %d" },    
  SEP
  // Time
	{ datetime,     "^c#ffff00^\uf017 " RESET "%s ",                           "%I:%M:%S %p" }, 
};
