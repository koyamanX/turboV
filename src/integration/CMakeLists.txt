add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/ram64x8K.nsl ${CMAKE_CURRENT_BINARY_DIR}/ram64x8K.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/rom64x2K.nsl ${CMAKE_CURRENT_BINARY_DIR}/rom64x2K.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/clint.nsl ${CMAKE_CURRENT_BINARY_DIR}/clint.v)
add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/uart.nsl ${CMAKE_CURRENT_BINARY_DIR}/uart.v)

add_custom_target(integration
    DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/ram64x8K.v
        ${CMAKE_CURRENT_BINARY_DIR}/rom64x2K.v
        ${CMAKE_CURRENT_BINARY_DIR}/clint.v
        ${CMAKE_CURRENT_BINARY_DIR}/uart.v
)
export_nsl_headers(integration)
