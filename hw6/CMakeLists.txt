cmake_minimum_required( VERSION 3.20 )
project( perfect_numer VERSION 1.0 )

message( "Using sources: perfect_numer.cpp" )
add_executable( perfect_numer )
target_sources( perfect_numer PRIVATE perfect_numer.cpp )

target_compile_features( perfect_numer PRIVATE cxx_std_20 )
install( TARGETS perfect_numer DESTINATION . )
install( FILES run.sh DESTINATION . )
