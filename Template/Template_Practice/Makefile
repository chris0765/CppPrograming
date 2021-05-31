CXXFLAGS = -Wall

ifeq ($(DEBUG), 1)
CXXFLAGS += -g
endif

target = main
SRCS= $(notdir $(wildcard *.cpp))
OBJS = $(SRCS:.cpp=.o)
GCHES = $(SRCS:.cpp=.h.gch)

all : $(target)



%.o : %.cpp  %.h
	$(CXX) $(CXXFLAGS) -c $^

$(target) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 


.PHONY: clean
clean : 
	rm -f $(OBJS) $(target) $(GCHES)