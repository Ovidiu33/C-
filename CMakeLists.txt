cmake_minimum_required(VERSION 3.25)
project(Biblioteca)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblioteca main.cpp Domain/entitate.cpp Repo/repo.cpp Console/ui.cpp Business/service.cpp Validator/validate.cpp Tests/tests.cpp)
