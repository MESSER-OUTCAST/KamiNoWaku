// Copyright (c) 2025, Jamison A. Drapeau
#include "kaminowaku.h"
#include "cmd_scan.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

/*
        DESCRIPTION

                This function is the main prompt and banner generator for the program.
                It will be called during both input and output regarding user commands.
*/
int kaminowaku (_carry_forward * _prog_data) {
        // C99 for loop error bypass ints
        int c;
        int i;

        // Globalize the seperator variable
        const char SEPERATOR[SUPSUP_BLOCK] = "---------------------------------------------------------------------------\0";

        // Resanatize input, refer to data.h for standards
        memset(_prog_data->cmd_input, 0x00, SUPER_BLOCK);

        // Catch first instance here, i.e. f_type = 0
        if (_prog_data->f_type == 0) {
                printf("< Initialization complete.\n");
                // Now that the initial banner is printed, set the f_type to one for use.
                _prog_data->f_type = 1;
        }

        // @@ CONTEXT CATCHING IF STATEMENT, Know that it exists and move on.
        // When a non-standard f_type is defined (i.e. ftype > 1) call the corresponding output of cmd_scan
        if (_prog_data->f_type > 1) {
                cmd_scan(_prog_data);
        }

        // Gather user input
        if (_prog_data->f_type == 1) {
                
                // Print banner, let the computer think if nescessary
                printf("\033\143");
                printf(ANSI_COLOR_MAGENTA "[" ANSI_COLOR_RESET);
                printf("KAMI NO WAKU ");
                printf(ANSI_COLOR_CYAN    "0.0.1"    ANSI_COLOR_RESET);
                printf(ANSI_COLOR_MAGENTA "]" ANSI_COLOR_RESET);
                printf(" Use 'help' if you're stuck.\n");
                printf("%s\n", SEPERATOR);
                //---------------------------------------------------------------------------[BANNER START]
                
                // @@ Here is the demo banner that changes color based on the context of the demo code
                if (_prog_data->demo_banner_change == 0) {
                        printf(ANSI_COLOR_RED     "+------------------------------+"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⠄⣾⣿⡇⢸⣿⣿⣿⠄⠈⣿⣿⣿⣿⠈⣿⡇⢹⣿⣿⣿⡇⡇⢸⣿⣿⡇⣿⣿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⢠⣿⣿⡇⢸⣿⣿⣿⡇⠄⢹⣿⣿⣿⡀⣿⣧⢸⣿⣿⣿⠁⡇⢸⣿⣿⠁⣿⣿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⢸⣿⣿⡇⠸⣿⣿⣿⣿⡄⠈⢿⣿⣿⡇⢸⣿⡀⣿⣿⡿⠸⡇⣸⣿⣿⠄⣿⣿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⢸⣿⡿⠷⠄⠿⠿⠿⠟⠓⠰⠘⠿⣿⣿⡈⣿⡇⢹⡟⠰⠦⠁⠈⠉⠋⠄⠻⢿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⢨⡑⠶⡏⠛⠐⠋⠓⠲⠶⣭⣤⣴⣦⣭⣥⣮⣾⣬⣴⡮⠝⠒⠂⠂⠘⠉⠿⠖⣬"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⠈⠉⠄⡀⠄⣀⣀⣀⣀⠈⢛⣿⣿⣿⣿⣿⣿⣿⣿⣟⠁⣀⣤⣤⣠⡀⠄⡀⠈⠁"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⠄⠠⣾⡀⣾⣿⣧⣼⣿⡿⢠⣿⣿⣿⣿⣿⣿⣿⣿⣧⣼⣿⣧⣼⣿⣿⢀⣿⡇⠄"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⡀⠄⠻⣷⡘⢿⣿⣿⡿⢣⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣜⢿⣿⣿⡿⢃⣾⠟⢁⠈"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "⢃⢻⣶⣬⣿⣶⣬⣥⣶⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣷⣶⣶⣾⣿⣷⣾⣾⢣"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_RED     "+------------------------------+"ANSI_COLOR_RESET "\n");
                } else if (_prog_data->demo_banner_change == 1) {
                        printf(ANSI_COLOR_CYAN    "+------------------------------+"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⠄⣾⣿⡇⢸⣿⣿⣿⠄⠈⣿⣿⣿⣿⠈⣿⡇⢹⣿⣿⣿⡇⡇⢸⣿⣿⡇⣿⣿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⢠⣿⣿⡇⢸⣿⣿⣿⡇⠄⢹⣿⣿⣿⡀⣿⣧⢸⣿⣿⣿⠁⡇⢸⣿⣿⠁⣿⣿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⢸⣿⣿⡇⠸⣿⣿⣿⣿⡄⠈⢿⣿⣿⡇⢸⣿⡀⣿⣿⡿⠸⡇⣸⣿⣿⠄⣿⣿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⢸⣿⡿⠷⠄⠿⠿⠿⠟⠓⠰⠘⠿⣿⣿⡈⣿⡇⢹⡟⠰⠦⠁⠈⠉⠋⠄⠻⢿⣿"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⢨⡑⠶⡏⠛⠐⠋⠓⠲⠶⣭⣤⣴⣦⣭⣥⣮⣾⣬⣴⡮⠝⠒⠂⠂⠘⠉⠿⠖⣬"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⠈⠉⠄⡀⠄⣀⣀⣀⣀⠈⢛⣿⣿⣿⣿⣿⣿⣿⣿⣟⠁⣀⣤⣤⣠⡀⠄⡀⠈⠁"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⠄⠠⣾⡀⣾⣿⣧⣼⣿⡿⢠⣿⣿⣿⣿⣿⣿⣿⣿⣧⣼⣿⣧⣼⣿⣿⢀⣿⡇⠄"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⡀⠄⠻⣷⡘⢿⣿⣿⡿⢣⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣜⢿⣿⣿⡿⢃⣾⠟⢁⠈"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET
                        ANSI_COLOR_RED     "⢃⢻⣶⣬⣿⣶⣬⣥⣶⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣷⣶⣶⣾⣿⣷⣾⣾⢣"ANSI_COLOR_RESET
                        ANSI_COLOR_CYAN    "|"ANSI_COLOR_RESET "\n"
                        ANSI_COLOR_CYAN    "+------------------------------+"ANSI_COLOR_RESET "\n");
                }
                printf("%s\n", SEPERATOR);
                //---------------------------------------------------------------------------[BANNER END]

                // This prints the output buffer and errors if there are any
                if (_prog_data->cmd_output[0] != 0x00) {
                        if (errno != 0) {
                                printf("< "); fflush(stdout);
                                perror(NULL); errno = 0;
                        }
                        // @@ This is where you could log to a file if you wanted to.
                        // @@ You could also log in the command scanner at each case.
                        printf("< %s\n", _prog_data->cmd_output);
                        memset(_prog_data->cmd_output, 0x00, OUT_BLOCK);
                }


                // @@ Prompt variations can be specified here if desired. (e.g. "[context]> ")
                printf("%s", _prog_data->prompt);

                // Flush IO
                fflush(stdout);

                // Scan in 64 bytes, FROM ZERO!
                if (fgets(_prog_data->cmd_input, SUPER_BLOCK - 1, stdin) == 0) {return -1;}
                if (_prog_data->cmd_input[61] != 0x00) {while ((getchar()) != 0x0A);}

                // Important debug information for 100% clean input.
                //printf("<! ending char = [%02X]", _prog_data->cmd_input[62]); fflush(stdout); sleep(2);

                // In case of system stall let the user know the machine is thinking, largely for debug only
                printf("< thinking...");
                fflush(stdout);

                // Clear screen only on non-cmd prompt return, e.g. all subroutines have finished at the time.
                printf("\033\143");

                // !! ERROR DETECTION
                //printf("!> [_prog_data->cmd_input] PRE-TRIM: %s\n\n", _prog_data->cmd_input);
                //for (b = 0; b < SUPER_BLOCK; b++) {
                //      if (b % 8 == 0 && b != 0) {
                //              printf("\n");
                //      }
                //      printf("%02X ", _prog_data->cmd_input[b]);
                //} printf(
                //      "\n\n!> INPUT Length PRE-TRIM: %lu\n",sizeof(_prog_data->cmd_input) / sizeof(_prog_data->cmd_input[0])
                //);

                // Scrub Input
                int first_good = 0;
                _prog_data->cmd_input[SUPER_BLOCK] = 0x00;
                if (_prog_data->cmd_input[0] != 0x0A) {
                        for ( i = SUPER_BLOCK - 1; i != 0; --i) {
                                if (
                                        (
                                                (_prog_data->cmd_input[i] < 48)
                                                || // Not a Number
                                                (_prog_data->cmd_input[i] > 57)
                                        ) && (
                                                (_prog_data->cmd_input[i] < 65)
                                                || // Not an uppercase Letter
                                                (_prog_data->cmd_input[i] > 90)
                                        ) && (
                                                (_prog_data->cmd_input[i] < 97)
                                                || // Not a lowercase Letter
                                                (_prog_data->cmd_input[i] > 122)
                                        ) && (  // Not one of these specific ascii characters
                                                (_prog_data->cmd_input[i] != 0x2F) /* / */
                                                &&
                                                (_prog_data->cmd_input[i] != 0x2D) /* - */
                                                &&
                                                (_prog_data->cmd_input[i] != 0x2E) /* . */
                                                &&
                                                (_prog_data->cmd_input[i] != 0x5C) /* \ */
                                                &&
                                                (_prog_data->cmd_input[i] != 0x2A) /* * */
                                                &&
                                                (_prog_data->cmd_input[i] != 0x20) /*   */
                                        )
                                ) {
                                             if (first_good == 0) {_prog_data->cmd_input[i] = 0x00;}
                                        else if (first_good == 1) {_prog_data->cmd_input[i] = 0x20;}
                                } else if (first_good == 0) {first_good = 1;}
                        }
                }
                // FOR above, stops at most recent clean byte

                // !! ERROR DETECTION
                //printf("!> INPUT POST-TRIM: %s\n\n", _prog_data->cmd_input);
                //for (b = 0; b < SUPER_BLOCK; b++) {
                //        if (b % 8 == 0 && b != 0) {
                //                printf("\n");
                //        }
                //        printf("%02X ", _prog_data->cmd_input[b]);
                //} printf(
                //        "\n\n!> INPUT Length POST-TRIM: %lu\n",sizeof(_prog_data->cmd_input) / sizeof(_prog_data->cmd_input[0])
                //);
                //sleep(5);

                // @@ Execute Anti-Duff Device and catch exit
                if (strcmp(_prog_data->cmd_input, "exit") == 0) {
                        printf("\033\143");
                        printf("\n\n< Exit.\n");
                        return 0;
                } else {
                        // CALL HERE FOR INPUTS
                        cmd_scan(_prog_data);
                }
        }
}
