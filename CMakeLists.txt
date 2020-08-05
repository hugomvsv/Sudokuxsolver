cmake_minimum_required(VERSION 3.14)
project(lpprog2fi C)

set(CMAKE_C_STANDARD 99)

add_executable(lpprog2fi main.c Fase2/Check.c Fase2/Check.h Fase2/library.h Fase2/R9.c Fase2/R9.h Fase2/R13.c Fase2/R13.h Fase2/R12.c Fase2/R12.h Fase2/Hidden.c Fase2/Hidden.h Fase2/NakedPairs.c Fase2/NakedPairs.h Fase2/PointingPairs.c Fase2/PointingPairs.h Fase2/box_line_reduction.c Fase2/box_line_reduction.h Fase2/R14.c Fase2/R14.h)