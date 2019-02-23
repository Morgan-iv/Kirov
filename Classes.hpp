#ifndef KIROV_CLASSES
#define KIROV_CLASSES
#include <string>
#include <vector>


enum BenchType{Saw,Plasma,Turning,Milling,Drill,Welding,Paint};
struct Work
{
	BenchType Type;
	int Time;
	int PrepareTime;
	Work(BenchType type,int time,int prepare_time)
	{
		Type=type;
		Time=time;
		PrepareTime=prepare_time;
	}
};

struct Detail
{
	std::string Name;
	int Amount;
	int Done;
	int Num;
	std::vector<Work> Sequence;
	Detail(std::string name)
	{
		Name=name;
	}
};

struct Bench
{
	size_t Remain;
	size_t Current;
	size_t Num;
	BenchType Type;
	std::list<size_t> Queue;
};

 






#endif
