#ifndef ANT_OPT
#define ANT_OPT

#include "lsalg.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

struct ant_params_t
{
    double alpha;
    double beta;
    double qzero;
    double tzero;
    double rho;
    double res_mult;
    ID_t iterations;
    std::vector<double> eta;
    std::vector<std::vector<double> > theta;
};

double drand()
{
    return (double)std::rand() / RAND_MAX;
}

ID_t calc_d(workGraph_t & G, std::vector<double> & eta, ID_t id, ID_t UBmax)
{
    if (G[id].next == G.size())
        eta[id] = 1.0 / UBmax;
    else
        eta[id] = 1.0 / (UBmax = calc_d(G, eta, G[id].next, UBmax) - G[G[id].next].len);
    return UBmax;
}

ID_t choose_ant(workGraph_t & G, benches_t & Q, EL_t & EL, ID_t pos, void * extparams)
{
    ant_params_t * P = (ant_params_t *)extparams;
    std::vector<double> probs(EL.size());
    ID_t i = 0;
    for (auto it = EL.begin(); it != EL.end(); ++it, ++i)
    {
        probs[i] = std::pow(P->theta[pos][*it], P->alpha) * std::pow(P->eta[*it], P->beta);
    }
    ID_t h;
    ID_t c;
    if (drand() < P->qzero)
    {
        h = *EL.begin();
        c = 0;
        i = 0;
        for (auto it = EL.begin(); it != EL.end(); ++it, ++i)
        {
            if (probs[i] > probs[c])
            {
                c = i;
                h = *it;
            }
        }
    }
    else
    {
        double psum = 0;
        for (ID_t i = 1; i < EL.size(); ++i)
        {
            probs[i] += probs[i - 1];
        }
        double chp = drand() * probs[EL.size() - 1];
        i = 0;
        for (auto it = EL.begin(); it != EL.end(); ++it, ++i)
        {
            if (chp < probs[i])
            {
                h = *it;
                break;
            }
        }
    }
    P->theta[pos][h] = (1.0 - P->rho) * P->theta[pos][h] + P->rho * P->tzero;
    return h;
}

LS_res_t ant_opt(workGraph_t G, benches_t Q, ant_params_t P)
{
    std::srand(std::time(0));
    P.eta.resize(G.size());
    std::fill(P.eta.begin(), P.eta.end(), 0.0);
    ID_t UBmax = 0;
    for (ID_t i = 0; i < G.size(); ++i)
    {
        UBmax += G[i].len;
    }
    for (ID_t i = 0; i < G.size(); ++i)
    {
        if (P.eta[i] == 0)
            calc_d(G, P.eta, i, UBmax);
    }
    P.theta.resize(G.size());
    for (ID_t i = 0; i < G.size(); ++i)
    {
        P.theta[i].resize(G.size());
        std::fill(P.theta[i].begin(), P.theta[i].end(), 1.0);
    }
    LS_res_t best_res;
    bool f = true;
    for (ID_t k = 0; k < P.iterations; ++k)
    {
        LS_res_t cur_res = LS_algo(G, Q, choose_ant, (void *)(&P));
        if (f)
        {
            best_res = cur_res;
            f = false;
        }
        if (cur_res.time < best_res.time)
            best_res = cur_res;
        for (ID_t i = 0; i < G.size(); ++i)
        {
            for (ID_t j = 0; j < G.size(); ++j)
            {
                P.theta[i][j] = (1.0 - P.rho) * P.theta[i][j] +
                    ((best_res.permut[i] != j) ? 0 : P.res_mult * P.rho / best_res.time);
            }
        }
    }
    return best_res;
}

#endif  //ANT_OPT
