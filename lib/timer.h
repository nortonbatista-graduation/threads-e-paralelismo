#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

using namespace std;

auto now()
{
    return chrono::steady_clock::now();
}

double elapsed_time(auto start, auto finish)
{
    return double(chrono::duration_cast<chrono::nanoseconds>(finish - start).count());
}

double convert_to_seconds(double nanoseconds)
{
    return nanoseconds / 1e9;
}

#endif // TIMER_H_INCLUDED
