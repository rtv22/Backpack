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
