#ifndef MYPPRINT
#define MYPPRINT

#include "lsalg.hpp"
#include <vector>
#include <iostream>
#include <cstring>
#include <list>

struct range_t
{
    ID_t n
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

void pretty_print(LS_res_t & res, workGraph_t & G, benches_t & Q)
{
    std::cout << res.time << std::endl;
    std::vector<range_t> prints (G.size());
    for (ID_t i = 0; i < G.size(); ++i)
    {
        //prints[i] = {res.permut[i], res.tsps[i], G[res.permut[i]].prep, G[res.permut[i]].len, G[res.permut[i]].type, 0};
        std::cout << res.permut[i] << ' ' << G[res.permut[i]].type << ' ' << res.tsps[i] << ' ' << G[res.permut[i]].len << std::endl;
    }
    /*
    std::sort(prints.begin(), prints.end(), cmp);
    std::vector<ID_t> rgs(Q.size() + 1);
    rgs[0] = 0;
    rgs[Q.size()] = G.size();
    ID_t j = 0;
    for (ID_t i = 0; i < Q.size() - 1; ++i)
    {
        while (j < G.size() && prints[j].t == i)
            ++j;
        rgs[i + 1] = j;
    }
    for (ID_t i = 0; i < Q.size(); ++i)
    {
        ID_t cur_t = 
    }
    */

    std::cout << std::endl;

    /*
    std::vector<behchprint_t> Qprint(Q.size());
    for (ID_t i = 0; i < Q.size(); ++i)
    {
        Qprint[i].sz = Q[i].order.n;
        Qprint[i].prints.resize(Qprint[i].sz);
        for (ID_t j = 0; j < Qprint[i].sz; ++j)
        {
            Qprint[i].prints[j].push_back({res.time, 0, 0});
        }
    }
    for (ID_t i = 0; i < G.size(); ++i)
    {
        btype_t tp = G[res.permut[i]].type;
        range_t cur_r = {res.tsps[i], G[res.permut[i]].prep, G[res.permut[i]].len};
        for (ID_t j = 0; j < Qprint[tp].sz; ++j)
        {
            auto it = Qprint[tp].prints[j].begin();
            while (it->s < cur_r.s)
                ++it;
            if (it == Qprint[tp].prints[j].begin())
            {
                if (cur_r.s + cur_r.l > it->s)
                    continue;
                else
                {
                    Qprint[tp].prints[j].insert(it, cur_r);
                    break
                }
            }
        }
    }
    */

    /*
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
    */
}

#endif  //MYPPRINT
