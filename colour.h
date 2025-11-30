#ifndef COLOUR_H
#define COLOUR_H

//for beauty purposes i included this file form chatgpt//
//if it violates the rule i will remove it in final submission//


//      RESET.    //
#define RESET       "\033[0m"
#define RESET_ALL   "\033[0m"

//      TEXT STYLES
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"
#define HIDDEN      "\033[8m"

// ===============================
//      STANDARD TEXT COLORS
// ===============================
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// ===============================
//      BRIGHT TEXT COLORS
// ===============================
#define BRIGHT_BLACK    "\033[90m"
#define BRIGHT_RED      "\033[91m"
#define BRIGHT_GREEN    "\033[92m"
#define BRIGHT_YELLOW   "\033[93m"
#define BRIGHT_BLUE     "\033[94m"
#define BRIGHT_MAGENTA  "\033[95m"
#define BRIGHT_CYAN     "\033[96m"
#define BRIGHT_WHITE    "\033[97m"

// ===============================
//      BACKGROUND COLORS
// ===============================
#define BG_BLACK        "\033[40m"
#define BG_RED          "\033[41m"
#define BG_GREEN        "\033[42m"
#define BG_YELLOW       "\033[43m"
#define BG_BLUE         "\033[44m"
#define BG_MAGENTA      "\033[45m"
#define BG_CYAN         "\033[46m"
#define BG_WHITE        "\033[47m"

// ===============================
//      BRIGHT BACKGROUNDS
// ===============================
#define BG_BRIGHT_BLACK    "\033[100m"
#define BG_BRIGHT_RED      "\033[101m"
#define BG_BRIGHT_GREEN    "\033[102m"
#define BG_BRIGHT_YELLOW   "\033[103m"
#define BG_BRIGHT_BLUE     "\033[104m"
#define BG_BRIGHT_MAGENTA  "\033[105m"
#define BG_BRIGHT_CYAN     "\033[106m"
#define BG_BRIGHT_WHITE    "\033[107m"

// ===============================
//      256 COLOR MODE
// ===============================
// Foreground:  \033[38;5;<number>m
// Background:  \033[48;5;<number>m
//
// Use like:
//     printf(ANSI256_FG(196) "Red" RESET);
//
#define ANSI256_FG(code)  "\033[38;5;" #code "m"
#define ANSI256_BG(code)  "\033[48;5;" #code "m"

// ===============================
//      TRUE COLOR (RGB)
// ===============================
// Foreground: \033[38;2;R;G;Bm
// Background: \033[48;2;R;G;Bm
//
// Use like:
// printf(RGB_FG(255,100,0) "Orange" RESET);
//
#define RGB_FG(r,g,b)     "\033[38;2;" #r ";" #g ";" #b "m"
#define RGB_BG(r,g,b)     "\033[48;2;" #r ";" #g ";" #b "m"

#define REDBOLD  "\033[1;31m"
#define BLUEBOLD  "\033[1;34m"
#define CYANBOLD  "\033[1;36m"
#define GREYBG   "\033[47m"
#define DARKBG  "\033[100m"
#define RESET    "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

#endif // COLORS_H