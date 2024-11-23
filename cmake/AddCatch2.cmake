set(CATCH2_DIR ${CMAKE_BINARY_DIR}/external/catch2)
set(CATCH2_TAG ${CATCH2_VERSION})
set(CATCH2_URL https://github.com/catchorg/Catch2)

FetchContent_Declare(
  catch2 
  GIT_REPOSITORY ${CATCH2_URL}
  GIT_TAG ${CATCH2_TAG}
  GIT_SHALLOW TRUE
  GIT_SUBMODULES ""   
  SOURCE_DIR ${CATCH2_DIR}
)

FetchContent_MakeAvailable(catch2)

# https://stackoverflow.com/questions/56089330/cmake-creates-lots-of-targets-i-didnt-specify/59493613#59493613
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)