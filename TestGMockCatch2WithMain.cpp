#include <catch2/catch_test_macros.hpp>
#include "mock_class.hpp"

using namespace ::testing;
TEST_CASE("Strict Mock Test")
{
    auto mock = StrictMock<MockClass>();
    auto caller = SimpleWrapper(mock);

    caller.call();
}

TEST_CASE("Expect call")
{
    auto mock = NiceMock<MockClass>();
    auto caller = SimpleWrapper(mock);

    EXPECT_CALL(mock, some_call()).Times(100);
    caller.call();
}