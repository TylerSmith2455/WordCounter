# CS315 Makefile for Program 4: Word Counter
# Feel free to modify as needed.
# Original author: Raphael Finkel 3/2020

CFLAGS = -Wall -g
CPPFLAGS = -Wall -g hashTable.cpp
GOAL = wordCount
DATA = data.txt

# compile and run the student program, placing the result in tmpRun.out
run: $(GOAL) $(DATA)
	./$(GOAL) < $(DATA) > tmpRun.out
	less tmpRun.out

# Modify the following recipe to zip exactly what you want to include.
zipAll: 
	zip toSubmit.zip $(GOAL).* Makefile README tmpRun.out *.txt hashTable.*
	
.PHONY: clean
clean:
	rm -f $(GOAL) $(WORKING) $(DATA) tmp* toSubmit.zip
