#ifndef ARG_HEADER
#define ARG_HEADER

namespace arg
{
    inline bool parsed = false;

    struct args
    {
        const char *name;
        const char *shrt;
        const char *desc;
        const char *dflt;
        bool required;
        const char *value;
        bool (*validate)(const char *val);
    };

    inline std::vector<args> all;

    void parseargs(int argc, char *argv[]);
    void addarg(arg::args arg);
} // namespace arg

#endif
