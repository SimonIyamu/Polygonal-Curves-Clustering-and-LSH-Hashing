all: curvesDemo lshDemo hyperCubeDemo

curvesDemo : Curves/main.o Point.o Curves/Curve.o Curves/readingFunctions.o Curves/curveHashing.o Curves/LSHC.o Curves/Grid.o dist.o H.o G.o LSH/LSH.o util.o HyperCube/HC.o
	g++ Curves/main.o  Point.o Curves/Curve.o Curves/readingFunctions.o Curves/curveHashing.o Curves/LSHC.o Curves/Grid.o dist.o H.o G.o LSH/LSH.o HyperCube/HC.o util.o -o curvesDemo -g

lshDemo : LSH/main.o Point.o dist.o H.o G.o LSH/LSH.o util.o Curves/Curve.o
	g++ LSH/main.o Point.o dist.o H.o G.o LSH/LSH.o util.o Curves/Curve.o -o lshDemo

hyperCubeDemo : HyperCube/main.o Point.o dist.o H.o G.o HyperCube/HC.o util.o Curves/Curve.o
	g++ HyperCube/main.o  Point.o dist.o H.o G.o HyperCube/HC.o util.o Curves/Curve.o -o hyperCubeDemo

Curves/main.o : Curves/main.cpp
	g++ -c Curves/main.cpp -g -o Curves/main.o

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp -o Point.o -g

Curves/Curve.o	: Curves/Curve.cpp Curves/Curve.hpp
	g++ -c Curves/Curve.cpp -o Curves/Curve.o -g

Curves/LSHC.o: Curves/LSHC.cpp Curves/LSHC.hpp
	g++ -c Curves/LSHC.cpp -o Curves/LSHC.o -g

Curves/readingFunctions.o:	Curves/readingFunctions.cpp Curves/readingFunctions.hpp	
	g++ -c Curves/readingFunctions.cpp -o Curves/readingFunctions.o -g

Curves/curveHashing.o:	Curves/curveHashing.cpp Curves/curveHashing.hpp
	g++ -c Curves/curveHashing.cpp -o Curves/curveHashing.o -g

Curves/Grid.o:	Curves/Grid.cpp Curves/Grid.hpp
	g++ -c Curves/Grid.cpp -o Curves/Grid.o -g 

LSH/main.o : LSH/main.cpp
	g++ -c LSH/main.cpp -o LSH/main.o -g 

H.o : H.cpp
	g++ -c H.cpp -o H.o -g

G.o : G.cpp
	g++ -c G.cpp -o G.o -g

LSH/LSH.o : LSH/LSH.cpp LSH/LSH.hpp
	g++ -c LSH/LSH.cpp -o LSH/LSH.o -g

util.o : util.cpp
	g++ -c util.cpp -o util.o -g

dist.o : dist.cpp
	g++ -c dist.cpp -o dist.o -g

HyperCube/main.o : HyperCube/main.cpp
	g++ -c HyperCube/main.cpp -o HyperCube/main.o -g 

HyperCube/HC.o : HyperCube/HC.cpp HyperCube/HC.hpp
	g++ -c HyperCube/HC.cpp -o HyperCube/HC.o -g

clean:
	rm curvesDemo Curves/main.o Point.o Curves/Curve.o Curves/readingFunctions.o Curves/curveHashing.o Curves/LSHC.o Curves/Grid.o lshDemo LSH/main.o dist.o H.o G.o LSH/LSH.o util.o HyperCube/main.o HyperCube/HC.o hyperCubeDemo
