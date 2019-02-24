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
        { 1, 0, 78, 10, 1 },
        { 2, 0, 61, 10, 2 },
        { 141, 0, 158, 5, 3 },
        { 4, 0, 112, 10, 1 },
        { 5, 0, 175, 5, 3 },
        { 6, 0, 35, 1, 4 },
        { 141, 0, 340, 0, 6 },
        { 8, 0, 130, 10, 1 },
        { 141, 0, 130, 10, 2 },
        { 10, 0, 110, 10, 1 },
        { 11, 0, 705, 5, 3 },
        { 12, 0, 210, 10, 2 },
        { 141, 0, 1000, 0, 6 },
        { 14, 0, 20, 10, 1 },
        { 141, 0, 20, 10, 2 },
        { 16, 0, 100, 10, 1 },
        { 17, 0, 410, 5, 3 },
        { 141, 0, 91, 1, 4 },
        { 19, 0, 56, 10, 1 },
        { 141, 0, 148, 10, 2 },
        { 21, 0, 238, 10, 1 },
        { 22, 0, 1905, 5, 3 },
        { 141, 0, 542, 10, 2 },
        { 24, 0, 100, 10, 1 },
        { 141, 0, 155, 5, 2 },
        { 26, 0, 40, 10, 1 },
        { 27, 0, 185, 5, 3 },
        { 28, 0, 195, 15, 4 },
        { 141, 0, 150, 0, 6 },
        { 30, 0, 30, 5, 0 },
        { 141, 0, 110, 10, 2 },
        { 32, 0, 10, 5, 0 },
        { 33, 0, 30, 5, 3 },
        { 34, 0, 121, 1, 4 },
        { 35, 0, 275, 0, 5 },
        { 141, 0, 15, 10, 2 },
        { 37, 0, 30, 10, 1 },
        { 141, 0, 250, 10, 2 },
        { 39, 0, 70, 10, 1 },
        { 40, 0, 310, 10, 3 },
        { 141, 0, 400, 10, 2 },
        { 42, 0, 20, 5, 0 },
        { 43, 0, 70, 10, 2 },
        { 141, 0, 80, 5, 3 },
        { 45, 0, 30, 5, 0 },
        { 46, 0, 230, 5, 3 },
        { 47, 0, 85, 10, 2 },
        { 141, 0, 376, 1, 4 },
        { 49, 0, 25, 10, 1 },
        { 141, 0, 45, 10, 2 },
        { 51, 0, 40, 10, 1 },
        { 52, 0, 75, 5, 3 },
        { 141, 0, 80, 10, 2 },
        { 54, 0, 35, 5, 0 },
        { 55, 0, 155, 5, 2 },
        { 56, 0, 95, 5, 3 },
        { 141, 0, 151, 1, 4 },
        { 58, 0, 20, 5, 0 },
        { 59, 0, 80, 5, 3 },
        { 141, 0, 106, 1, 4 },
        { 61, 0, 85, 10, 1 },
        { 141, 0, 130, 5, 2 },
        { 63, 0, 20, 10, 1 },
        { 141, 0, 65, 5, 3 },
        { 65, 0, 15, 5, 0 },
        { 66, 0, 80, 10, 2 },
        { 67, 0, 25, 5, 3 },
        { 141, 0, 100, 0, 6 },
        { 69, 0, 30, 5, 0 },
        { 70, 0, 305, 5, 3 },
        { 71, 0, 185, 10, 2 },
        { 72, 0, 226, 1, 4 },
        { 141, 0, 125, 0, 5 },
        { 74, 0, 15, 5, 0 },
        { 75, 0, 25, 10, 2 },
        { 76, 0, 20, 5, 3 },
        { 141, 0, 61, 1, 4 },
        { 78, 0, 25, 5, 0 },
        { 79, 0, 55, 5, 3 },
        { 141, 0, 90, 10, 2 },
        { 81, 0, 40, 10, 1 },
        { 82, 0, 155, 5, 2 },
        { 83, 0, 35, 5, 3 },
        { 141, 0, 300, 0, 6 },
        { 85, 0, 40, 10, 1 },
        { 141, 0, 140, 5, 3 },
        { 87, 0, 15, 5, 0 },
        { 141, 0, 85, 10, 2 },
        { 89, 0, 15, 5, 0 },
        { 90, 0, 50, 5, 3 },
        { 141, 0, 25, 10, 2 },
        { 92, 0, 15, 10, 1 },
        { 93, 0, 45, 10, 2 },
        { 94, 0, 40, 5, 3 },
        { 141, 0, 116, 1, 4 },
        { 96, 0, 110, 10, 1 },
        { 141, 0, 905, 5, 3 },
        { 98, 0, 80, 5, 0 },
        { 99, 0, 380, 5, 2 },
        { 141, 0, 76, 1, 4 },
        { 101, 0, 30, 5, 0 },
        { 102, 0, 155, 5, 3 },
        { 103, 0, 130, 5, 2 },
        { 104, 0, 51, 1, 4 },
        { 141, 0, 125, 0, 5 },
        { 106, 0, 665, 5, 3 },
        { 141, 0, 280, 5, 2 },
        { 108, 0, 310, 10, 2 },
        { 109, 0, 130, 5, 3 },
        { 141, 0, 51, 1, 4 },
        { 111, 0, 80, 5, 3 },
        { 141, 0, 85, 10, 2 },
        { 113, 0, 85, 10, 2 },
        { 114, 0, 15, 5, 3 },
        { 115, 0, 21, 1, 4 },
        { 141, 0, 50, 0, 6 },
        { 117, 0, 15, 5, 0 },
        { 118, 0, 40, 5, 3 },
        { 119, 0, 75, 10, 2 },
        { 120, 0, 6, 1, 4 },
        { 141, 0, 25, 0, 5 },
        { 122, 0, 50, 5, 3 },
        { 123, 0, 80, 10, 2 },
        { 141, 0, 6, 1, 4 },
        { 125, 0, 110, 10, 2 },
        { 141, 0, 20, 5, 3 },
        { 127, 0, 105, 5, 3 },
        { 128, 0, 140, 10, 2 },
        { 129, 0, 11, 1, 4 },
        { 141, 0, 100, 0, 6 },
        { 131, 0, 15, 5, 0 },
        { 132, 0, 15, 5, 3 },
        { 133, 0, 30, 5, 2 },
        { 134, 0, 25, 15, 4 },
        { 141, 0, 25, 0, 5 },
        { 136, 0, 130, 5, 3 },
        { 137, 0, 30, 5, 2 },
        { 141, 0, 6, 1, 4 },
        { 139, 0, 55, 10, 2 },
        { 140, 0, 80, 5, 3 },
        { 141, 0, 6, 1, 4 }
    };
    benches_t Q(7);
    ID_t maxtime = 100000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 2);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 2);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 2);
    Q[5].type = 5; Q[5].order = segtree_t(maxtime, 1);
    Q[6].type = 6; Q[6].order = segtree_t(maxtime, 1);

    LS_res_t res = LS_algo(G, Q, trivia, nullptr);
    pretty_print(res, G, Q);
}

