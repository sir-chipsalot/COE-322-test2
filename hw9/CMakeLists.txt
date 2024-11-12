cmake_minimum_required( VERSION 3.20 )
project( linkshared VERSION 1.0 )

message( "Using sources: linkshared.cpp" )
add_executable( linkshared )
target_sources( linkshared PRIVATE linkshared.cpp )

target_compile_features( linkshared PRIVATE cxx_std_20 )
install( TARGETS linkshared DESTINATION . )
install( FILES run.sh DESTINATION . )
