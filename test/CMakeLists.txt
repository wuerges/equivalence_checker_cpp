add_executable(Test test.cxx)
target_link_libraries(Test 
    Lib
  )

add_test( Test ./Test )