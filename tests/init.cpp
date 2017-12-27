#include <Backpack.hpp>
#include <catch.hpp>

SCENARIO("init", "[init]") {
	Backpack test;
	REQUIRE(test.Weight() == 0);
	REQUIRE(test.Value() == 0);
}

SCENARIO("copy", "[copy]")
{
	Backpack test (100, 3);
	Backpack copy(test);
	REQUIRE(test.Weight() == 100);
	REQUIRE(test.Value() == 3);
}

SCENARIO("main_1", "[main_1]")
{
	Backpack test(300, 3);				//___________MaxW = 300____________
	Backpack copy(test);				//|   №   |   weight   |    cost   |
	int val[] = { 10, 20, 30 };			//|   1   |    100     |     10    |
	int wt[] = { 100, 120, 130 };			//|   2   |    120     |     20    |		maxVal = 50
	REQUIRE(test.knapSack(wt, val, copy) == 50);	//|   3   |    130     |     30    |											//---------------------------------|	
							//----------------------------------					
}

SCENARIO("main_2", "[main_2]")
{
	Backpack test(300, 3);					//___________MaxW = 300____________
	Backpack copy(test);					//|   №   |   weight   |    cost   |
	int val[] = { 100, 20, 30 };				//|   1   |    100     |     100   |
	int wt[] = { 100, 120, 130 };				//|   2   |    120     |     20    |		maxVal = 130 
	REQUIRE(test.knapSack(wt, val, copy) == 130);		//|   3   |    130     |     30    |
								//---------------------------------|
}

SCENARIO("main_3", "[main_3]")
{
	Backpack test(130, 20);
	Backpack copy(test);
	int val[] = { 10, 20, 30, 40, 50, 60, 75, 80, 90, 100, 100, 110, 90, 80, 10, 30, 40, 80, 15, 75 };
	int wt[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
	REQUIRE(test.knapSack(wt, val, copy) == 585);
}




