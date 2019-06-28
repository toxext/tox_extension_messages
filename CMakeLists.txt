project(tox_extension_messages)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

find_package(ToxExt REQUIRED)

add_library(ToxExtensionMessages tox_extension_messages.c)
target_compile_options(ToxExtensionMessages PRIVATE -Wall -Wextra -Werror -std=gnu11)
target_link_libraries(ToxExtensionMessages ToxExt::ToxExt)
set_target_properties(ToxExtensionMessages PROPERTIES PUBLIC_HEADER "tox_extension_messages.h")
target_include_directories(ToxExtensionMessages PRIVATE "${TOXCORE_INCLUDEDIR}")
set_target_properties(ToxExtensionMessages PROPERTIES OUTPUT_NAME "tox_extension_messages")

install(TARGETS ToxExtensionMessages EXPORT ToxExtensionMessagesConfig ARCHIVE DESTINATION lib PUBLIC_HEADER DESTINATION include)
install(EXPORT ToxExtensionMessagesConfig DESTINATION lib/cmake/ToxExtensionMessages NAMESPACE ToxExtensionMessages::)

enable_testing()
add_subdirectory(test)
