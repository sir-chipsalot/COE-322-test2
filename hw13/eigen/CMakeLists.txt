cmake_minimum_required( VERSION 3.12 )
project( jacobi VERSION 1.0 )

add_executable( jacobi jacobi.cpp )
target_compile_features( jacobi PRIVATE cxx_std_23 )

find_package( Eigen3 REQUIRED  )
target_link_libraries( jacobi PUBLIC Eigen3::Eigen )

install( TARGETS jacobi DESTINATION . )

# emacs:
## ESC x repl<sp>st<sp>
# vi:
## 1,$s/oldstring/newstring/g
