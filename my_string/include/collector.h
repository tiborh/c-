#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <ostream>
#include <cstring>
#include <cassert>

struct collector
{
    collector();
    collector(const char*);
    collector(const collector& c)
    {
        collector(c.get());
    }
    ~collector();
    char* get() const;
    int size() const
    {
        return len;
    }
    void set(const char*);
    void cat(const char*);
    void cat(const collector& s)
    {
        cat(s.get());
    }
private:
    int len;
    char *in_str;
};

std::ostream& operator<<(std::ostream&, const collector&);
#endif // COLLECTOR_H
