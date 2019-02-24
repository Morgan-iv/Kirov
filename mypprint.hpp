#ifndef MYPPRINT
#define MYPPRINT

#include "lsalg.hpp"
#include <vector>
#include <iostream>
#include <cstring>

void pretty_print(LS_res_t & res, workGraph_t & G, benches_t & Q)
{
    std::cout << res.time << std::endl;
    for (ID_t i = 0; i < G.size(); ++i)
    {
        std::cout << res.permut[i] << ' ' << res.tsps[i] << ' ' << G[res.permut[i]].len << std::endl;
    }
    std::cout << std::endl;
    char ** benchlines = new char *[Q.size()];
    for (ID_t i = 0; i < Q.size(); ++i)
    {
        benchlines[i] = new char[res.time + 1];
        memset(benchlines[i], '.', res.time);
        benchlines[i][res.time] = '\0';
    }
    for (ID_t i = 0; i < G.size(); ++i)
    {
        int p = G[res.permut[i]].type;
        memset(benchlines[p] + res.tsps[i], '0' + res.permut[i], G[res.permut[i]].len);
    }
    for (int i = 0; i < Q.size(); ++i)
    {
        std::cout << benchlines[i] << std::endl;
        delete[] benchlines[i];
    }
    delete[] benchlines;
}

#endif  //MYPPRINT
