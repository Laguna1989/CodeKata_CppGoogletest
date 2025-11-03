#include "implementation.hpp"
#include <catch2/catch_all.hpp>

TEST_CASE("Implementation Test")
{

    SECTION("Is this working?") { REQUIRE(answer() == 42); }
}
