#include <iostream>
#include <regex>

#include "arg.h"

bool validateportarg(const char *val)
{
    return true;
}

int main(int argc, char *argv[])
{
    arg::args portarg = {};
    // portarg.validate = validateportarg;
    arg::addarg(portarg);

    // arg::parseargs(argc, argv);

    if (!arg::parsed)
    {
        return 1;
    }

    return 0;
}
