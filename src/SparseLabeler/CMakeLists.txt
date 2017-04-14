
include_directories(
  model
)

add_executable(SparseLabeler SparseLabeler.cpp)
target_link_libraries(SparseLabeler ${LIBS})
