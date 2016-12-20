#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <stdexcept>
#include <cstring> // strlen
#include <list>
#include <fstream> // for file handling
#include <algorithm> // sort

using namespace std;

const int MAXNUM = 100;

void fillvector1(vector<int> &a, int vsize)
{
    for(int i = 0; i < vsize; i++)
        a[i] = rand() % MAXNUM;
}

void fillvector2(vector<int> &a, int vsize)
{
    for(int i = 0; i < vsize; i++)
        a.push_back(rand() % MAXNUM);
}

void fillvector(vector <int> &inv)
{
    int vsize = rand() % (MAXNUM-10) + 10;
    for(int i = 0; i < vsize; i++)
        inv.push_back(rand() % MAXNUM);
}

vector<int> createVector(int reserved)
{
    vector<int> outv;
    outv.reserve(reserved);
    int vsize = rand()%MAXNUM;

    fillvector2(outv,vsize);

    return outv;
}

vector<int> createVector()
{
    int reserved = MAXNUM;
    vector<int> outv = createVector(reserved);
    return outv;
}

vector<string> createStringVector(string* ina,int arraysize)
{
    vector<string> outv;
    for(int i=0; i < arraysize; i++)
        outv.push_back(*(ina+i));

    return outv;
}

void printvector(vector<int> in)
{
    for(unsigned int i = 0; i < in.size(); i++) // size() is unsigned
    {
        cout << in[i];
        if (i < in.size()-1)
            cout << ", ";
        else
            cout << '\n';
    }
    cout << "Capacity: " << in.capacity() << " Size: " << in.size() << endl;
}

void printvector(vector<int> inv, vector<int>::const_iterator invi)
{
    for(invi = inv.begin(); invi != inv.end(); ++invi)
        cout << *invi << ", ";
    cout << endl;
    cout << "Capacity: " << inv.capacity() << " Size: " << inv.size() << endl;
}

void printvector(vector<char> in)
{
    for(unsigned int i = 0; i < in.size(); i++) // size() is unsigned
    {
        cout << in[i];
        if (i < in.size()-1)
            cout << ", ";
        else
            cout << '\n';
    }
    cout << "Capacity: " << in.capacity() << " Size: " << in.size() << endl;
}

void printvector(vector<string> in)
{
    vector<string>::const_iterator ini;
    vector<string>::const_iterator first = in.begin();
    vector<string>::const_iterator last = in.end();
    char firstchar;
    if (in.size() > MAXNUM/10)
    {
        for(ini = in.begin(); ini != in.end(); ini++)
            if (distance(first,ini) < MAXNUM/20 ||
                distance(ini,last) < MAXNUM/20)
                cout << *ini << endl;
            else
                if ((*ini).at(0) != firstchar)
                {
                    firstchar = (*ini).at(0);
                    cout << firstchar << "..." << endl;
                }
    }
    else
        for(ini = in.begin(); ini != in.end(); ini++)
            cout << *ini << endl;
}

void printlist(list<string> inl) //extremely slow
{
    list<string>::const_iterator inli;
    list<string>::const_iterator first = inl.begin();
    list<string>::const_iterator last = inl.end();
    char firstchar;
    if (inl.size() > MAXNUM/10)
        for(inli = inl.begin(); inli != inl.end(); inli++)
            if (distance(first,inli) < MAXNUM/20 ||
                distance(inli,last) > static_cast<signed>(inl.size()) - MAXNUM/20)
                cout << *inli << endl;
            else
                if ((*inli).at(0) != firstchar)
                {
                    firstchar = (*inli).at(0);
                    cout << firstchar << "..." << endl;
                }
}

void printVectorReverse(vector<string> inv)
{
    vector<string>::reverse_iterator invi;
    vector<string>::reverse_iterator first = inv.rbegin();
    vector<string>::reverse_iterator last = inv.rend();
    for (invi = first; invi != last; invi++) // in the reverse world, ++ is the right thing.
        cout << *invi << endl;
}

