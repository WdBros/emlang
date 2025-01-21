default:
	g++ linter.cpp evaluator.cpp parser.cpp tokenizer.cpp calculator.cpp -o emlang 

debug:
	echo "Making debug build!"
	g++ -g1 linter.cpp evaluator.cpp parser.cpp tokenizer.cpp calculator.cpp -o emlang