void ant_run()
{
    workGraph_t G =
    {
        { 1, 0, 78, 10, 1 },
        { 2, 0, 61, 10, 2 },
        { 141, 0, 158, 5, 3 },
        { 4, 0, 112, 10, 1 },
        { 5, 0, 175, 5, 3 },
        { 6, 0, 35, 1, 4 },
        { 141, 0, 340, 0, 6 },
        { 8, 0, 130, 10, 1 },
        { 141, 0, 130, 10, 2 },
        { 10, 0, 110, 10, 1 },
        { 11, 0, 705, 5, 3 },
        { 12, 0, 210, 10, 2 },
        { 141, 0, 1000, 0, 6 },
        { 14, 0, 20, 10, 1 },
        { 141, 0, 20, 10, 2 },
        { 16, 0, 100, 10, 1 },
        { 17, 0, 410, 5, 3 },
        { 141, 0, 91, 1, 4 },
        { 19, 0, 56, 10, 1 },
        { 141, 0, 148, 10, 2 },
        { 21, 0, 238, 10, 1 },
        { 22, 0, 1905, 5, 3 },
        { 141, 0, 542, 10, 2 },
        { 24, 0, 100, 10, 1 },
        { 141, 0, 155, 5, 2 },
        { 26, 0, 40, 10, 1 },
        { 27, 0, 185, 5, 3 },
        { 28, 0, 195, 15, 4 },
        { 141, 0, 150, 0, 6 },
        { 30, 0, 30, 5, 0 },
        { 141, 0, 110, 10, 2 },
        { 32, 0, 10, 5, 0 },
        { 33, 0, 30, 5, 3 },
        { 34, 0, 121, 1, 4 },
        { 35, 0, 275, 0, 5 },
        { 141, 0, 15, 10, 2 },
        { 37, 0, 30, 10, 1 },
        { 141, 0, 250, 10, 2 },
        { 39, 0, 70, 10, 1 },
        { 40, 0, 310, 10, 3 },
        { 141, 0, 400, 10, 2 },
        { 42, 0, 20, 5, 0 },
        { 43, 0, 70, 10, 2 },
        { 141, 0, 80, 5, 3 },
        { 45, 0, 30, 5, 0 },
        { 46, 0, 230, 5, 3 },
        { 47, 0, 85, 10, 2 },
        { 141, 0, 376, 1, 4 },
        { 49, 0, 25, 10, 1 },
        { 141, 0, 45, 10, 2 },
        { 51, 0, 40, 10, 1 },
        { 52, 0, 75, 5, 3 },
        { 141, 0, 80, 10, 2 },
        { 54, 0, 35, 5, 0 },
        { 55, 0, 155, 5, 2 },
        { 56, 0, 95, 5, 3 },
        { 141, 0, 151, 1, 4 },
        { 58, 0, 20, 5, 0 },
        { 59, 0, 80, 5, 3 },
        { 141, 0, 106, 1, 4 },
        { 61, 0, 85, 10, 1 },
        { 141, 0, 130, 5, 2 },
        { 63, 0, 20, 10, 1 },
        { 141, 0, 65, 5, 3 },
        { 65, 0, 15, 5, 0 },
        { 66, 0, 80, 10, 2 },
        { 67, 0, 25, 5, 3 },
        { 141, 0, 100, 0, 6 },
        { 69, 0, 30, 5, 0 },
        { 70, 0, 305, 5, 3 },
        { 71, 0, 185, 10, 2 },
        { 72, 0, 226, 1, 4 },
        { 141, 0, 125, 0, 5 },
        { 74, 0, 15, 5, 0 },
        { 75, 0, 25, 10, 2 },
        { 76, 0, 20, 5, 3 },
        { 141, 0, 61, 1, 4 },
        { 78, 0, 25, 5, 0 },
        { 79, 0, 55, 5, 3 },
        { 141, 0, 90, 10, 2 },
        { 81, 0, 40, 10, 1 },
        { 82, 0, 155, 5, 2 },
        { 83, 0, 35, 5, 3 },
        { 141, 0, 300, 0, 6 },
        { 85, 0, 40, 10, 1 },
        { 141, 0, 140, 5, 3 },
        { 87, 0, 15, 5, 0 },
        { 141, 0, 85, 10, 2 },
        { 89, 0, 15, 5, 0 },
        { 90, 0, 50, 5, 3 },
        { 141, 0, 25, 10, 2 },
        { 92, 0, 15, 10, 1 },
        { 93, 0, 45, 10, 2 },
        { 94, 0, 40, 5, 3 },
        { 141, 0, 116, 1, 4 },
        { 96, 0, 110, 10, 1 },
        { 141, 0, 905, 5, 3 },
        { 98, 0, 80, 5, 0 },
        { 99, 0, 380, 5, 2 },
        { 141, 0, 76, 1, 4 },
        { 101, 0, 30, 5, 0 },
        { 102, 0, 155, 5, 3 },
        { 103, 0, 130, 5, 2 },
        { 104, 0, 51, 1, 4 },
        { 141, 0, 125, 0, 5 },
        { 106, 0, 665, 5, 3 },
        { 141, 0, 280, 5, 2 },
        { 108, 0, 310, 10, 2 },
        { 109, 0, 130, 5, 3 },
        { 141, 0, 51, 1, 4 },
        { 111, 0, 80, 5, 3 },
        { 141, 0, 85, 10, 2 },
        { 113, 0, 85, 10, 2 },
        { 114, 0, 15, 5, 3 },
        { 115, 0, 21, 1, 4 },
        { 141, 0, 50, 0, 6 },
        { 117, 0, 15, 5, 0 },
        { 118, 0, 40, 5, 3 },
        { 119, 0, 75, 10, 2 },
        { 120, 0, 6, 1, 4 },
        { 141, 0, 25, 0, 5 },
        { 122, 0, 50, 5, 3 },
        { 123, 0, 80, 10, 2 },
        { 141, 0, 6, 1, 4 },
        { 125, 0, 110, 10, 2 },
        { 141, 0, 20, 5, 3 },
        { 127, 0, 105, 5, 3 },
        { 128, 0, 140, 10, 2 },
        { 129, 0, 11, 1, 4 },
        { 141, 0, 100, 0, 6 },
        { 131, 0, 15, 5, 0 },
        { 132, 0, 15, 5, 3 },
        { 133, 0, 30, 5, 2 },
        { 134, 0, 25, 15, 4 },
        { 141, 0, 25, 0, 5 },
        { 136, 0, 130, 5, 3 },
        { 137, 0, 30, 5, 2 },
        { 141, 0, 6, 1, 4 },
        { 139, 0, 55, 10, 2 },
        { 140, 0, 80, 5, 3 },
        { 141, 0, 6, 1, 4 }
    };
    benches_t Q(7);
    ID_t maxtime = 100000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 2);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 2);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 2);
    Q[5].type = 5; Q[5].order = segtree_t(maxtime, 1);
    Q[6].type = 6; Q[6].order = segtree_t(maxtime, 1);

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