void outofrange(vector<int> in, int vsize)
{
    cout << "\nTesting out-of-range error message.\n";
    try
    {
        in.at(vsize) = 0;
    }
    catch(out_of_range e)
    {
        cerr << "Vector read problem: " << e.what() << endl;
    }
}

void arraylike(int arraysize)
{
    vector<int> testvector(arraysize);

    cout << "\nCreating vector with size: " << arraysize << endl;
    fillvector1(testvector,arraysize);
    printvector(testvector);
    outofrange(testvector,arraysize);
}

void noInitialSize()
{
    vector<int> testvector;
    const int vsize = rand() % MAXNUM;

    cout << "\nCreating vector with no initial size.\n";
    fillvector2(testvector,vsize); // fillvector1 would result in Segmentation Fault
    printvector(testvector);
}

void testengine()
{
    unsigned int sc = 0;
    cout << "\nRunning test engine.\n";
    for (int i = 0; i < MAXNUM; i++)
    {
        vector<int> tv;
        fillvector2(tv,i);
        if (sc < tv.capacity())
        {
            cout << "Capacity: " << tv.capacity() << " Size: " << tv.size() << endl;
            sc = tv.capacity();
        }
    }
    cout << "Exiting test engine.\n";
}

void testreturned()
{
    cout << "\nCreating vector with reserved capacity.\n";
    vector<int> aVector = createVector(MAXNUM);
    printvector(aVector);
    aVector.resize(aVector.size()/2);
    cout << "Halved:\n";
    printvector(aVector);
}

void array2vector(const char* testarray)
{
    cout << "\nConverting constant char array to vector.\n";
    cout << testarray << endl;
    int asize = strlen(testarray);  // cannot handle unicode
    cout << "String length: " << asize << endl;
    vector<char> tv(testarray,testarray+asize);  //does not work with unicode
    printvector(tv);
}

void invalid_pointer()
{
    vector<int> v(5);
    int *pi = &v[3];
    cout << "\npi points to: " << *pi << endl;
    cout << "Capacity: " << v.capacity() << " Size: " << v.size() << endl;
    v.push_back(999); // <-- may trigger a reallocation
    *pi = 333;        // <-- can cause an error, pi may not be valid any more
    // reserve(6) before push_back and pointer creation could prevent it
    cout << "pi points to: " << *pi << endl;
    cout << "Capacity: " << v.capacity() << " Size: " << v.size() << endl;
}

void with_const_iterator()
{
    vector<int> a;
    vector<int>::const_iterator ai;
    cout << "\nDoing it with constant iterator:\n";
    fillvector(a);
    printvector(a,ai);
}

vector<string> list2vector(list<string> inl)
{
    vector<string> outv(inl.begin(),inl.end());
    return outv;
}

list<string> createlist()
{
    list<string> outlist;
    string input_line;
    const char* input_filename = "/etc/dictionaries-common/words";
    ifstream fh(input_filename);

    if (fh.is_open())
    {
        while (getline(fh,input_line))
            outlist.push_back(input_line);
        fh.close();
    } else
        cout << "Cannot open: " << input_filename << endl;

    return outlist;
}

void list2vector_test()
{
    list<string> tl = createlist();
    vector<string> tv = list2vector(tl);
    cout << "\nTesting list to vector test.\n";
    // omitted because it is very slow:
    //printlist(tl);
    printvector(tv);
    cout << "Capacity: " << tv.capacity() << " Size: " << tv.size() << endl;
}

void testassign()
{
    cout << "\nTesting assign:\n";
    vector<int> tv = createVector();
    printvector(tv);
    int tvsize = tv.size();
    int assigned_size = tvsize / 2;
    tv.assign(assigned_size,0);
    printvector(tv);
}

void printVectorFirstLast(vector<string> inv)
{
    cout << *inv.begin() << ((inv.size() > 2) ? "..." : " ");
    cout << ((inv.size() > 1) ? *(inv.end()-1) : "") << endl; //end points at beyond last element
}

void printVectorFrontBack(vector<string> inv)
{
    cout << inv.front() << ((inv.size() > 2) ? "..." : " ");
    cout << ((inv.size() > 1) ? inv.back() : "") << endl; //end points at beyond last element
}

