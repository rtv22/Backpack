#include <Backpack.hpp>
#include <catch.hpp>

SCENARIO("init", "[init]") {
	Backpack test;
	REQUIRE(test.maxW() == 0);
	REQUIRE(test.n() == 0);
}
