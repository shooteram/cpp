#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

#include "arg.h"
#include "color.h"

namespace arg
{
    void addarg(arg::args arg)
    {
        if (!arg.name)
        {
            std::cout << color::foreground::red
                      << "An argument has been added without a name.\n"
                      << color::reset;
            return;
        }

        if (arg.validate && !arg.validate(arg.value))
        {
            std::cout << color::foreground::red
                      << "Could not validate the passed argument " << arg.name << ".\n"
                      << color::reset;
            return;
        }

        arg::all.push_back(arg);
    }

    void parseargs(int argc, char *argv[])
    {
        if (parsed)
        {
            std::cout << color::foreground::red
                      << "arguments already parsed.\n"
                      << color::reset;
            return;
        }

        for (arg::args &arg : all)
        {
            std::cout << "arg: " << arg.name << "\n";
        }

        std::regex rgx("^(-|--)([a-zA-Z+]+$)");
        // std::regex val("^[a-zA-Z0-9]+$");
        std::smatch match;

        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            std::cout << "arg n" << i << ": " << arg << "\n";

            if (std::regex_match(arg, std::regex(rgx)))
            {
                std::regex_search(arg, match, rgx);
                if (3 != match.size())
                {
                    std::cout << "an error occured while trying to retrieve the name of an argument\n";
                    return;
                }

                std::string name = match[2].str();

                if (!arg::all.empty())
                {
                    std::cout << "args are not empty\n";

                    const arg::args argtmp = {"port"};
                    std::vector<arg::args>::iterator it = std::find_if(
                        all.begin(), all.end(),
                        [&ca = argtmp](const args &a) -> bool { return ca.name == a.name; });

                    std::cout << "name: " << *it.base()->name << "\n";
                }
            }
        }

        parsed = true;
    }
} // namespace arg