void ant_run_full()
{
    workGraph_t G =
    {
        { 2, 1, 0, 250, 0, 5 },
        { 1, 217, 0, 100, 0, 6 },
        { 0, 3, 0, 15, 5, 0 },
        { 1, 4, 0, 40, 10, 2 },
        { 1, 5, 0, 65, 15, 3 },
        { 1, 0, 0, 51, 1, 4 },
        { 0, 7, 0, 15, 5, 0 },
        { 1, 8, 0, 40, 10, 2 },
        { 1, 9, 0, 65, 15, 3 },
        { 1, 0, 0, 51, 1, 4 },
        { 2, 11, 0, 350, 0, 5 },
        { 1, 217, 0, 100, 0, 6 },
        { 0, 13, 0, 15, 5, 0 },
        { 1, 14, 0, 40, 10, 2 },
        { 1, 15, 0, 65, 15, 3 },
        { 1, 10, 0, 11, 1, 4 },
        { 0, 17, 0, 15, 5, 0 },
        { 1, 18, 0, 30, 10, 2 },
        { 1, 19, 0, 65, 15, 3 },
        { 1, 10, 0, 11, 1, 4 },
        { 6, 21, 0, 1650, 0, 5 },
        { 1, 217, 0, 300, 0, 6 },
        { 0, 23, 0, 265, 25, 3 },
        { 1, 24, 0, 160, 10, 2 },
        { 1, 20, 0, 70, 10, 4 },
        { 0, 26, 0, 35, 5, 0 },
        { 1, 20, 0, 220, 10, 2 },
        { 0, 28, 0, 65, 5, 0 },
        { 1, 29, 0, 250, 10, 2 },
        { 1, 20, 0, 151, 1, 4 },
        { 0, 31, 0, 65, 5, 0 },
        { 1, 20, 0, 190, 10, 2 },
        { 0, 33, 0, 65, 5, 0 },
        { 1, 34, 0, 160, 10, 2 },
        { 1, 20, 0, 275, 5, 3 },
        { 0, 36, 0, 65, 5, 0 },
        { 1, 37, 0, 70, 10, 2 },
        { 1, 20, 0, 365, 5, 3 },
        { 6, 39, 0, 275, 0, 5 },
        { 1, 217, 0, 50, 0, 6 },
        { 0, 41, 0, 95, 25, 3 },
        { 1, 42, 0, 25, 10, 2 },
        { 1, 38, 0, 30, 10, 4 },
        { 0, 44, 0, 10, 5, 0 },
        { 1, 38, 0, 45, 10, 2 },
        { 0, 46, 0, 10, 5, 0 },
        { 1, 47, 0, 130, 10, 2 },
        { 1, 38, 0, 21, 1, 4 },
        { 0, 49, 0, 10, 5, 0 },
        { 1, 38, 0, 180, 10, 2 },
        { 0, 51, 0, 10, 5, 0 },
        { 1, 52, 0, 25, 10, 2 },
        { 1, 38, 0, 10, 5, 3 },
        { 0, 54, 0, 10, 5, 0 },
        { 1, 55, 0, 35, 10, 2 },
        { 1, 38, 0, 15, 5, 3 },
        { 6, 57, 0, 275, 0, 5 },
        { 1, 217, 0, 50, 0, 6 },
        { 0, 59, 0, 15, 5, 0 },
        { 1, 56, 0, 65, 10, 2 },
        { 0, 61, 0, 15, 5, 0 },
        { 1, 56, 0, 70, 10, 2 },
        { 0, 63, 0, 15, 5, 0 },
        { 1, 64, 0, 55, 10, 2 },
        { 1, 56, 0, 30, 5, 3 },
        { 0, 66, 0, 25, 10, 1 },
        { 1, 67, 0, 35, 10, 2 },
        { 1, 56, 0, 38, 3, 4 },
        { 0, 69, 0, 15, 5, 0 },
        { 1, 70, 0, 30, 5, 2 },
        { 1, 56, 0, 30, 5, 3 },
        { 0, 72, 0, 25, 10, 1 },
        { 1, 73, 0, 30, 5, 2 },
        { 1, 74, 0, 40, 5, 3 },
        { 1, 75, 0, 46, 1, 4 },
        { 1, 56, 0, 50, 0, 6 },
        { 0, 77, 0, 78, 10, 1 },
        { 1, 78, 0, 61, 10, 2 },
        { 1, 217, 0, 158, 5, 3 },
        { 0, 80, 0, 112, 10, 1 },
        { 1, 81, 0, 175, 5, 3 },
        { 1, 82, 0, 35, 1, 4 },
        { 1, 217, 0, 340, 0, 6 },
        { 0, 84, 0, 130, 10, 1 },
        { 1, 217, 0, 130, 10, 2 },
        { 0, 86, 0, 110, 10, 1 },
        { 1, 87, 0, 705, 5, 3 },
        { 1, 88, 0, 210, 10, 2 },
        { 1, 217, 0, 1000, 0, 6 },
        { 0, 90, 0, 20, 10, 1 },
        { 1, 217, 0, 20, 10, 2 },
        { 0, 92, 0, 100, 10, 1 },
        { 1, 93, 0, 410, 5, 3 },
        { 1, 217, 0, 91, 1, 4 },
        { 0, 95, 0, 56, 10, 1 },
        { 1, 217, 0, 148, 10, 2 },
        { 0, 97, 0, 238, 10, 1 },
        { 1, 98, 0, 1905, 5, 3 },
        { 1, 217, 0, 542, 10, 2 },
        { 0, 100, 0, 100, 10, 1 },
        { 1, 217, 0, 155, 5, 2 },
        { 0, 102, 0, 40, 10, 1 },
        { 1, 103, 0, 185, 5, 3 },
        { 1, 104, 0, 195, 15, 4 },
        { 1, 217, 0, 150, 0, 6 },
        { 0, 106, 0, 30, 5, 0 },
        { 1, 217, 0, 110, 10, 2 },
        { 0, 108, 0, 10, 5, 0 },
        { 1, 109, 0, 30, 5, 3 },
        { 1, 110, 0, 121, 1, 4 },
        { 1, 111, 0, 275, 0, 5 },
        { 1, 217, 0, 15, 10, 2 },
        { 0, 113, 0, 30, 10, 1 },
        { 1, 217, 0, 250, 10, 2 },
        { 0, 115, 0, 70, 10, 1 },
        { 1, 116, 0, 310, 10, 3 },
        { 1, 217, 0, 400, 10, 2 },
        { 0, 118, 0, 20, 5, 0 },
        { 1, 119, 0, 70, 10, 2 },
        { 1, 217, 0, 80, 5, 3 },
        { 0, 121, 0, 30, 5, 0 },
        { 1, 122, 0, 230, 5, 3 },
        { 1, 123, 0, 85, 10, 2 },
        { 1, 217, 0, 376, 1, 4 },
        { 0, 125, 0, 25, 10, 1 },
        { 1, 217, 0, 45, 10, 2 },
        { 0, 127, 0, 40, 10, 1 },
        { 1, 128, 0, 75, 5, 3 },
        { 1, 217, 0, 80, 10, 2 },
        { 0, 130, 0, 35, 5, 0 },
        { 1, 131, 0, 155, 5, 2 },
        { 1, 132, 0, 95, 5, 3 },
        { 1, 217, 0, 151, 1, 4 },
        { 0, 134, 0, 20, 5, 0 },
        { 1, 135, 0, 80, 5, 3 },
        { 1, 217, 0, 106, 1, 4 },
        { 0, 137, 0, 85, 10, 1 },
        { 1, 217, 0, 130, 5, 2 },
        { 0, 139, 0, 20, 10, 1 },
        { 1, 217, 0, 65, 5, 3 },
        { 0, 141, 0, 15, 5, 0 },
        { 1, 142, 0, 80, 10, 2 },
        { 1, 143, 0, 25, 5, 3 },
        { 1, 217, 0, 100, 0, 6 },
        { 0, 145, 0, 30, 5, 0 },
        { 1, 146, 0, 305, 5, 3 },
        { 1, 147, 0, 185, 10, 2 },
        { 1, 148, 0, 226, 1, 4 },
        { 1, 217, 0, 125, 0, 5 },
        { 0, 150, 0, 15, 5, 0 },
        { 1, 151, 0, 25, 10, 2 },
        { 1, 152, 0, 20, 5, 3 },
        { 1, 217, 0, 61, 1, 4 },
        { 0, 154, 0, 25, 5, 0 },
        { 1, 155, 0, 55, 5, 3 },
        { 1, 217, 0, 90, 10, 2 },
        { 0, 157, 0, 40, 10, 1 },
        { 1, 158, 0, 155, 5, 2 },
        { 1, 159, 0, 35, 5, 3 },
        { 1, 217, 0, 300, 0, 6 },
        { 0, 161, 0, 40, 10, 1 },
        { 1, 217, 0, 140, 5, 3 },
        { 0, 163, 0, 15, 5, 0 },
        { 1, 217, 0, 85, 10, 2 },
        { 0, 165, 0, 15, 5, 0 },
        { 1, 166, 0, 50, 5, 3 },
        { 1, 217, 0, 25, 10, 2 },
        { 0, 168, 0, 15, 10, 1 },
        { 1, 169, 0, 45, 10, 2 },
        { 1, 170, 0, 40, 5, 3 },
        { 1, 217, 0, 116, 1, 4 },
        { 0, 172, 0, 110, 10, 1 },
        { 1, 217, 0, 905, 5, 3 },
        { 0, 174, 0, 80, 5, 0 },
        { 1, 175, 0, 380, 5, 2 },
        { 1, 217, 0, 76, 1, 4 },
        { 0, 177, 0, 30, 5, 0 },
        { 1, 178, 0, 155, 5, 3 },
        { 1, 179, 0, 130, 5, 2 },
        { 1, 180, 0, 51, 1, 4 },
        { 1, 217, 0, 125, 0, 5 },
        { 0, 182, 0, 665, 5, 3 },
        { 1, 217, 0, 280, 5, 2 },
        { 0, 184, 0, 310, 10, 2 },
        { 1, 185, 0, 130, 5, 3 },
        { 1, 217, 0, 51, 1, 4 },
        { 0, 187, 0, 80, 5, 3 },
        { 1, 217, 0, 85, 10, 2 },
        { 0, 189, 0, 85, 10, 2 },
        { 1, 190, 0, 15, 5, 3 },
        { 1, 191, 0, 21, 1, 4 },
        { 1, 217, 0, 50, 0, 6 },
        { 0, 193, 0, 15, 5, 0 },
        { 1, 194, 0, 40, 5, 3 },
        { 1, 195, 0, 75, 10, 2 },
        { 1, 196, 0, 6, 1, 4 },
        { 1, 217, 0, 25, 0, 5 },
        { 0, 198, 0, 50, 5, 3 },
        { 1, 199, 0, 80, 10, 2 },
        { 1, 217, 0, 6, 1, 4 },
        { 0, 201, 0, 110, 10, 2 },
        { 1, 217, 0, 20, 5, 3 },
        { 0, 203, 0, 105, 5, 3 },
        { 1, 204, 0, 140, 10, 2 },
        { 1, 205, 0, 11, 1, 4 },
        { 1, 217, 0, 100, 0, 6 },
        { 0, 207, 0, 15, 5, 0 },
        { 1, 208, 0, 15, 5, 3 },
        { 1, 209, 0, 30, 5, 2 },
        { 1, 210, 0, 25, 15, 4 },
        { 1, 217, 0, 25, 0, 5 },
        { 0, 212, 0, 130, 5, 3 },
        { 1, 213, 0, 30, 5, 2 },
        { 1, 217, 0, 6, 1, 4 },
        { 0, 215, 0, 55, 10, 2 },
        { 1, 216, 0, 80, 5, 3 },
        { 1, 217, 0, 6, 1, 4 }
    };
    benches_t Q(7);
    ID_t maxtime = 100000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 2);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 2);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 2);
    Q[5].type = 5; Q[5].order = segtree_t(maxtime, 1);
    Q[6].type = 6; Q[6].order = segtree_t(maxtime, 1);

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

