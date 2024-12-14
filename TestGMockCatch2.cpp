#include <catch2/catch_session.hpp>
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

// Fix for the problem:

class GTestCatch2Listener : public testing::EmptyTestEventListener
{
  std::set<std::string> m_file_names;

  void OnTestPartResult(const testing::TestPartResult& result) override
  {
    std::string filename = "unknown";
    size_t linenumber = 0;
    std::string message = "unknown";

    if (result.file_name())
      filename = result.file_name();

    if (result.line_number() != -1)
      linenumber = static_cast<std::size_t>(result.line_number());

    if (result.message())
      message = result.message();

    auto [it, _] = m_file_names.insert(filename);
    ::Catch::SourceLineInfo sourceLineInfo(it->c_str(), linenumber);

    if (result.fatally_failed()) {
      ::Catch::AssertionHandler assertion(
        "GMock", sourceLineInfo, "", ::Catch::ResultDisposition::Normal);

      assertion.handleMessage(::Catch::ResultWas::ExplicitFailure,
                              std::move(message));

      assertion.complete();
    } else if (result.nonfatally_failed()) {
      ::Catch::AssertionHandler assertion(
        "GMock",
        sourceLineInfo,
        "",
        ::Catch::ResultDisposition::ContinueOnFailure);

      assertion.handleMessage(::Catch::ResultWas::ExplicitFailure,
                              std::move(message));

      assertion.complete();
    }
  }
};

int
main(int argc, char** argv)
{
  Catch::Session session;
  InitGoogleMock(&argc, argv);

  TestEventListeners& gtest_listeners = UnitTest::GetInstance()->listeners();
  gtest_listeners.Append(new GTestCatch2Listener());
  delete gtest_listeners.Release(
    UnitTest::GetInstance()->listeners().default_result_printer());

  return session.run(argc, argv);
}