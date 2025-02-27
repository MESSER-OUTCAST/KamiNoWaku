// Copyright (c) 2025, Jamison A. Drapeau
#include "kaminowaku.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main () {

        // Generate data structure
        _carry_forward _prog_data;
        
        // Set initial prompt
        memset(_prog_data.prompt, 0x00, DOUBLE_BLOCK);
        strcpy(_prog_data.prompt, "> ");

        // Set and scrub initial program data, refer to data.h for standards
        _prog_data.f_type = 0;
        _prog_data.cmd_token = NULL;
        
        // Clean IO memory
        memset(_prog_data.cmd_input, 0x00, SUPER_BLOCK);
        memset(_prog_data.cmd_output, 0x00, OUT_BLOCK);
        memset(_prog_data.cmd_carry, 0x00, SUPER_BLOCK);

        // @@ Initialize any variables you create here
        _prog_data.demo_banner_change = 0;

        // Transition to prompt
        while ( kaminowaku(&_prog_data) );

        return 0;
}
