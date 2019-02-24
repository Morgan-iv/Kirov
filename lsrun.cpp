#include "lsalg.hpp"
#include "mypprint.hpp"
#include "antopt.hpp"

ID_t trivia(workGraph_t & G, benches_t & Q, EL_t & EL, ID_t pos, void * npar)
{
    return *(EL.begin());
}

void single_LS()
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
    LS_res_t res = LS_algo(G, Q, trivia, nullptr);
    pretty_print(res, G, Q);
}

void ant_run()
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

    ant_params_t P;
    P.alpha = 0.5;
    P.beta = 0.5;
    P.qzero = 0.6;
    P.tzero = 0.6;
    P.rho = 0.5;
    P.res_mult = 100.0;
    P.iterations = 50;

    LS_res_t res = ant_opt(G, Q, P);
    pretty_print(res, G, Q);
}

int main(int argc, char const *argv[])
{
    ant_run();
    return 0;
}
