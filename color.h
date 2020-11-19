#ifndef CONSOLE_HEADER
#define CONSOLE_HEADER

namespace color
{
    inline const char *reset = "\e[0m";

    namespace foreground
    {
        inline const char *black = "\e[30m";
        inline const char *red = "\e[31m";
        inline const char *green = "\e[32m";
        inline const char *yellow = "\e[33m";
        inline const char *blue = "\e[34m";
        inline const char *magenta = "\e[35m";
        inline const char *cyan = "\e[36m";
        inline const char *white = "\e[97m";
    } // namespace foreground

    namespace background
    {
        inline const char *black = "\e[40m";
        inline const char *red = "\e[41m";
        inline const char *green = "\e[42m";
        inline const char *yellow = "\e[43m";
        inline const char *blue = "\e[44m";
        inline const char *magenta = "\e[45m";
        inline const char *cyan = "\e[46m";
        inline const char *white = "\e[97m";
    } // namespace background
} // namespace color

#endif
