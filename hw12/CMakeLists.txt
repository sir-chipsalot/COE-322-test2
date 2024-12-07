cmake_minimum_required( VERSION 3.20 )
project( quadratic VERSION 1.0 )

message( "Using sources: 2pascaltriangle.cpp" )
add_executable( quadratic )
target_sources( quadratic PRIVATE quadratics.cpp )

target_compile_features( quadratic PRIVATE cxx_std_20 )
install( TARGETS quadratic DESTINATION . )
install( FILES run.sh DESTINATION . )
