cmake_minimum_required( VERSION 3.20 )
project( fizzbuzz VERSION 1.0 )

message( "Using sources: fizzbuzz.cpp" )
add_executable( fizzbuzz )
target_sources( fizzbuzz PRIVATE fizzbuzz.cpp )

target_compile_features( fizzbuzz PRIVATE cxx_std_20 )
install( TARGETS fizzbuzz DESTINATION . )
install( FILES run.sh DESTINATION . )
