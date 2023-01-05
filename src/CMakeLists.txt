set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)
set(REVISION 0)
configure_file(version.h.in version.h)

add_subdirectory(core)
add_subdirectory(integration)
add_subdirectory(wishbone)
