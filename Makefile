CXX = g++

default:
	$(CXX) linter.cpp evaluator.cpp parser.cpp tokenizer.cpp calculator.cpp -o emlang 

debug:
	echo "Making debug build!"
	$(CXX) -g1 linter.cpp evaluator.cpp parser.cpp tokenizer.cpp calculator.cpp -o emlang