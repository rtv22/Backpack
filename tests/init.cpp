#include <Backpack.hpp>
#include <catch.hpp>

SCENARIO("init", "[init]") {
	Backpack t;
	REQUIRE(matrix.maxW() == 0);
	REQUIRE(matrix.n() == 0);
}
