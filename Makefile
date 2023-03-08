CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

HEADERS = operation_class.h file_handler.h timer.h cursor_handler.h
SRCS =  main.cpp timer.cpp operation_class.cpp file_handler.cpp cursor_handler.cpp
OBJS = ${SRCS:.cpp=.o}

MAIN = operationTimer

all: ${MAIN}
	@echo	Simple compilter named operationTimer has been compiled

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.