cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(tests)


# test succeed if compilation fails
function(test_not_compiling name)
	set(file ${name}.cpp)
	try_compile(COMPILE_SUCCEEDED
		${CMAKE_BINARY_DIR}
		${CMAKE_SOURCE_DIR}/${file}
		CMAKE_FLAGS "-DINCLUDE_DIRECTORIES=${CMAKE_SOURCE_DIR}/../include"
		)

	if(COMPILE_SUCCEEDED)
	  message(SEND_ERROR "${file}		test failed!")
	else()
		message(STATUS "${file}		test passed.")
	endif()

	include_directories(../include)
	add_executable(${name} ${file})
endfunction(test_not_compiling)

# test succeed if compilation succeed
function(test_compiling name)
	set(file ${name}.cpp)
	try_compile(COMPILE_SUCCEEDED
		${CMAKE_BINARY_DIR}
		${CMAKE_SOURCE_DIR}/${file}
		CMAKE_FLAGS "-DINCLUDE_DIRECTORIES=${CMAKE_SOURCE_DIR}/../include"
		)

	if(NOT COMPILE_SUCCEEDED)
	  message(SEND_ERROR "${file}		test failed!")
	else()
		message(STATUS "${file}		test passed.")
	endif()

	include_directories(../include)
	add_executable(${name} ${file})
endfunction(test_compiling)


# make sure valid code can compile
test_compiling(test_testing)
# test strong type
test_compiling(arithmetic_types_operators)
test_compiling(T_param)
test_compiling(T_ref_param)
test_not_compiling(ST_param)
test_not_compiling(ST_ref_param)