void poptest()
{
    string myarray[] = {"春","夏","秋","冬"};
    int arraylength = sizeof(myarray)/sizeof(*myarray);
    cout << "\nTesting pop_back:\n";
    vector<string> myvector = createStringVector(myarray,arraylength);
    printvector(myvector);
    cout << "Reverse print:\n";
    printVectorReverse(myvector);
    cout << "Starting popping:\n";
    while(!myvector.empty())
    {
        cout << "with first/last:\n";
        printVectorFirstLast(myvector);
        cout << "with front/back:\n";
        printVectorFrontBack(myvector);
        myvector.pop_back();
    }
}

vector<string> mergeStringVectors(vector<string> a, vector<string> b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << "First:\n";
    printvector(a);
    cout << "Second:\n";
    printvector(b);
    vector<string>::iterator ai;
    vector<string>::iterator bi;
    vector<string> vo;

    ai = a.begin(), bi = b.begin();
    do {
        if (ai == a.end())
            vo.push_back(*bi++);
        else if(bi == a.end())
            vo.push_back(*ai++);
        else if ((*ai).compare(*bi) < 0)
            vo.push_back(*ai++);
        else if ((*ai).compare(*bi) > 0)
            vo.push_back(*bi++);
    }while(ai!=a.end() || bi!=b.end());

    return vo;
}

void mergeTest()
{
    cout << "\nMerging two string vectors:\n";
    string an_array[] = {"Anna","Deirdre","Delilah","Sarah","Vanessa","Zoe"};
    vector<string> a (an_array,an_array+6);
    string another_arr[] = {"Abel","Fergus","Frank","Jonas","William","Xerxes","Zoroaster"};
    vector<string> b (another_arr,another_arr+7);
    vector<string> mergedv = mergeStringVectors(a,b);
    cout << "Merged vector:\n";
    printvector(mergedv);
}

void insertTest()
{
    cout << "\nInsert Test:\n";
    int a[] = {23,46,73,46,2};
    vector<int> av(a,a+5);
    int anum = 78;
    int b[] = {12,55,789,201,563214};
    vector<int> bv(b,b+5);
    cout << "First:\n";
    printvector(av);
    cout << "Second:\n";
    printvector(bv);
    vector<int>::iterator avi = av.begin();
    avi++;
    avi = av.insert(avi,anum);
    cout << "First (integer inserted):\n";
    printvector(av);
    avi++;
    av.insert(avi,bv.begin(),bv.end());
    cout << "First (vector content inserted):\n";
    printvector(av);
    avi = av.end();
    av.insert(avi,5,0);
    cout << "First (zero elements inserted):\n";
    printvector(av);
    avi = av.begin();
    av.erase(avi);
    cout << "First element erased:\n";
    printvector(av);
    av.erase(avi,avi+3); //avi should be reinitialised
    cout << "Three more elements erased:\n";
    printvector(av);
    av.clear();
    cout << "Cleared:\n";
    printvector(av);
}

void vectorSwapTest()
{
    cout << "\nTesting vector swap:\n";
    string seasons[] = {"春","夏","秋","冬"};
    vector<string> a(seasons,seasons+4);
    cout << "Vector a:\n";
    printvector(a);
    string colours[] = {"青","赤","黒","白","緑"};
    vector<string> b(colours,colours+5);
    cout << "Vector b:\n";
    printvector(b);
    a.swap(b);
    cout << "After swap:\n";
    cout << "Vector a:\n";
    printvector(a);
    cout << "Vector b:\n";
    printvector(b);
}

int main()
{
    const int vsize = 10;
    arraylike(vsize);

    noInitialSize();
    testreturned();
    testengine();

    const char* testarray = "悪妻は百年の不作。(あくさいはひゃくねんのふさく)";
    array2vector(testarray);
    const char* testarray2 = "Literally: A bad wife [brings] a hundred years of bad harvest.";
    array2vector(testarray2);

    invalid_pointer();
    with_const_iterator();
    list2vector_test();
    testassign();
    poptest();
    mergeTest();
    insertTest();
    vectorSwapTest();

    return 0;
}
