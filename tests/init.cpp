#include <Backpack.hpp>
#include <catch.hpp>

SCENARIO("init", "[init]") {
	Backpack test;
	REQUIRE(test.Weight() == 0);
	REQUIRE(test.Value() == 0);
}

SCENARIO("copy", "[copy]")
{
	Backpack test (100, 2);
	Backpack copy(test);
	REQUIRE(test.Weight() == 100);
	REQUIRE(test.Value() == 2);
}

SCENARIO("main", "[main]")
{
	Backpack test(300, 3);				//___________MaxW = 300____________
	Backpack copy(test);				//|   №   |   weight   |    cost   |
	int val[] = { 10, 20, 30 };			//|   1   |    100     |     10    |
	int wt[] = { 100, 120, 130 };			//|   2   |    120     |     20    |		maxVal = 50
	REQUIRE(test.knapSack(wt, val, copy) == 50);	//|   3   |    130     |     30    |											//---------------------------------|	
							//----------------------------------					
}

SCENARIO("main1", "[main1]")
{
	Backpack test(300, 3);					//___________MaxW = 300____________
	Backpack copy(test);					//|   №   |   weight   |    cost   |
	int val[] = { 100, 20, 30 };				//|   1   |    100     |     100   |
	int wt[] = { 100, 120, 130 };				//|   2   |    120     |     20    |		maxVal = 130 
	REQUIRE(test.knapSack(wt, val, copy) == 130)		//|   3   |    130     |     30    |
								//---------------------------------|
}






