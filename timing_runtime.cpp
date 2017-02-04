#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const long long START = 0;
const long long END = 2000000;
const long long STEP = 5;

void function()
{
    long long number = 0;

    for( long long i = START; i != END; ++i )
    {
       number += STEP;
    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duranano = duration_cast<nanoseconds>( t2 - t1 ).count();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    auto durmilli = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << "Adding numbers from " << START << " to " << END
	 << " (with stepping " << STEP << ")\n";
    cout << "Duration: " << duranano << "  (nanoseconds)\n";
    cout << "Duration: " << duration << " (microseconds)\n";
    cout << "Duration: " << durmilli << " (milliseconds)\n";
    return 0;
}
