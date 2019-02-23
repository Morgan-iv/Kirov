#include <cstdio>
#include <vector>
#include <string>
#include "Classes.hpp"

typedef std::vector<Detail> Details_t;
typedef std::vector<Bench> Bench_t;

void load_details(std::string CSV, Details_t & details)
{
    FILE * f = fopen(CSV.c_str(), "r");
    char buf1[30];
    char buf2[30];
    size_t num = details.size();
    for (size_t i = 0; i < num; ++i)
    {
        fscanf(f, "%s,%s", buf1, buf2);
        res[i].Name = std::string(buf2);
    }
    fclose(f);
}

void load_amounts(std::string CSV, Details_t & details)
{
    FILE * f = fopen(CSV.c_str(), "r");
    char buf1[30];
    char buf2[30];
    size_t num = details.size();
    int am;
    for (size_t i = 0; i < num; ++i)
    {
        fscanf(f, "%s,%s,%d", buf1, buf2, &am);
        res[i].Amount;
    }
    fclose(f);
}



size_t choose_detail(Bench & b)
{
    return 0;
}

int main(int argc, const char * argv[])
{

    Details_t details;
    Bench_t benches;


    for (size_t i = 0; i < details.size(); ++i)
    {
        size_t cur_b = 0;
        for (size_t j = 0; j < benches.size(); ++j)
        {
            if (details[i].Sequence[0].Type == benches[j].Type &&
                benches[cur_b].Queue.size() > benches[j].Queue.size())
            {
                cur_b = j;
            }
        }
        benches[cur_b].Queue.push_back(i);
    }

    size_t lastrange = 0;
    for (size_t quant = 0;;)
    {
        size_t mintime = (size_t)1e9;
        for (int i = 0; i < benches.size(); ++i)
        {
            benches[i].Remain -= lastrange;
            if (benches[i].Remain > 0 && benches[i].Remain < mintime)
            {
                mintime = benches[i].Remain;
            }
            if (benches[i].Remain == 0)
            {
                Bench & cur_b = benches[i];
                details[cur_b.Current].Num = cur_b.Num + 1;
                BenchType nexttype = details[cur_b.Current].Sequence[cur_b.Num + 1].Type;
                size_t nextbench = choose_bench(nexttype);
                benches[nextbench].Queue.push_back(cur_b.Current);
                size_t ch = choose_detail(i);
                printf("Detail %5d ")
                cur_b.Current = cur_b.Queue[ch];
                Detail & cur_d = details[cur_b.Current];
                Work & cur_w = cur_d.Sequence[cur_d.Num];
                int time = cur_w.PrepareTime + cur_w.Time * cur_d.Amount;
                cur_b.Remain = time;
                cur_b.Queue.remove(ch)
                if (time < mintime)
                    mintime = cur_b.Remain;
            }
        }
        lastrange = mintime;
        quant += lastrange;
        if (need_exit())
            break;
    }

    return 0;
}