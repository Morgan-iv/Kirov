#include "lsalg.cpp"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    workGraph_t G = 
    {
        { 1,  0, 70,  1 },
        { 2,  0, 400, 2 },
        { 10, 0, 310, 3 },

        { 4,  0, 20,  0 },
        { 5,  0, 70,  2 },
        { 10, 0, 80,  3 },

        { 7,  0, 30,  0 },
        { 8,  0, 85,  2 },
        { 9,  0, 230, 3 },
        { 10, 0, 376, 4 }
    };
    benches_t Q(5);
    ID_t maxtime = 10000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 1);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 1);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 1);
    LS_res_t res = LS_algo(G, Q, maxtime);
    std::cout << res.time << std::endl;
    for (ID_t i = 0; i < G.size(); ++i)
    {
        std::cout << res.permut[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}