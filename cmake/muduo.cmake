include(FetchContent)

fetchcontent_declare(muduo
  GIT_REPOSITORY https://github.com/chenshuo/muduo.git
  GIT_TAG v2.0.3
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/muduo
)

fetchcontent_makeavailable(muduo)