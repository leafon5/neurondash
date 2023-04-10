#include "includes.h"
// defines add_hook to use minhook
// lets you use mod_main
#include <matdash/boilerplate.hpp>

// matdash::create_console
#include <matdash/console.hpp>

#include "hookmain.hpp"


void mod_main(HMODULE module) {


    matdash::create_console();

    Hooks::init();

}