void single_LS_tr()
{
    workGraph_t G =
    {
        { 1, 0, 78, 10, 1 },
        { 2, 0, 61, 10, 2 },
        { 36, 0, 158, 5, 3 },
        { 4, 0, 112, 10, 1 },
        { 5, 0, 175, 5, 3 },
        { 6, 0, 35, 1, 4 },
        { 36, 0, 340, 0, 6 },
        { 8, 0, 130, 10, 1 },
        { 36, 0, 130, 10, 2 },
        { 10, 0, 110, 10, 1 },
        { 11, 0, 705, 5, 3 },
        { 12, 0, 210, 10, 2 },
        { 36, 0, 1000, 0, 6 },
        { 14, 0, 20, 10, 1 },
        { 36, 0, 20, 10, 2 },
        { 16, 0, 100, 10, 1 },
        { 17, 0, 410, 5, 3 },
        { 36, 0, 91, 1, 4 },
        { 19, 0, 56, 10, 1 },
        { 36, 0, 148, 10, 2 },
        { 21, 0, 238, 10, 1 },
        { 22, 0, 1905, 5, 3 },
        { 36, 0, 542, 10, 2 },
        { 24, 0, 100, 10, 1 },
        { 36, 0, 155, 5, 2 },
        { 26, 0, 40, 10, 1 },
        { 27, 0, 185, 5, 3 },
        { 28, 0, 195, 15, 4 },
        { 36, 0, 150, 0, 6 },
        { 30, 0, 30, 5, 0 },
        { 36, 0, 110, 10, 2 },
        { 32, 0, 10, 5, 0 },
        { 33, 0, 30, 5, 3 },
        { 34, 0, 121, 1, 4 },
        { 35, 0, 275, 0, 5 },
        { 36, 0, 15, 10, 2 },
    };
    benches_t Q(7);
    ID_t maxtime = 100000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 2);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 2);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 2);
    Q[5].type = 5; Q[5].order = segtree_t(maxtime, 1);
    Q[6].type = 6; Q[6].order = segtree_t(maxtime, 1);

    LS_res_t res = LS_algo(G, Q, trivia, nullptr);
    pretty_print(res, G, Q);
}

