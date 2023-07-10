#include "menu.h"
#include "std.h"

#include <conio.h>

#define RUNNING (true)
#define RIGHT_ARROW ('>')
#define LEFT_ARROW ('<')

usize menu(String name, StringArr options) {
    const usize num_of_options = options.len;

    u32 pos = 0; 
    bool choice = false;

    while (RUNNING) {
        usize apos = pos % num_of_options;

        system("cls");

        std_print_stream(stdout, "   {s}\n", name);

        for (usize i = 0; i < num_of_options; ++i) {
            if (i == apos) {
                std_print_stream(stdout, " {c} ", RIGHT_ARROW);
            } else {
                std_print_stream(stdout, "   ");
            }

            std_print_stream(stdout, "{s}", options.arr[i]);

            std_print_stream(stdout, "\n");
        }

        if (choice) {
            std_print_stream(stdout, "\n");
            return apos;
        }
        
        switch (_getch()) {
            case 'j': pos += 1; break;
            case 'k': pos -= 1; break;
            case  13: choice = true;
            default: ;
        }
    }

    return USIZE_MAX;
}

usize menu_ex(String name, StringArr options, usize last_position) {
    const usize num_of_options = options.len;

    u32 pos = last_position; 
    bool choice = false;

    while (RUNNING) {
        usize apos = pos % num_of_options;

        system("cls");

        std_print_stream(stdout, "{s}\n", name);

        for (usize i = 0; i < num_of_options; ++i) {
            if (i == apos) {
                std_print_stream(stdout, " {c} ", RIGHT_ARROW);
            } else {
                std_print_stream(stdout, "   ");
            }

            std_print_stream(stdout, "{s}", options.arr[i]);

            std_print_stream(stdout, "\n");
        }

        // !here is the return
        if (choice) {
            std_print_stream(stdout, "\n");
            return apos;
        }
        
        switch (_getch()) {
            case 'j': pos += 1; break;
            case 'k': pos -= 1; break;
            case  13: choice = true;
            default: ;
        }
    }

    return USIZE_MAX;
}

void turn_off_cursor(void) {
    fprintf(stdout, "\33[?25l");
}

void turn_on_cursor(void) {
    fprintf(stdout, "\33[?25h");
    fflush(stdout);
}

usize menu_ex_cursor(String name, StringArr options, usize last_position) {
    turn_off_cursor();

    const usize num_of_options = options.len;

    u32 pos = last_position; 
    bool choice = false;

    while (RUNNING) {
        usize apos = pos % num_of_options;

        system("cls");

        std_print_stream(stdout, "   {s}\n   ", name);

        for (usize i = 0; i < name.len; ++i) {
            std_print_stream(stdout, "-");
        }

        for (usize i = 0; i < num_of_options; ++i) {
            if (i == apos) {
                std_print_stream(stdout, "\n {c} ", RIGHT_ARROW);
            } else {
                std_print_stream(stdout, "\n   ");
            }

            std_print_stream(stdout, "{s}", options.arr[i]);

            if (i == apos) {
                std_print_stream(stdout, " {c} ", LEFT_ARROW);
            }
        }

        if (choice) {
            turn_on_cursor();
            std_print_stream(stdout, "\n");
            return apos;
        }
        
        switch (_getch()) {
            case 'j': pos += 1; break;
            case 'k': pos -= 1; break;
            case  13: choice = true;
            default: ;
        }
    }

    return USIZE_MAX;
}

void menu_pause(void) {
    std_print_stream(stdout, "\npress any key to continue...");
    _getch();
}
