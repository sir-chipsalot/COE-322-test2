cmake_minimum_required( VERSION 3.20 )
project( newtonpoly VERSION 1.0 )

message( "Using sources: newtonpoly.cpp" )
add_executable( newtonpoly )
target_sources( newtonpoly PRIVATE newtonpoly.cpp )

target_compile_features( newtonpoly PRIVATE cxx_std_20 )
install( TARGETS newtonpoly DESTINATION . )
install( FILES run.sh DESTINATION . )
