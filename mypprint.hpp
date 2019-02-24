#ifndef MYPPRINT
#define MYPPRINT

#include "lsalg.hpp"
#include <vector>
#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>

struct range_t
{
    ID_t n;
    ID_t s;
    ID_t p;
    ID_t l;
    int t;
    int done;
};

bool cmp(range_t a, range_t b)
{
    return (a.t < b.t) || (a.t == b.t && a.s + a.l < b.s + b.l);
}

bool cmp2(range_t a, range_t b)
{
    return a.s < b.s;
}

void pretty_print(LS_res_t & res, workGraph_t & G, benches_t & Q)
{
    std::cout << res.time << std::endl;
    std::vector<range_t> prints (G.size());
    for (ID_t i = 0; i < G.size(); ++i)
    {
        prints[i] = {res.permut[i], res.tsps[i], G[res.permut[i]].prep, G[res.permut[i]].len, G[res.permut[i]].type, 0};
        std::cout << prints[i].n << ' ' << prints[i].s << ' ' << prints[i].p << ' ' << prints[i].l << ' ' << prints[i].t << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<range_t> > benchtypes (Q.size());
    for (ID_t i = 0; i < G.size(); ++i)
    {
        benchtypes[prints[i].t].push_back(prints[i]);
    }
    for (int i = 0; i < Q.size(); ++i)
    {
        std::sort(benchtypes[i].begin(), benchtypes[i].end(), cmp2);
    }
    for (int i = 0; i < Q.size(); ++i)
    {
        int max_parallel = Q[i].order.max_num;
        for (int k = 0; k < max_parallel; ++k)
        {
            ID_t max_r = 0;
            for (ID_t j = 0; j < benchtypes[i].size(); ++j)
            {
                if (!benchtypes[i][j].done && benchtypes[i][j].s >= max_r)
                {
                    benchtypes[i][j].done = true;
                    std::cout << '(' << benchtypes[i][j].n << ','
                                     << benchtypes[i][j].s << ','
                                     << benchtypes[i][j].p << ','
                                     << benchtypes[i][j].l << ')' << ", ";
                    max_r = benchtypes[i][j].s + benchtypes[i][j].l;
                }
            }
            std::cout << std::endl;
        }
        bool f = true;
        for (ID_t j = 0; j < benchtypes[i].size(); ++j)
        {
            if (!benchtypes[i][j].done)
            {
                f = false;
                break;
            }
        }
        if (!f)
        {
            std::cout << "smth wrong\n";
            break;
        }
    }

    std::cout << std::endl;
}

#endif  //MYPPRINT
