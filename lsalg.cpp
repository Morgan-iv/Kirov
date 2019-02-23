#include <list>
#include <vector>
#include <set>

using int_t = int64_t;
using ID_t = size_t;
using btype_t = int;

/*
struct range_t
{
    ID_t b;
    ID_t e;
};
*/

struct segtree_t
{
    ID_t n;
    std::vector<ID_t> t;
    void build (ID_t num, ID_t v, ID_t tl, ID_t tr)
    {
        if (tl == tr)
            t[v] = num;
        else
        {
            ID_t tm = (tl + tr) / 2;
            build (num, v * 2, tl, tm);
            build (num, v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }
    ID_t min(ID_t a, ID_t b)
    {
        return (a < b) ? a : b;
    }
    ID_t max(ID_t a, ID_t b)
    {
        return (a > b) ? a : b;
    }
    segtree_t(ID_t maxtime = 1, ID_t num = 1)
    {
        t.resize(maxtime * 4);
        build(num, 1, 0, maxtime - 1);
    }
    ID_t res (ID_t v, ID_t tl, ID_t tr, ID_t l, ID_t r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        ID_t tm = (tl + tr) / 2;
        return res (v * 2, tl, tm, l, min(r, tm))
            + res (v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void update (ID_t v, ID_t tl, ID_t tr, ID_t pos, ID_t change)
    {
        if (tl == tr)
            t[v] -= change;
        else
        {
            ID_t tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v * 2, tl, tm, pos, change);
            else
                update (v * 2 + 1, tm + 1, tr, pos, change);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }
};

struct LS_res_t
{
    ID_t time;
    std::vector<ID_t> permut;
};

struct work_t
{
    std::set<ID_t> parents;
    ID_t next;
    ID_t min_time;
    ID_t len;
    btype_t type;
};

struct bench_t
{
    btype_t type;
    segtree_t order;
};

using workGraph_t = std::vector<work_t>;
using benches_t = std::vector<bench_t>;
using EL_container_t = std::set;
using EL_t = EL_container_t<ID_t>;
//using EL_it_t = EL_t::iterator;

ID_t choose(EL_t EL)
{
    return *(EL.begin());
}

LS_res_t LS_algo(workGraph_t G, benches_t Q, ID_t maxtime)
{
    EL_t EL;
    LS_res_t LS_res;
    for (ID_t i = 0; i < G.size(); ++i)
    {
        EL.insert(i);
    }
    for (ID_t i = 0; i < G.size(); ++i)
    {
        EL.erase(G[i].next);
    }
    while (!EL.empty())
    {
        ID_t j = choose(EL);
        work_t & cur_w = G[j];
        ID_t time = G[j].min_time;
        bench_t & cur_b = Q[cur_w.type];
        while (cur_b.order.res(1, 0, maxtime - 1, time, time + cur_w.len - 1) == 0)
            ++time;
        LS_res.permut.push_back(j);
        if (LS_res.time < time + cur_w.len)
            LS_res.time = time + cur_w.len;
        for (ID_t i = 0; i < cur_w.len; ++i)
            cur_b.order.update(1, 0, maxtime - 1, time + i, 1);
        EL.insert(cur_w.next);
        if (G[cur_w.next].min_time < time + cur_w.len)
            G[cur_w.next].min_time = time + cur_w.len
        EL.erase(j);
    }
    return LS_res;
}
