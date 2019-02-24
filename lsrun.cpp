#include "lsalg.hpp"
#include "mypprint.hpp"
#include <vector>
#include <iostream>
#include <cstring>

ID_t choose(EL_t EL)
{
    return *(EL.begin());
}

int main(int argc, char const *argv[])
{
    workGraph_t G = 
    {
        { 1,  0, 70,  10, 1 },
        { 2,  0, 400, 10, 2 },
        { 10, 0, 310, 10, 3 },

        { 4,  0, 20,  5,  0 },
        { 5,  0, 70,  10, 3 },
        { 10, 0, 80,  5,  2 },

        { 7,  0, 30,  5,  0 },
        { 8,  0, 85,  10, 2 },
        { 9,  0, 230, 5,  3 },
        { 10, 0, 376, 1,  4 }
    };
    benches_t Q(5);
    ID_t maxtime = 10000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 1);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 1);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 1);
    LS_res_t res = LS_algo(G, Q);
    pretty_print(res, G, Q);
    return 0;
}
