cmake_minimum_required( VERSION 3.20 )
project( newton VERSION 1.0 )

message( "Using sources: newton.cpp" )
add_executable( pascal )
target_sources( pascal PRIVATE 2pascaltriangle.cpp )

target_compile_features( pascal PRIVATE cxx_std_20 )
install( TARGETS pascal DESTINATION . )
install( FILES run.sh DESTINATION . )
