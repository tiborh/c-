void print_lines(deque<deque<string>> lines)
{
    for (deque<string> a_line : lines)
    {
        for (deque<string>::iterator iline = a_line.begin(); iline != a_line.end(); ++iline)
            cout << *iline << ' ';
        cout << '\n';
    }
}

int count_dots(string instr)
{
    int level = {};
    if (instr.at(0) == '.')
        {
            stringstream iss(instr);
            string prefstr;
            iss >> prefstr;
            level = prefstr.size();
        }
        else if (instr.at(0) == '*')
        {
            stringstream iss(instr);
            string prefstr;
            iss >> prefstr;
            if (prefstr.size() == 3)
                level = 0;
        }
        else
            level = 1;
    return level;
}

int main(int argc, char **argv)
{
#ifndef NDEBUG
    node_test();
    tree_test();
#endif

    if (argc < 2)
    {
        cout << "Give filename to process.\n";
        return 1;
    }

    fstream fh;
    const char* fn = argv[1];
    const char* fm = "r";
    if (!open_file(fh,fn,fm))
    {
        cout << "File cannot be opened: " << argv[1] << '\n';
        return 2;
    }
    deque<deque<string>> lines;
    string a_line = {};
    while(getline(fh,a_line))
    {
        stringstream iss(a_line);
        cout << a_line << '\n';
        deque<string> a_line = {};
        for(int i = 0; i < nu_of_node_dat && !iss.eof(); ++i)
        {
            string sub;
            getline(iss,sub,'\t');
            cout << '\t' << sub << '\n';
            int level = -1;
            if (i == 0)
                level = count_dots(sub);
            a_line.push_back(sub);
        }
        clog << a_line.size() << ' ';
        lines.push_back(a_line);
        //while(iss);
    }
    clog << '\n';
    clog << lines.size() << '\n';

    fh.close();

    return 0;
}
