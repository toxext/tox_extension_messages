if (COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif()

include(CTest)

# I'm sure I could do this better but I don't want to spend my time on cmake really
function(tox_extension_messages_test test_name)
	add_executable(${test_name} ${ARGN})
	# we use gnu11 for the tests so we can use the container_of macro for inheritance a la linux
	target_compile_options(${test_name} PRIVATE -Wall -Wextra -Werror -std=gnu11 -ftest-coverage -fprofile-arcs)
	#target_link_options(${test_name} PRIVATE -fprofile-arcs -ftest-coverage)
	target_link_libraries(${test_name} gcov ToxExt::Mock)
	target_include_directories(${test_name} PRIVATE "${TOXCORE_INCLUDEDIR}")
	add_test(${test_name} ${test_name})
endfunction(tox_extension_messages_test)

tox_extension_messages_test(sanity_test sanity_test.c)
