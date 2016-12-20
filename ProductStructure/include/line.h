#ifndef LINE_H
#define LINE_H

#include <string>
#include <sstream>
#include <deque>
#include <map>

const char sep = '\t';
const int min_pno_length = 8;
const int min_rst_length = 3;
const int min_fdes_length = 1;

class line
{
public:
    line(std::string prodnum,
         std::string prodrev,
         std::string prodname,
         std::string proddes):
        num(prodnum),
        rev(prodrev),
        nam(prodname),
        des(proddes)
    {
        valid = validate();
        set_tier();
    }
    line(std::string line_str)
    {
        split_line(line_str);
        valid = validate();
        set_tier();
    }
    bool is_valid() { return valid; }
    std::string get_num() { return num; }
    std::string get_nam() { return nam; }
    std::string get_rev() { return rev; }
    std::string get_des() { return des; }
    int get_tier() { return tier; }
    //std::map<std::string,std::string> get_line();
    friend std::ostream& operator<<(std::ostream& os,const line &other)
    {
        os << "Tier " << other.tier << ":\n\t\""
                      << other.num << "\",\n\t\""
                      << other.rev << "\",\n\t\""
                      << other.nam << "\",\n\t\""
                      << other.des << "\"";
        return os;
    }
protected:
    std::string num;
    std::string rev;
    std::string nam;
    std::string des;
    int tier;
    std::deque<std::string*> pars;
    bool validate();
    void split_line(std::string);
    void init_pars();
    void set_tier();
private:
    bool valid;
};

#endif // LINE_H
