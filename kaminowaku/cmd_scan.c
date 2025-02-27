// Copyright 2025 Jamison A. Drapeau
#include "cmd_scan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <regex.h>

/*
        - READ IN ENTIRETY
        - This is probably the most important code block in the entire program.
        - It takes in command data from the carry forward structure and processes it into arguments.

        I was going to use recurssive calls but they are not needed. Simply follow
        the flow of logic relative to the global data being handled by the entire
        program. In particular, _prog_data->f_type is used to handle extra prints
        done by first printing the banner in prompt and then resetting it in
        this file at the end of each code block.

        So the only reason I don't do something like returns is to keep things a little
        neater. In essence we want to print the banner out before every input and output.
        This flow with the global variable is a LITTLE like goto statements but it works.
        This way we keep the banner printing to a SINGLE function rather than replicating
        the call every time we output. We also have the option to recurse if needed.

        I was initially using an if/else ladder but the switch statement bypasses an entire
        logical check that would be needed in each if/esle, though it does not look quite
        as clean. Working like this allows us to create little "microfunctions" without all
        of the extra compiler overhead as well.

        For help adding your own stuff follow the @@ marked comments with the associated steps.

*/

void cmd_scan (_carry_forward * _prog_data) {
        switch (_prog_data->f_type) {
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                case 1: // Figure out which command it is
                        // Tokenize just the initial command argument, this is not persistent outside of the address
                        memset(_prog_data->cmd_carry, 0x00, SUPER_BLOCK);
                        memcpy(_prog_data->cmd_carry, _prog_data->cmd_input, SUPER_BLOCK - 1);
                        _prog_data->cmd_token = NULL;
                        _prog_data->cmd_token = strtok(_prog_data->cmd_input, " ");

                        //--------------------------------------------------------
                        // Test the initial token to choose follow on path to take
                        //--------------------------------------------------------

                        // @@ STEP_ONE: Trace this to case 2
                        if (strcmp(_prog_data->cmd_token, "help") == 0) {
                                _prog_data->f_type = 2;
                                return;
                        }
                        // @@ Example of a command with no tokens
                        else if (strcmp(_prog_data->cmd_token, "pwd") == 0) {
                                _prog_data->f_type = 3;
                                return;
                        }
                        // @@ Example of a command with tokens
                        else if (strcmp(_prog_data->cmd_token, "cd") == 0) {
                                _prog_data->f_type = 4;
                                return;
                        }
                        // @@ Here is an example of maximizing the framework
                        else if (strcmp(_prog_data->cmd_token, "demo") == 0) {
                                _prog_data->f_type = 5;
                                return;
                        }
                        // @@ STEP_THREE: Add your command to the ladder
                        else {
                                _prog_data->f_type = 30000;
                                return;
                        }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                case 2: // Display command list
                        strcat(_prog_data->cmd_output, "COMMAND LIST:\n");
                        strcat(_prog_data->cmd_output, ANSI_COLOR_MAGENTA "[\t" ANSI_COLOR_RESET "pwd\t\t\t<-- Print current working directory" ANSI_COLOR_MAGENTA "\t]\n" ANSI_COLOR_RESET);
                        strcat(_prog_data->cmd_output, ANSI_COLOR_MAGENTA "[\t" ANSI_COLOR_RESET "cd <args>\t\t<-- Change working directory" ANSI_COLOR_MAGENTA "\t\t]\n" ANSI_COLOR_RESET);
                        strcat(_prog_data->cmd_output, ANSI_COLOR_MAGENTA "[\t" ANSI_COLOR_RESET "demo\t\t\t<-- Run through example code" ANSI_COLOR_MAGENTA "\t\t]\n" ANSI_COLOR_RESET);
                        // @@ STEP_TWO: Add your command in sequence here in whatever format you choose.
                        strcat(_prog_data->cmd_output, ANSI_COLOR_MAGENTA "[\t" ANSI_COLOR_RESET "exit\t\t\t<-- Exit and return to shell" ANSI_COLOR_MAGENTA "\t\t]" ANSI_COLOR_RESET);
                        _prog_data->f_type = 1;
                        return;
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                case 3: // @@ EXAMPLE: Print the current working directory
                        getcwd(_prog_data->cmd_output, MAX_BLOCK);
                        _prog_data->f_type = 1;
                        return;
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                case 4: // @@ EXAMPLE: Change the current working directory of the program
                        // Get next command token
                        _prog_data->cmd_token = strtok(_prog_data->cmd_carry, " ");
                        _prog_data->cmd_token = strtok(NULL, " ");
                        // Try to navigate in the new directory
                        if (chdir(_prog_data->cmd_token) != 0) {
                                strcat(_prog_data->cmd_output, "Token was: ");
                                strcat(_prog_data->cmd_output, _prog_data->cmd_token);
                                _prog_data->f_type = 1;
                                return;
                        }
                        // Buffer the new directory into a full path
                        char new_directory[SUPER_BLOCK];
                        getcwd(new_directory, SUPER_BLOCK);
                        strcat(_prog_data->cmd_output, new_directory);
                        _prog_data->f_type = 1;
                        return;
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                case 5: // @@ CUSTOM COMMAND DEMO
                        /*
                        
                                In this example we check for the arg with strstr because the strtok()
                                finds the root token which is just used to determine the command itself.
                        
                        */
                        
                        if (strstr(_prog_data->cmd_carry, "change") != NULL) {
                                _prog_data->demo_banner_change = 1;
                                _prog_data->f_type = 1;
                        } else if (strstr(_prog_data->cmd_carry, "revert") != NULL) {
                                _prog_data->demo_banner_change = 0;
                                _prog_data->f_type = 1;
                        } else {
                                strcat(_prog_data->cmd_output, "Usage: demo [option]\n\n\tchange\t\t- Changes the banner color.\n\trevert\t\t- Reverts the banner color.\n");
                                _prog_data->f_type = 1;
                        }
                        return;
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                // @@ STEP_FOUR: Using the the above code as reference, add your "microfunction" here
                /* e.g.
                case X: // comment
                        // stuff
                        strcat(_prog_data->cmd_output, "output\n");
                        _prog_data->f_type = 1;
                        return;
                */
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                case 30000: // Default if no command is found
                        strcat(_prog_data->cmd_output,"Command not found.");
                        _prog_data->f_type = 1;
                        return;
                ///////////////////////////////////////////////////////////////////////////////////////////////////////
        }
}
