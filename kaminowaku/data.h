// Copyright 2025 Jamison A. Drapeau
#ifndef __DATA__H
#define __DATA__H

// Define standard data widths
#define       OUT_BLOCK  65536
#define       MAX_BLOCK   4096
#define    SUPSUP_BLOCK    128
#define     SUPER_BLOCK     64
#define    DOUBLE_BLOCK     32
#define           BLOCK     16

// Define Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//  printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
//  printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
//  printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
//  printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
//  printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
//  printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");

// Define persistent program data
typedef struct {
        // Prompt String
        unsigned char           prompt[DOUBLE_BLOCK];
        // Depth Tracking
        int                     f_type;
        // Buffers
        unsigned char           cmd_input[SUPER_BLOCK];
        unsigned char           cmd_output[OUT_BLOCK];
        unsigned char           cmd_carry[SUPER_BLOCK];
        unsigned char *         cmd_token;
        
        // @@ Your Variables
        int                     demo_banner_change;
        
} _carry_forward;
#endif
