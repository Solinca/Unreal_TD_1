#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check Vector")
{
	std::vector<int> v(5);

	REQUIRE(v.size() == 5);


	CHECK(v[0] == 0);

	CHECK(v[1] == 0);

	CHECK(v[2] == 0);
}

SCENARIO("Vector manipulation")
{
	GIVEN("Vector with few elements")
	{
		std::vector<int> v(5);

		REQUIRE(v.size() == 5);

		WHEN("Resizing")
		{
			v.resize(10);

			THEN("Size and capacity changes")
			{
				REQUIRE(v.size() == 10);

				REQUIRE(v.capacity() == 10);
			}
		}

		WHEN("Clearing")
		{
			v.clear();

			THEN("Size is changed but not capacity")
			{
				REQUIRE(v.size() == 0);

				REQUIRE(v.capacity() == 5);
			}
		}
	}
}
