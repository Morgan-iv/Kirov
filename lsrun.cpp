#include "lsalg.cpp"
#include <vector>
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    workGraph_t G = 
    {
        { 1,  0, 70,  1 },
        { 2,  0, 400, 2 },
        { 10, 0, 310, 3 },

        { 4,  0, 20,  0 },
        { 5,  0, 70,  3 },
        { 10, 0, 80,  2 },

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
        std::cout << res.permut[i] << ' ' << res.tsps[i] << ' ' << G[res.permut[i]].len << std::endl;
    }

    std::cout << std::endl;
    char * bres[5];
    bres[0] = new char[res.time + 1]; memset(bres[0], '.', res.time); bres[0][res.time] = '\0';
    bres[1] = new char[res.time + 1]; memset(bres[1], '.', res.time); bres[1][res.time] = '\0';
    bres[2] = new char[res.time + 1]; memset(bres[2], '.', res.time); bres[2][res.time] = '\0';
    bres[3] = new char[res.time + 1]; memset(bres[3], '.', res.time); bres[3][res.time] = '\0';
    bres[4] = new char[res.time + 1]; memset(bres[4], '.', res.time); bres[4][res.time] = '\0';

    for (ID_t i = 0; i < G.size(); ++i)
    {
        int p = G[res.permut[i]].type;
        memset(bres[p] + res.tsps[i], '0' + res.permut[i], G[res.permut[i]].len);
    }
    std::cout << bres[0] << std::endl;
    std::cout << bres[1] << std::endl;
    std::cout << bres[2] << std::endl;
    std::cout << bres[3] << std::endl;
    std::cout << bres[4] << std::endl;

    delete[] bres[0];
    delete[] bres[1];
    delete[] bres[2];
    delete[] bres[3];
    delete[] bres[4];
    return 0;
}