void ant_run_tr()
{
    workGraph_t G =
    {
        { 1, 0, 78, 10, 1 },
        { 2, 0, 61, 10, 2 },
        { 36, 0, 158, 5, 3 },
        { 4, 0, 112, 10, 1 },
        { 5, 0, 175, 5, 3 },
        { 6, 0, 35, 1, 4 },
        { 36, 0, 340, 0, 6 },
        { 8, 0, 130, 10, 1 },
        { 36, 0, 130, 10, 2 },
        { 10, 0, 110, 10, 1 },
        { 11, 0, 705, 5, 3 },
        { 12, 0, 210, 10, 2 },
        { 36, 0, 1000, 0, 6 },
        { 14, 0, 20, 10, 1 },
        { 36, 0, 20, 10, 2 },
        { 16, 0, 100, 10, 1 },
        { 17, 0, 410, 5, 3 },
        { 36, 0, 91, 1, 4 },
        { 19, 0, 56, 10, 1 },
        { 36, 0, 148, 10, 2 },
        { 21, 0, 238, 10, 1 },
        { 22, 0, 1905, 5, 3 },
        { 36, 0, 542, 10, 2 },
        { 24, 0, 100, 10, 1 },
        { 36, 0, 155, 5, 2 },
        { 26, 0, 40, 10, 1 },
        { 27, 0, 185, 5, 3 },
        { 28, 0, 195, 15, 4 },
        { 36, 0, 150, 0, 6 },
        { 30, 0, 30, 5, 0 },
        { 36, 0, 110, 10, 2 },
        { 32, 0, 10, 5, 0 },
        { 33, 0, 30, 5, 3 },
        { 34, 0, 121, 1, 4 },
        { 35, 0, 275, 0, 5 },
        { 36, 0, 15, 10, 2 },
    };
    benches_t Q(7);
    ID_t maxtime = 100000;
    Q[0].type = 0; Q[0].order = segtree_t(maxtime, 1);
    Q[1].type = 1; Q[1].order = segtree_t(maxtime, 1);
    Q[2].type = 2; Q[2].order = segtree_t(maxtime, 2);
    Q[3].type = 3; Q[3].order = segtree_t(maxtime, 2);
    Q[4].type = 4; Q[4].order = segtree_t(maxtime, 2);
    Q[5].type = 5; Q[5].order = segtree_t(maxtime, 1);
    Q[6].type = 6; Q[6].order = segtree_t(maxtime, 1);

    ant_params_t P;
    P.alpha = 0.5;
    P.beta = 0.5;
    P.qzero = 0.6;
    P.tzero = 0.6;
    P.rho = 0.5;
    P.res_mult = 50.0;
    P.iterations = 150;

    LS_res_t res = ant_opt(G, Q, P);
    pretty_print(res, G, Q);
}

int main(int argc, char const *argv[])
{
    ant_run_full();
    return 0;
}
