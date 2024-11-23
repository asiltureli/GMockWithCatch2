set(GTEST_DIR ${CMAKE_BINARY_DIR}/external/googletest)
set(GTEST_TAG ${GTEST_VERSION})
set(GTEST_URL https://github.com/google/googletest)

FetchContent_Declare(
  googletest 
  GIT_REPOSITORY ${GTEST_URL}
  GIT_TAG ${GTEST_TAG}
  GIT_SHALLOW TRUE
  GIT_SUBMODULES ""   
  SOURCE_DIR ${GTEST_DIR}
)

FetchContent_MakeAvailable(googletest)