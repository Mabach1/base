#include "menu.h"
#include "std.h"

#include <conio.h>

#define RUNNING (true)

usize menu(StringArr options) {
    const usize num_of_options = options.len;

    u32 pos = 0; 
    bool choice = false;

    while (RUNNING) {
        usize apos = pos % num_of_options;

        system("cls");

        for (usize i = 0; i < num_of_options; ++i) {
            if (i == apos) {
                std_print_stream(stdout, " {c} ", 16);
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

usize menu_ex(StringArr options, usize last_position) {
    const usize num_of_options = options.len;

    u32 pos = last_position; 
    bool choice = false;

    while (RUNNING) {
        usize apos = pos % num_of_options;

        system("cls");

        for (usize i = 0; i < num_of_options; ++i) {
            if (i == apos) {
                std_print_stream(stdout, " {c} ", 16);
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

usize menu_ex_cursor(StringArr options, usize last_position) {
    const usize num_of_options = options.len;

    u32 pos = last_position; 
    bool choice = false;

    while (RUNNING) {
        usize apos = pos % num_of_options;

        system("cls");

        for (usize i = 0; i < num_of_options; ++i) {
            if (i == apos) {
                std_print_stream(stdout, " {c} ", 16);
            } else {
                std_print_stream(stdout, "   ");
            }

            std_print_stream(stdout, "{s}", options.arr[i]);

            if (i == apos) {
                std_print_stream(stdout, " {c} ", 17);
            }

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

void menu_pause(void) {
    std_print_stream(stdout, "\npress any key to continue...");
    _getch();
}
