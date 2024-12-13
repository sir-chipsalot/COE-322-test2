cmake_minimum_required( VERSION 3.20 )
project( collatz VERSION 1.0 )

message( "Using sources: collatz.cpp" )
add_executable( collatz )
target_sources( collatz PRIVATE collatz.cpp )

target_compile_features( collatz PRIVATE cxx_std_20 )
install( TARGETS collatz DESTINATION . )
install( FILES run.sh DESTINATION . )
