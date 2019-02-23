#ifndef KIROV_CLASSES
#define KIROV_CLASSES
#include <string>
#include <vector>


enum BenchType{Saw,Plasma,Turning,Milling,Drill,Welding,Paint};
struct Work{
	BenchType Type;
	int Time;
	int PrepareTime;
	Work(BenchType type,int time,int prepare_time){
		Type=type;
		Time=time;
		PrepareTime=prepare_time;
	}
};

struct Detail{
	std::string Name;
	int Amount;
	int Done;
	std::vector<Work> Sequence;
	Detail(std::string name){
		Name=name;
	}
};

struct Bench{
	BenchType Type;
	std::vector<Detail> Queue;
};

 






#endif
